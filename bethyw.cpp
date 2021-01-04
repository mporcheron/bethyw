


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
  this code and make sure it is safe. You may need to remove or modify the
  provided code to get your program to work fully.
*/

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "libs/cxxopts/cxxopts.hpp"

#include "bethyw.h"
#include "input.h"
#include "datasets.h"

/*
  Run Beth Yw?, parsing the command line arguments.
*/
void BethYw::run(int argc, char *argv[]) {
  // Parse the command line arguments
  auto &cxxopts = BethYw::cxxopts();
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

      "o,output",
      "Output desired. Valid values: average, trend, or all",
      cxxopts::value<std::string>()->default_value("all"))(

      "h,help",
      "Print usage.");

  auto &args = BethYw::args(argc, argv);

  // Print the help usage if requested
  if (args.count("help")) {
    BethYw::help(std::cout, 0);
  }

  // Parse data directory argument
  std::string dir;
  try {
    dir = args["dir"].as<std::string>() + DIR_SEP;
  } catch (std::domain_error &err) {
    BethYw::help(std::cerr, 1);
  }

  // Parse other arguments, import areas and then all the datasets
  // needed
  auto datasetsToImport = BethYw::parseDatasetsArg();
  auto areasFilter      = BethYw::parseAreasArg();
  auto measuresFilter   = BethYw::parseMeasuresArg();
  auto yearsFilter      = BethYw::parseYearsArg();

  Areas<> data = Areas<>();
  BethYw::loadAreas(data, dir, areasFilter);
  BethYw::loadDatasets(
    data,
    dir,
    datasetsToImport,
    areasFilter,
    measuresFilter,
    yearsFilter);

  // Take the appropriate action
  auto output           = BethYw::parseOutputArg();
  switch (output) {
    case ALL:
    BethYw::printAll(data);
    break;

    case AVERAGE:
    BethYw::printAverage(data);
    break;

    case TREND:
    BethYw::printTrend(data);
    break;
  }
}

/*
  Because Beth Yw? is just a namespace (there is no need for it to be a class),
  we store cxxopts as a static variable here so that it can be fetched from
  different functions.

  You do not need to modify this function.
*/
cxxopts::Options& BethYw::cxxopts() {
  static cxxopts::Options cxxopts(
        "bethyw",
        "Student ID: " + STUDENT_NUMBER + "\n\n"
        "This program is designed to parse Official UK/Welsh Government"
        " statistics data files and answer \"what is…?\" questions.\n");
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
  TODO: BethYw::parseDatasetsArg()

  Parse the datasets argument passed into the command line. 

  The datasets argument is optional, and if it is not included, all datasets 
  should be imported. If it is included, it should be a comma-separated list of 
  datasets to import (based on their key in the map InputFiles::DATASETS in 
  datasets.h). If the argument contains the value "all", all datasets should be 
  imported.

  This function validates the passed in dataset names against the names in
  InputFiles::DATASETS. If an invalid name is entered, output to std::cerr:
    No dataset matches key <input name>
  where <input name> is the name supplied by the user through the terminal.

  In case of error, exit the program with error code 1.

  @return
    A std::vector of BethYw::InputFileSource to import
 */
std::vector<BethYw::InputFileSource> BethYw::parseDatasetsArg() {
  // TODO map: swap this function to the following:
  // // This function is incomplete, but to get you started...
  //
  // // Retrieve all the parsed arguments
  // auto &args = BethYw::args();
  //
  // // Retrieve all valid datasets (this is an unordered_map), see datasets.h
  // auto &allDatasets = InputFiles::DATASETS;
  //
  // // Create the container for the return type
  // std::vector<InputFileSource> datasetsToImport;
  //
  // // You can get the std::vector of arguments from cxxopts like this:
  // auto inputDatasets = args["datasets"].as<std::vector<std::string>>();
  // // You now to check this and compare the strings in this vector to the
  // // keys in allDatasets above. Populate datasetsToImport with the values
  // // from map allDatasets above and then return this vector
  //
  // // You'll want to ignore/remove the following lines of code, they simply
  // // import all datasets (for now).
  // for(auto const& dataset: allDatasets)
  //     datasetsToImport.push_back(dataset.second);
  // return datasetsToImport;

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
  TODO: BethYw::parseAreasArg()
  
  Parses the areas command line argument, which is optional. If it doesn't 
  exist or exists and contains "all" as value, all areas should be imported.

  Unlike datasets we can't check the validity of the values as it depends
  on each individual file imported (which hasn't happened until runtime).
  Therefore, we simply fetch the list of areas and later pass it to the
  Areas::populate() function.

  @return 
    An std::unordered_set of std::strings corresponding to specific areas
    to import, or an empty set if all areas should be imported.

*/
std::unordered_set<std::string> BethYw::parseAreasArg() {
  auto &args = BethYw::args();
  std::unordered_set<std::string> areas(0);
  try {
    auto temp = args["areas"].as<std::vector<std::string>>();
    areas = std::unordered_set<std::string>(temp.begin(), temp.end());
  } catch (std::exception &ex) {
  }

  for (auto it = areas.begin(); it != areas.end(); it++) {
    if (*it == "all") {
      areas.clear();
      break;
    }
  }
  
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

  All inputted measures should be converted to lowercase, and the all value
  should be treated in a case-insensitive way.

  @return 
    An std::unordered_set of std::strings corresponding to specific measures
    to import, or an empty set if all measures should be imported.
*/
std::unordered_set<std::string> BethYw::parseMeasuresArg() {
  auto &args = BethYw::args();
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
  TODO: BethYw::parseYearsArg()

  Parse the years command line argument. Years is either a four digit year 
  value, or two four digit year values separated by a hyphen (i.e. either 
  YYYY or YYYY-ZZZZ).

  This should be parsed as two integers and inserted into a std::tuple,
  representing the start and end year (inclusive). If both values are 0,
  then there is no range to be applied. If no year argument is given or there
  is an error, return <0,0> (i.e. to import all years).

  @return
    A std::tuple containing two unsigned ints
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
  TODO: BethYw::parseOutputArg()

  Parse the output command line argument and return a value from the 
  BethYw::Output enum.

  @return 
    A BethYw::Output
*/
BethYw::Output BethYw::parseOutputArg() {
  auto &args = BethYw::args();
  BethYw::Output action = ALL;
  try {
    std::string value = args["output"].as<std::string>();
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
  TODO: BethYw::loadAreas(&areas, dir, areasFilter)

  Load the areas.csv file from the directory `dir`. Parse the file and
  create the appropriate Area objects inside an Areas object.

  areas.csv is guaranteed to be formatted as:
    Local authority code,Name (eng),Name (cym)

  Hint: to implement this function. First you will need create an InputFile 
  object with the filename of the areas file, open it, and then pass the file 
  to the Areas::populate() function.

  Hint 2: because Areas is a templated class, you will have to refer to it as 
  Areas<>.

  @param areas
    An Areas instance that should be modified

  @param dir
    Directory where the areas.csv file is

  @param areasFilter
    An unordered set of areas to filter, or empty to import all areas

  @example
    Areas<> areas();

    BethYw::loadAreas(areas, "data", BethYw::parseAreasArg());
*/
void BethYw::loadAreas(Areas<> &areas,
                       const std::string &dir,
                       std::unordered_set<std::string> &areasFilter) {
  const std::string fileAreas = dir + InputFiles::AREAS.FILE;

  try {
    InputSource *source = new InputFile(fileAreas);
    std::istream &stream = source->open();
    areas.populate(stream,
                  InputFiles::AREAS.PARSER,
                  InputFiles::AREAS.COLS,
                  &areasFilter);
  } catch (const std::runtime_error &ex) {
    std::cerr << fileAreas << " error:\n" << ex.what() << std::endl;
    std::exit(1);
  }
}

/*
  TODO: BethYw::loadDatasets(
    areas,
    dir,
    datasetsToImport,
    areasFilter,
    measuresFilter,
    yearsFilter)

  Import datasets from datasetsToImport as files in dir into areas, filtering
  with areasFilter, measuresFilter, and yearsFilter.

  @param areas
    An Areas instance that should be modified

  @param dir
    The directory where the datasets are is

  @param datasetsToImport
    A vector of InputFileSource objects

  @param areasFilter
    An unordered set of areas (as authority codes encoded in std::strings)
    to filter, or empty to import all areas

  @param measuresFilter
    An unordered set of measures (as measure codes encoded in std::strings)
    to filter, or empty to import all areas

  @param yarsFilter
    An two-pair tuple of unsigned ints corresponding to the range of years 
    to import, which should both be 0 to import all years.

  @example
    Areas<> areas();

    BethYw::loadDatasets(
      areas,
      "data",
      BethYw::parseDatasetsArgument()
      BethYw::parseAreasArg()
      BethYw::parseMeasuresArg()
      BethYw::parseYearsArg());
*/
void BethYw::loadDatasets(
    Areas<> &areas,
    const std::string &dir,
    std::vector<InputFileSource> &datasetsToImport,
    std::unordered_set<std::string> &areasFilter,
    std::unordered_set<std::string> &measuresFilter,
    std::tuple<unsigned int,unsigned int> &yearsFilter) {
  for (auto dataset = datasetsToImport.begin();
       dataset != datasetsToImport.end();
       dataset++) {
    try {
      InputSource *source = new InputFile(dir + dataset->FILE);
      std::istream &stream = source->open();
      areas.populate(stream,
                    dataset->PARSER,
                    dataset->COLS,
                    &areasFilter,
                    &measuresFilter,
                    &yearsFilter);
    } catch (const std::runtime_error &ex) {
      std::cerr << "Source error:\n" << ex.what() << std::endl;
      std::exit(1);
    }
  }
}

/*
  TODO:BethYw::printAll(areas)

  Simply dumps all the information requested into the standard output.

  Output should be formatted like the following to pass the tests. Note:
  area names and measure names should be alphabetically sorted.

  Check the coursework specification for how this output should be formated,
  although a short summary of this is given below too.

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

    @param areas
      A non-modified populated Areas object
*/
void BethYw::printAll(Areas<> &areas) {
  // TODO map: replace function with
  // std::cout << "Print all the information!" << std::endl;
  for (auto area = areas.begin(); area != areas.end(); area++) {
    std::cout << area->second << std::endl;
  }
}

/*
  TODO:BethYw::printAverage(areas)

  Calculate the average for each area and measure imported, across all
  years imported, and print this out to std::cout to std::cout;

  Check the coursework specification for how this output should be formated. 

  @param areas
    A non-modified populated Areas object
*/
void BethYw::printAverage(Areas<> &areas) {
  std::cout << "Calculate and print average information" << std::endl;
}

/*
  TODO: Calculate the percentage difference for each area and measure imported,
  from the first year imported to the last, and print this out to std::cout.

  Check the coursework specification for how this output should be formated.

  @param areas
    A non-modified populated Areas object
*/
void BethYw::printTrend(Areas<> &areas) {
  std::cout << "Calculate and print trend information" << std::endl;
}
