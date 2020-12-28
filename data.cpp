


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains numerous functions you must implement. Each function you
  must implement as a TODO comment inside it. See data.h for explanations
  of how the code is organised for the classes in this file.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "libs/cxxopts/cxxopts.hpp"
#include "libs/nlohmann/json.hpp"

#include "data.h"

using json = nlohmann::json;




Measure::Measure(std::string &label) : mLabel(label), mDataByYear() {}

void Measure::addDatum(const int &year, const Measure_t &datum) {
  // TODO: Insert the datum point into the internal map
  mDataByYear.insert_or_assign(year, datum);
}

std::ostream& operator<<(std::ostream &os, const Measure &st) {
  // TODO: implement the << overload operator, so that we print the statistic
  // data in the following format:
  // <label>\n
  //  Year0 Year1   Year2 ...  Yearn\n
  // Value1 Value2 Value3 ... Valuen\n
  //
  // You should align the year and value outputs by padding the outputs
  // with spaces, i.e. the year and values should be in the same position/
  // alignment.
  //
  // While you will be able to convert the key of the map (which is an int) to
  // a std::string using std::to_string(), you will have to use the static
  // function I've included in the declaration of Measure to do this for the 
  // value (which is a Measure_t). You can do that by calling 
  // Measure::to_string(<variable of Measure_t type>);
  os << st.mLabel << std::endl;

  // Iterate through and print the years and save the values to a stringstream
  std::stringstream values;
  for (auto it = st.mDataByYear.begin(); it != st.mDataByYear.end(); ++it) {
    std::string year = std::to_string(it->first);
    std::string value = Measure::to_string(it->second);

    int len = std::max(year.length(), value.length());

    os << std::setw(len) << year << " ";
    values << std::setw(len) << value << " ";
  }
  os << "\n" << values.str() << std::endl;

  return os;
}





Area::Area(
    const std::string &localAuthorityCode)
        : mLocalAuthorityCode(localAuthorityCode),
          mNames(),
          mMeasures() {}

// Insert a <}}language, name for the area> pair into the names map.
void Area::setName(const std::string &lang, const std::string &name) {
  // TODO: Add a language and name pair to the map.
  mNames.insert_or_assign(lang, name);
}

// Search the unordered map in names for a key. if you don't find the value,
// throw a std::runtime_error
const std::string& Area::getName(const std::string &lang) const {
  // TODO: Search the internal map and return a name for the given language 
  // code. If not area is found, ensure an appropriate exception is thrown.
  return mNames.at(lang);
}

void Area::addMeasure(std::string &ident, const Measure &stat) {
  // TODO: Insert the Measure into the internal map.
  mMeasures.insert_or_assign(ident, stat);
}

Measure& Area::getMeasure(std::string &ident) {
  // TODO: To implement this, find the item in the map or throw an
  // std::out_of_range exception.
  return mMeasures.at(ident);
}

std::map<std::string, Measure>& Area::getAllMeasures() {
  return mMeasures;
}





Areas::Areas() : mData() {}

// Parse input for the areas data. At the moment, you only need to worry about
// parsing the provided CSV format (where DataType equals AuthorityCodeCSV). We have
// the type variable here in case of future needs.
//
// If an unexpected type is passed, throws a std::runtime_error.
void Areas::populate(std::istream &is, const DataType &type) noexcept(false) {
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
    Areas::populateFromAuthorityCodeCSV(is);
  } else if (type == WelshStatsJSON) {
    Areas::populateFromWelshStatsJSON(is);
  } else {
    throw std::runtime_error("Areas::populate: Unexpected data type");
  }
}

// Parse the areas CSV and construct the Area object. This is a simple dataset
// that is a comma-separated values file (CSV), where the first row gives 
// the name of the columns, and then each row is a new set of data.
//
// In this case, we use this parser to parse areas.csv
void Areas::populateFromAuthorityCodeCSV(std::istream &is) noexcept(false) {
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
  if(!std::getline(is, line)) {
    throw std::runtime_error("Areas::populateFromAuthorityCodeCSV: "
      "File contains no data");
  }

  // Parse the data
  unsigned int lineNo = 2;
  try {
    while(std::getline(is, line)) {
      std::string areaCode, cell;

      // Scan the line for a comma, likely not the most efficient but 
      // it hands off the matching to an underlying library for now...
      std::istringstream s(line);
      s.exceptions(std::ifstream::failbit|std::ifstream::badbit);

      // First column is the area code
      getline(s, areaCode, ',');
      Area area = Area(areaCode);
      
      // Second column is the title in English
      getline(s, cell, ',');
      area.setName("eng", cell);
      
      // Third column is the title in Welsh
      getline(s, cell, ',');
      area.setName("cym", cell);
      
      mData.insert_or_assign(areaCode, area);
      
      lineNo++;
    }
  } catch (...) {
    const std::string err = "AreaCSVParser::parse: "
      "Error on or near line " + std::to_string(lineNo);
    throw std::runtime_error(err);
  }
}

void Areas::populateFromWelshStatsJSON(std::istream &is) noexcept(false) {
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
      "Invalid JSON: " + std::string(ex.what());
    throw std::runtime_error(err);
  }
  
  // Column titles in the JSON data
  const std::string COL_AUTHORITY_CODE = "Localauthority_Code";
  const std::string COL_AREA_NAME_ENG = "Localauthority_ItemName_ENG";
  const std::string COL_MEASURE_NAME_ENG = "Measure_ItemName_ENG";
  const std::string COL_YEAR = "Year_Code";
  const std::string COL_VALUE = "Data";

  std::string currLocalAuthorityCode, currMeasureName;
  Area *area;
  Measure *m;
  for (auto& el : j["value"].items()) {
    auto &data = el.value();

    // Check if this is the same as the last local area or not
    if (data[COL_AUTHORITY_CODE] != currLocalAuthorityCode) {
      auto search = mData.find(data[COL_AUTHORITY_CODE]);
      if (search != mData.end()) {
        area = &(search->second);
      } else {
        area = new Area(data[COL_AUTHORITY_CODE]);
        area->setName("eng",  data[COL_AREA_NAME_ENG]);
        mData.insert({data[COL_AUTHORITY_CODE], *area});
      }
      currLocalAuthorityCode = data[COL_AUTHORITY_CODE];
      std::cout << "" << area->getName("eng") << std::endl;
    }
    
    if (data[COL_MEASURE_NAME_ENG] != currMeasureName) {
      currMeasureName = data[COL_MEASURE_NAME_ENG];
      
      try {
        m = &(area->getMeasure(currMeasureName));
      } catch(std::out_of_range &ex) {
        m = new Measure(currMeasureName);
      }
      
    }
    
    int year = std::stoi((std::string) data[COL_YEAR]);
    double value = data[COL_VALUE];
    
    m->addDatum(year, value);
    area->addMeasure(currMeasureName, *m);
  }
}

std::unordered_map<std::string, Area> Areas::getAll() {
  return mData;
}

Area& Areas::get(const std::string &areaCode) {
  // TODO: To implement this, find the item in the map or throw an
  // std::out_of_range exception.
  return mData.at(areaCode);
}

const int Areas::size() const {
  return mData.size();
}
