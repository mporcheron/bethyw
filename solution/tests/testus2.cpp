


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  Catch2 test script — https://github.com/catchorg/Catch2
  Catch2 is licensed under the BOOST license.
 */

#include "../lib_catch.hpp"

#include <stdexcept>
#include <string>

#include "../measure.h"

SCENARIO( "a Measure object can be populated with values [extended]", "[Measure][populate][extended]" ) {

  GIVEN( "a newly constructed Measure instance" ) {

    const std::string codename = "pop";
    const std::string label = "Population";
    Measure measure(codename, label);

    WHEN( "there are two year:value pairs to insert, both with the same year" ) {

      const int year1     = 2010;
      const double value1 = 1000;
      const int year2     = 2010;
      const double value2 = 2000;

      THEN( "they will both be emplaced without exception" ) {

        REQUIRE_NOTHROW( measure.setValue(year1, value1) );
        REQUIRE_NOTHROW( measure.setValue(year2, value2) );

        AND_THEN( "the second value will have replaced the first value" ) {

          REQUIRE( measure.getValue(year2) == value2 );

        } // AND_THEN

      } // THEN

    } // WHEN

  } // GIVEN

} // SCENARIO

