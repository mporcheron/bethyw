


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
#include "input.h"
#include "parse.h"



// Start Beth Yw?
int main(int argc, char *argv[]) {
    cxxopts::Options options(
      "bethyw",
      "This program is designed to parse Official UK/Welsh Government"
      " statistics data files and answer \"what is…?\" questions.");

    options.add_options()
        ("dir",
          "Directory for input data passed in as files",
          cxxopts::value<std::string>())
        ("d,datasets",
          "The dataset(s) to import and analyse",
          cxxopts::value<std::string>())
        ("m,measures",
          "Select a subset of measures from the dataset(s)",
          cxxopts::value<std::string>())
        ("y,years",
          "Focus on a particular year (YYYY) or "
            "inclusive range of years (YYYY-ZZZZ)",
          cxxopts::value<std::string>()->default_value("false"))
        ("a,action",
          "Action to take. Valid values for arg: average, trend, "
            "or print (default).",
          cxxopts::value<std::string>()->implicit_value("print"))
        ("h,help", "Print usage.");

    auto result = options.parse(argc, argv);

    // Print the help usage for this program
    if (result.count("help")) {
      std::cout << options.help() << std::endl;
      std::exit(0);
    }

    // Read the data directory argument
    // TODO map: replace block with std::string dir = result…
    std::string dir;
    try {
       dir = result["dir"].as<std::string>() + DIR_SEP;
    } catch(std::domain_error &err) {
      std::cerr << options.help() << std::endl;
      std::exit(0);
    }

    // Load in the list of local areas used in the statistics
    Areas data = Areas();
    const std::string fileAreas = dir + InputFiles::AREAS.file;
    try {
      InputSource *source = new InputFile(fileAreas);
      // TODO map: replace below two lines with source->open();
      std::istream &stream = source->open();
      data.populate(stream, DataType::AuthorityCodeCSV);
    } catch(const std::runtime_error &ex) {
      std::cout << fileAreas << " error:\n" << ex.what() << std::endl;
      std::exit(1);
    }

    // Load data files
    const std::string filePopDens = dir + InputFiles::POPULATION_DENSITY.file;
    try {
        // Test open the data file
        InputSource *source = new InputFile(filePopDens);
        std::istream &stream = source->open();
        data.populate(stream, DataType::WelshStatsJSON);
    } catch(const std::runtime_error &ex) {
        std::cout << "Source error:\n" << ex.what() << std::endl;
        abort();
    }

    // Print out test data
    std::cout << "There are " << data.size() << " areas" << std::endl;
    auto &areas = data.getAllAreas();
    for(auto itAreas = areas.begin(); itAreas != areas.end(); itAreas++) {
      std::cout << (itAreas->second).getName("eng") << std::endl;

      auto &measures = (itAreas->second).getAllMeasures();
      for(auto itMeas = measures.begin(); itMeas != measures.end(); itMeas++) {
        Measure &m = itMeas->second;
        std::cout << m << std::endl;
      }
    }

    return 0;
}