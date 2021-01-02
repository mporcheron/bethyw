


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains all the helper functions for initialising and running
  Beth yw?
 */

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