#ifndef SRC_AREAS_H
#define SRC_AREAS_H

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <STUDENT NUMBER>

  This file contains the Areas class, which is responsible for parsing data
  from a standard input stream and converting it into a series of objects:

  Measure       — Represents a single measure for an area, e.g.
   |              population. Contains a human-readable label and a map of
   |              the measure accross a number of years.
   |
   +-> Area       Represents an area. Contains a unique local authority code
        |         used in national statistics, a map of the names of the area 
        |         (i.e. in English and Welsh), and a map of various Measure 
        |         objects.
        |
        +-> Areas A simple class that contains a map of all Area objects,
                  indexed by the local authority code.

  Some code has been provided in your coursework, along with explanatory 
  comments.

  TODO: Read the block comments with TODO in areas.cpp to know which 
  functions and member variables you need to declare in these classes.
 */

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>

#include "datasets.h"
#include "area.h"

/*
  A shortcut for filters based on strings such as categorisations e.g. area,
  and measures.
*/
using StringFilterSet = std::unordered_set<std::string>;

/*
  A shortcut for a year filter.
*/
using YearFilterTuple = std::tuple<unsigned int, unsigned int>;

/*
  Shortcut for the data within an Areas() object that maps authority codes
  to an area name.

  TODO: you should remove the declaration of the Null class below, and give
  AreasContainer a valid Standard Library container of your choosing.
*/
class Null { };
using AreasContainer = Null;

/*
  Areas is a class that stores all the data categorised by area. The 
  underlying Standard Library container is customisable using the alias above.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Areas {
public:
  Areas();
  ~Areas();

  void setArea(std::string &ident, Area &stat);
  Area &getArea(const std::string &areaCode);
  size_t size() const noexcept;
  
  void populateFromAuthorityCodeCSV(
      std::istream &is,
      const BethYw::SourceColumnMapping &cols,
      const std::unordered_set<std::string> * const areas = nullptr)
      noexcept(false);

  void populateFromAuthorityByYearCSV(
      std::istream &is,
      const BethYw::SourceColumnMapping &cols,
      const StringFilterSet * const areasFilter = nullptr,
      const YearFilterTuple * const yearsFilter = nullptr)
      noexcept(false);

  void populateFromWelshStatsJSON(
      std::istream &is,
      const BethYw::SourceColumnMapping &cols,
      const StringFilterSet * const areasFilter = nullptr,
      const StringFilterSet * const measuresFilter = nullptr,
      const YearFilterTuple * const yearsFilter = nullptr)
      noexcept(false);

  void populate(
      std::istream &is,
      const BethYw::SourceDataType &type,
      const BethYw::SourceColumnMapping &cols) noexcept(false);

  void populate(
      std::istream &is,
      const BethYw::SourceDataType &type,
      const BethYw::SourceColumnMapping &cols,
      const StringFilterSet * const areasFilter = nullptr,
      const StringFilterSet * const measuresFilter = nullptr,
      const YearFilterTuple * const yearsFilter = nullptr)
      noexcept(false);

  std::string toJSON() const;

  friend std::ostream &operator<<(std::ostream &os, const Areas &areas);
};

#endif // SRC_AREAS_H