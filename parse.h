#ifndef PARSE_H_
#define PARSE_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file handles classes that contain the data parsed from the various
  sources. The file's classes are structured in a granular way, from the most
  specific to most broad.
  
  Measure       — Represents a single measure for an area, e.g. 
   |              population. Contains a human-readable label and a map of 
   |              the measure accross a number of years.
   |
   +-> Area       Represents an area in Wales. Contains a unique local
        |         authority code used in national statistics, a map of the 
        |         names of the area (i.e. in English and Welsh), and a map of
        |         various Measure objects.
        |
        +-> Areas A simple class that contains a map of all Area objects, 
                  indexed by the local authority code. This is derived from
                  the DataContainer class, which is an abstract type. 
                  DataContainer exists so that in future we can expand our
                  code to include areas broken down by different groupings
                  instead of geographic areas.
 */

#include <map>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <unordered_set>
#include <variant>





// Enums (short for enumerations) are similar to their Java implementation.
// It is a user-defined type, used to assign names to internal constants
// in code, instead of simply passing in integers/strings etc.
// 
// For example, functions can take a value/constant from a specific enum
// and use it in a switch statement, doing different things 
//
// As such, it is a useful way for us to specify information in both a 
// machine and human-readable format.
//
// Unlike Java, enum in C++ only map to intenger values. You can either let
// the compiler generate the values automatically, in which it allocates a 
// unique integer (0-indexed). Or, you can set the value by giving the name
// followed by = <value> (e.g. XLSX=4).
//
// This enum specifies the format types that the InputSource class can parse.
// We could have implemented an if statement that parsed a string for the data
// type, or perhaps used integers. But with a enum both in code and to anyone
// who just glances at the code can infer the meaning.
enum DataType {
  None, AuthorityCodeCSV, WelshStatsJSON
};





// Data from the different sources typically has different column headings
// for the same value (e.g. some might say "Year" whereas others might say
// "Year_Code"). Here we create another enum for these column headings for
// the parser.

// Each input passed to the Areas() object will have to specifiy a 
// an unordered map to match each of these enum values into a string that
// the source contains.
enum SourceColumns {
  AUTH_CODE, AUTH_NAME, MEASURE_CODE, MEASURE_NAME, YEAR, VALUE
};

using SourceColumnsMatch = std::unordered_map<SourceColumns,std::string>;





// For each set of data, we have a value for each individual measure over
// several years. Therefore, we will contain this in a "Measure" class, along
// with a human-readable label.
//
// For example, if we had population size, we might have a mLabel "Population",
// and in mDataByYear, we would have numerous years (as keys) with the size of 
// the population in the second pair part/value of the map.
//
// For the values, we make use of std::variant, which is a C++17 feature that 
// implements a "union". It allows us to state that the type of the value
// will be one of any number of given types. To keep our code simple, we
// define, using the using keyword, the type for this data.
using Measure_t = std::variant<int, double, std::string>;

// We derive Measure_c as the container for the year:value mappings
using Measure_c = std::map<int, Measure_t>;

// Becayse of the way std::variant is implemented in C++, we need to write 
// a function that converts the values from std::variant in the above map 
// (mDataByYear) and returns them as a std::string
//
// For the coursework, you can ignore how this and just assume it works! :)
struct MeasureValueToString {
  std::string operator()(int value) { return std::to_string(value); }
  std::string operator()(double value) { return std::to_string(value); }
  std::string operator()(const std::string& value) { return value; }
};


// Finally, we have the Measure class
class Measure {
private:
  std::string mCode;
  std::string mLabel;
  Measure_c mData;

public:
  Measure(std::string &code, std::string &label);
  ~Measure() = default;
  friend std::ostream& operator<<(std::ostream &os, const Measure &st);
  
  Measure(const Measure& other)
      : mCode(other.mCode),
        mLabel(other.mLabel),
        mData(other.mData) {
    std::cout << "   > Copy Measure " << mLabel << std::endl;
  }
  Measure& operator=(const Measure& other) = default;
  Measure(Measure&& other) = default;
  Measure& operator=(Measure&& ither) = default;
  
  static std::string to_string(const Measure_t& input) {
    return std::visit(MeasureValueToString{}, input);
  }
  
  const std::string& getCode() const {
    return mCode;
  }
  
  const std::string& getLabel() const {
    return mLabel;
  }
  
  // Wrapper around underlying iterator functions for ease
  Measure_c::iterator begin() { return mData.begin(); }
  Measure_c::const_iterator cbegin() { return mData.begin(); }
  
  Measure_c::iterator end() { return mData.end(); }
  Measure_c::const_iterator cend() { return mData.cend(); }
  
  Measure_c::reverse_iterator rbegin() { return mData.rbegin(); }
  Measure_c::const_reverse_iterator crbegin() { return mData.crbegin(); }
  
  Measure_c::reverse_iterator rend() { return mData.rend(); }
  Measure_c::const_reverse_iterator crend() { return mData.crend(); }
  
  void emplace(const int &key, Measure_t &&value) {
    mData.emplace(key, std::move(value));
  }
  
  Measure_t& at(const int &year) { return mData.at(year); }
  size_t size() const noexcept { return mData.size(); }
};





// The area class stores the area-based data for Wales. We use local authority
// codes assigned by the Office for National Statistics and the name for the 
// area.
//
// We store the data in a std::map, where the key is a simple identifier for 
// the data (as a std::string) and the value is a Measure class.
using Area_c = std::map<std::string, Measure>;

class Area {
protected:
  std::string mLocalAuthorityCode;
  std::map<std::string, std::string> mNames;
  Area_c mMeasures;
  
public:
  Area(const std::string &localAuthorityCode);
  ~Area() = default;
  
  Area(const Area& other)
      : mLocalAuthorityCode(other.mLocalAuthorityCode),
        mNames(other.mNames),
        mMeasures(other.mMeasures){
    std::cout << ">> Copy Area " << getName("eng") << std::endl;
  }
  Area& operator=(const Area& other) = default;
  Area(Area&& other) = default;
  Area& operator=(Area&& ither) = default;

  const std::string& getLocalAuthorityCode() const;

  // Get/set name adds a name for a specific language using ISO 639-2/B codes
  void setName(const std::string &lang, const std::string &name);
  const std::string& getName(const std::string &lang) const;
  
  // TODO map: remove all these functions
  void emplace(std::string &ident, Measure &&stat) {
    mMeasures.emplace(ident, std::move(stat));
  }
  
  // Wrapper around underlying iterator functions for ease
  Area_c::iterator begin() { return mMeasures.begin(); }
  Area_c::const_iterator cbegin() { return mMeasures.begin(); }
  
  Area_c::iterator end() { return mMeasures.end(); }
  Area_c::const_iterator cend() { return mMeasures.cend(); }
  
  Area_c::reverse_iterator rbegin() { return mMeasures.rbegin(); }
  Area_c::const_reverse_iterator crbegin() { return mMeasures.crbegin(); }
  
  Area_c::reverse_iterator rend() { return mMeasures.rend(); }
  Area_c::const_reverse_iterator crend() { return mMeasures.crend(); }
  
  Measure& at(const std::string &ident) { return mMeasures.at(ident); }  
  size_t size() const noexcept { return mMeasures.size(); }
  
  friend bool operator==(const Area &lhs, const Area &rhs);
  friend bool operator!=(const Area &lhs, const Area &rhs);
  friend bool operator<(const Area &lhs, const Area &rhs);
};





// Generic Data class. All of our containers will inherit from this class, which
// will in turn contain data inside an STL container. Note this this innter
// container is unspecified at this stage (i.e. we will use the template type
// T).
//
// Data containers are a simple container class for an STL Container. When 
// default constructed, the data should be empty, but they can be constructed
// used the copy and move constructors, and from a stream.
// template <class T>
class DataContainer {
protected:
  DataContainer() = default;

  DataContainer(const DataContainer& other) = delete;
  DataContainer& operator=(const DataContainer& other) = delete;
  DataContainer(DataContainer&& other) = delete;
  DataContainer& operator=(DataContainer&& ither) = delete;

public:
  virtual ~DataContainer() = default;

  // Parses the list of Welsh areas used in the statistics website, including
  // their local authority code, English, and Welsh names.
  virtual void populate(
      std::istream &is,
      const DataType &type,
      const SourceColumnsMatch &cols) noexcept(false) = 0;
  
  // Same as above, but limiting the range to a select number of measures
  // and years.
  virtual void populate(
      std::istream &is,
      const DataType &type,
      const SourceColumnsMatch &cols,
      const std::unordered_set<std::string> &measures,
      const std::tuple<unsigned int,unsigned int> &years) noexcept(false) = 0;
};







// We store the each area in a set
using Areas_c = std::map<std::string, Area>;

// A class that stores all areas.
template <class Container = Areas_c>
class Areas : public DataContainer {

private:
  Areas();

protected:
  Areas_c mAreas;

public:
  virtual ~Areas() = default;

  Areas(const Areas& other) = delete;
  Areas& operator=(const Areas& other) = delete;
  Areas(Areas&& other) = delete;
  Areas& operator=(Areas&& ither) = delete;
  
  // This implements the Singleton design principle. We have a private 
  // constructor which means Areas can only be constructed from within.
  // Only one function in this class will actually construct an Areas()
  // object, getInstance(). On the first time this function is called,
  // getInstance() will instantiate an Areas() object, and save it to a 
  // local static variable. That means each successive time getInstance()
  // is called, the same instance will be returned.
  static Areas &getInstance() {
    static Areas instance;
    return instance;
  }

  // Parses the list of Welsh areas used in the statistics website, including
  // their local area code, English, and Welsh names as a CSV file.
  virtual void populateFromAuthorityCodeCSV(
      std::istream &is,
      const SourceColumnsMatch &cols) noexcept(false);
  
  // Parse the data files from the statistics website.
  virtual void populateFromWelshStatsJSON(
      std::istream &is,
      const SourceColumnsMatch &cols,
      const std::unordered_set<std::string> * const measures = nullptr,
      const std::tuple<unsigned int,unsigned int> * const years = nullptr)
        noexcept(false);

  // Parses the list of Welsh areas used in the statistics website, including
  // their local area code, English, and Welsh names.
  virtual void populate(
      std::istream &is,
      const DataType &type,
      const SourceColumnsMatch &cols) noexcept(false);
  
  // Same as above, but limiting the range to a select number of measures
  // and years.
  virtual void populate(
      std::istream &is,
      const DataType &type,
      const SourceColumnsMatch &cols,
      const std::unordered_set<std::string> &measures,
      const std::tuple<unsigned int,unsigned int> &years) noexcept(false);
  
  // Wrapper around underlying iterator functions for ease
  // TODO map: remove all of these
  void emplace(std::string &ident, Area &&stat) {
    mAreas.emplace(ident, std::move(stat));
  }
  
  Areas_c::iterator begin() { return mAreas.begin(); }
  Areas_c::const_iterator cbegin() { return mAreas.begin(); }
  
  Areas_c::iterator end() { return mAreas.end(); }
  Areas_c::const_iterator cend() { return mAreas.cend(); }
  
  Areas_c::reverse_iterator rbegin() { return mAreas.rbegin(); }
  Areas_c::const_reverse_iterator crbegin() { return mAreas.crbegin(); }
  
  Areas_c::reverse_iterator rend() { return mAreas.rend(); }
  Areas_c::const_reverse_iterator crend() { return mAreas.crend(); }
  
  Area& at(const std::string &areaCode) { return mAreas.at(areaCode); }
  size_t size() const noexcept { return mAreas.size(); }
};


#endif // PARSE_H_