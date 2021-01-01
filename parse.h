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
#include <string>
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
  std::string mLabel;
  std::map<int, Measure_t> mDataByYear;

public:
  Measure(std::string &label);
  ~Measure() = default;
  void addDatum(const int &key, const Measure_t &value);
  friend std::ostream& operator<<(std::ostream &os, const Measure &st);
  
  Measure(const Measure& other) : mLabel(other.mLabel), mDataByYear(other.mDataByYear) {
    std::cout << "   > Copy Measure " << mLabel << std::endl;
  }
  Measure& operator=(const Measure& other) = default;
  Measure(Measure&& other) = default;
  Measure& operator=(Measure&& ither) = default;
  
  static std::string to_string(const Measure_t& input) {
    return std::visit(MeasureValueToString{}, input);
  }
};





// The area class stores the area-based data for Wales. We use local authority
// codes assigned by the Office for National Statistics and the name for the 
// area.
//
// We store the data in a std::map, where the key is a simple identifier for 
// the data (as a std::string) and the value is a Measure class.
class Area {
protected:
  std::string mLocalAuthorityCode;
  std::map<std::string, std::string> mNames;
  std::map<std::string, Measure> mMeasures;
  
public:
  Area(const std::string &localAuthorityCode);
  ~Area() = default;
  
  Area(const Area& other) : mLocalAuthorityCode(other.mLocalAuthorityCode), mNames(other.mNames), mMeasures(other.mMeasures){
    std::cout << ">> Copy Area " << getName("eng") << std::endl;
  }
  Area& operator=(const Area& other) = default;
  Area(Area&& other) = default;
  Area& operator=(Area&& ither) = default;

  const std::string& getLocalAuthorityCode() const;

  // Get/set name adds a name for a specific language using ISO 639-2/B codes
  void setName(const std::string &lang, const std::string &name);
  const std::string& getName(const std::string &lang) const;
  
  void addMeasure(std::string &ident, Measure &stat);
  Measure& getMeasure(std::string &ident);
  std::map<std::string, Measure>& getAllMeasures();
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
  virtual void populate(std::istream &is, const DataType &type) noexcept(false) 
                                                                            = 0;
};







// A class that stores all areas.
typedef std::map<std::string, Area> AreasContainer;
template <class Container = AreasContainer>
class Areas : public DataContainer {
protected:
  Container mData; // TODO map: remove details

public:
  Areas();
  virtual ~Areas() = default;

  Areas(const Areas& other) = delete;
  Areas& operator=(const Areas& other) = delete;
  Areas(Areas&& other) = delete;
  Areas& operator=(Areas&& ither) = delete;
  
  // Parses the list of Welsh areas used in the statistics website, including
  // their local area code, English, and Welsh names as a CSV file.
  virtual void populateFromAuthorityCodeCSV(std::istream &is) noexcept(false);
  
  // Parse the data files from the statistics website.
  virtual void populateFromWelshStatsJSON(std::istream &is) noexcept(false);

  // Parses the list of Welsh areas used in the statistics website, including
  // their local area code, English, and Welsh names.
  virtual void populate(std::istream &is, const DataType &type) noexcept(false);

  // Various simple getters.
  Container& getAllAreas() {
    return mData;
  }

  Area& getArea(const std::string &areaCode);
  const int size() const;
};




#endif // PARSE_H_