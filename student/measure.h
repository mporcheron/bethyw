#ifndef SRC_MEASURE_H_
#define SRC_MEASURE_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <STUDENT NUMBER>

  This file contains the decalaration of the Measure class.

  Some code has been provided in your coursework, along with explanatory 
  comments.

  TODO: Read the block comments with TODO in measure.cpp to know which 
  functions and member variables you need to declare in these classes.
 */

#include <string>

/*
  For each set of data, we have a value for each individual measure over
  several years. Therefore, we will contain this in a "Measure" class, along
  with a human-readable label.

  For future proofing, we could  make use of std::variant, which is a C++17
  feature that implements a "union". It allows us to state that the type of 
  the value will be one of any number of given types. To keep our code simple,
  we define, using the using keyword, the type for this data. For now, we'll
  just set all data to doubles.
*/
using Measure_t = void;

/*
  The Measure class contains a measure code, label, and a container readings
  from across a number of years.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Measure {
  Measure(std::string code, const std::string &label);
};

#endif // SRC_MEASURE_H_