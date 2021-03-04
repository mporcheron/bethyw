#ifndef AREA_H_
#define AREA_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains the Area class declaration. Area objects contain all the
  Measure objects for a given local area, along with names for that area and a
  unique authority code.

  TODO: Read the block comments with TODO in area.cpp to know which 
  functions and member variables you need to declare in this class.
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
*/
using Area_c = std::map<std::string, Measure>;

/*
  An Area object consists of a unique authority code, a container for names
  for the area in any number of different languages, and a container for the
  Measures objects.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Area {
protected:
  std::string mLocalAuthorityCode;
  std::map<std::string, std::string> mNames;
  std::vector<std::string> mNamesList;
  Area_c mMeasures;

public:
  Area(const std::string& localAuthorityCode);
  ~Area() = default;

  Area(const Area& other) = default;
  Area& operator=(const Area& other) = default;
  Area(Area&& other) = default;
  Area& operator=(Area&& other) = default;

  const std::string& getLocalAuthorityCode() const;

  const std::string& getName(std::string lang) const;
  const std::map<std::string, std::string>& getNames() const;
  void setName(std::string lang, const std::string& name);
  void setName(std::string lang, std::string&& name);

  void setMeasure(std::string ident, Measure& stat);
  void setMeasure(std::string ident, Measure&& stat);
  Measure& getMeasure(std::string ident);
  size_t size() const noexcept;

  friend std::ostream& operator<<(std::ostream& os, const Area& area);
  friend bool operator==(const Area& lhs, const Area& rhs);
  
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

#endif // AREA_H_