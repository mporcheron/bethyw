
import json
import os
import pandas as pd
import sys
import webbrowser as wb

this_dir = os.path.dirname(os.path.abspath(__file__)) + "/"

colAuthorityCode = 'Area_Code'
colMeasureCodename = 'Pollutant_ItemName_ENG'
colYear = 'Year_Code'
colValue = 'Data'

with open(this_dir + 'envi0201.json') as data_file:    
    data = json.load(data_file)

df = pd.json_normalize(data, 'value', [])
df = df.astype({colValue: "double"})
df = df.sort_values(by=[colAuthorityCode, colMeasureCodename, colYear])

counts = {}
minYear = {}
maxYear = {}

prevArea = ""
prevMeasure = ""
for col, row in df.iterrows():
  localAuthorityCode = str(row[colAuthorityCode])
  measureCodename = str(row[colMeasureCodename])
  year = str(row[colYear])
  value = row[colValue]

  if localAuthorityCode != prevArea:
    print('')
  elif measureCodename != prevMeasure:
    print('')
    
  if localAuthorityCode in counts:
    if measureCodename in counts[localAuthorityCode]:
      counts[localAuthorityCode][measureCodename] += 1
      
      if year < minYear[localAuthorityCode][measureCodename][0]:
        minYear[localAuthorityCode][measureCodename] = (year, value)
      if year > maxYear[localAuthorityCode][measureCodename][0]:
        maxYear[localAuthorityCode][measureCodename] = (year, value)
    else:
      counts[localAuthorityCode][measureCodename] = 1
      minYear[localAuthorityCode][measureCodename] = (year, value)
      maxYear[localAuthorityCode][measureCodename] = (year, value)
  else:
    counts[localAuthorityCode] = {}
    counts[localAuthorityCode][measureCodename] = 1

    minYear[localAuthorityCode] = {}
    minYear[localAuthorityCode][measureCodename] = (year, value)

    maxYear[localAuthorityCode] = {}
    maxYear[localAuthorityCode][measureCodename] = (year, value)

  print('REQUIRE( areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getValue(' + year + ') == ' + str(value) + ' );')

  prevArea = localAuthorityCode
  prevMeasure = measureCodename
  
print('\n\n')

for localAuthorityCode, area in counts.items():
  for measureCodename, count in area.items():
      print('REQUIRE( areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").size() == ' + str(count) + ' );')
  print('')

print('\n\n')

for localAuthorityCode, area in counts.items():
  print('REQUIRE( areas.getArea("' + localAuthorityCode + '").size() == ' + str(len(area.values())) + ' );')

print('\n\n')

print('REQUIRE( areas.size() == ' + str(len(counts.values())) + ' );')

print('\n\n')

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