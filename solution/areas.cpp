


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  The file's contains the Areas class implementation. Areas are the top
  level of the data structure in Beth Yw?:

  Areas is also responsible for importing data from a stream (using the
  various populate() functions) and creating the Area and Measure objects.

  This file contains numerous functions you must implement. Each function you
  must implement has a TODO block comment. 
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#include "lib_json.hpp"

#include "datasets.h"
#include "areas.h"
#include "area.h"
#include "measure.h"

/*
  Shorthand for the imported JSON parsing library.
*/
using json = nlohmann::json;

/*
  TODO: Areas::Areas()

  Constructor for an Areas object.

  @example
    Areas data = Areas();
*/
Areas::Areas() : mAreasByCode(), mAreasByName() {}

/*
  TODO: Areas::setArea(key, value)

  Add a particular area to the Areas object.

  @param key
    The local authority code to insert

  @param value
    The Area object that will contain the measures

  @example
    Areas data = Areas();
    Area area("W06000023");
    data.setArea("W06000023", area);
*/
void Areas::setArea(std::string &key, Area &value) {
  auto existingIt = mAreasByCode.find(key);
  if (existingIt != mAreasByCode.end()) {
    Area &existingArea = existingIt->second;

    auto names = value.getNames();
    for (auto it = names.begin(); it != names.end(); it++) {
      existingArea.setName(it->first, it->second);
    }

    for (auto it = value.begin(); it != value.end(); it++) {
      existingArea.setMeasure(it->first, it->second);
    }

    return;
  }
  
  mAreasByCode.emplace(key, value);
}

/*
  TODO: Areas::setArea(key, value)

  Add a particular area to the Areas object.

  Note that this overloaded function should be called with std::move() 
  encasing the value so that Measure takes ownership over the resource.

  @param key
    The local authority code to insert

  @param value
    The Area object that will contain the measures

  @example
    Areas data = Areas();
    Area area("W06000023");
    areas.setArea("W06000023", std::move(area));
*/
void Areas::setArea(std::string &key, Area &&value) {
  auto existingIt = mAreasByCode.find(key);
  if (existingIt != mAreasByCode.end()) {
    Area &existingArea = existingIt->second;

    auto names = value.getNames();
    for (auto it = names.begin(); it != names.end(); it++) {
      existingArea.setName(it->first, it->second);
    }

    for (auto it = value.begin(); it != value.end(); it++) {
      existingArea.setMeasure(it->first, it->second);
    }

    return;
  }
  
  mAreasByCode.emplace(key, std::move(value));
}

/*
  TODO: Areas::getArea(key)

  Retrieve an Area instance for a local authority code or by name

  @param key
    The local authority code or name to find the value

  TODO map: remove lines above for student, remove liens below for solution

  Retrieve an Area instance for a local authority code.

  @param key
    The local authority code to find the value for

  @throws
    std::out_of_range if year does not exist in Areas

  @example
    Areas data = Areas();
    Area area("W06000023");
    areas.setArea("W06000023", area);
    ...
    Area area2 = areas.getArea("W06000023");
*/
Area &Areas::getArea(const std::string &key) {
  // mAreasByCode.at(key);
  try {
    return mAreasByCode.at(key);
  } catch (const std::out_of_range &ex) {
  }

  try {
    return mAreasByCode.at(mAreasByName.at(key));
  } catch (const std::out_of_range &ex) {
  }

  throw std::out_of_range("No area found matching " + key);
}

/*
  TODO map: delete this function and comment

  Given one or more needles, how many match to the haystack. This is a case
  insensitive search, and will search for partial strings.

  @param needles
    The list of needles to find in the haystack

  @param haystack
    The haystack to count the number of occurences of the needles

  @returns
    Number of occurences
*/
size_t Areas::wildcardCountSet(
    const std::unordered_set<std::string> &needles,
    const std::string &haystack) const {
  // count exact matches first
  size_t retval = needles.count(haystack);
  
  std::string haystackCopy = haystack;
  std::transform(
    haystackCopy.begin(),
    haystackCopy.end(),
    haystackCopy.begin(), 
    [](unsigned char c){ return std::toupper(c); });

  // Iterate over codes and match them with a wildcard approach
  for (auto it = needles.cbegin(); it != needles.cend(); it++) {
    std::string needle = *it;
    auto result = std::search(
        haystackCopy.begin(), haystackCopy.end(),
        needle.begin(), needle.end(),
        [](char ch1, char ch2) {
          return ch1 == std::toupper(ch2);
        });
        
    if (result != haystackCopy.end()) {
      retval += 1;
    }
  }

  return retval;
}

/*
  Check if a local authority should be filtered out or not.

  @param areasFilter
    A set of strings for areas to import, or an empty set if all areas
    should be imported

  @param localAuthorityCode
    The code for the local authority

  @return
    True if the area should be excluded, false otherwise
*/
bool Areas::isLocalAuthorityFiltered(
    const std::unordered_set<std::string> &areasFilter,
    const std::string localAuthorityCode)
    noexcept {
  if (areasFilter.size() > 0) {
    // does the filter contain the local authority code?
    if (wildcardCountSet(areasFilter, localAuthorityCode) > 0) {
      // the filter contains the authority code
      return false;
    } else {
      // the filter does not contain the authority code, so we will check the 
      // existing area objects' to see if we have encountered this before

      auto area = mAreasByCode.find(localAuthorityCode);
      if (area == mAreasByCode.end()) {
        // We haven't encountered this authority before, so we've reached
        // a deadend. Don't import the area.
        return true;
      }
    
      // We have encountered this authority before, so lets check the names
      // of that area against the filter
      try {
        const auto names = area->second.getNames();
        for (auto it = names.begin(); it != names.end(); it++) {
          auto name = it->second;
          if (wildcardCountSet(areasFilter, name) > 1) {
            // The name matches the filter, so include the area
            return false;
          }
        }
      } catch (const std::out_of_range &ex) {
      }
    } 
  }
  
  return false;
}

/*
  TODO: Areas::size()

  Retrieve the number of areas within the container This function should not
  modify the object or throw an exception.

  @return
    The number of Areas

  @example
    Areas data = Areas();
    Area area("W06000023");
    areas.setArea("W06000023", area);
    auto size = areas.size(); // returns 1
*/
size_t Areas::size() const noexcept {
  return mAreasByCode.size();
}

/*
  TODO: Areas::populateFromAuthorityCodeCSV(is, cols, areasFilter)

  This function specifically parses the compiled areas.csv file of local 
  authority codes, and their names in English and Welsh.

  This is a simple dataset that is a comma-separated values file (CSV), where
  the first row gives the name of the columns, and then each row is a set of
  data.

  For this coursework, you can assume that areas.csv will always have the same
  three columns in the same order.

  Once the data is parsed, you need to create the appropriate Area() objects and
  insert them in to a Standard Library container within Areas().

  @param is
    The input stream from InputSource

  @param cols
    A map of the enum SourceColumn (see areas.h) to strings that give the
    column header in the CSV file, which is statically defined in datasets.h

  @param areasFilter
    An umodifiable pointer to set of strings for areas to import, or an empty 
    set if all areas should be imported

  @see
    See datasets.h for details of how the variable cols is organised

  @see
    See bethyw.cpp for details of how the variable areasFilter is created

  @example
    InputFile input("data/areas.csv");
    auto is = input.open();

    auto cols = InputFiles::AREAS.COLS;

    auto areasFilter = BethYw::parseAreasArg();

    Areas data = Areas();
    areas.populateFromAuthorityCodeCSV(is, cols, &areasFilter);

  @throws 
    std::runtime_error if a parsing error occurs (e.g. due to a malformed file)
    std::out_of_range if there are not enough columns in cols
*/
void Areas::populateFromAuthorityCodeCSV(
    std::istream &is,
    const BethYw::SourceColumnMapping &cols,
    const std::unordered_set<std::string> * const areasFilter) noexcept(false) {
  // First row is our column titles, skip it
  std::string line;
  if (!std::getline(is, line)) {
    throw std::runtime_error("Areas::populateFromAuthorityCodeCSV: "
                             "File contains no data");
  }

  bool areasFilterEnabled = areasFilter != nullptr && !areasFilter->empty();

  // Parse the data
  unsigned int lineNo = 2;
  try {
    while (std::getline(is, line)) {
      std::string localAuthorityCode, nameEnglish, nameWelsh;

      // Scan the line for a comma, likely not the most efficient but
      // it hands off the matching to an underlying library for now...
      std::istringstream s(line);
      s.exceptions(std::ifstream::failbit | std::ifstream::badbit);

      // First column is the area code
      getline(s, localAuthorityCode, ',');

      // Second column is the title in English
      getline(s, nameEnglish, ',');

      // Third column is the title in Welsh
      getline(s, nameWelsh, ',');

      if (areasFilterEnabled &&
          wildcardCountSet(*areasFilter, localAuthorityCode) == 0 &&
          wildcardCountSet(*areasFilter, nameEnglish) == 0 &&
            wildcardCountSet(*areasFilter, nameWelsh) == 0) {
        continue;
      }

      Area area = Area(localAuthorityCode);
      area.setName("eng", nameEnglish);
      area.setName("cym", nameWelsh);

      this->setArea(localAuthorityCode, std::move(area));

      mAreasByName.emplace(nameEnglish, localAuthorityCode);
      mAreasByName.emplace(nameWelsh, localAuthorityCode);

      lineNo++;
    }
  } catch (const std::exception &ex) {
    const std::string err = "AreaCSVParser::parse: "
                            "Error on or near line " +
                            std::to_string(lineNo);
    throw std::runtime_error(err);
  }
}

/*
  TODO: Areas::populateFromWelshStatsJSON(is,
                                            cols,
                                            areasFilter,
                                            measuresFilter,
                                            yearsFilter)

  Implement the partsing of the data from JSON files.

  Data from Welsh Statistics is in the JSON format, and contains three
  top-level keys: odata.metadata, value, odata.nextLink. value contains the
  data we need. Rather than been hierarchical, it contains data as a
  continuous list (e.g. as you would find in a table). For each row in value,
  there is a mapping of various column headings and their respective vaues.

  Therefore, you need to loop through the items in value (in a loop)
  using a JSON library. To help you, I've selected the nlohmann::json
  library that you must use for your coursework. I've included this in the
  libs folder. Read up on how to use it here: https://github.com/nlohmann/json

  Example of using this library:
    - Reading/parsing in from a stream is very simply using the >> operators:
        json j;
        stream >> j;

    - Looping through parsed JSON is done with a simple for loop. Inside the
      loop, you can access each using the array syntax, with the key/
      column name, e.g. data["Localauthority_ItemName_ENG"] gives you the
      local area name:
        for (auto& el : j["value"].items()) {
           auto &data = el.value();
           std::string localAuthorityCode = data["Localauthority_ItemName_ENG"];
           // do stuff here...
        }

  In this function, you will have to parse the statistics files, extracting
  the area code, English name (the files only contain the English names),
  and each measure by year.

  If you encounter an area that does not exist in the Areas container, you
  should create the Area object.

  If areasFilter is a non-empty set only include areas where the authority
  code is within areasFilter. If measuresFilter is a non-empty set only include
  measures where the measure code is within measuresFilter. If yearsFilter is
  not equal to <0,0>, only import years within the range specified by the
  tuple (inclusive).

  I've provided the column names for each JSON file that you need to parse
  as std::string's in datasets.h. This mapping should be passed through to the
  cols parameter of this function.

  Note that in the JSON format, years are stored as strings, but we need
  them as ints. When retrieving values from the JSON library, you will
  have to cast them to the right type.

  @param is
    The input stream from InputSource

  @param cols
    A map of the enum SourceColumn (see areas.h) to strings that give the
    column header in the CSV file, which is statically defined in datasets.h

  @param areasFilter
    An umodifiable pointer to set of strings for areas to import, or an empty 
    set if all areas should be imported

  @param measuresFilter
    An umodifiable pointer to set of strings for measures to import, or an empty 
    set if all measures should be imported

  @param yearsFilter
    An umodifiable pointer to a tuple of two unsigned integers, where if both
    values are 0, then all years should be imported, otherwise they should be
    treated as a the range of years to be imported

  @throws 
    std::runtime_error if a parsing error occurs (e.g. due to a malformed file)
    std::out_of_range if there are not enough columns in cols

  @see
    See datasets.h for details of how the variable cols is organised

  @see
    See bethyw.cpp for details of how the variable areasFilter is created

  @example
    InputFile input("data/popu1009.json");
    auto is = input.open();

    auto cols = InputFiles::DATASETS["popden"].COLS;

    auto areasFilter = BethYw::parseAreasArg();
    auto measuresFilter = BethYw::parseMeasuresArg();
    auto yearsFilter = BethYw::parseMeasuresArg();

    Areas data = Areas();
    areas.populateFromWelshStatsJSON(
      is,
      cols,
      &areasFilter,
      &measuresFilter,
      &yearsFilter);
*/
void Areas::populateFromWelshStatsJSON(
    std::istream &is,
    const BethYw::SourceColumnMapping &cols,
    const std::unordered_set<std::string> *const areasFilter,
    const std::unordered_set<std::string> *const measuresFilter,
    const std::tuple<unsigned int, unsigned int> * const yearsFilter)
    noexcept(false) {
  json j;
  try {
    is >> j;
  } catch (const json::exception &ex) {
    const std::string err = "Areas::populateFromWelshStatsJSON: "
                            "Invalid JSON: " +
                            std::string(ex.what());
    throw std::runtime_error(err);
  }

  // First, we fetch the various column titles from the hardcoded data in
  // datasets.h
  std::string COL_AUTHORITY_CODE, COL_AREA_NAME, COL_YEAR, COL_VALUE;
  try {
    COL_AUTHORITY_CODE = cols.at(BethYw::AUTH_CODE);
    COL_AREA_NAME = cols.at(BethYw::AUTH_NAME_ENG);
    COL_YEAR = cols.at(BethYw::YEAR);
    COL_VALUE = cols.at(BethYw::VALUE);
  } catch(const std::out_of_range &ex) {
    throw std::out_of_range("Areas::populateFromWelshStatsJSON: "
                            "Incomplete column specification!");
  }
  
  // Some datasets only have one measure, which is hardcoded in datasets.h
  // In that case, we store the hardcoded code in COL_MEASURE_CODE and 
  // COL_MEASURE_NAME
  bool multipleMeasures = true;
  std::string COL_MEASURE_CODE, COL_MEASURE_NAME;
  try {
    COL_MEASURE_CODE = cols.at(BethYw::MEASURE_CODE);
    COL_MEASURE_NAME = cols.at(BethYw::MEASURE_NAME);
  } catch(const std::out_of_range &ex) {
    try {
      COL_MEASURE_CODE = cols.at(BethYw::SINGLE_MEASURE_CODE);
      COL_MEASURE_NAME = cols.at(BethYw::SINGLE_MEASURE_NAME);
      multipleMeasures = false;
    } catch(const std::out_of_range &ex2) {
      throw std::out_of_range("Areas::populateFromWelshStatsJSON: "
                              "Incomplete column specification, "
                              "no measure details specified!");
    }
  }

  // Determine whether the respective area, measures, and years filters
  // are enabled or not
  bool areasFilterEnabled    = areasFilter != nullptr &&
                               !areasFilter->empty();
  bool measuresFilterEnabled = measuresFilter != nullptr &&
                               !measuresFilter->empty();
  bool yearsFilterEnabled    = yearsFilter != nullptr &&
                               std::get<0>(*yearsFilter) != 0 &&
                               std::get<1>(*yearsFilter) != 0;

  // Now loop through each row in the JSON file
  // std::string localAuthorityCode;
  for (auto &el : j["value"].items()) {
    auto &data = el.value();

    // Fetch the local authority code and name to check whether this
    // has been added to the imported data already
    std::string localAuthorityCode, areaNameEnglish;
    try {
        localAuthorityCode = data[COL_AUTHORITY_CODE];
        areaNameEnglish = data[COL_AREA_NAME];
    } catch (const nlohmann::detail::type_error &ex) {
      throw std::out_of_range("Areas::populateFromWelshStatsJSON: "
                              "Column specification did not match file for "
                              "COL_AUTHORITY_CODE or COL_AREA_NAME!");
    }

    auto existingArea = mAreasByCode.find(localAuthorityCode);

    if (areasFilterEnabled) {
      // Welsh names aren't in the JSON data, so we can only check local
      // authority codes and English names by default
      if (wildcardCountSet(*areasFilter, localAuthorityCode) == 0 &&
          wildcardCountSet(*areasFilter, areaNameEnglish) == 0) {

        // But, if the area already exists, we might have a Welsh name for it 
        // already, so we need to check that to!
        // If there isn't an existing area, we just have to assume it doesn't
        // match the filter and skip it.
        if (existingArea != mAreasByCode.end()) {
          try {
            const std::string &areaNameWelsh =
                existingArea->second.getName("cym");
            if (wildcardCountSet(*areasFilter, areaNameWelsh) == 0) {
              continue;
            }
          } catch (const std::out_of_range &ex) {
            continue;
          }
        } else {
          continue;
        }
      }
    }
    
    // Are there multiple measures in the data or a single measure?
    // Either way, we need to check whether this is on the filter list
    std::string measureCode, measureName;
    if (multipleMeasures) {
      measureCode = data[COL_MEASURE_CODE];
      measureName = data[COL_MEASURE_NAME];
    } else {
      measureCode = COL_MEASURE_CODE;
      measureName = COL_MEASURE_NAME;
    }

    std::transform(
        measureCode.begin(),
        measureCode.end(),
        measureCode.begin(),::tolower);
    if (measuresFilterEnabled && measuresFilter->count(measureCode) == 0) {
      continue;
    }
    
    // Now check the year to see if its within the range
    unsigned int year = 0;
    try {
      year = std::stoi(data[COL_YEAR].get_ref<std::string&>());
      if (yearsFilterEnabled && (year < std::get<0>(*yearsFilter) ||
                                 year > std::get<1>(*yearsFilter))) {
        continue;
      }
    } catch (const nlohmann::detail::type_error &ex) {
      throw std::out_of_range("Areas::populateFromWelshStatsJSON: "
                              "Column specification did not match file for "
                              "YEAR!");
    } catch (const std::bad_cast &ex) {
      throw std::out_of_range("Areas::populateFromWelshStatsJSON: "
                              "Column specification did not match file for "
                              "YEAR!");
    }

    // We now fetch the value. Some datasets store numerical data as strings :(
    double value(0.0);
    try {
      value = data[COL_VALUE];
    } catch (const nlohmann::detail::type_error &ex) {
      // dagnabbit, its problably a string!
      value = std::stod((std::string) data[COL_VALUE]);
    }
    
    // Finally, we add the value to the measure to the area to the areas
    if (existingArea != mAreasByCode.end()) {
      // The area exists, so we'll add to the existing instance
      Area &area = existingArea->second;
      
      // Determine if a matching Measure exists within the Area
      try {
        // It does!
        Measure &existingMeasure = area.getMeasure(measureCode);
        existingMeasure.setValue(year, std::move(value));
      } catch (const std::out_of_range &ex) {
        // It does not, so create a new measure
        Measure newMeasure = Measure(measureCode, measureName);
        newMeasure.setValue(year, std::move(value));
        area.setMeasure(measureCode, std::move(newMeasure));
      }
    } else {
      // The Area doesn't exist, so create it and the Measure
      Area area = Area(localAuthorityCode);
      area.setName("eng", areaNameEnglish);

      Measure newMeasure = Measure(measureCode, measureName);
      newMeasure.setValue(year, std::move(value));
      area.setMeasure(measureCode, std::move(newMeasure));
      
      this->setArea(localAuthorityCode, std::move(area));
      
      mAreasByName.emplace(data[COL_AREA_NAME], localAuthorityCode);
    }
  }
}


/*
  TODO: Areas::populateFromAuthorityByYearCSV(is, cols, areasFilter, yearFilter)

  This function imports CSV files that consist of columns containing the
  authority code followed by years. Each row is an authority code, and then 
  the value for the years.

  This code assumes the first column is the authority code.

  @param is
    The input stream from InputSource

  @param cols
    A map of the enum SourceColumn (see areas.h) to strings that give the
    column header in the CSV file, which is statically defined in datasets.h

  @param areasFilter
    An umodifiable pointer to set of strings for areas to import, or an empty 
    set if all areas should be imported

  @param measuresFilter
    An umodifiable pointer to set of strings for measures to import, or an empty 
    set if all measures should be imported

  @param yearsFilter
    An umodifiable pointer to a tuple of two unsigned integers, where if both
    values are 0, then all years should be imported, otherwise they should be
    treated as a the range of years to be imported

  @return
    void

  @see
    See datasets.h for details of how the variable cols is organised

  @see
    See bethyw.cpp for details of how the variable areasFilter is created

  @example
    InputFile input("data/complete-popu1009-pop.csv");
    auto is = input.open();

    auto cols = InputFiles::DATASETS["complete-pop"].COLS;

    auto areasFilter = BethYw::parseAreasArg();
    auto yearsFilter = BethYw::parseYearsArg();

    Areas data = Areas();
    areas.populateFromAuthorityCodeCSV(is, cols, &areasFilter, &yearsFilter);

  @throws 
    std::runtime_error if a parsing error occurs (e.g. due to a malformed file)
    std::out_of_range if there are not enough columns in cols
*/
void Areas::populateFromAuthorityByYearCSV(
    std::istream &is,
    const BethYw::SourceColumnMapping &cols,
    const std::unordered_set<std::string> * const areasFilter,
    const std::unordered_set<std::string> * const measuresFilter,
    const std::tuple<unsigned int, unsigned int> * const yearsFilter)
    noexcept(false) {

  bool measuresFilterEnabled     = measuresFilter != nullptr &&
                                   !measuresFilter->empty();

  // Get the measure code and name from the static data
  std::string measureCode       = cols.at(BethYw::SINGLE_MEASURE_CODE);
  const std::string measureName = cols.at(BethYw::SINGLE_MEASURE_NAME);

  std::transform(
      measureCode.begin(),
      measureCode.end(),
      measureCode.begin(),::tolower);

  if (measuresFilterEnabled && measuresFilter->count(measureCode) == 0) {
    return;
  }

  const unsigned int authorityCodeColIdent = (unsigned int) -1;

  bool areasFilterEnabled = areasFilter != nullptr &&
                            !areasFilter->empty();
  bool yearsFilterEnabled = yearsFilter != nullptr &&
                            std::get<0>(*yearsFilter) != 0 &&
                            std::get<1>(*yearsFilter) != 0;

  // Mapping of the column ordering to the year, the authority code
  // will be given a value of -1 (we can assume no stats go back 2000+ years)
  std::vector<int> colHeaders;

  // Parse the header row
  std::string line;
  if (!std::getline(is, line)) {
    throw std::runtime_error("Areas::populateFromAuthorityCodeCSV: "
                             "File contains no data");
  } else {
    std::stringstream s(line);
    s.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    
    std::string cell;
    try { // Exception is thrown at the end of the line
      while (std::getline(s, cell, ',')) {
        try {
          if (cell == cols.at(BethYw::AUTH_CODE)) {
            colHeaders.push_back(authorityCodeColIdent);
          } else {
            colHeaders.push_back(std::stoi(cell));
          }
        } catch (const std::out_of_range &ex) {
          throw std::runtime_error("Areas::populateFromAuthorityCodeCSV: "
                                   "Must specify valid AUTH_CODE column!");
        }
      }
    } catch(const std::ios_base::failure &ex) {
    }
  }
  
  // Parse the remaining rows
  unsigned int lineNo = 2;
  try {
    while (std::getline(is, line)) { // row loop
      // Scan the line for a comma, likely not the most efficient but
      // it hands off the matching to an underlying library for now...
      std::istringstream lineStream(line);
      
      // s.exceptions(std::ifstream::failbit | std::ifstream::badbit);

      // Because we don't know where the authority column will be, we
      // store all values in a temp map and then copy them into the Area
      // object at the end
      std::string localAuthorityCode;
      std::unordered_map<unsigned int,double> tempData;
      
      try {
        bool importArea = false;
        unsigned int col = 0;
        std::string cell;
        while (std::getline(lineStream, cell, ',')) { // cell loop
          unsigned int columnIdent = colHeaders.at(col++);

          // As above, if year is == -1, its the authority code
          if (columnIdent == authorityCodeColIdent) {
            // This is the local authority!
            if (areasFilterEnabled &&
                isLocalAuthorityFiltered(*areasFilter, cell)) {
              break;
            }

            importArea = true;
            localAuthorityCode = cell;
          } else {
            // It's a year value in this column
            if (yearsFilterEnabled &&
                 (columnIdent < std::get<0>(*yearsFilter) ||
                  columnIdent > std::get<1>(*yearsFilter))) {
              continue;
            }
            
            if (cell.length() == 0) {
              continue;
            }

            unsigned int year = columnIdent;
            tempData.emplace(year, std::stod(cell));
          }
        }

        if (!importArea) {
          continue;
        }

        // Finally, we add the value to the measure to the area to the areas
        auto existingArea = mAreasByCode.find(localAuthorityCode);
        if (existingArea != mAreasByCode.end()) {
          // The area exists, so we'll add to the existing instance
          Area &area = existingArea->second;

          // Determine if a matching Measure exists within the Area
          try {
            Measure &existingMeasure = area.getMeasure(measureCode);
            // It does!
            for (auto it = tempData.begin(); it != tempData.end(); it++) {
              existingMeasure.setValue(
                static_cast<unsigned int>(it->first),
                it->second);
            }
          } catch (const std::out_of_range &ex) {
            // It does not, so create a new measure
            Measure newMeasure = Measure(measureCode, measureName);

            for (auto it = tempData.begin(); it != tempData.end(); it++) {
              newMeasure.setValue(
                static_cast<unsigned int>(it->first),
                it->second);
            }

            area.setMeasure(measureCode, std::move(newMeasure));
          }
        } else {
          // The Area doesn't exist, so create it and the Measure
          Area area = Area(localAuthorityCode);
          Measure newMeasure = Measure(measureCode, measureName);

          for (auto it = tempData.begin(); it != tempData.end(); it++) {
            newMeasure.setValue(
              static_cast<unsigned int>(it->first),
            it->second);
          }

          area.setMeasure(measureCode, std::move(newMeasure));

          this->setArea(localAuthorityCode, std::move(area));
        }
        lineNo++;
      } catch (const std::ios_base::failure &ex) {
      }
    }
  } catch (const std::exception &ex) {
    const std::string err = "Areas::populateFromAuthorityByYearCSV: "
                            "Error on or near line " +
                            std::to_string(lineNo);
    throw std::runtime_error(err);
  }
}

/*
  TODO: Areas::populate(is, type, cols)

  Parse data from an standard input stream, that is of a particular type,
  and with a given column mapping, filtering for specific area authority codes,
  measure identifiers, and years, and fill the container.

  This function should look at the type and have off to one of the two 
  functions you've implemented above (populateFromAuthorityCodeCSV and
  populateFromWelshStatsJSON).

  The function must check if the stream is in working order and has contents.

  @param is
    The input stream from InputSource

  @param type
    A value from the BethYw::SourceDataType enum which states the underlying data file
    structure

  @param cols
    A map of the enum SourceColumn (see areas.h) to strings that give the
    column header in the CSV file, which is statically defined in datasets.h

  @throws 
    std::runtime_error if a parsing error occurs (e.g. due to a malformed file),
    the stream is not open/valid/has any contents, or an unexpected type
    is passed in.
    std::out_of_range if there are not enough columns in cols

  @see
    See datasets.h for details of the values variable type can have

  @see
    See datasets.h for details of how the variable cols is organised

  @see
    See bethyw.cpp for details of how the variable areasFilter is created

  @example
    InputFile input("data/popu1009.json");
    auto is = input.open();

    auto cols = InputFiles::DATASETS["popden"].COLS;

    Areas data = Areas();
    areas.populate(
      is,
      BethYw::SourceDataType::WelshStatsJSON,
      cols);
*/
void Areas::populate(std::istream &is,
                       const BethYw::SourceDataType &type,
                       const BethYw::SourceColumnMapping &cols)
                       noexcept(false) {
  // check if the stream is open and readable
  is.seekg(1, is.beg);
  if (is.eof() || is.fail()) {
    throw std::runtime_error("Areas::populate: Stream not open");
  }
  is.seekg(0, is.beg);

  // hand off to the specific functions
  if (type == BethYw::AuthorityCodeCSV) {
    populateFromAuthorityCodeCSV(is, cols);
  } else if (type == BethYw::WelshStatsJSON) {
    populateFromWelshStatsJSON(is, cols);
  } else if (type == BethYw::AuthorityByYearCSV) {
    populateFromAuthorityByYearCSV(is, cols);
  } else {
    throw std::runtime_error("Areas::populate: Unexpected data type");
  }
}

/*
  TODO: Areas::populate(
    is,
    type,
    cols,
    areasFilter,
    measuresFilter,
    yearsFilter)

  Parse data from an standard input stream, that is of a particular type,
  and with a given column mapping, filtering for specific area authority codes,
  measure identifiers, and years, and fill the container.

  This function should look at the type and have off to one of the two 
  functions you've implemented above (populateFromAuthorityCodeCSV and
  populateFromWelshStatsJSON).

  The function must check if the stream is in working order and has contents.

  This overloaded function includes pointers to the three filters for areas,
  measures, and years.

  @param is
    The input stream from InputSource

  @param type
    A value from the BethYw::SourceDataType enum which states the underlying data file
    structure

  @param cols
    A map of the enum SourceColumn (see areas.h) to strings that give the
    column header in the CSV file, which is statically defined in datasets.h

  @param areasFilter
    An umodifiable pointer to set of strings for areas to import, or an empty 
    set if all areas should be imported

  @param measuresFilter
    An umodifiable pointer to set of strings for measures to import, or an empty 
    set if all measures should be imported

  @param yearsFilter
    An umodifiable pointer to a tuple of two unsigned integers, where if both
    values are 0, then all years should be imported, otherwise they should be
    treated as a the range of years to be imported

  @throws 
    std::runtime_error if a parsing error occurs (e.g. due to a malformed file),
    the stream is not open/valid/has any contents, or an unexpected type
    is passed in.
    std::out_of_range if there are not enough columns in cols

  @see
    See datasets.h for details of the values variable type can have

  @see
    See datasets.h for details of how the variable cols is organised

  @see
    See bethyw.cpp for details of how the variable areasFilter is created

  @example
    InputFile input("data/popu1009.json");
    auto is = input.open();

    auto cols = InputFiles::DATASETS["popden"].COLS;

    auto areasFilter = BethYw::parseAreasArg();
    auto measuresFilter = BethYw::parseMeasuresArg();
    auto yearsFilter = BethYw::parseMeasuresArg();

    Areas data = Areas();
    areas.populate(
      is,
      BethYw::SourceDataType::WelshStatsJSON,
      cols,
      &areasFilter,
      &measuresFilter,
      &yearsFilter);
*/
void Areas::populate(
    std::istream &is,
    const BethYw::SourceDataType &type,
    const BethYw::SourceColumnMapping &cols,
    const std::unordered_set<std::string> *const areasFilter,
    const std::unordered_set<std::string> *const measuresFilter,
    const std::tuple<unsigned int, unsigned int> *const yearsFilter)
    noexcept(false) {
  // check if the stream is open and readable
  is.seekg(1, is.beg);
  if (is.eof() || is.fail()) {
    throw std::runtime_error("Areas::populate: Stream not open");
  }
  is.seekg(0, is.beg);
  
  // hand off to the specific functions
  if (type == BethYw::AuthorityCodeCSV) {
    populateFromAuthorityCodeCSV(is, cols, areasFilter);
  } else if (type == BethYw::WelshStatsJSON) {
    populateFromWelshStatsJSON(is,
                               cols,
                               areasFilter,
                               measuresFilter,
                               yearsFilter);
  } else if (type == BethYw::AuthorityByYearCSV) {
    populateFromAuthorityByYearCSV(is,
                                   cols,
                                   areasFilter,
                                   measuresFilter,
                                   yearsFilter);
  } else {
    throw std::runtime_error("Areas::populate: Unexpected data type");
  }
}

/*
  TODO: Areas::toJSON()

  Convert this Areas object, and all its containing Area instances, and
  the Measure instances within those all to values.

  Use the sample JSON library as above to create this. Construct a blank
  JSON object:
    json j;

  Convert this json object to a string:
    j.dump();

  Read the documentation for how to convert your outcome code to JSON:
    https://github.com/nlohmann/json#arbitrary-types-conversions
  
  The JSON should be formatted as such:
    {
    "<localAuthorityCode1>" : {
                              "names": { "<languageCode1>": "<languageName1>",
                                         "<languageCode2>": "<languageName2>" 
                                         …
                                         "<languageCodeN>": "<languageNameN>" }, 
                              "measures" : { "<year1>": <value1>,
                                             "<year2>": <value2>,
                                             …
                                            "<yearN>": <valueN> }
                               },
    "<localAuthorityCode2>" : {
                              "names": { "<languageCode1>": "<languageName1>",
                                         "<languageCode2>": "<languageName2>" 
                                         …
                                         "<languageCodeN>": "<languageNameN>" }, 
                              "measures" : { "<year1>": <value1>,
                                             "<year2>": <value2>,
                                             …
                                            "<yearN>": <valueN> }
                               }
    ...
    "<localAuthorityCodeN>" : {
                              "names": { "<languageCode1>": "<languageName1>",
                                         "<languageCode2>": "<languageName2>" 
                                         …
                                         "<languageCodeN>": "<languageNameN>" }, 
                              "measures" : { "<year1>": <value1>,
                                             "<year2>": <value2>,
                                             …
                                            "<yearN>": <valueN> }
                               }
    }
  
  @return
    std::string of JSON
*/
std::string Areas::toJSON() const {
  json j;

  for (auto areaIt = cbegin(); areaIt != cend(); areaIt++) {
    const Area &area = areaIt->second;
    const std::string localAuthorityCode = area.getLocalAuthorityCode();

    auto names = area.getNames();
    for (auto nameIt = names.cbegin(); nameIt != names.end(); nameIt++) {
      j[localAuthorityCode]["names"][nameIt->first] = nameIt->second;
    }
    
    auto measures = area.getNames();
    for (auto measureIt = area.cbegin();
         measureIt != area.cend();
         measureIt++) {
      const Measure &measure = measureIt->second;
      const std::string measureCodename = measure.getCodename();

      for (auto yearIt = measure.cbegin(); yearIt != measure.cend(); yearIt++) {
        const std::string year = std::to_string(yearIt->first);
        const double value = yearIt->second;
        j[localAuthorityCode]["measures"][measureCodename][year] = value;
      }
    }
  }
  
  const std::string result = j.dump();
  if (result == "null") {
    return "{}";
  }
  
  return result;
}

/*
  TODO: operator<<(os, measure)

  Overload the << operator to print all of the imported data.

  Output should be formatted like the following to pass the tests. Areas should
  be printed, ordered alphabetically by their local authority code. Measures 
  within each Area should be ordered alphabetically by their codename.

  See the coursework specification for more information, although for reference
  here is a quick example of how output should be formatted:

    <English name of area 1> / <Welsh name of area 1> (<authority code 1>)
    <Measure 1 name> (<Measure 1 code>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean 1> <diff 1> <diffp 1>

    <Measure 2 name> (<Measure 2 code>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean 2> <diff 2> <diffp 2>

    <Measure 3 name> (<Measure 3 code>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean 3> <diff 3> <diffp 3>

    ...

    <Measure x name> (<Measure x code>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean x> <diff x> <diffp x>


    <English name of area 2> / <Welsh name of area 2> (<authority code 2>)
    <Measure 1 name> (<Measure 1 code>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean 1> <diff 1> <diffp 1>

    <Measure 2 name> (<Measure 2 code>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean 2> <diff 2> <diffp 2>

    <Measure 3 name> (<Measure 3 code>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean 3> <diff 3> <diffp 3>

    ...

    <Measure x name> (<Measure x code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n> <mean x> <diff x> <diffp x>

    ...

    <English name of area y> / <Welsh name of area y> (<authority code y>)
    <Measure 1 name> (<Measure 1 codename>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n> <mean 1> <diff 1> <diffp 1>

    <Measure 2 name> (<Measure 2 codename>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n> <mean 2> <diff 2> <diffp 2>

    <Measure 3 name> (<Measure 3 codename>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n> <mean 3> <diff 3> <diffp 3>

    ...

    <Measure x name> (<Measure x codename>)
     <year 1>  <year 2> <year 3> ...  <year n>  Average    Diff.   % Diff.
    <value 1>  <year 2> <year 3> ... <value n> <mean x> <diff x> <diffp x>

  With real data, your output should start like this for the command
  bethyw --dir <dir> -p popden -y 1991-1993 (truncated for readability):

    Isle of Anglesey / Ynys Môn (W06000001)
    Land area (area) 
          1991       1992       1993    Average    Diff.  % Diff. 
    711.680100 711.680100 711.680100 711.680100 0.000000 0.000000 

    Population density (dens) 
         1991      1992      1993   Average    Diff.  % Diff. 
    97.126504 97.486216 98.038430 97.550383 0.911926 0.938905 

    Population (pop) 
            1991         1992         1993      Average      Diff.  % Diff. 
    69123.000000 69379.000000 69772.000000 69424.666667 649.000000 0.938906 


    Gwynedd / Gwynedd (W06000002)
    Land area (Area)
    ...

  See the coursework specification for more information.

  @param os
    The output stream to write to

  @param areas
    The Areas object to write to the output stream

  @return
    Reference to the output stream

  @example
    Areas areas();
    std::cout << areas << std::end;
*/
std::ostream &operator<<(std::ostream &os, const Areas &areas) {
  for (auto area = areas.cbegin(); area != areas.cend(); area++) {
    os << area->second;
  }

  return os;
}