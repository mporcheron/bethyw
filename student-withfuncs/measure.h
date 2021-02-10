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

/*
  The Measure class contains a measure code, label, and a container readings
  from across a number of years.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Measure {
  Measure(std::string code, const std::string &label);
  ~Measure();

  Measure_t &getValue(const int &key);
  void setValue(const int &key, const Measure_t &value);
  size_t size() const noexcept;

  Measure_t getDifference() const noexcept;
  double getDifferenceAsPercentage() const noexcept;
  double getAverage() const noexcept;

  friend std::ostream &operator<<(std::ostream &os, const Measure &measure);
  friend bool operator==(const Measure &lhs, const Measure &rhs);
};

#endif // SRC_MEASURE_H_