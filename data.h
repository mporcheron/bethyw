#ifndef DATA_H_
#define DATA_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains static information about files in the data/ directory.
 */

#include "parse.h"





struct InputFileSource {
  // arg is the program argument value that should match to this dataset
  const std::string arg;
  
  // file is the name of the file in the data/ directory
  const std::string file;
  
  // parser is a DataType that tells the populate() function in Areas how
  // to parse the text from the file
  const DataType parser;
};





// This namespace stores all the files in the data directory as const char* 
// consts, allowing for them to be substituted at compile-time into our code
namespace InputFiles {
  const InputFileSource AREAS
    = {"areas", "areas.csv", DataType::AuthorityCodeCSV};

  const InputFileSource POPULATION_DENSITY
    = {"popden", "popu1009.json", DataType::WelshStatsJSON};

  const InputFileSouce DATASETS[10];
};


#endif // DATA_H_