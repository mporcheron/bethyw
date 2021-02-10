


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  Catch2 test script — https://github.com/catchorg/Catch2
  Catch2 is licensed under the BOOST license.
 */

#include "../lib_catch.hpp"

#include <fstream>
#include <string>

#include "../datasets.h"
#include "../areas.h"

SCENARIO( "popu1009.json can be correctly parsed [extended for non-lowercase]", "[Areas][popu1009][extended]" ) {

  auto get_istream = [](const std::string &path) {
    return std::ifstream(path);
  };

  GIVEN( "a newly constructed Areas instance" ) {

    Areas areas = Areas();

    AND_GIVEN( "a valid popu1009.json file as an open std::istream" ) {

      const std::string test_file = "datasets/popu1009.json";
      auto stream                 = get_istream(test_file);

      REQUIRE( stream.is_open() );

      THEN( "the Areas instance will be populated without exception" ) {

        REQUIRE_NOTHROW( areas.populateFromWelshStatsJSON(stream, BethYw::InputFiles::DATASETS[0].COLS, nullptr, nullptr, nullptr) );

        AND_THEN( "the Areas instance has size 12" ) {

          REQUIRE( areas.size() == 12 );

        } // AND_THEN

        AND_THEN( "each Measure in each Area in the Areas instance has correct size (mixed) [non-lowercase measure]" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("Area").size() == 29 );

          REQUIRE( areas.getArea("W06000001").getMeasure("Dens").size() == 29 );

          REQUIRE( areas.getArea("W06000001").getMeasure("Pop").size() == 29 );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN
  
} // SCENARIO