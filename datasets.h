#ifndef DATASETS_H_
#define DATASETS_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains information about files in the datasets directory.

  In newer versions of C++, we would store this information as constexpr
  (constant expressions), that can be baked into out code at compile-time. To
  ensure we can run our coursework with older versions of C++, and to keep
  the information in a logical and accessible way for you, for now we adopt
  this approach which simply loads the information onto the stack and heap
  as the program executes.

  You must not modify this file as it will be replaced with a fresh copy
  during marking.
 */


#include <string>
#include <unordered_map>

#include "data.h"

namespace BethYw {

/*
  This is a simple container that we use for storing information about the
  datasets in the data directory.
*/
struct InputFileSource {
  // CODE is the string used in t he program arguments
  const std::string CODE;

  // NAME is the name given to this dataset
  const std::string NAME;

  // FILE is the name of the file in the data directory
  const std::string FILE;

  // PARSER is a DataType that tells the populate() function in Areas how
  // to parse the text from the file
  const DataType PARSER;

  // COLS is a map of the column headings for this dataset
  // the key is a SourceColumns enum value, which is defined in data.h
  // the value is the name of the column in the data file
  // this is really 
  const std::unordered_map<SourceColumn, std::string> COLS;
};

/*
  In this namespace, we store all the static data for the various datasets
  that can be found in the data directory.
*/
namespace InputFiles {

const InputFileSource AREAS = {
  "areas",
  "areas",
  "areas.csv",
  DataType::AuthorityCodeCSV,
  {
      {AUTH_CODE,     "Local authority code"},
      {AUTH_NAME_ENG, "Name (eng)"},
      {AUTH_NAME_CYM, "Name (cym)"}
  }
}; // const InputFileSource AREAS

const InputFileSource POPDEN = {
  "popden",
  "Population density",
  "popu1009.json",
  DataType::WelshStatsJSON,
  {
    {AUTH_CODE,     "Localauthority_Code"},
    {AUTH_NAME_ENG, "Localauthority_ItemName_ENG"},
    {MEASURE_CODE,  "Measure_Code"},
    {MEASURE_NAME,  "Measure_ItemName_ENG"},
    {YEAR,          "Year_Code"},
    {VALUE,         "Data"}
  }
}; // const InputFileSource POPDEN

const InputFileSource BIZ = {
  "biz",
  "Active Businesses",
  "econ0080.json",
  DataType::WelshStatsJSON,
  {
    {AUTH_CODE,     "Area_Code"},
    {AUTH_NAME_ENG, "Area_ItemName_ENG"},
    {MEASURE_CODE,  "Variable_Code"},
    {MEASURE_NAME,  "Variable_ItemNotes_ENG"},
    {YEAR,          "Year_Code"},
    {VALUE,         "Data"}
  }
}; // const InputFileSource BIZ

const InputFileSource AQI = {
  "aqi",
  "Air Quality Indicators",
  "envi0201.json",
  DataType::WelshStatsJSON,
  {
    {AUTH_CODE,     "Area_Code"},
    {AUTH_NAME_ENG, "Area_ItemName_ENG"},
    {MEASURE_CODE,  "Pollutant_ItemName_ENG"},
    {MEASURE_NAME,  "Pollutant_ItemName_ENG"},
    {YEAR,          "Year_Code"},
    {VALUE,         "Data"}
  }
}; // const InputFileSource AQI

const InputFileSource TRAINS = {
  "trains",
  "Rail passenger journeys",
  "tran0152.json",
  DataType::WelshStatsJSON,
  {
    {AUTH_CODE,           "LocalAuthority_Code"},
    {AUTH_NAME_ENG,       "LocalAuthority_ItemName_ENG"},
    {SINGLE_MEASURE_CODE, "rail"},
    {SINGLE_MEASURE_NAME, "Rail passenger journeys"},
    {YEAR,                "Year_Code"},
    {VALUE,               "Data"}
  }
}; // const InputFileSource TRAINS

const InputFileSource COMPLETE_POPDEN = {
  "complete-popden",
  "Population density",
  "complete-popu1009-popden.csv",
  DataType::AuthorityByYearCSV,
  {
    {AUTH_CODE,           "AuthorityCode"},
    {SINGLE_MEASURE_CODE, "Dens"},
    {SINGLE_MEASURE_NAME, "Population density"}
  }
}; // const InputFileSource COMPLETE_POPDEN

const InputFileSource COMPLETE_POP = {
  "complete-pop",
  "Population",
  "complete-popu1009-pop.csv",
  DataType::AuthorityByYearCSV,
  {
    {AUTH_CODE,           "AuthorityCode"},
    {SINGLE_MEASURE_CODE, "Pop"},
    {SINGLE_MEASURE_NAME, "Population"}
  }
}; // const InputFileSource COMPLETE_POP

const InputFileSource COMPLETE_AREA = {
  "complete-area",
  "Land area",
  "complete-popu1009-area.csv",
  DataType::AuthorityByYearCSV,
  {
    {AUTH_CODE,           "AuthorityCode"},
    {SINGLE_MEASURE_CODE, "Area"},
    {SINGLE_MEASURE_NAME, "Land area"}
  }
}; // const InputFileSource COMPLETE_AREA

constexpr size_t NUM_DATASETS = 7;

const InputFileSource DATASETS[NUM_DATASETS] = { POPDEN,
                                                 BIZ,
                                                 AQI,
                                                 TRAINS,
                                                 COMPLETE_POPDEN,
                                                 COMPLETE_POP,
                                                 COMPLETE_AREA};

}; // namespace InputFiles

}; // namespace BethYw

#endif // DATASETS_H_