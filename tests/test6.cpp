


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
#include <unordered_map>

#include "../data.h"

SCENARIO( "an Area instance be constructed with a local authority code", "[Area][construct]" ) {

  GIVEN( "a local authority code as a std::string" ) {

    std::string localAuthorityCode = "W06000011";

    THEN( "an Area instance can be constructed" ) {

      REQUIRE_NOTHROW( Area(localAuthorityCode) );

    } // THEN
    
  } // GIVEN

} // SCENARIO

SCENARIO( "an Area instance can have names in multiple languages", "[Area][names]" ) {

  GIVEN( "a newly constructed Area instance" ) {

    std::string localAuthorityCode = "W06000011";
    Area area(localAuthorityCode);

    THEN( "the local authority code can be retrieved" ) {

      REQUIRE( area.getLocalAuthorityCode() == localAuthorityCode );

    } // THEN

    THEN( "names in multiple languages can be set" ) {
      
      auto langCode = GENERATE( as<std::string>{}, "eng", "cym" );
      auto name     = GENERATE( as<std::string>{}, "Name in English", "Name in Welsh" );

      REQUIRE_NOTHROW( area.setName(langCode, name) );
      REQUIRE( area.getName(langCode) == name );

    } // THEN

    THEN( "language codes are converted to lower case" ) {
      
      const std::string name = "Name";

      REQUIRE_NOTHROW( area.setName("eNg", name) );
      REQUIRE( area.getName("eng") == name );

    } // THEN

    const std::string exceptionMessage = "Area::setName: Language code must be three alphabetical letters only";
    
    THEN( "setting a name with a non-three letter code throws an std::invalid_argumet with the message " + exceptionMessage ) {

      auto langCode          = GENERATE( as<std::string>{}, "", "test", "123" );
      const std::string name = "Name";

      REQUIRE_THROWS_AS( area.setName(langCode, name), std::invalid_argument );
      REQUIRE_THROWS_WITH( area.setName(langCode, name), exceptionMessage );

    } // THEN

    THEN( "the object contains no Measures" ) {

      REQUIRE_NOTHROW( area.size() == 0 );

    } // THEN

  } // GIVEN

} // SCENARIO

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

        REQUIRE_NOTHROW( area.emplace(codename, measure) );

        AND_THEN( "the Area instance size will be 1" ) {

          REQUIRE( area.size() == 1 );

        } // AND_THEN

        AND_THEN( "the Measure instance can be retrieved without exception with a lowercase codename" ) {

          REQUIRE_NOTHROW( area.at(codenameLower) );

        } // AND_THEN

        AND_THEN( "the Measure instance is equal to the original" ) {

          Measure &newMeasure = area.at(codenameLower);
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

        REQUIRE_NOTHROW( area.emplace(codename1, measure1) );
        REQUIRE_NOTHROW( area.emplace(codename2, measure2) );

        AND_THEN( "the Area instance size will be 2" ) {

          REQUIRE( area.size() == 2 );

        } // AND_THEN

        AND_THEN( "the Measure instances can be retrieved without exception" ) {

          REQUIRE_NOTHROW( area.at(codename1) );
          REQUIRE_NOTHROW( area.at(codename2) );

        } // AND_THEN

        AND_THEN( "the Measure instances are equal to the original" ) {

          Measure &newMeasure1 = area.at(codename1);
          REQUIRE( measure1 == newMeasure1 );

          Measure &newMeasure2 = area.at(codename2);
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

      measure1.emplace(year1, value1);
      measure1.emplace(year2, value2);

      measure2.emplace(year2, value2a);
      measure2.emplace(year3, value3);

      THEN( "the Measure instance2 can be emplace into the Area instance without exception" ) {

        REQUIRE_NOTHROW( area.emplace(codename, measure1) );
        REQUIRE_NOTHROW( area.emplace(codename, measure2) );

        AND_THEN( "the Area instance size will be 1" ) {

          REQUIRE( area.size() == 1 );

        } // AND_THEN

        AND_THEN( "the Measure instance can be retrieved without exception" ) {

          REQUIRE_NOTHROW( area.at(codename) );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have the second Measure instance's label" ) {

          Measure &newMeasure = area.at(codename);
          REQUIRE( newMeasure.getLabel() == label2 );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have non-overlapping data from the first Measure instance" ) {

          Measure &newMeasure = area.at(codename);
          REQUIRE( newMeasure.at(year1) == value1 );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have non-overlapping data from the second Measure instance" ) {

          Measure &newMeasure = area.at(codename);
          REQUIRE( newMeasure.at(year3) == value3 );

        } // AND_THEN

        AND_THEN( "the Measure instance returned will have overlapping data from the second Measure instance" ) {

          Measure &newMeasure = area.at(codename);
          REQUIRE( newMeasure.at(year2) != value2 );
          REQUIRE( newMeasure.at(year2) == value2a );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN

} // SCENARIO