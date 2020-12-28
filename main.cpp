


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron
 */

#include <iostream>
#include <string>

#include "libs/cxxopts/cxxopts.hpp"

#include "data.h"
#include "sources.h"



// Start Beth Yw?
int main(int argc, char *argv[]) {
    cxxopts::Options options(
      "bethyw",
      "This program is designed to parse Official UK/Welsh Government statistics data files and answer \"what is…?\" questions.");

    // TODO: Implement the additional program arguments as specified in 
    // README.md

    options.add_options()
        ("f,inputfiles",
          "Directory for input data passed in as files.",
          cxxopts::value<std::string>())
        // ("o,output", "Save an ascii file to the provided path.",  cxxopts::value<std::string>())
        // ("s,steps","The number of steps to simulate the world.", cxxopts::value<int>()->default_value("10"))
        // ("e,every","Print world to the console every N steps. 0 disables printing.", cxxopts::value<int>()->default_value("0"))
        // ("t,toroidal", "Simulate the Game of Life on a torus.", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage.");

    // Parse the command line arguments
    auto result = options.parse(argc, argv);

    // Print the help usage for this program
    if (result.count("help")) {
      std::cout << options.help() << std::endl;
      std::exit(0);
    }

    const std::string dirData = result["inputfiles"].as<std::string>() + DIR_SEP;

    // Load in the list of local areas used in the statistics
    Areas data = Areas();
    const std::string fileAreas = dirData + InputFiles::AREAS;
    try {
      InputSource *source = new InputFile(fileAreas);
      std::istream &stream = source->open();
      data.populate(stream, DataType::AreaCodeCSV);
    } catch(const std::runtime_error &ex) {
      std::cout << fileAreas << " error:\n" << ex.what() <<  "\n" << std::endl;
      abort();
    }

    // Load data files
    const std::string filePopDens = dirData + InputFiles::POPULATION_DENSITY;
    try {
        // Test open the data file
        InputSource *source = new InputFile(filePopDens);
        std::istream &stream = source->open();
        data.populate(stream, DataType::WelshStatsJSON);
    } catch(const std::runtime_error &ex) {
        std::cout << "Source error:\n" << ex.what() << "\n" << std::endl;
        abort();
    }

    // Print out test data
    std::cout << "There are " << data.size() << " areas" << std::endl;
    std::unordered_map<std::string, Area> areas = data.getAll();
    for(auto iter = areas.begin(); iter != areas.end(); ++iter){
      std::cout << (iter->second).getName("eng") << std::endl;

      std::unordered_map<std::string, Measure> measures =
                                              (iter->second).getAllMeasures();

      for(auto iter2 = measures.begin(); iter2 != measures.end(); ++iter2){
        std::cout << iter2->second << std::endl;
      }

    }

    return 0;
}