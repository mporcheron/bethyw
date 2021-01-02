#ifndef DATA_H_
#define DATA_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains static information about files in the data/ directory.
 */

#include <string>
#include <unordered_map>

#include "parse.h"










struct InputFileSource {
  // name is the name given to this dataset
  const std::string NAME;
  
  // file is the name of the file in the data/ directory
  const std::string FILE;
  
  // parser is a DataType that tells the populate() function in Areas how
  // to parse the text from the file
  const DataType PARSER;
  
  // cols is a map of the column headings for this dataset
  // the key is a SourceColumns enum value, which is defined in parse.h
  // the value is the name of the column in the data file
  const std::unordered_map<SourceColumns,std::string> COLS;
};





// This namespace stores all the files in the data directory as const char* 
// consts, allowing for them to be substituted at compile-time into our code
namespace InputFiles {
  const InputFileSource AREAS
    = {"areas", "areas.csv", DataType::AuthorityCodeCSV};

  const std::unordered_map<std::string, InputFileSource> DATASETS{
    {"popden", {
      "Population density",
      "popu1009.json",
      DataType::WelshStatsJSON,
      {
        {AUTH_CODE,    "Localauthority_Code"},
        {AUTH_NAME,    "Localauthority_ItemName_ENG"},
        {MEASURE_CODE, "Measure_Code"},
        {MEASURE_NAME, "Measure_ItemName_ENG"},
        {YEAR,         "Year_Code"},
        {VALUE,        "Data"}
      }}}
  };
};


#endif // DATA_H_