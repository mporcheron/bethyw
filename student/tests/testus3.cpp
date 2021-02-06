


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  Catch2 test script — https://github.com/catchorg/Catch2
  Catch2 is licensed under the BOOST license.
 */

#include "../catch.hpp"

#include <fstream>

#include "../datasets.h"
#include "../areas.h"
#include "../area.h"

SCENARIO( "an Areas instance can contain Area instances [extended]", "[Areas][contain][extended]" ) {

  GIVEN( "a newly constructed Areas" ) {

    Areas areas;
    
    AND_GIVEN( "two newly constructed Area instances with the same local authority codes ('W06000011') but overlapping Measures" ) {
      
      std::string localAuthorityCode = "W06000011";
      Area area1(localAuthorityCode);
      Area area2(localAuthorityCode);
      Area areaCombined(localAuthorityCode);

      const std::string codename1 = "pop";
      const std::string label1 = "Population";
      Measure measure1(codename1, label1);
      
      const std::string codename2 = "dens";
      const std::string label2 = "Population density";
      Measure measure2(codename2, label2);
      
      area1.setMeasure(codename1, measure1);
      area2.setMeasure(codename2, measure2);
      
      areaCombined.setMeasure(codename1, measure1);
      areaCombined.setMeasure(codename2, measure2);
      
      THEN( "the Area instances can be emplaced in the Areas instance without exception" ) {

        REQUIRE_NOTHROW( areas.setArea(localAuthorityCode, area1) );
        REQUIRE_NOTHROW( areas.setArea(localAuthorityCode, area2) );

        AND_THEN( "the names of the second Area instances will overwrite the first" ) {

          Area &newArea = areas.getArea(localAuthorityCode);
          
          REQUIRE( newArea == areaCombined );

        } // AND_THEN

      } // THEN
    
    } // AND_GIVEN

  } // THEN

} // SCENARIO
