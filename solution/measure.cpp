


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains the implementation of the Measure class. Measure is a
  very simple class that needs to contain a few member variables for its name,
  codename, and a Standard Library container for data. The data you need to 
  store is values, organised by year. I'd recommend storing the values as 
  doubles.

  This file contains numerous functions you must implement. Each function you
  must implement has a TODO block comment. 
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "measure.h"

/*
  TODO: Measure::Measure(codename, label);

  Construct a single Measure, that has values across many years.

  All StatsWales JSON files have a codename for measures. You should convert 
  all codenames to lowercase.

  @param codename
    The codename for the measure

  @param label
    Human-readable (i.e. nice/explanatory) label for the measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);
*/
Measure::Measure(std::string codename, const std::string& label)
    : mLabel(label), mData(), mSum(0) {
  std::transform(codename.begin(),
                 codename.end(),
                 codename.begin(),
                 ::tolower);
   mCodename = std::move(codename);
}

/*
  TODO: Measure::getCodename()

  Retrieve the code for the Measure. This function should be callable from a 
  constant context and must promise to not modify the state of the instance or 
  throw an exception.

  @return
    The codename for the Measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    ...
    auto code = measure.getCodename();
*/
const std::string& Measure::getCodename() const noexcept { return mCodename; }

/*
  TODO: Measure::getLabel()

  Retrieve the human-friendly label for the Measure. This function should be 
  callable from a constant context and must promise to not modify the state of 
  the instance and to not throw an exception.

  @return
    The human-friendly label for the Measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    ...
    auto label = measure.getLabel();
*/
const std::string& Measure::getLabel() const noexcept { return mLabel; }

/*
  TODO: Measure::setLabel(label)

  Change the label for the Measure.

  @param label
    The new label for the Measure

  @example
    Measure measure("pop", "Population");
    measure.setValue(1999, 12345678.9);
    ...
    measure.setLabel("New Population");
*/
void Measure::setLabel(const std::string& label) { mLabel = label; }

/*
  TODO: Measure::getValue(key)

  Retrieve a Measure's value for a given year.

  @param key
    The year to find the value for

  @return
    The value stored for the given year

  @throws
    std::out_of_range if year does not exist in Measure with the message
    No value found for year <year>

  @return
    The value

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    ...
    auto value = measure.getValue(1999); // returns 12345678.9
*/
Measure_t& Measure::getValue(const int& key) {
  try {
    return mData.at(key);
  } catch (const std::out_of_range& ex) {
    throw std::out_of_range("No value found for year " + std::to_string(key));
  }
}

/*
  TODO: Measure::setValue(key, value)

  Add a particular year's value to the Measure object. If a value already
  exists for the year, replace it.

  @param key
    The year to insert a value at

  @param value
    The value for the given year

  @return
    void

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
*/
void Measure::setValue(const int& key, const Measure_t& value) {
  auto existingIt = mData.find(key);
  if (existingIt != mData.end()) {
    mSum -= existingIt->second;
    mData.erase(key);
  }
  
  mSum += value;
  mData.emplace(key, value);
}

void Measure::setValue(const int& key, const Measure_t&& value) {
  auto existingIt = mData.find(key);
  if (existingIt != mData.end()) {
    mSum -= existingIt->second;
    mData.erase(key);
  }

  mSum += value;
  mData.emplace(key, std::move(value));
}

/*
  TODO: Measure::size()

  Retrieve the number of years data we have for this measure. This function
  should be callable from a constant context and must promise to not change
  the state of the instance or throw an exception.

  @return
    The size of the measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    auto size = measure.size(); // returns 1
*/
size_t Measure::size() const noexcept {
  return mData.size();
}

/*
  TODO: Measure::getDifference()

  Calculate the difference between the first and last year imported. This
  function should be callable from a constant context and must promise to not
  change the state of the instance or throw an exception.

  @return
    The difference/change in value from the first to the last year, or 0 if it
    cannot be calculated

  @example
    Measure measure("pop", "Population");
    measure.setValue(1999, 12345678.9);
    measure.setValue(2001, 12345679.9);
    auto diff = measure.getDifference(); // returns 1.0
*/
Measure_t Measure::getDifference() const noexcept {
  if (size() == 0) {
    return 0;
  }

  return crbegin()->second - cbegin()->second;
}

/*
  TODO: Measure::getDifferenceAsPercentage()

  Calculate the difference between the first and last year imported as a 
  percentage. This function should be callable from a constant context and
  must promise to not change the state of the instance or throw an exception.

  @return
    The difference/change in value from the first to the last year as a decminal
    value, or 0 if it cannot be calculated

  @example
    Measure measure("pop", "Population");
    measure.setValue(1990, 12345678.9);
    measure.setValue(2010, 12345679.9);
    auto diff = measure.getDifferenceAsPercentage();
*/
double Measure::getDifferenceAsPercentage() const noexcept {
  if (size() == 0) {
    return 0;
  }

  return getDifference() / cbegin()->second * 100.0;
}

/*
  TODO: Measure::getAverage()

  Calculate the average/mean value for all the values. This function should be
  callable from a constant context and must promise to not change the state of 
  the instance or throw an exception.

  @return
    The average value for all the years, or 0 if it cannot be calculated

  @example
    Measure measure("pop", "Population");
    measure.setValue(1999, 12345678.9);
    measure.setValue(1999, 12345679.9);
    auto diff = measure.getDifference(); // returns 1
*/
double Measure::getAverage() const noexcept {
  if (size() == 0) {
    return 0;
  }

  return mSum/size();
}

/*
  TODO: operator<<(os, measure)

  Overload the << operator to print all of the Measure's imported data.

  We align the year and value outputs by padding the outputs with spaces,
  i.e. the year and values should be right-aligned to each other so they
  can be read as a table of numerical values.

  Years should be printed in chronological order. Three additional columns
  should be included at the end of the output, correspodning to the average
  value across the years, the difference between the first and last year,
  and the percentage difference between the first and last year.

  If there is no data in this measure, print the name and code, and 
  on the next line print: <no data>

  See the coursework specification for more information.

  @param os
    The output stream to write to

  @param measure
    The Measure to write to the output stream

  @return
    Reference to the output stream

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    std::cout << measure << std::end;
*/
std::ostream& operator<<(std::ostream& os, const Measure& measure) {
  os << measure.getLabel() << " (" << measure.getCodename();
  os << ") "  << std::endl;

  if (measure.size() == 0) {
    os << "<no data>" << std::endl;
    return os;
  }

  // Iterate through and print the years and save the values to a stringstream
  std::stringstream values;
  for (auto it = measure.cbegin(); it != measure.cend(); it++) {
    std::string year = std::to_string(it->first);
    std::string value = std::to_string(it->second);

    int len = std::max(year.length(), value.length());

    os << std::setw(len) << year << " ";
    values << std::setw(len) << value << " ";
  }

  // Add average and change values
  {
    std::string title = "Average";
    double average = measure.getAverage();
    std::string averageStr = std::to_string(average);

    int len = std::max(title.length(), averageStr.length());

    os << std::setw(len) << title << " ";
    values << std::setw(len) << averageStr << " ";
  }

  double change = measure.getDifference();
  {
    std::string title = "Diff.";
    std::string changeStr = std::to_string(change);

    int len = std::max(title.length(), changeStr.length());

    os << std::setw(len) << title << " ";
    values << std::setw(len) << changeStr << " ";
  }

  {
    std::string title = "% Diff.";
    double changeP = measure.getDifferenceAsPercentage();
    std::string changePStr = std::to_string(changeP);

    int len = std::max(title.length(), changePStr.length());

    os << std::setw(len) << title << " ";
    values << std::setw(len) << changePStr << " ";
  }
  
  os << "\n" << values.str() << std::endl;

  return os;
}

/*
  TODO: operator==(lhs, rhs)

  Overload the == operator for two Measure objects. Two Measure objects
  are only equal when their codename, label and data are all equal.

  @param lhs
    A Measure object

  @param lhs
    A second Measure object

  @return
    true if both Measure objects have the same codename, label and data; false
    otherwise
*/
bool operator==(const Measure& lhs, const Measure& rhs) {
  return lhs.mCodename == rhs.mCodename &&
         lhs.mLabel    == rhs.mLabel &&
         lhs.mData     == rhs.mData &&
         lhs.mSum      == rhs.mSum;
}