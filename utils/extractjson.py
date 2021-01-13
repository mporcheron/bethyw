
import json
import os
import pandas as pd
import sys
import webbrowser as wb

this_dir = os.path.dirname(os.path.abspath(__file__)) + "/"

colAuthorityCode = 'Localauthority_Code'
colMeasureCodename = 'Measure_Code'
colYear = 'Year_Code'
colValue = 'Data'

with open(this_dir + 'popu1009.json') as data_file:    
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

for localAuthorityCode, area in counts.items():
  areaDf = df[df[colAuthorityCode].str.contains(localAuthorityCode)]
  for measureCodename, count in area.items():
    measureDf = areaDf[areaDf[colMeasureCodename].str.contains(measureCodename)]
    mean = "(("
    count = 0
    for val in iter(measureDf[colValue]):
      mean += str(val) + " + "
      count += 1
    mean += " 0) / " + str(count) + ")"
    print('REQUIRE( std::to_string(areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getAverage()) == std::to_string(' + mean + ') );')

  print('')

print('\n\n')
#
for localAuthorityCode, area in minYear.items():
  areaDf = df[df[colAuthorityCode].str.contains(localAuthorityCode)]
  for measureCodename, count in area.items():
    diff = str(maxYear[localAuthorityCode][measureCodename][1]) + " - " + str(minYear[localAuthorityCode][measureCodename][1])
    print('REQUIRE( areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getDifference() == (' +  diff + ') );')

  print('')

print('\n\n')

for localAuthorityCode, area in minYear.items():
  areaDf = df[df[colAuthorityCode].str.contains(localAuthorityCode)]
  for measureCodename, count in area.items():
    diff = "std::to_string((" + str(maxYear[localAuthorityCode][measureCodename][1]) + " - " + str(minYear[localAuthorityCode][measureCodename][1]) + ")/" + str(minYear[localAuthorityCode][measureCodename][1]) + "*100)"
    print('REQUIRE( std::to_string(areas.getArea("' + localAuthorityCode + '").getMeasure("' + measureCodename.lower() + '").getDifferenceAsPercentage()) == ' + diff + ' );')

   print('')
# https://canvas.swansea.ac.uk/api/v1/groups/17533/users?per_page=300&include%5B%5D=sections&include%5B%5D=group_submissions&include%5B%5D=active_status&exclude%5B%5D=pseudonym