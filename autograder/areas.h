#ifndef SRC_AREAS_H
#define SRC_AREAS_H

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

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
#include <iterator>
#include <map>
#include <set>
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
using AreasContainer = std::map<std::string, Area>;
using AreasContainerNamesToAuthorityCodes = std::map<std::string, std::string>;

/*
  Areas is a class that stores all the data categorised by area. The 
  underlying Standard Library container is customisable using the Container
  template parameter (with the default set to whatever AreasContainer is aliasing
  above).

  TODO: You should read the various block comments in the corresponding 
  implementation file to know what to declare.
*/
class Areas {
protected:
  AreasContainer mAreasByCode;
  AreasContainerNamesToAuthorityCodes mAreasByName;

public:
  Areas();
  ~Areas() = default;

  Areas(const Areas &other) = delete;
  Areas &operator=(const Areas &other) = delete;
  Areas(Areas &&other) = default;
  Areas &operator=(Areas &&ither) = default;

  size_t wildcardCountSet(
    const std::unordered_set<std::string> &needles,
    const std::string& haystack) const;
  bool isLocalAuthorityFiltered(
      const std::unordered_set<std::string> &areasFilter,
      const std::string localAuthorityCode)
      noexcept;
    
  void setArea(std::string &ident, Area &stat);
  void setArea(std::string &ident, Area &&stat);
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
      const StringFilterSet * const measuresFilter = nullptr,
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
  
  /*
    Wrapper around underlying iterator functions for ease.
  */
  inline AreasContainer::iterator begin() {
    return mAreasByCode.begin();
  }
  inline AreasContainer::const_iterator cbegin() const {
    return mAreasByCode.cbegin();
  }

  inline AreasContainer::iterator end() {
    return mAreasByCode.end();
  }
  inline AreasContainer::const_iterator cend() const {
    return mAreasByCode.cend();
  }

  inline AreasContainer::reverse_iterator rbegin() {
    return mAreasByCode.rbegin();
  }
  inline AreasContainer::const_reverse_iterator crbegin() const {
    return mAreasByCode.crbegin();
  }

  inline AreasContainer::reverse_iterator rend() {
    return mAreasByCode.rend();
  }
  inline AreasContainer::const_reverse_iterator crend() const {
    return mAreasByCode.crend();
  }
};

#endif // SRC_AREAS_H