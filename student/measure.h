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