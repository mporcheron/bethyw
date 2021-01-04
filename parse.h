#ifndef PARSE_H_
#define PARSE_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file is responsible for parsing data from a standard input stream and 
  converting it into a series of objects. This class contains the declarations
  for those objects.

  Some code has been provided in your coursework, along with explanatory 
  comments.

  TODO: Read the block comments with TODO in parse.cpp to know which 
  functions and member variables you need to declare in these classes.
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_set>
#include <variant>

/*
  Enums (short for enumerations) are similar to their Java implementation.
  It is a user-defined type, used to assign names to internal constants
  in code, instead of simply passing in integers/strings etc.

  For example, functions can take a value/constant from a specific enum
  and use it in a switch statement, doing different things

  As such, it is a useful way for us to specify information in both a
  machine and human-readable format.

  Unlike Java, enum in C++ only map to intenger values. You can either let
  the compiler generate the values automatically, in which it allocates a
  unique integer (0-indexed). Or, you can set the value by giving the name
  followed by = <value> (e.g. AuthorityCodeCSV=1).

  This enum specifies the format types that the InputSource class can parse.
  We could have implemented an if statement that parsed a string for the data
  type, or perhaps used integers. But with a enum both in code and to anyone
  who just glances at the code can infer the meaning.
*/
enum DataType { None, AuthorityCodeCSV, WelshStatsJSON };

/*
  Data from the different sources typically hagve different column headings
  for the same value (e.g. some might say "Year" whereas others might say
  "Year_Code"). Here we create another enum for these column headings for
  the parser.

  Each input passed to the Areas() object will have to specifiy a
  an unordered map to match each of these enum values into a string that
  the source contains.
*/
enum SourceColumns {
  AUTH_CODE,
  AUTH_NAME,
  MEASURE_CODE,
  MEASURE_NAME,
  YEAR,
  VALUE
};

/*
  We use the shortcut SourceColumnsMatch in this file for simplcity.
*/
using SourceColumnsMatch = std::unordered_map<SourceColumns, std::string>;

/*
  TODO map: remove

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
  TODO map: remove

  We declare Measure_c as the container for the year:value mappings (i.e. 
  the Measure data container) as a shortcut.
*/
using Measure_c = std::map<int, Measure_t>;

/*
  Because of the way std::variant is implemented in C++, we need to write
  a function that converts the values from std::variant in the above map
  and returns them as a std::string

  For the coursework, you can ignore how this and just assume it works! :)
*/
struct MeasureValueToString {
  std::string operator()(long value) { return std::to_string(value); }
  std::string operator()(double value) { return std::to_string(value); }
  std::string operator()(const std::string &value) { return value; }
};

/*
  The Measure class contains a measure code, label, and a map of year:value
  mappings.

  TODO: You should read the various block comments in the corresponding 
  implementation file to know what to implement.
*/
class Measure {
private:
  std::string mCode;
  std::string mLabel;
  Measure_c mData;

public:
  Measure(std::string &code, std::string &label);
  ~Measure() = default;

  Measure(const Measure &other)
      : mCode(other.mCode), mLabel(other.mLabel), mData(other.mData) {
    std::cerr << "!!!! Copy Construct Measure " << mLabel << std::endl;
  }
  Measure &operator=(const Measure &other) {
    std::cerr << "!!!! Copy Assign Measure " << other.mLabel << std::endl;
    mCode  = other.mCode;
    mLabel = other.mLabel;
    mData  = other.mData;
    return *this;
  }
  Measure(Measure &&other) = default;
  Measure &operator=(Measure &&ither) = default;

  inline const std::string &getCode() const;
  inline const std::string &getLabel() const;

  inline Measure_t &at(const int &key);
  inline void emplace(const int &key, Measure_t &value);
  inline void emplace(const int &key, Measure_t &&value);
  inline size_t size() const noexcept;

  friend std::ostream &operator<<(std::ostream &os, const Measure &measure);
  
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
  implementation file to know what to implement.
*/
class Area {
protected:
  std::string mLocalAuthorityCode;
  std::map<std::string, std::string> mNames;
  Area_c mMeasures;

public:
  Area(const std::string &localAuthorityCode);
  ~Area() = default;

  Area(const Area &other)
      : mLocalAuthorityCode(other.mLocalAuthorityCode), mNames(other.mNames),
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
  Area(Area &&other) = default;
  Area &operator=(Area &&ither) = default;

  inline const std::string &getLocalAuthorityCode() const;
  inline const std::string &getName(const std::string &lang) const;
  inline void setName(const std::string &lang, const std::string &name);
  inline void setName(const std::string &lang, std::string &&name);

  inline void emplace(std::string ident, Measure &stat);
  inline void emplace(std::string ident, Measure &&stat);
  inline Measure &at(std::string ident);
  inline size_t size() const noexcept;

  friend bool operator==(const Area &lhs, const Area &rhs);
  friend bool operator!=(const Area &lhs, const Area &rhs);
  friend bool operator<(const Area &lhs, const Area &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Area &st);
  
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

/*
  A shortcut for filters based on strings such as categorisations e.g. area,
  and measures.

  TODO map: delete
*/
using StringFilterSet = std::unordered_set<std::string>;

/*
  A shortcut for a year filter.

  TODO map: delete
*/
using YearFilterTuple = std::tuple<unsigned int, unsigned int>;

/*
  Shortcut for the data within an Areas<>() object that maps authority codes
  to an area name.

  TODO: you should remove the declaration of the Null class below, and give
  Areas_c a valid container.
*/
// TODO map: replace with
// class Null { };
// using Areas_c = Null;
using Areas_c = std::map<std::string, Area>;

/*
  Areas<> is a class that stores all the data categorised by area. The 
  underlying Standard Library container is customisable using the Container
  template parameter.

  TODO: You should read the various block comments in the corresponding 
  implementation file to know what to implement.
*/
template <class Container = Areas_c>
class Areas {
protected:
  Areas_c mAreas;

public:
  Areas();
  virtual ~Areas() = default;

  Areas(const Areas &other) = delete;
  Areas &operator=(const Areas &other) = delete;
  Areas(Areas &&other) = default;
  Areas &operator=(Areas &&ither) = default;

  // Parses the list of Welsh areas used in the statistics website, including
  // their local area code, English, and Welsh names as a CSV file.

  /*
    A function that specifically parses the compiled areas.csv file of
    local authority codes, and their names in English and Welsh.

    See comment blocks on the populate() functions below for an explanation
    of the function parameters and their effect. 
  
    See the comment block in parse.cpp for an explanation of areas.csv.

    If a parsing error occurs (e.g. due to a malformed file), throw a 
    std::runtime_error.
  */
  virtual void populateFromAuthorityCodeCSV(
      std::istream &is,
      const SourceColumnsMatch &cols,
      const std::unordered_set<std::string> * const areas = nullptr)
      noexcept(false);

  /*
    A function that specifically parses the JSON from the StatsWales website.
      
    See comment blocks on the populate() functions below for an explanation
    of the function parameters and their effect. 

    If a parsing error occurs (e.g. due to a malformed file), throw a 
    std::runtime_error.
  */
  virtual void populateFromWelshStatsJSON(
      std::istream &is,
      const SourceColumnsMatch &cols,
      const StringFilterSet * const areasFilter = nullptr,
      const StringFilterSet * const measuresFilter = nullptr,
      const YearFilterTuple * const yearsFilter = nullptr)
      noexcept(false);

  /*
    Parse all data from an std::istream, that is of a particular type, and with
    a given column mapping,  and fill the container.

    If a parsing error occurs (e.g. due to a malformed file), throw a 
    std::runtime_error.
  */
  virtual void populate(
      std::istream &is,
      const DataType &type,
      const SourceColumnsMatch &cols) noexcept(false);

  /*
    Parse data from an std::istream, that is of a particular type, and with
    a given column mapping, filtering for specific area authority codes,,
    measure identifiers, and years, and fill the container.

    areasFilter should be an unordered set of strings. If the set is empty
    or areasFilter is equal to nullptr, all areas should be imported. 
    
    measuresFilter operates in the same way for measures.
      
    yearsFilter is a tuple of two unsigned ints. If yearsFilter is equal to 
    nullPtr or both unsigned ints equal 0, all years will be imported otherwise 
    only years within the range (inclusive) should be imported.

    If a parsing error occurs (e.g. due to a malformed file), throw a 
    std::runtime_error.
  */
  virtual void populate(
      std::istream &is,
      const DataType &type,
      const SourceColumnsMatch &cols,
      const StringFilterSet * const areasFilter = nullptr,
      const StringFilterSet * const measuresFilter = nullptr,
      const YearFilterTuple * const yearsFilter = nullptr)
      noexcept(false);

  /*
    Wrapper around underlying iterator functions for ease.
      
   TODO map: remove all of these
  */
  inline void emplace(std::string &ident, Area &&stat) {
    mAreas.emplace(ident, std::move(stat));
  }

  inline Areas_c::iterator begin() { return mAreas.begin(); }
  inline Areas_c::const_iterator cbegin() { return mAreas.cbegin(); }

  inline Areas_c::iterator end() { return mAreas.end(); }
  inline Areas_c::const_iterator cend() { return mAreas.cend(); }

  inline Areas_c::reverse_iterator rbegin() { return mAreas.rbegin(); }
  inline Areas_c::const_reverse_iterator crbegin() { return mAreas.crbegin(); }

  inline Areas_c::reverse_iterator rend() { return mAreas.rend(); }
  inline Areas_c::const_reverse_iterator crend() { return mAreas.crend(); }

  inline Area &at(const std::string &areaCode) { return mAreas.at(areaCode); }
  inline size_t size() const noexcept { return mAreas.size(); }
};

#endif // PARSE_H_