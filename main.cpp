


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "libs/cxxopts/cxxopts.hpp"

#include "data.h"
#include "input.h"
#include "parse.h"


namespace BethYw {
  class ImportAllValues {};
  
  void loadAreas(const std::string &dir) {
    auto &data = Areas<>::getInstance();
    
    const std::string fileAreas = dir + InputFiles::AREAS.FILE;
    
    try {
      InputSource *source = new InputFile(fileAreas);
      // TODO map: replace below two lines with source->open();
      std::istream &stream = source->open();
      data.populate(stream, InputFiles::AREAS.PARSER, InputFiles::AREAS.COLS);
    } catch(const std::runtime_error &ex) {
      std::cout << fileAreas << " error:\n" << ex.what() << std::endl;
      std::exit(1);
    }
  }
  
  // Parse a command line argument's value that consists of a comma-separated 
  // list of options. If no argument is found, or the argument is equal to 
  // "all", throw a ImportAllValues exception.
  std::unordered_set<std::string> parseCSVArgument(
      const cxxopts::ParseResult &opts,
      const std::string &arg) {
    std::string value;
    try {
      value = opts[arg].as<std::string>();
    } catch (std::domain_error &ex) {
      throw ImportAllValues();
    }
    
    if (value == "all") {
      throw ImportAllValues();
    }
    
    std::unordered_set<std::string> parsedArgs;
    std::stringstream argStream(value);
    while(argStream.good()) {
      std::string substr;
      std::getline(argStream, substr, ',');
      parsedArgs.emplace(std::move(substr));
    }
  
    return parsedArgs;
  }

  // Parse a command line argument's value that consists of either a year  
  // (YYYY) or a range of years (YYYY-ZZZZ). If invalid input is entered,
  // all years are importd.
  std::tuple<unsigned int,unsigned int> parseYearsArgument(
      const cxxopts::ParseResult &opts,
      const std::string &arg) {
    std::string value;
    try {
      value = opts[arg].as<std::string>();
    } catch (std::domain_error &ex) {
      throw ImportAllValues();
    }
    
    try {
      // is a range or a single year
      if (value.find('-') != std::string::npos) {
          int start = std::stoi(value.substr(0, value.find('-')));
          int end = std::stoi(value.substr(value.find('-')+1));
          return std::make_tuple(start, end);
      } else {
        int year = std::stoi(value);
        return std::make_tuple(year, year);
      }
    } catch(std::invalid_argument &ex) {
      throw ImportAllValues();
    }
  }
  
  // Parse a command line argument's value that consists of a comma-separated 
  // list of options. If no argument is found, or the argument is equal to 
  // "all", throw a ImportAllValues exception.
  std::string parseSelectionArgument(
      const cxxopts::ParseResult &opts,
      const std::string &arg,
      const std::vector<std::string> &choice,
      const std::string &defaultChoice) {
    std::string value;
    try {
      value = opts[arg].as<std::string>();
    } catch (std::domain_error &ex) {
      return defaultChoice;
    }
    
    for (auto it = choice.begin(); it != choice.end(); it++) {
      if (value == *it) {
        return value;
      }
    }
    
    return defaultChoice;
  }
  
  void print() {
    auto &data = Areas<>::getInstance();
    std::cout << "There are " << data.size() << " areas" << std::endl;
    for(auto itAreas = data.begin(); itAreas != data.end(); itAreas++) {
      Area &area = itAreas->second;
      std::cout << area.getName("eng") << std::endl;

      for(auto itArea = area.begin(); itArea != area.end(); itArea++) {
        Measure &m = itArea->second;
        std::cout << m << std::endl;
      }
    }
  }
};

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
        "The dataset(s) to import and analyse as a comma-separated list "
          "(omit or set to 'all' to import and analyse all datasets)",
        cxxopts::value<std::string>())
      ("m,measures",
        "Select a subset of measures from the dataset(s)"
          "(omit or set to 'all' to import and analyse all measures)",
        cxxopts::value<std::string>())
      ("y,years",
        "Focus on a particular year (YYYY) or "
          "inclusive range of years (YYYY-ZZZZ)",
        cxxopts::value<std::string>()->default_value("0"))
      ("a,action",
        "Action to take. Valid values for arg: average, trend, "
          "or print (default).",
        cxxopts::value<std::string>()->default_value("print"))
      ("h,help", "Print usage.");

  cxxopts::ParseResult result = options.parse(argc, argv);

  // Print the help usage for this program
  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    std::exit(0);
  }
    

  // Parse data directory aegument
  // TODO map: replace block with:
  // std::string dir result["dir"].as<std::string>() + DIR_SEP;
  std::string dir;
  try {
     dir = result["dir"].as<std::string>() + DIR_SEP;
  } catch(std::domain_error &err) {
    std::cerr << options.help() << std::endl;
    std::exit(0);
  }
    

  // Load in the list of local areas used in the statistics
  auto &data = Areas<>::getInstance();
  BethYw::loadAreas(dir);
    
  // Parse datasets argument
  std::vector<InputFileSource> datasets;
  try {
    // If no datasets are requested or the value is 'all', throw a 
    // true and then in the catch block we can import all
    //
    // This really is abusing the exception handling for our purposes,
    // oh well    
    auto vals = BethYw::parseCSVArgument(result, "datasets");
    for(auto val = vals.begin(); val != vals.end(); val++) {
      auto dataset = InputFiles::DATASETS.find(*val);
      if (dataset != InputFiles::DATASETS.end()) {
        InputFileSource file = dataset->second;
        datasets.push_back(std::move(file));
      } else {
        std::cerr << "No dataset matches key " << *val;
        std::cerr << std::endl;
        std::exit(1);
      }
    }
  } catch(BethYw::ImportAllValues &ex) {
    for(auto dataset = InputFiles::DATASETS.begin();
        dataset != InputFiles::DATASETS.end();
        dataset++) {
      datasets.push_back(dataset->second);
    }
  }

  // Parse measures argument
  std::unordered_set<std::string> measures;
  try {
    measures = BethYw::parseCSVArgument(result, "measures");
  } catch(BethYw::ImportAllValues &ex) {
  }
  
  // Parse years argument
  std::tuple<unsigned int,unsigned int> years;
  try {
    years = BethYw::parseYearsArgument(result, "years");
  } catch(BethYw::ImportAllValues &ex) {
  }
  
  // Load datasets
  for (auto dataset = datasets.begin();
       dataset != datasets.end();
       dataset++) {

    std::cout << "Loading " << dataset->NAME << std::endl;
    try {
      // Test open the data file
      InputSource *source = new InputFile(dir + dataset->FILE);
      std::istream &stream = source->open();
      data.populate(stream, dataset->PARSER, dataset->COLS, measures, years);
    } catch(const std::runtime_error &ex) {
      std::cout << "Source error:\n" << ex.what() << std::endl;
      std::exit(1);
    }
  }

  // Now take the appropriate action
  auto action = BethYw::parseSelectionArgument(
    result,
    "action",
    {"average", "trend", "print"},
    "print");

  //auto years = 
  if (action == "average") {
    std::cout << "Calculate averages" << std::endl;
  } else if (action == "trend") {
      std::cout << "Calculate trends" << std::endl;
  } else if (action == "print") {
      BethYw::print();
  } 

  return 0;
}