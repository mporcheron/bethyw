#ifndef SRC_AREA_H_
#define SRC_AREA_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <STUDENT NUMBER>

  This file contains the Area class declaration. Area objects contain all the
  Measure objects for a given local area, along with names for that area and a
  unique authority code.

  Some code has been provided in your coursework, along with explanatory 
  comments.

  TODO: Read the block comments with TODO in area.cpp to know which 
  functions and member variables you need to declare in these classes.
 */

#include <iostream>
#include <map>
#include <string>

#include "measure.h"

/*
  An Area object consists of a unique authority code, a container for names
  for the area in any number of different languages, and a container for the
  Measures objects.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Area {
  Area(const std::string &localAuthorityCode);
  ~Area();

  const std::string &getLocalAuthorityCode() const;

  const std::string &getName(std::string lang) const;
  const std::map<std::string, std::string> &getNames() const;
  void setName(std::string lang, const std::string &name);

  void setMeasure(std::string ident, Measure &stat);
  Measure &getMeasure(std::string ident);
  size_t size() const noexcept;
  
  friend std::ostream &operator<<(std::ostream &os, const Area &area);
  friend bool operator==(const Area &lhs, const Area &rhs);
};

#endif // SRC_AREA_H_