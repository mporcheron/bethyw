
import os
import pandas as pd
import sys
import webbrowser as wb

this_dir = os.path.dirname(os.path.abspath(__file__)) + "/"

colAuthorityCode = 'AuthorityCode'
colMeasureCodename = 'Pollutant_ItemName_ENG'
colYear = 'Year_Code'
colValue = 'Data'

df = pd.read_csv(this_dir + 'complete-popu1009-popden.csv')

counts = {}
minYear = {}
maxYear = {}

prevArea = ""
prevMeasure = ""
measureCodename = "dens"
for i, row in df.iterrows():
  localAuthorityCode = str(row['AuthorityCode'])

  for j, value in enumerate(row): 
    if j == 0:
      continue

    year = str(df.columns[j])

    if localAuthorityCode in counts:
      if measureCodename in counts[localAuthorityCode]:
        counts[localAuthorityCode][measureCodename] += 1
      else:
        counts[localAuthorityCode][measureCodename] = 1
    else:
      counts[localAuthorityCode] = {}
      counts[localAuthorityCode][measureCodename] = 1

    print('REQUIRE( areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getValue(' + year + ') == ' + str(value) + ' );')
  
print('\n\n')

for localAuthorityCode, area in counts.items():
  for measureCodename, count in area.items():
      print('REQUIRE( areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").size() == ' + str(count) + ' );')

print('\n\n')

for localAuthorityCode, area in counts.items():
  print('REQUIRE( areas.getArea("' + localAuthorityCode + '").size() == ' + str(len(area.values())) + ' );')

print('\n\n')

print('REQUIRE( areas.size() == ' + str(len(counts.values())) + ' );')

# print('\n\n')

# for localAuthorityCode, area in counts.items():
#   areaDf = df[df[colAuthorityCode].str.contains(localAuthorityCode)]
#   for measureCodename, count in area.items():
#     measureDf = areaDf[areaDf[colMeasureCodename].str.contains(measureCodename)]
#
#     mean = str(int(measureDf[colValue].mean() * 100)/100.0)
#     meanlen = str(len(mean))
#     print('REQUIRE( std::to_string(areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getAverage()).substr(0,' + meanlen + ') == "' + mean + '" );')
#
#   print('')
#
# print('\n\n')
#
# for localAuthorityCode, area in minYear.items():
#   areaDf = df[df[colAuthorityCode].str.contains(localAuthorityCode)]
#   for measureCodename, count in area.items():
#     diff = float(maxYear[localAuthorityCode][measureCodename][1]) - float(minYear[localAuthorityCode][measureCodename][1])
#     diff = str(int(diff * 100)/100.0)
#     difflen = str(len(diff))
#     print('REQUIRE( std::to_string(areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getDifference()).substr(0,' + difflen + ') == "' + diff + '" );')
#
#   print('')
#
# print('\n\n')
#
# for localAuthorityCode, area in minYear.items():
#   areaDf = df[df[colAuthorityCode].str.contains(localAuthorityCode)]
#   for measureCodename, count in area.items():
#     diff = (float(maxYear[localAuthorityCode][measureCodename][1]) - float(minYear[localAuthorityCode][measureCodename][1])) / float(minYear[localAuthorityCode][measureCodename][1]) * 100
#     diff = str(int(diff * 100)/100.0)
#     difflen = str(len(diff))
#     print('REQUIRE( std::to_string(areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getDifferenceAsPercentage()).substr(0,' + difflen + ') == "' + diff + '" );')
#
#   print('')
# https://canvas.swansea.ac.uk/api/v1/groups/17533/users?per_page=300&include%5B%5D=sections&include%5B%5D=group_submissions&include%5B%5D=active_status&exclude%5B%5D=pseudonym