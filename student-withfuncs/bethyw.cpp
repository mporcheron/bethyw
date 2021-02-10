


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <STUDENT NUMBER>

  This file contains all the helper functions for initialising and running
  Beth Yw? In languages such as Java, this would be a class, but we really
  don't need a class here. Classes are for modelling data, and so forth, but
  here the code is pretty much a sequential block of code (BethYw::run())
  calling a series of helper functions.

  TODO: This file contains numerous functions you must implement. Each one
  is denoted with a TODO in the block comment. Note that some code has been
  provided in some functions to get you started, but you should read through
  this code and make sure it is safe. You may need to remove or modify the
  provided code to get your program to work fully. You may implement additional
  functions not specified.
*/

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
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

  Hint: cxxopts.parse() throws exceptions you'll need to catch

  @param argc
    Number of program arguments

  @param argv
    Program arguments

  @return
    Exit code
*/
int BethYw::run(int argc, char *argv[]) {
  auto cxxopts = BethYw::cxxoptsSetup();
  auto args = cxxopts.parse(argc, argv);

  // Print the help usage if requested
  if (args.count("help")) {
    std::cerr << cxxopts.help() << std::endl;
    return 0;
  }

  // Parse data directory argument
  std::string dir = args["dir"].as<std::string>() + DIR_SEP;

  // Parse other arguments and import data
  // auto datasetsToImport = BethYw::parseDatasetsArg(args);
  // auto areasFilter      = BethYw::parseAreasArg(args);
  // auto measuresFilter   = BethYw::parseMeasuresArg(args);
  // auto yearsFilter      = BethYw::parseYearsArg(args);

  Areas data = Areas();

  // BethYw::loadAreas(data, dir, areasFilter);
  //
  // BethYw::loadDatasets(data,
  //                      dir,
  //                      datasetsToImport,
  //                      areasFilter,
  //                      measuresFilter,
  //                      yearsFilter);

  if (args.count("json")) {
    // The output as JSON
    // std::cout << data.toJSON() << std::endl;
  } else {
    // The output as tables
    // std::cout << data << std::endl;
  }

  return 0;
}

/*
  This function sets up and returns a valid cxxopts object. You do not need to
  modify this function.

  @return
     A constructed cxxopts object

  @example
    auto cxxopts = BethYw::cxxoptsSetup();
    auto args = cxxopts.parse(argc, argv);
*/
cxxopts::Options BethYw::cxxoptsSetup() {
  cxxopts::Options cxxopts(
        "bethyw",
        "Student ID: " + STUDENT_NUMBER + "\n\n"
        "This program is designed to parse Official UK/Welsh Government"
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
  TODO: BethYw::parseDatasetsArg()

  Parse the datasets argument passed into the command line. 

  The datasets argument is optional, and if it is not included, all datasets 
  should be imported. If it is included, it should be a comma-separated list of 
  datasets to import (based on their key in the map InputFiles::DATASETS in 
  datasets.h). If the argument contains the value "all", all datasets should be 
  imported.

  This function validates the passed in dataset names against the codes in
  InputFiles::DATASETS. If an invalid code is entered, throw a
  std::invalid_argument with the message: No dataset matches key <input code>
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
  // This function is incomplete, but to get you started...

  // Retrieve all valid datasets, see datasets.h
  size_t numDatasets = InputFiles::NUM_DATASETS;
  auto &allDatasets = InputFiles::DATASETS;

  // Create the container for the return type
  std::vector<InputFileSource> datasetsToImport;

  // You can get the std::vector of arguments from cxxopts like this:
  // Note that this function will throw an exception if datasets is not set as 
  // an argument
  auto inputDatasets = args["datasets"].as<std::vector<std::string>>();

  // You now need to compare the strings in this vector to the keys in
  // allDatasets above. Populate datasetsToImport with the values
  // from the map allDatasets above and then return a vector

  // You'll want to ignore/remove the following lines of code, they simply
  // import all datasets (for now) as an example to get you started
  for(unsigned int i = 0; i < numDatasets; i++)
      datasetsToImport.push_back(allDatasets[i]);

  return datasetsToImport;
}

/*
  TODO: BethYw::parseAreasArg()
  
  Parses the areas command line argument, which is optional. If it doesn't 
  exist or exists and contains "all" as value, all areas should be imported.

  Unlike datasets we can't check the validity of the values as it depends
  on each individual file imported (which hasn't happened until runtime).
  Therefore, we simply fetch the list of areas and later pass it to the
  Areas::populate() function.

  The filtering of areas should be case insensitive.

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
  // The unordered set you will return
  std::unordered_set<std::string> areas;

  // Retrieve the areas' argument like so:
  auto temp = args["areas"].as<std::vector<std::string>>();
  
  // ...
  
  return areas;
}

/*
  TODO: BethYw::parseMeasuresArg()

  Parse the measures command line argument, which is optional. If it doesn't 
  exist or exists and contains "all" as value, all measures should be imported.

  Unlike datasets we can't check the validity of the values as it depends
  on each individual file imported (which hasn't happened until runtime).
  Therefore, we simply fetch the list of areas and later pass it to the
  Areas::populate() function.

  The filtering of measures should be case insensitive.

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
  throw std::logic_error(
    "BethYw::parseMeasuresArg() has not been implemented!");
}

/*
  TODO: BethYw::parseYearsArg()

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
std::tuple<unsigned int, unsigned int> BethYw::parseYearsArg(
    cxxopts::ParseResult& args) {
  throw std::logic_error("BethYw::parseYearsArg() has not been implemented!");
}

/*
  TODO: BethYw::loadAreas(areas, dir, areasFilter)

  Load the areas.csv file from the directory `dir`. Parse the file and
  create the appropriate Area objects inside the Areas object passed to
  the function in the `areas` argument.

  areas.csv is guaranteed to be formatted as:
    Local authority code,Name (eng),Name (cym)

  Hint: To implement this function. First you will need create an InputFile 
  object with the filename of the areas file, open it, and then pass the file 
  to the Areas::populate() function, which will take a pointer to 
  `areasFilter`.

  @param areas
    An Areas instance that should be modified

  @param dir
    Directory where the areas.csv file is

  @param areasFilter
    An unordered set of areas to filter, or empty to import all areas

  @return
    void

  @example
    Areas areas();

    BethYw::loadAreas(areas, "data", BethYw::parseAreasArg());
*/
void BethYw::loadAreas(Areas &areas,
                       const std::string &dir,
                       std::unordered_set<std::string> &areasFilter) {
  throw std::logic_error("BethYw::loadAreas() has not been implemented!");
}

/*
  TODO: BethYw::loadDatasets(areas,
                             dir,
                             datasetsToImport,
                             areasFilter,
                             measuresFilter,
                             yearsFilter)

  Import datasets from `datasetsToImport` as files in `dir` into areas,
  filtering them with the `areasFilter`, `measuresFilter`, and `yearsFilter`.

  The actual filtering will be done by the Areas::populate() function, thus 
  you need to merely pass pointers on to these flters.

  @param areas
    An Areas instance that should be modified

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
    Areas &areas,
    const std::string &dir,
    std::vector<InputFileSource> &datasetsToImport,
    std::unordered_set<std::string> &areasFilter,
    std::unordered_set<std::string> &measuresFilter,
    std::tuple<unsigned int,unsigned int> &yearsFilter) {
  throw std::logic_error("BethYw::loadDatasets() has not been implemented!");
}

