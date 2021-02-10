


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  Catch2 test script — https://github.com/catchorg/Catch2
  Catch2 is licensed under the BOOST license.
 */

#include "../lib_catch.hpp"

#include <string>

#include "../area.h"

SCENARIO( "an Area instance throws an exception when the language code is not three letters", "[Area][setName][exception]" ) {

  GIVEN( "a newly constructed Area instance" ) {

    std::string localAuthorityCode = "W06000011";
    Area area(localAuthorityCode);

    THEN( "the Area instance will throw an exception when given invalid language code" ) {

      REQUIRE_THROWS_AS( area.setName("test", "testing"), std::invalid_argument );
      REQUIRE_THROWS_AS( area.setName("123", "testing"), std::invalid_argument );
      REQUIRE_THROWS_AS( area.setName("te1", "testing"), std::invalid_argument );
      
    } // THEN

  } // GIVEN

} // SCENARIO