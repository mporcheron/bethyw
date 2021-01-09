#ifndef BETHYW_H_
#define BETHYW_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains all the helper functions for initialising and running
  Beth Yw?

  TODO: Read the block comments with TODO in bethyw.cpp to know which 
  functions you need to declare in this file.
 */

#include "libs/cxxopts/cxxopts.hpp"

#include "datasets.h"

const char DIR_SEP =
#ifdef _WIN32
    '\\';
#else
    '/';
#endif

namespace BethYw {

/*
  TODO: Enter your student number here!
*/
const std::string STUDENT_NUMBER = "987654";

/*
  The ImportAllValues class is an exception that is thrown by the command
  line argument parser functions below if all the values match.

  TODO map: remove this class
*/
class ImportAllValues {};

/*
  These are the possible outputs once data is imported.
*/
enum Output { ALL, AVERAGE, TREND };

/*
  Run Beth Yw?, parsing the command line arguments and acting upon them.
*/
void run(int argc, char *argv[]);

/*
  Initialise the Beth Yw? command line arguments parser.
*/
cxxopts::Options& cxxopts();

/*
  Container for the initialsied arguments result so that we can refetch it
  in multiple functions.

  This has default values for argc and argv so that on successive calls they
  can be ommitted. Note that on the first call, they are required!
*/
cxxopts::ParseResult& args(int argc = 0, char *argv[] = nullptr);

/*
  Print out the help information, and then exit the program.
*/
void help(std::ostream &os, const int &errorCode);

/*
  Parse the areas argument and return a std::unordered_set of all the
  areas to import, or an empty set if all areas should be imported.
*/
std::unordered_set<std::string> parseAreasArg();

/*
  Parse the datasets argument and return a std::vector of all the datasets
  to import. InputFileSource is declared in datasets.h.
*/
std::vector<InputFileSource> parseDatasetsArg();

/*
  Parse the measures argument and return a std::unordered_set of all the
  measures to import, or an empty set if all measures should be imported.
*/
std::unordered_set<std::string> parseMeasuresArg();

/*
  Parse the years argument and return a std::tuple of the range of years
  to import (or <0,0> to import all years).
*/
std::tuple<unsigned int, unsigned int> parseYearsArg();

/*
  Parse the output argument and return a value from the Output enum.
*/
Output parseOutputArg();

/*
  Load the areas.csv file from the directory `dir`. Parse the file and
  create the appropriate Area objects inside an Areas object.
*/
void loadAreas(
    Areas<> &areas,
    const std::string &dir,
    std::unordered_set<std::string> &filter);

/*
  Load the datasets in datasetsToImport into the Areas object from files
  in dir. If areasFilter or measuresFilter contain codes matching any
  (they should contain authority code and measure codes respectively),
  then only import those areas and measures. If areasFilter is empty, import 
  all areas. If measuresFilter is empty, import all measures.

  yearsFilter should be two unsigned ints; if both 0 then import all years.
  Otherwise import only years within the range (inclusive) specified in the
  tuple.
*/
void loadDatasets(
    Areas<> &cat,
    const std::string &dir,
    std::vector<InputFileSource> &datasetsToImport,
    std::unordered_set<std::string> &areasFilter,
    std::unordered_set<std::string> &measuresFilter,
    std::tuple<unsigned int,unsigned int> &yearsFilter);


}; // namespace BethYw

#endif // BETHYW_H_