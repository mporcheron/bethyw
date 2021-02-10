


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <STUDENT NUMBER>

  This file contains the implementation for the Area class. Area are relatively
  simple classes that contain a local authority code, a container of names in
  different languages (perhaps stored in an associative container?) and a series
  of Measure objects (also in some form of container).

  This file contains numerous functions you must implement. Each function you
  must implement has a TODO block comment. 
*/

#include "area.h"

/*
  TODO: Area::Area(localAuthorityCode)

  Construct an Area with a given local authority code.

  @param localAuthorityCode
    The local authority code of the Area

  @example
    Area("W06000023");
*/
Area::Area(const std::string &localAuthorityCode) {
  throw std::logic_error("Area::Area() has not been implemented!");
}

/*
  TODO: Area::getLocalAuthorityCode()

  Retrieve the local authority code for this Area. This function should be 
  callable from a constant context.
  
  @return
    The Area's local authority code

  @example
    Area area("W06000023");
    ...
    auto authCode = area.getLocalAuthorityCode();
*/
const std::string &Area::getLocalAuthorityCode() const {
  throw std::logic_error(
    "Area::getLocalAuthorityCode() has not been implemented!");
}

/*
  TODO: Area::getName(lang)

  Get a name for the Area in a specific language. This function should be 
  callable from a constant context.

  @param lang
    A three-leter language code in ISO 639-2/B format, e.g. cym or eng

  @return
    The name for the area in the given language

  @throws
    std::out_of_range if lang is not a set language

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    ...
    auto name = area.getName("eng");
*/
const std::string &Area::getName(std::string lang) const {
  throw std::logic_error("Area::getName() has not been implemented!");}

/*
  TODO: Area::setName(lang, name)

  Set a name for the Area in a specific language.

  @param lang
    A three-letter (alphabetical) language code in ISO 639-2/B format,
    e.g. cym or eng, which should be converted to lowercase

  @param name
    The name of the Area in this language

  @throws
    std::invalid_argument if lang is not a three letter alphabetic code

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    area.setName("cym", "Powys");
*/
void Area::setName(std::string lang, const std::string &name) {
  throw std::logic_error("Area::setName() has not been implemented!");}

/*
  TODO: Area::getMeasure(key)

  Retrieve a Measure object given its codename. This function should be case
  insensitive.

  @param key
    The codename for the measure you want to retrieve

  @return
    A Measure object

  @throws
    std::out_of_range if there is no measure with the given code with message:
    No measure found matching <codename>

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");

    Measure measure("Pop", "Population");
    area.setMeasure("Pop", measure);
    ...
    auto measure2 = area.at("pop");
*/
Measure &Area::getMeasure(std::string key) {
  throw std::logic_error("Area::getMeasure() has not been implemented!");
}

/*
  TODO: Area::setMeasure(codename, measure)

  Add a particular Measure to this Area object. Note that the Measure's
  codename should be converted to lowercase.

  If a Measure already exists with the same codename in this Area, overwrite any
  values contained within the existing Measure with those in the new Measure
  passed into this function. The resulting Measure should be a combination of
  the two Measures instances.

  @param key
    The codename for the Measure

  @param measure
    The Measure object

  @return
    void

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");

    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    double value = 12345678.9;
    measure.setValue(1999, value);

    area.setMeasure(code, measure);
*/
void Area::setMeasure(std::string key, Measure &value) {
  throw std::logic_error("Area::setMeasure() has not been implemented!");}

/*
  TODO: Area::size()

  Retrieve the number of Measures we have for this Area. This function
  should not modify the object or throw an exception.

  @return
    The size of the Area (i.e. the number of Measures)

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");

    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    area.setMeasure(code, measure);
    auto size = area.size();
*/
size_t Area::size() const noexcept {
  return 0;
}

/*
  TODO: operator<<(os, area)

  Overload the stream output operator.

  Output the name of the Area in English and Welsh, followed by the local
  authority code. Then output all the measures for the area.

  If the Area only has only one name, output this. If the area has no names,
  output the name "Unnamed".

  Measures should be ordered by their Measure codename.

  See the coursework specification for more examples.

  @param os
    The output stream to write to

  @param area
    Area to write to the output stream

  @return
    Reference to the output stream

  @example
    Area area("W06000023");
    area.setName("eng", "Powys");
    std::cout << area << std::end;
*/
std::ostream &operator<<(std::ostream &os, const Area &area) {
  return os;
}

/*
  TODO: operator==(lhs, rhs)

  Overload the == operator for two Area objects. Two Area objects
  are only equal when their local authority code, all names, and all data are
  equal.

  @param lhs
    An Area object

  @param lhs
    A second Area object

  @return
    true if both Area instanes have the same local authority code, names
    and data; false otherwise.

  @example
    Area area1("MYCODE1");
    Area area2("MYCODE1");

    bool eq = area1 == area2;
*/
bool operator==(const Area &lhs, const Area &rhs) {
  return false;
}
