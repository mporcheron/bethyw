#ifndef SRC_AREA_H_
#define SRC_AREA_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains the Area class declaration. Area objects contain all the
  Measure objects for a given local area, along with names for that area and a
  unique authority code.

  Some code has been provided in your coursework, along with explanatory 
  comments.

  TODO: Read the block comments with TODO in area.cpp to know which 
  functions and member variables you need to declare in these classes.
 */

#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

#include "measure.h"

/*
  The Areas class stores the area-based statistics data in a map of measure
  code to Measure object. Here we define this shortcut for the class.

  TODO map: delete
*/
using Area_c = std::map<std::string, Measure>;

/*
  An Area consists of a unique authority code, a map of names and a map of 
  measures (where the measure code is the key and a Measure object is the 
  value).

  TODO: You should read the various block comments in the corresponding 
  implementation file to know what to declare.
*/
class Area {
protected:
  std::string mLocalAuthorityCode;
  std::map<std::string, std::string> mNames;
  std::vector<std::string> mNamesList;
  Area_c mMeasures;

public:
  Area(const std::string &localAuthorityCode);
  ~Area() = default;

  /* 
  Area(const Area &other)
      : mLocalAuthorityCode(other.mLocalAuthorityCode),
        mNames(other.mNames),
        mMeasures(other.mMeasures) {
    std::cerr << "!!!! Copy Construct Area" << std::endl;
  }
  Area &operator=(const Area &other) {
    std::cerr << "!!!! Copy Assign Area" << std::endl;
    mLocalAuthorityCode  = other.mLocalAuthorityCode;
    mNames = other.mNames;
    mMeasures  = other.mMeasures;
    return *this;
  }
  */

  Area(const Area &other) = default;
  Area &operator=(const Area &other) = default;
  Area(Area &&other) = default;
  Area &operator=(Area &&other) = default;

  const std::string &getLocalAuthorityCode() const;

  const std::string &getName(std::string lang) const;
  const std::map<std::string, std::string> &getNames() const;
  void setName(std::string lang, const std::string &name);
  void setName(std::string lang, std::string &&name);

  void setMeasure(std::string ident, Measure &stat);
  void setMeasure(std::string ident, Measure &&stat);
  Measure &getMeasure(std::string ident);
  size_t size() const noexcept;

  friend std::ostream &operator<<(std::ostream &os, const Area &area);
  friend bool operator==(const Area &lhs, const Area &rhs);
  
  /*
    Wrapper around underlying iterator functions for ease.
  */
  inline Area_c::iterator begin() {
    return mMeasures.begin();
  }
  inline Area_c::const_iterator cbegin() const {
    return mMeasures.cbegin();
  }

  inline Area_c::iterator end() {
    return mMeasures.end();
  }
  inline Area_c::const_iterator cend() const {
    return mMeasures.cend();
  }

  inline Area_c::reverse_iterator rbegin() {
    return mMeasures.rbegin();
  }
  inline Area_c::const_reverse_iterator crbegin() const {
    return mMeasures.crbegin();
  }

  inline Area_c::reverse_iterator rend() {
    return mMeasures.rend();
  }
  inline Area_c::const_reverse_iterator crend() const {
    return mMeasures.crend();
  }
};

#endif // SRC_AREA_H_