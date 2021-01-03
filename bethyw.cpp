


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
 */

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "libs/cxxopts/cxxopts.hpp"

#include "bethyw.h"
#include "input.h"
#include "data.h"

/*
  Run Beth Yw?, parsing the command line arguments
*/
void BethYw::run(int argc, char *argv[]) {
  // Parse the command line arguments
  auto &cxxopts = BethYw::cxxopts();
  cxxopts.add_options()(
      "dir",
      "Directory for input data passed in as files",
      cxxopts::value<std::string>())(
    
      "d,datasets",
      "The dataset(s) to import and analyse as a comma-separated list "
      "(omit or set to 'all' to import and analyse all datasets)",
      cxxopts::value<std::vector<std::string>>())(
    
      "m,measures",
      "Select a subset of measures from the dataset(s) "
      "(omit or set to 'all' to import and analyse all measures)",
      cxxopts::value<std::vector<std::string>>())(
    
      "y,years",
      "Focus on a particular year (YYYY) or "
      "inclusive range of years (YYYY-ZZZZ)",
      cxxopts::value<std::string>()->default_value("0"))(
    
      "a,action",
      "Action to take. Valid values for arg: average, trend, "
      "or all (default).",
      cxxopts::value<std::string>()->default_value("all"))(
    
      "h,help",
      "Print usage.");

  auto &args = BethYw::args(argc, argv);

  // Print the help usage if requested
  if (args.count("help")) {
    BethYw::help(std::cout, 0);
  }

  // Parse data directory argument and load the list of Areas into
  // the Areas<> object
  std::string dir;
  try {
    dir = args["dir"].as<std::string>() + DIR_SEP;
  } catch (std::domain_error &err) {
    BethYw::help(std::cerr, 1);
  }

  BethYw::loadAreas(dir);

  auto datasetsToImport = BethYw::parseDatasetsArg();
  auto measuresToImport = BethYw::parseMeaauresArg();
  auto yearsToImport    = BethYw::parseYearsArg();
  auto action           = BethYw::parseActionArg();

  // Load datasets into the Areas object
  auto &data = Areas<>::getInstance();
  for (auto dataset = datasetsToImport.begin();
       dataset != datasetsToImport.end();
       dataset++) {
    try {
      InputSource *source = new InputFile(dir + dataset->FILE);
      std::istream &stream = source->open();
      data.populate(stream,
                    dataset->PARSER,
                    dataset->COLS,
                    measuresToImport,
                    yearsToImport);
    } catch (const std::runtime_error &ex) {
      std::cout << "Source error:\n" << ex.what() << std::endl;
      std::exit(1);
    }
  }
 
  // Take the appropriate action
  switch (action) {
    case ALL:
    BethYw::printAll();
    break;

    case AVERAGE:
    BethYw::printAverage();
    break;

    case TREND:
    BethYw::printTrend();
    break;
  }
}

/*
  Because Beth Yw? is just a namespace (there is no need for it to be a class),
  we store cxxopts as a static variable here so that it can be fetched from
  different functions.
*/
cxxopts::Options& BethYw::cxxopts() {
  static cxxopts::Options cxxopts(
        "bethyw",
        "This program is designed to parse Official UK/Welsh Government"
        " statistics data files and answer \"what is…?\" questions.");
  return cxxopts;
}

/*
  We're using cxxopts for command-line argument parsing and help generation. We
  store the parsed result in a static variable in this function so that is can 
  be easily re-retrieved.
*/
cxxopts::ParseResult& BethYw::args(int argc, char *argv[]) {
  static cxxopts::ParseResult args = BethYw::cxxopts().parse(argc, argv);
  return args;
}

/*
  We're using cxxopts for command-line argument parsing and help generation. We
  store the parsed result in a static variable in this function so that is can 
  be easily re-retrieved.
*/
void BethYw::help(std::ostream &os, const int &exitCode) {
  os << BethYw::cxxopts().help() << std::endl;
  std::exit(exitCode);
}

/*
  TODO: Parse the datasets argument. The datasets argument is optional, and if 
  it is not included, all datasets should be imported. If it is included, it 
  should  be a comma-separated list of datasets to import (based on their key 
  in the map InputFiles::DATASETS in data.h). If the argument contains the 
  value "all", all datasets should be imported.

  This function should return a list of datasets to import as a std::vector, 
  where the dataset corresponds to the value in the map InputFiles::DATASETS 
  in data.h.
 */
std::vector<InputFileSource> BethYw::parseDatasetsArg() {
  auto &args = BethYw::args();
  auto &allDatasets = InputFiles::DATASETS;
  std::vector<InputFileSource> datasetsToImport;

  try {
    // TODO map: remove/simplify this code
    std::vector<std::string> inputDatasets;
    try {
      inputDatasets = args["datasets"].as<std::vector<std::string>>();
    } catch (std::domain_error &ex) {
      throw BethYw::ImportAllValues();
    } catch (std::bad_cast &ex) {
      std::cerr << "Invalid input for dataset argument" << std::endl;
      std::exit(1);
    }

    if (inputDatasets.empty() || inputDatasets.at(0) == "area") {
      throw BethYw::ImportAllValues();
    }

    for (auto inputDataset = inputDatasets.begin();
         inputDataset != inputDatasets.end();
         inputDataset++) {
      auto dataset = allDatasets.find(*inputDataset);
      if (dataset != allDatasets.end()) {
        InputFileSource file = dataset->second;
        datasetsToImport.push_back(std::move(file));
      } else {
        std::cerr << "No dataset matches key " << *inputDataset << std::endl;
        std::exit(1);
      }
    }
  } catch (BethYw::ImportAllValues &ex) {
    for (auto dataset = allDatasets.begin();
         dataset != allDatasets.end();
         dataset++) {
      datasetsToImport.push_back(dataset->second);
    }
  }
  
  return datasetsToImport;
}

/*
  TODO: Parse the measures argument, which is optional. If it doesn't exist or
  exists and contains "all" as value, all measures should be imported.

  Unlike above:
    * we can't check the validity of the values as it depends
      on each individual file imported. Therefore, we simply fetch the list
      of measures and later pass it to the Areas::populate() function.
    * we want to strip 'all' out of the vector as in the Areas::populate()
      function an empty vector is considerd to be 'import all measures'.

  Therefore, this function should return an unordered set of strings of measures
  to import, or if all measures should be imported, the set should be empty.  
*/
std::unordered_set<std::string> BethYw::parseMeaauresArg() {
  auto &args = BethYw::args();
  std::unordered_set<std::string> measures(0);
  try {
    auto temp = args["measures"].as<std::vector<std::string>>();
    measures = std::unordered_set<std::string>(temp.begin(), temp.end());
  } catch (std::domain_error &ex) {
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
  TODO: Parse the years argument. Years is either a four digit year value, or
  two four digit year values separated by a hyphen (i.e. either YYYY or
  YYYY-ZZZZ). This should be parsed as two integers and inserted into a
  std::tuple, representing the start and end year (inclusive). If both
  values are 0, then there is no range to be applied. If no year argument
  is given or there is an error, return <0,0> (i.e. to import all years).
*/
std::tuple<unsigned int, unsigned int> BethYw::parseYearsArg() {
  auto &args = BethYw::args();
  std::tuple<unsigned int, unsigned int> years = std::make_tuple(0, 0);

  try {
    std::string value = args["years"].as<std::string>();

    if (value.find('-') != std::string::npos) {
      int start = std::stoi(value.substr(0, value.find('-')));
      int end = std::stoi(value.substr(value.find('-') + 1));
      auto tuple = std::make_tuple(start, end);
      years = std::move(tuple);
    } else {
      int year = std::stoi(value);
      auto tuple = std::make_tuple(year, year);
      years = std::move(tuple);
    }
  } catch (std::domain_error &ex) {
  } catch (std::invalid_argument &ex) {
  } catch (BethYw::ImportAllValues &ex) {
  } catch (...) {
    std::cerr << "Unknown error parsing years argument." << std::endl;
    std::exit(1);
  }
  
  return years;
}

/*
  TODO: Parse the action argument and return a value from the Action enum.

  Now take the appropriate action by parsing the action argument. There are
  three possible actions:
    * If omitted or equal to "all", we print all the data imported out.
    * If equal to "average", an average value for all the imported data
      is printed out
    * If equal to "trend", the percentage difference between the first year
      and last year that were imported is printed out
*/
BethYw::Action BethYw::parseActionArg() {
  auto &args = BethYw::args();
  BethYw::Action action = ALL;
  try {
    std::string value = args["action"].as<std::string>();
    if (value == "average") {
      action = AVERAGE;
    } else if (value == "trend") {
      action = TREND;
    } 
  } catch (std::domain_error &ex) {
  }

  return action;
}

/*
  Load the areas.csv file from the directory `dir`. Parse the file and
  create the appropriate Area objects inside an Areas object.

  areas.csv is guaranteed to be formatted as:
    Local authority code,Name (eng),Name (cym)

  TODO: Implement this function. First you create an InputFile object with the
  filename of the areas file, open it, and then pass the file to the
  Areas<>::populate() function.
*/
void BethYw::loadAreas(const std::string &dir) {
  auto &data = Areas<>::getInstance();

  const std::string fileAreas = dir + InputFiles::AREAS.FILE;

  try {
    InputSource *source = new InputFile(fileAreas);
    // TODO map: replace below two lines with source->open();
    std::istream &stream = source->open();
    data.populate(stream, InputFiles::AREAS.PARSER, InputFiles::AREAS.COLS);
  } catch (const std::runtime_error &ex) {
    std::cout << fileAreas << " error:\n" << ex.what() << std::endl;
    std::exit(1);
  }
}

/*
  TODO: Simply dump all the information requested into the standard output.

  Output should be formatted like the following to pass the tests. Note: 
  area names and measure names should be alphabetically sorted.

  Within each measure, data should be printed in oldest year first to most
  recent year. The year is right aligned to the end of the value (see example
  at the bottom of this block comment).

  Ignore indentation on this output (i.e. except for the year row, each row's
  output should start in the first column of the output). Adhere to the number
  of rows between output (i.e. two between measures of the same area, and 
  three between areas).

    <English name of area 1> / <Welsh name of area 1> (<authority code 1>)
    <Measure 1 name> (<Measure 1 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>


    <Measure 2 name> (<Measure 2 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>


    <Measure 3 name> (<Measure 3 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>

    ...

    <Measure x name> (<Measure x code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>



    <English name of area 2> / <Welsh name of area 2> (<authority code 2>)
    <Measure 1 name> (<Measure 1 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>


    <Measure 2 name> (<Measure 2 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>


    <Measure 3 name> (<Measure 3 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>

    ...

    <Measure x name> (<Measure x code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>

    ...

    <English name of area y> / <Welsh name of area y> (<authority code y>)
    <Measure 1 name> (<Measure 1 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>


    <Measure 2 name> (<Measure 2 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>


    <Measure 3 name> (<Measure 3 code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>

    ...

    <Measure x name> (<Measure x code>)
     <year 1>  <year 2> <year 3> ...  <year n>
    <value 1>  <year 2> <year 3> ... <value n>

  For example, your output should start like this for the command
  bethyw --dir <dir> -p popden (truncated for readability):

    Isle of Anglesey / Ynys Môn (W06000001)
    Land area (Area)
          1991       1992       1993       1994       1995       1996 ...
    711.680100 711.680100 711.680100 711.680100 711.680100 711.680100 ...


    Population density (Dens)
         1991      1992      1993      1994      1995      1996      1997 ...
    97.126504 97.486216 98.038430 97.216432 96.147131 96.380382 95.701706 ...


    Population (Pop)
            1991         1992         1993         1994         1995 ...
    69123.000000 69379.000000 69772.000000 69187.000000 68426.000000 ...



    Gwynedd / Gwynedd (W06000002)
    Land area (Area)
    ...
*/
void BethYw::printAll() {
  // std::cout << "Print all the information" << std::endl;
  
  auto &areas = Areas<>::getInstance();
  for (auto area = areas.begin(); area != areas.end(); area++) {
    std::cout << area->second << std::endl;
  }
}

/*
  TODO: Calculate the average for each area and measure imported, across all 
  years imported, and print this out.
*/
void BethYw::printAverage() {
  std::cout << "Calculate and print average information" << std::endl;
}

/*
  TODO: Calculate the percentage difference for each area and measure imported, 
  from the first year imported to the last, and print this out.
*/
void BethYw::printTrend() {
  std::cout << "Calculate and print trend information" << std::endl;
}
