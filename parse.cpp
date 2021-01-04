


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  The file's classes are structured in a granular way, from the most
  specific to most broad.

  Measure       — Represents a single measure for an area, e.g.
   |              population. Contains a human-readable label and a map of
   |              the measure accross a number of years.
   |
   +-> Area       Represents an area in Wales. Contains a unique local
        |         authority code used in national statistics, a map of the
        |         names of the area (i.e. in English and Welsh), and a map of
        |         various Measure objects.
        |
        +-> Areas A simple class that contains a map of all Area objects,
                  indexed by the local authority code. This is derived from
                  the DataContainer class, which is an abstract type.
                  DataContainer exists so that in future we can expand our
                  code to include areas broken down by different groupings
                  instead of geographic areas.

  This file contains numerous functions you must implement. Each function you
  must implement has a TODO block comment. 
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <tuple>

#include "libs/cxxopts/cxxopts.hpp"
#include "libs/nlohmann/json.hpp"

#include "parse.h"

using json = nlohmann::json;

/*
  TODO: Measure::Measure(code, label);

  Construct a single measure, that has values across many years.

  All StatsWales JSON files have a codename for measures. We use this to 
  allow filtering in the command line arguments. You should convert all codes 
  to lowercase.

  @param code
    The codename for the measure

  @param label
    Human-readable (i.e. nice/explanatory) label for the measure

  @example
    Measure("Pop", "Population");
*/
Measure::Measure(std::string &code, std::string &label)
    : mCode(code), mLabel(label), mData() {
  std::transform(mCode.begin(), mCode.end(), mCode.begin(), ::tolower);
}

/*
  TODO: Measure::getCode()

  Retrieve the code for the measure. This function should not modify the object.

  @return
    The code for the measure

  @example
    Measure measure("pop", "Population");
    measure.emplace(1999, 12345678.9);
    ...
    auto code = measure.getCode();
*/
inline const std::string &Measure::getCode() const { return mCode; }

/*
  TODO: Measure::getLabel()

  Retrieve the label for the measure. This function should not modify the
  object.

  @return
    The label for the measure

  @example
    Measure measure("pop", "Population");
    measure.emplace(1999, 12345678.9);
    ...
    auto label = measure.getLabel();
*/
inline const std::string &Measure::getLabel() const { return mLabel; }

/*
  TODO: Measure::at(key)

  Add a particular year's value to the Measure object.

  Note, this overloaded function should be called with std::move() 
  encasing the value so that Measure takes ownership over the resource.

  @param key
    The year to find

  @param value
    The value, which Measure will take ownership of

  @example
    Measure measure("pop", "Population");
    measure.emplace(1999, 12345678.9);

    double value = measure.at(1999);
*/
inline Measure_t &Measure::at(const int &key) {
  return mData.at(key);
}

/*
  TODO: Measure::emplace(key, value)

  Add a particular year's value to the Measure object.

  @param key
    The year

  @throws
    std::out_of_range if year is not in the measure

  @example
    Measure measure("pop", "Population");
    measure.emplace(1999, 12345678.9);
*/
inline void Measure::emplace(const int &key, Measure_t &value) {
  mData.emplace(key, value);
}

/*
  TODO: Measure::emplace(key, value)

  Add a particular year's value to the Measure object.

  Note, this overloaded function should be called with std::move() 
  encasing the value so that Measure takes ownership over the resource.

  @param key
    The year

  @param value
    The value, which Measure will take ownership of

  @example
    Measure measure("pop", "Population");
    double value = 12345678.9;
    measure.emplace(1999, std::move(value));
*/
inline void Measure::emplace(const int &key, Measure_t &&value) {
  mData.emplace(key, std::move(value));
}

/*
  TODO: Measure::size()

  Retrieve the number of years data we have for this measure. This function
  should not modify the object or throw an exception.

  @return
    The size of the measure

  @example
    Measure measure("pop", "Population");
    measure.emplace(1999, 12345678.9);
    ...
    auto size = measure.size();
*/
inline size_t Measure::size() const noexcept {
  return mData.size();
}

/*
  TODO: operator<<(os, measure)

  Overload the << operator for print the measure's imported data.

  We align the year and value outputs by padding the outputs with spaces,
  i.e. the year and values should be right-aligned to each other so they
  can be read as a table of numerical values.

  See the coursework specification for more information.

  @param os
    The output stream to write to

  @param measure
    Measure to write to the output stream

  @return
    Reference to the output stream.

  @example
    Measure measure("pop", "Population");
    measure.emplace(1999, 12345678.9);
    std::cout << measure << std::end;;
*/
std::ostream &operator<<(std::ostream &os, const Measure &measure) {
  os << measure.getLabel() << " (" << measure.getCode() << ")" << std::endl;

  // Iterate through and print the years and save the values to a stringstream
  std::stringstream values;
  for (auto it = measure.cbegin(); it != measure.cend(); ++it) {
    std::string year = std::to_string(it->first);
    std::string value = std::to_string(it->second);

    int len = std::max(year.length(), value.length());

    os << std::setw(len) << year << " ";
    values << std::setw(len) << value << " ";
  }
  os << "\n" << values.str() << std::endl;

  return os;
}

/*
  TODO: Area::Area(localAuthorityCode)

  Construct an area with a given local authority code.

  @param localAuthorityCode
    A reference to the local authority code
*/
Area::Area(const std::string &localAuthorityCode)
    : mLocalAuthorityCode(localAuthorityCode), mNames(), mMeasures() {}

/*
  TODO: getLocalAuthorityCode()

  Retrieve the local authority code. This function should not modify the object.
  
  @return
    The local authority code.
*/
inline const std::string &Area::getLocalAuthorityCode() const {
  return mLocalAuthorityCode;
}

/*
  TODO: getName(lang)

  Get a name for the area in a specific language. This function should not 
  modify the object.

  @param lang
    A three-leter language code in ISO 639-2/B format

  @return
    Name for the area

  @throws
    std::out_of_range if lang is not a set language

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    ...
    std::string name = area.getName("eng");
*/
inline const std::string &Area::getName(const std::string &lang) const {
  return mNames.at(lang);
}

/*
  TODO: setName(lang, name)

  Set a name for the area in a specific language.

  @param lang
    A three-leter language code in ISO 639-2/B format

  @param name
    Name of the area in this language

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    area.setName("cym", "Powys");
*/
inline void Area::setName(const std::string &lang, const std::string &name) {
  mNames.emplace(lang, name);
}

/*
  TODO: setName(lang, name)

  Set a name for the area in a specific language.

  @param lang
    A three-leter language code in ISO 639-2/B format

  @param name
    Name of the area in this language, which Area will take ownership of

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    area.setName("cym", "Powys");
*/
inline void Area::setName(const std::string &lang, std::string &&name) {
  mNames.emplace(lang, std::move(name));
}

/*
  Output all imported measures within an area.

  @param os
    The output stream to write to

  @param area
    Area to write to the output stream

  @return
    Reference to the output stream

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    std::cout << area << std::end;;

  TODO map: remove
*/
std::ostream &operator<<(std::ostream &os, const Area &area) {
  os << area.getName("eng") << " / " << area.getName("cym") << " ("
     << area.getLocalAuthorityCode() << ")" << std::endl;

  for (auto measure = area.cbegin(); measure != area.cend(); measure++) {
    os << measure->second << std::endl;
  }

  return os;
}

/*
  TODO: Areas()

  Constructor for an areas object.

  Hint: because we have templated Areas, you have to include
  template <> before you put the function header, and refer to the class as 
  Areas<> before the scope resolution operator.

  @example
    Areas<>()
*/
template <>
Areas<>::Areas() : mAreas() {}

// Parse the areas CSV and construct the Area object. This is a simple dataset
// that is a comma-separated values file (CSV), where the first row gives
// the name of the columns, and then each row is a set of data.
//
// In this case, we use this parser to parse areas.csv
template <>
void Areas<>::populateFromAuthorityCodeCSV(
    std::istream &is, const SourceColumnsMatch &cols,
    const std::unordered_set<std::string> *const areasFilter) noexcept(false) {
  // TODO Implement this parsing function. You can assume the columns will
  // remain in the same ordering in your implementation as they are in the data
  // file provided in the coursework.
  //
  // Parse the file and throw a std::runtime_error if anything is wrong.
  //
  // Once you have parsed a row of CSV data, you need to construct an Area
  // object. You should add each Area object to the Areas class member variable
  // mData.

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
      std::string areaCode, cell;

      // Scan the line for a comma, likely not the most efficient but
      // it hands off the matching to an underlying library for now...
      std::istringstream s(line);
      s.exceptions(std::ifstream::failbit | std::ifstream::badbit);

      // First column is the area code
      getline(s, areaCode, ',');

      if (areasFilterEnabled && areasFilter->count(areaCode) == 0) {
        continue;
      }

      Area area = Area(areaCode);

      // Second column is the title in English
      getline(s, cell, ',');
      area.setName("eng", std::move(cell));

      // Third column is the title in Welsh
      getline(s, cell, ',');
      area.setName("cym", std::move(cell));

      this->emplace(areaCode, std::move(area));

      lineNo++;
    }
  } catch (...) {
    const std::string err = "AreaCSVParser::parse: "
                            "Error on or near line " +
                            std::to_string(lineNo);
    throw std::runtime_error(err);
  }
}

template <>
void Areas<>::populateFromWelshStatsJSON(
    std::istream &is, const SourceColumnsMatch &cols,
    const std::unordered_set<std::string> *const areasFilter,
    const std::unordered_set<std::string> *const measuresFilter,
    const std::tuple<unsigned int, unsigned int>
        *const yearsFilter) noexcept(false) {
  // TODO: Implement the partsing of the data from JSON files.
  //
  // Data from Welsh Statistics is in the JSON format, and contains three
  // top-level keys: odata.metadata, value, odata.nextLink. value contains the
  // data we need. Rather than been hierarchical, it contains data as a
  // continuous list (e.g. as you would find in a table).
  //
  // { odata.metadata => weblink about the data,
  //.  value => all the data we need,
  //   odata.nextLink => another weblink }
  //
  // Inside value there is a list of statistics. This is not hierarchical of
  // data but rather a table, where each item in this list is a row. JSON is a
  // repetitive format, so for each row, for each cell, you have both the column
  // header and the value stored as a key:value mapping.
  //
  // Therefore, you need to loop through the items in value (in a for loop)
  // using a JSON library. To help you, I've selected the nlohmann::json
  // library that you must use for your coursework. I've included this in the
  // libs folder. Read up on how to use it here:
  // https://github.com/nlohmann/json
  //
  // Key examples:
  //   - reading/parsing in from a stream is very simply using the >> operators:
  //     json j;
  //     stream >> j;
  //
  //   - looping through parsed json is done with a simple for loop. Inside the
  //     loop, you can access each using the array syntax, with the key/
  //     column name, e.g. data["Localauthority_ItemName_ENG"] gives you the
  //     local area name:
  //     for (auto& el : j["value"].items()) {
  //.      auto &data = el.value();
  //.      // do stuff here...
  //     }
  //
  // In this function, you will have to parse the statistics file, extracting
  // the area code, English name (the files only contain the English names),
  // and each statistic by year.
  //
  // You should construct a Measure object for each Measure for each area,
  // and insert the values for each year included for that measure. I've
  // provided the column names as const std::string's for your reference.
  //
  // Note that in the JSON format, years are stored as strings, but we need
  // them as ints. When retrieving values from the JSON library, you will
  // have to cast them to the right type.
  //
  // You should then create, if it doesn't exist, the Area instance in mData
  // and add the measure.
  json j;
  try {
    is >> j;
  } catch (json::exception &ex) {
    const std::string err = "Areas::populateFromWelshStatsJSON: "
                            "Invalid JSON: " +
                            std::string(ex.what());
    throw std::runtime_error(err);
  }

  // Column titles in the JSON data
  const std::string COL_AUTHORITY_CODE = cols.at(AUTH_CODE);
  const std::string COL_AREA_NAME = cols.at(AUTH_NAME);
  const std::string COL_MEASURE_CODE = cols.at(MEASURE_CODE);
  const std::string COL_MEASURE_NAME = cols.at(MEASURE_NAME);
  const std::string COL_YEAR = cols.at(YEAR);
  const std::string COL_VALUE = cols.at(VALUE);

  // Determine whether the respective area, measures, and years filters
  // are enabled or not
  bool areasFilterEnabled = areasFilter != nullptr && !areasFilter->empty();
  bool measuresFilterEnabled =
      measuresFilter != nullptr && !measuresFilter->empty();
  bool yearsFilterEnabled = yearsFilter != nullptr &&
                            std::get<0>(*yearsFilter) != 0 &&
                            std::get<1>(*yearsFilter) != 0;

  std::string localAuthorityCode;
  for (auto &el : j["value"].items()) {
    auto &data = el.value();

    std::string localAuthorityCode = data[COL_AUTHORITY_CODE];
    if (areasFilterEnabled && areasFilter->count(localAuthorityCode) == 0) {
      continue;
    }

    std::string measureCode = data[COL_MEASURE_CODE];

    // If there is a limiting set of measures, and this measure is not
    // in it. skip it
    if (measuresFilterEnabled && measuresFilter->count(measureCode) == 0) {
      continue;
    }

    unsigned int year = std::stoi((std::string)data[COL_YEAR]);

    // Likewise, if there is a limiting range of years and our year is not
    // within it, skip it.
    if (yearsFilterEnabled && (year < std::get<0>(*yearsFilter) ||
                               year > std::get<1>(*yearsFilter))) {
      continue;
    }

    std::string measureName = data[COL_MEASURE_NAME];

    double value = data[COL_VALUE];

    auto existingArea = mAreas.find(localAuthorityCode);
    if (existingArea != mAreas.end()) {
      Area &area = existingArea->second;

      try {
        Measure &existingMeasure = area.at(measureCode);
        existingMeasure.emplace(year, std::move(value));
      } catch (std::out_of_range &ex) {
        Measure newMeasure = Measure(measureCode, measureName);
        newMeasure.emplace(year, std::move(value));
        area.emplace(measureCode, std::move(newMeasure));
      }
    } else {
      Area area = Area(localAuthorityCode);
      area.setName("eng", data[COL_AREA_NAME]);

      Measure newMeasure = Measure(measureCode, measureName);
      newMeasure.emplace(year, std::move(value));
      area.emplace(measureCode, std::move(newMeasure));
    }
  }
}

// Parse input for the areas data. At the moment, you only need to worry about
// parsing the provided CSV format (where DataType equals AuthorityCodeCSV). We
// have the type variable here in case of future needs.
//
// If an unexpected type is passed, throws a std::runtime_error.
template <>
void Areas<>::populate(std::istream &is, const DataType &type,
                       const SourceColumnsMatch &cols) noexcept(false) {
  // TODO Implement a function that accepts an open input stream, and calls
  // either Areas::populateFromAuthorityCodeCSV or
  // Areas::populateFromWelshStatsJSON depending on the DataType.
  //
  // Throw an std::runtime_error in unexpected situations.
  is.seekg(1, is.beg);
  if (is.eof() || is.fail()) {
    throw std::runtime_error("Areas::populate: Stream not open");
  }
  is.seekg(0, is.beg);

  if (type == AuthorityCodeCSV) {
    populateFromAuthorityCodeCSV(is, cols);
  } else if (type == WelshStatsJSON) {
    populateFromWelshStatsJSON(is, cols);
  } else {
    throw std::runtime_error("Areas::populate: Unexpected data type");
  }
}

// Parse input for the areas data. At the moment, you only need to worry about
// parsing the provided CSV format (where DataType equals AuthorityCodeCSV). We
// have the type variable here in case of future needs.
//
// If an unexpected type is passed, throws a std::runtime_error.
template <>
void Areas<>::populate(
    std::istream &is, const DataType &type, const SourceColumnsMatch &cols,
    const std::unordered_set<std::string> *const areasFilter,
    const std::unordered_set<std::string> *const measuresFilter,
    const std::tuple<unsigned int, unsigned int>
        *const yearsFilter) noexcept(false) {
  // TODO Implement a function that accepts an open input stream, and calls
  // either Areas::populateFromAuthorityCodeCSV or
  // Areas::populateFromWelshStatsJSON depending on the DataType.
  //
  // Throw an std::runtime_error in unexpected situations.
  is.seekg(1, is.beg);
  if (is.eof() || is.fail()) {
    throw std::runtime_error("Areas::populate: Stream not open");
  }
  is.seekg(0, is.beg);

  if (type == AuthorityCodeCSV) {
    populateFromAuthorityCodeCSV(is, cols, areasFilter);
  } else if (type == WelshStatsJSON) {
    populateFromWelshStatsJSON(is, cols, areasFilter, measuresFilter,
                               yearsFilter);
  } else {
    throw std::runtime_error("Areas::populate: Unexpected data type");
  }
}
