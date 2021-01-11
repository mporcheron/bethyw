


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  Catch2 test script — https://github.com/catchorg/Catch2
  Catch2 is licensed under the BOOST license.
 */

#include "../libs/catch2/catch.hpp"

#include <string>

#include "../data.h"

SCENARIO( "an Area instance can contain Measure instances", "[Area][names]" ) {

  GIVEN( "a newly constructed Area instance" ) {

    std::string localAuthorityCode = "W06000011";
    Area area(localAuthorityCode);

    AND_GIVEN( "a newly constructed Measure instance ('{op')" ) {

      const std::string codename      = "Pop";
      const std::string codenameLower = "pop";
      const std::string label         = "Population";
      Measure measure(codename, label);

      THEN( "the Measure instance can be emplace into the Area instance without exception" ) {

        REQUIRE_NOTHROW( area.setMeasure(codename, measure) );

        AND_THEN( "the Area instance size will be 1" ) {

          REQUIRE( area.size() == 1 );

        } // AND_THEN

        AND_THEN( "the Measure instance can be retrieved without exception with a lowercase codename" ) {

          REQUIRE_NOTHROW( area.getMeasure(codenameLower) );

        } // AND_THEN

        AND_THEN( "the Measure instance is equal to the original" ) {

          Measure &newMeasure = area.getMeasure(codenameLower);
          REQUIRE( measure == newMeasure );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

    AND_GIVEN( "two newly constructed Measure instances with two different codenames ('pop', 'dens')" ) {

      const std::string codename1 = "pop";
      const std::string label1 = "Population";
      Measure measure1(codename1, label1);
      
      const std::string codename2 = "dens";
      const std::string label2 = "Population density";
      Measure measure2(codename2, label2);

      THEN( "the Measure instance2 can be emplace into the Area instance without exception" ) {

        REQUIRE_NOTHROW( area.setMeasure(codename1, measure1) );
        REQUIRE_NOTHROW( area.setMeasure(codename2, measure2) );

        AND_THEN( "the Area instance size will be 2" ) {

          REQUIRE( area.size() == 2 );

        } // AND_THEN

        AND_THEN( "the Measure instances can be retrieved without exception" ) {

          REQUIRE_NOTHROW( area.getMeasure(codename1) );
          REQUIRE_NOTHROW( area.getMeasure(codename2) );

        } // AND_THEN

        AND_THEN( "the Measure instances are equal to the original" ) {

          Measure &newMeasure1 = area.getMeasure(codename1);
          REQUIRE( measure1 == newMeasure1 );

          Measure &newMeasure2 = area.getMeasure(codename2);
          REQUIRE( measure2 == newMeasure2 );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

    AND_GIVEN( "two newly constructed Measure instances with the same codenames ('pop') and overlapping data" ) {

      const std::string codename = "pop";

      const std::string label1 = "Population";
      const std::string label2 = "My new population";

      const int year1   = 2010;
      const int value1  = 1000;

      const int year2   = 2011;
      const int value2  = 2000;
      const int value2a = 4000;

      const int year3   = 2012;
      const int value3  = 3000;

      Measure measure1(codename, label1);
      Measure measure2(codename, label2);

      measure1.setValue(year1, value1);
      measure1.setValue(year2, value2);

      measure2.setValue(year2, value2a);
      measure2.setValue(year3, value3);

      THEN( "the Measure instance2 can be emplace into the Area instance without exception" ) {

        REQUIRE_NOTHROW( area.setMeasure(codename, measure1) );
        REQUIRE_NOTHROW( area.setMeasure(codename, measure2) );

        AND_THEN( "the Area instance size will be 1" ) {

          REQUIRE( area.size() == 1 );

        } // AND_THEN

        AND_THEN( "the Measure instance can be retrieved without exception" ) {

          REQUIRE_NOTHROW( area.getMeasure(codename) );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have the second Measure instance's label" ) {

          Measure &newMeasure = area.getMeasure(codename);
          REQUIRE( newMeasure.getLabel() == label2 );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have non-overlapping data from the first Measure instance" ) {

          Measure &newMeasure = area.getMeasure(codename);
          REQUIRE( newMeasure.getValue(year1) == value1 );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have non-overlapping data from the second Measure instance" ) {

          Measure &newMeasure = area.getMeasure(codename);
          REQUIRE( newMeasure.getValue(year3) == value3 );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have overlapping data from the second Measure instance" ) {

          Measure &newMeasure = area.getMeasure(codename);
          REQUIRE( newMeasure.getValue(year2) != value2 );
          REQUIRE( newMeasure.getValue(year2) == value2a );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN

} // SCENARIO