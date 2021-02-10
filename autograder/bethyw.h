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

#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "lib_cxxopts.hpp"

#include "areas.h"

/*
  OS-specific directory separator
*/
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
  Run Beth Yw?, parsing the command line arguments and acting upon them.
*/
int run(int argc, char *argv[]);

/*
  Create a cxxopts instance.
*/
cxxopts::Options cxxoptsSetup();

/*
  Parse the datasets argument and return a std::vector of all the datasets
  to import. InputFileSource is declared in datasets.h.
*/
std::vector<InputFileSource> parseDatasetsArg(cxxopts::ParseResult& args);

/*
  Parse the areas argument and return a std::unordered_set of all the
  areas to import, or an empty set if all areas should be imported.
*/
std::unordered_set<std::string> parseAreasArg(cxxopts::ParseResult& args);

/*
  Parse the measures argument and return a std::unordered_set of all the
  measures to import, or an empty set if all measures should be imported.
*/
std::unordered_set<std::string> parseMeasuresArg(cxxopts::ParseResult& args);

/*
  Parse the years argument and return a std::tuple of the range of years
  to import (or <0,0> to import all years).
*/
std::tuple<unsigned int, unsigned int> parseYearsArg(
    cxxopts::ParseResult& args);

/*
  Load the areas.csv file from the directory `dir`. Parse the file and
  create the appropriate Area objects inside an Areas object.
*/
void loadAreas(
    Areas &areas,
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
    Areas &cat,
    const std::string &dir,
    std::vector<InputFileSource> &datasetsToImport,
    std::unordered_set<std::string> &areasFilter,
    std::unordered_set<std::string> &measuresFilter,
    std::tuple<unsigned int,unsigned int> &yearsFilter) noexcept;

} // namespace BethYw

#endif // BETHYW_H_