#ifndef BETHYW_H_
#define BETHYW_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains all the helper functions for initialising and running
  Beth Yw?
 */

#include "libs/cxxopts/cxxopts.hpp"

#include "data.h"

namespace BethYw {

/*
  The ImportAllValues class is an exception that is thrown by the command
  line argument parser functions below if all the values match.
  
  TODO map: remove this class
*/
class ImportAllValues {};

/*
  These are the possible actions to take once data is imported.
*/
enum Action { ALL, AVERAGE, TREND };

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
  Parse the datasets argument and return a std::vector of all the datasets
  to import. InputFileSource is declared in data.h.
*/
std::vector<InputFileSource> parseDatasetsArg();

/*
  Parse the measures argument and return a std::unordered_set of all the 
  measures to import, or an empty set if all measures should be imported.
*/
std::unordered_set<std::string> parseMeaauresArg();

/*
  Parse the years argument and return a std::tuple of the range of years
  to import (or <0,0> to import all years).
*/
std::tuple<unsigned int, unsigned int> parseYearsArg();

/*
  Parse the action argument and return a value from the Action enum.
*/
Action parseActionArg();

/*
  Load the areas.csv file from the directory `dir`. Parse the file and
  create the appropriate Area objects inside an Areas object.
*/
void loadAreas(const std::string &dir);

/*
  Dump all the information requested into the standard output.
*/
void printAll();

/*
  Calculate the average for each area and measure imported, across all years
  imported, and print this out.
*/
void printAverage();

/*
  Calculate the percentage difference for each area and measure imported, from
  the first year imported to the last, and print this out.
*/
void printTrend();
  
}; // namespace BethYw

#endif // BETHYW_H_