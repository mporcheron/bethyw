


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains all the helper functions for initialising and running
  Beth Yw? In languages such as Java, this would be a class, but we really
  don't need a class here. Classes are for modelling data, and so forth, but
  here the code is pretty much a sequential block of code (BethYw::run())
  calling a series of helper functions.

  TODO: This file contains numerous functions you must implement. Each one
  is denoted with a TODO in the block comment. Note that some code has been
  provided in some functions to get you started, but you should read through
  this code and make sure it is safe and complete. You may need to remove or
  modify the provided code to get your program to work fully. You may implement
  additional functions not specified.
*/

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "lib_cxxopts.hpp"

#include "datasets.h"
#include "bethyw.h"
#include "input.h"

/*
  Run Beth Yw?, parsing the command line arguments, importing the data,
  and outputting the requested data to the standard output/error.

  Hint: cxxopts.parse() throws exceptions you'll need to catch. Read the cxxopts
  documentation for more information.

  @param argc
    Number of program arguments

  @param argv
    Program arguments

  @return
    Exit code
*/
int BethYw::run(int argc, char *argv[]) {
  auto cxxopts = BethYw::cxxoptsSetup();
  try {
    auto args  = cxxopts.parse(argc, argv);

    // Print the help usage if requested
    if (args.count("help")) {
      std::cerr << cxxopts.help() << std::endl;
      return 0;
    }

    // Parse data directory argument
    std::string dir = args["dir"].as<std::string>() + DIR_SEP;

    // Parse other arguments and import data
    auto datasetsToImport = BethYw::parseDatasetsArg(args);
    auto areasFilter      = BethYw::parseAreasArg(args);
    auto measuresFilter   = BethYw::parseMeasuresArg(args);
    auto yearsFilter      = BethYw::parseYearsArg(args);

    Areas data = Areas();

    BethYw::loadAreas(data, dir, areasFilter);

    BethYw::loadDatasets(data,
                         dir,
                         datasetsToImport,
                         areasFilter,
                         measuresFilter,
                         yearsFilter);

    if (args.count("json")) {
      // The output as JSON
      std::cout << data.toJSON() << std::endl;
    } else {
      // The output as tables
      std::cout << data << std::endl;
    }

    return 0;
  } catch (const cxxopts::missing_argument_exception& ex) {
    std::cerr << "Missing value for argument:" << ex.what() << std::endl;
    return 1;
  } catch (const std::invalid_argument& ex) {
    std::cerr << ex.what() << std::endl;
    return 1;
  }
}

/*
  This function sets up and returns a valid cxxopts object. You do not need to
  modify this function.

  @return
     A constructed cxxopts object
*/
cxxopts::Options BethYw::cxxoptsSetup() {
  cxxopts::Options cxxopts(
        "bethyw",
        "Student ID: " + STUDENT_NUMBER + "\n\n"
        "This program is designed to parse official Welsh Government"
        " statistics data files and answer \"what is…?\" questions.\n");
    
  cxxopts.add_options()(
      "dir",
      "Directory for input data passed in as files",
      cxxopts::value<std::string>()->default_value("datasets"))(

      "d,datasets",
      "The dataset(s) to import and analyse as a comma-separated list of codes "
      "(omit or set to 'all' to import and analyse all datasets)",
      cxxopts::value<std::vector<std::string>>())(

      "a,areas",
      "The areas(s) to import and analyse as a comma-separated list of "
      "authority codes (omit or set to 'all' to import and analyse all areas)",
      cxxopts::value<std::vector<std::string>>())(

      "m,measures",
      "Select a subset of measures from the dataset(s) "
      "(omit or set to 'all' to import and analyse all measures)",
      cxxopts::value<std::vector<std::string>>())(

      "y,years",
      "Focus on a particular year (YYYY) or "
      "inclusive range of years (YYYY-ZZZZ)",
      cxxopts::value<std::string>()->default_value("0"))(

      "j,json",
      "Print the output as JSON instead of tables.")(

      "h,help",
      "Print usage.");

  return cxxopts;
}

/*
  TODO: BethYw::parseDatasetsArg(args)

  Parse the datasets argument passed into the command line. 

  The datasets argument is optional, and if it is not included, all datasets 
  should be imported. If it is included, it should be a comma-separated list of 
  datasets to import. If the argument contains the value "all"
  (case-insensitive), all datasets should be imported.

  This function validates the passed in dataset names against the codes in
  DATASETS array in the InputFiles namespace in datasets.h. If an invalid code
  is entered, throw a std::invalid_argument with the message:
  No dataset matches key: <input code>
  where <input name> is the name supplied by the user through the argument.

  @param args
    Parsed program arguments

  @return
    A std::vector of BethYw::InputFileSource instances to import

  @throws
    std::invalid_argument if the argument contains an invalid dataset with
    message: No dataset matches key <input code>

  @example
    auto cxxopts = BethYw::cxxoptsSetup();
    auto args = cxxopts.parse(argc, argv);

    auto datasetsToImport = BethYw::parseDatasetsArg(args);
 */
std::vector<BethYw::InputFileSource> BethYw::parseDatasetsArg(
    cxxopts::ParseResult& args) {
  size_t numDatasets = InputFiles::NUM_DATASETS;
  auto& allDatasets = InputFiles::DATASETS;
  std::vector<InputFileSource> datasetsToImport;

  try {
    std::vector<std::string> inputDatasets;
    try {
      inputDatasets = args["datasets"].as<std::vector<std::string>>();
    } catch (const std::bad_cast& ex) {
      throw std::invalid_argument("Invalid input for dataset argument");
    } catch (const std::domain_error& ex) {
      throw BethYw::ImportAllValues();
    }

    if (inputDatasets.empty()) {
      throw BethYw::ImportAllValues();
    }

    for (auto inputDataset = inputDatasets.begin();
         inputDataset != inputDatasets.end();
         inputDataset++) {
      std::string code = *inputDataset;
      std::transform(code.begin(), code.end(), code.begin(), ::tolower);
      if (code == "all") {
        throw BethYw::ImportAllValues();
      }

      bool match = false;
      for (unsigned int i = 0; i < numDatasets; i++) {
        const InputFileSource& ifs = allDatasets[i];
        if (ifs.CODE == code) {
          datasetsToImport.push_back(ifs);
          match = true;
          break;
        } 
      }
      
      if (!match) {
        throw std::invalid_argument("No dataset matches key: " + code);
      }
    }
  } catch (const BethYw::ImportAllValues& ex) {
    datasetsToImport.clear();
    for (size_t i = 0; i < numDatasets; i++) {
      datasetsToImport.push_back(allDatasets[i]);
    }
  }

  return datasetsToImport;
}

/*
  TODO: BethYw::parseAreasArg(args)
  
  Parses the areas command line argument, which is optional. If it doesn't 
  exist or exists and contains "all" as value (any case), all areas should be
  imported, i.e., the filter should be an empty set.

  Unlike datasets we can't check the validity of the values as it depends
  on each individual file imported (which hasn't happened until runtime).
  Therefore, we simply fetch the list of areas and later pass it to the
  Areas::populate() function.

  The filtering of inputs should be case insensitive.

  @param args
    Parsed program arguments

  @return 
    An std::unordered_set of std::strings corresponding to specific areas
    to import, or an empty set if all areas should be imported.

  @throws
    std::invalid_argument if the argument contains an invalid areas value with
    message: Invalid input for area argument
*/
std::unordered_set<std::string> BethYw::parseAreasArg(
    cxxopts::ParseResult& args) {
  std::unordered_set<std::string> areas(0);
  try {
    auto temp = args["areas"].as<std::vector<std::string>>();
    areas = std::unordered_set<std::string>(temp.begin(), temp.end());
  } catch (const std::domain_error& ex) {
    // Do nothing, this is thrown when the areas argument isn't set
  } catch (const std::exception& ex) {
    throw std::invalid_argument("Invalid input for area argument");
  }

  for (auto it = areas.begin(); it != areas.end(); it++) {
    std::string area = std::string(*it);
    std::transform(area.begin(), area.end(), area.begin(), ::tolower);
    if (area == "all") {
      areas.clear();
      break;
    }
  }
  
  return areas;
}

/*
  TODO: BethYw::parseMeasuresArg(args)

  Parse the measures command line argument, which is optional. If it doesn't 
  exist or exists and contains "all" as value (any case), all measures should
  be imported.

  Unlike datasets we can't check the validity of the values as it depends
  on each individual file imported (which hasn't happened until runtime).
  Therefore, we simply fetch the list of areas and later pass it to the
  Areas::populate() function.

  The filtering of inputs should be case insensitive.

  @param args
    Parsed program arguments

  @return 
    An std::unordered_set of std::strings corresponding to specific measures
    to import, or an empty set if all measures should be imported.

  @throws
    std::invalid_argument if the argument contains an invalid measures value
    with the message: Invalid input for measures argument
*/
std::unordered_set<std::string> BethYw::parseMeasuresArg(
    cxxopts::ParseResult& args) {
  std::unordered_set<std::string> measures(0);
  try {
    auto temp = args["measures"].as<std::vector<std::string>>();
    measures.reserve(temp.size());
    for (auto measure : temp) {
      std::transform(
        measure.begin(),
        measure.end(),
        measure.begin(),
        ::tolower);
      measures.insert(measure);
    }
  } catch (const std::domain_error& ex) {
    // Do nothing, this is thrown when the measures argument isn't set
  } catch (const std::exception& ex) {
    throw std::invalid_argument("Invalid input for measures argument");
  }

  for (auto it = measures.begin(); it != measures.end(); it++) {
    if (*it == "all") {
      measures.clear();
      break;
    }
  }

  return measures;
}

/*
  TODO: BethYw::parseYearsArg(args)

  Parse the years command line argument. Years is either a four digit year 
  value, or two four digit year values separated by a hyphen (i.e. either 
  YYYY or YYYY-ZZZZ).

  This should be parsed as two integers and inserted into a std::tuple,
  representing the start and end year (inclusive). If one or both values are 0,
  then there is no filter to be applied. If no year argument is given return
  <0,0> (i.e. to import all years). You will have to search
  the web for how to construct std::tuple objects! 

  @param args
    Parsed program arguments

  @return
    A std::tuple containing two unsigned ints

  @throws
    std::invalid_argument if the argument contains an invalid years value with
    the message: Invalid input for years argument
*/
std::tuple<unsigned int, unsigned int>BethYw::parseYearsArg(
    cxxopts::ParseResult& args) {
  std::tuple<unsigned int, unsigned int> years = std::make_tuple(0, 0);

  try {
    std::string value = args["years"].as<std::string>();

    if (value.find('-') != std::string::npos) {
      if (value == "0-0") {
        return years;
      } else if (value.length() != 9) {
        throw std::invalid_argument("Invalid input for years argument");
      }
      
      int start = std::stoi(value.substr(0, value.find('-')));
      int end = std::stoi(value.substr(value.find('-') + 1));
      auto tuple = std::make_tuple(start, end);
      years = std::move(tuple);
    } else {
      if (value == "0") {
        return years;
      } else if (value.length() != 4) {
        throw std::invalid_argument("Invalid input for years argument");
      }
      
      int year = std::stoi(value);
      auto tuple = std::make_tuple(year, year);
      years = std::move(tuple);
    }
  } catch (const std::domain_error& ex) {
    throw std::invalid_argument("Invalid input for years argument");
  } catch (const std::invalid_argument& ex) {
    throw std::invalid_argument("Invalid input for years argument");
  } catch (const BethYw::ImportAllValues& ex) {
  }

  return years;
}

/*
  TODO: BethYw::loadAreas(areas, dir, areasFilter)

  Load the areas.csv file from the directory `dir`. Parse the file and
  create the appropriate Area objects inside the Areas object passed to
  the function in the `areas` argument.

  areas.csv is guaranteed to be formatted as:
    Local authority code,Name (eng),Name (cym)

  Hint: To implement this function. First you will need create an InputFile 
  object with the filename of the areas file, open it, and then pass reference 
  to the stream to the Areas::populate() function.

  Hint 2: you can retrieve the specific filename for a dataset, e.g. for the 
  areas.csv file, from the InputFileSource's FILE member variable

  @param areas
    An Areas instance that should be modified (i.e. the populate() function
    in the instance should be called)

  @param dir
    Directory where the areas.csv file is

  @param areasFilter
    An unordered set of areas to filter, or empty to import all areas

  @return
    void

  @example
    Areas areas();

    BethYw::loadAreas(areas, "data", BethYw::parseAreasArg(args));
*/
void BethYw::loadAreas(Areas& areas,
                       const std::string& dir,
                       std::unordered_set<std::string>& areasFilter) {
  const std::string fileAreas = dir + InputFiles::AREAS.FILE;

  try {
    auto source = std::make_unique<InputFile>(fileAreas);
    areas.populate(source->open(),
                   InputFiles::AREAS.PARSER,
                   InputFiles::AREAS.COLS,
                   &areasFilter);
  } catch (const std::runtime_error& ex) {
    std::cerr << "Error importing dataset:\n" << ex.what() << std::endl;
    std::exit(1);
  }
}

/*
  TODO: BethYw::loadDatasets(areas,
                             dir,
                             datasetsToImport,
                             areasFilter,
                             measuresFilter,
                             yearsFilter)

  Import datasets from `datasetsToImport` as files in `dir` into areas, and
  filtering them with the `areasFilter`, `measuresFilter`, and `yearsFilter`.

  The actual filtering will be done by the Areas::populate() function, thus 
  you need to merely pass pointers on to these flters.

  This function should promise not to throw an exception. If there is an
  error/exception thrown in any function called by thus function, catch it and
  output 'Error importing dataset:', followed by a new line and then the output
  of the what() function on the exception.

  @param areas
    An Areas instance that should be modified (i.e. datasets loaded into it)

  @param dir
    The directory where the datasets are

  @param datasetsToImport
    A vector of InputFileSource objects

  @param areasFilter
    An unordered set of areas (as authority codes encoded in std::strings)
    to filter, or empty to import all areas

  @param measuresFilter
    An unordered set of measures (as measure codes encoded in std::strings)
    to filter, or empty to import all measures

  @param yearsFilter
    An two-pair tuple of unsigned ints corresponding to the range of years 
    to import, which should both be 0 to import all years.

  @return
    void

  @example
    Areas areas();

    BethYw::loadDatasets(
      areas,
      "data",
      BethYw::parseDatasetsArgument(args),
      BethYw::parseAreasArg(args),
      BethYw::parseMeasuresArg(args),
      BethYw::parseYearsArg(args));
*/
void BethYw::loadDatasets(
    Areas& areas,
    const std::string& dir,
    std::vector<InputFileSource>& datasetsToImport,
    std::unordered_set<std::string>& areasFilter,
    std::unordered_set<std::string>& measuresFilter,
    std::tuple<unsigned int,unsigned int>& yearsFilter) noexcept {
  for (auto dataset = datasetsToImport.begin();
       dataset != datasetsToImport.end();
       dataset++) {
    try {
      auto source = std::make_unique<InputFile>(dir + dataset->FILE);
      areas.populate(source->open(),
                     dataset->PARSER,
                     dataset->COLS,
                     &areasFilter,
                     &measuresFilter,
                     &yearsFilter);
    } catch (const std::runtime_error& ex) {
      std::cerr << "Error importing dataset:\n" << ex.what() << std::endl;
      std::exit(1);
    }
  }
}
