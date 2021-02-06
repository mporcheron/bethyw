#ifndef SRC_MEASURE_H_
#define SRC_MEASURE_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains the decalaration of the Measure class.

  Some code has been provided in your coursework, along with explanatory 
  comments.

  TODO: Read the block comments with TODO in measure.cpp to know which 
  functions and member variables you need to declare in these classes.
 */

#include <iterator>
#include <map>
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
using Measure_t = double;

/*
  We declare Measure_c as the container for the year:value mappings (i.e. 
  the Measure data container) as a shortcut.
*/
using Measure_c = std::map<int, Measure_t>;

/*
  The Measure class contains a measure code, label, and a map of year:value
  mappings.

  TODO: You should read the various block comments in the corresponding 
  implementation file to know what to implement.
*/
class Measure {
private:
  std::string mCodename;
  std::string mLabel;
  Measure_c mData;
  double mSum;

public:
  Measure(std::string code, const std::string &label);
  ~Measure() = default;

  Measure(const Measure &other) = default;
  Measure &operator=(const Measure &other) = default;
  Measure(Measure &&other) = default;
  Measure &operator=(Measure &&other) = default;

  // Measure(const Measure &other)
  //     : mCodename(other.mCodename), mLabel(other.mLabel), mData(other.mData) {
  //   std::cerr << "!!!! Copy Construct Measure " << mLabel << std::endl;
  // }
  // Measure &operator=(const Measure &other) {
  //   std::cerr << "!!!! Copy Assign Measure " << other.mLabel << std::endl;
  //   mCodename = other.mCodename;
  //   mLabel    = other.mLabel;
  //   mData     = other.mData;
  //   return *this;
  // }

  const std::string &getCodename() const;
  const std::string &getLabel() const;
  void setLabel(const std::string &label);

  Measure_t &getValue(const int &key);
  void setValue(const int &key, const Measure_t &value);
  void setValue(const int &key, const Measure_t &&value);
  size_t size() const noexcept;

  Measure_t getDifference() const noexcept;
  double getDifferenceAsPercentage() const noexcept;
  double getAverage() const noexcept;

  friend std::ostream &operator<<(std::ostream &os, const Measure &measure);
  friend bool operator==(const Measure &lhs, const Measure &rhs);

  /*
    Wrapper around underlying iterator functions for ease.
  */
  inline Measure_c::iterator begin() {
    return mData.begin();
  }
  inline Measure_c::const_iterator cbegin() const {
    return mData.cbegin();
  }

  inline Measure_c::iterator end() {
    return mData.end();
  }
  inline Measure_c::const_iterator cend() const {
    return mData.cend();
  }

  inline Measure_c::reverse_iterator rbegin() {
    return mData.rbegin();
  }
  inline Measure_c::const_reverse_iterator crbegin() const {
    return mData.crbegin();
  }

  inline Measure_c::reverse_iterator rend() {
    return mData.rend();
  }
  inline Measure_c::const_reverse_iterator crend() const {
    return mData.crend();
  }
};

#endif // SRC_MEASURE_H_