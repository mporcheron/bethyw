


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
#include <string>

#include "../datasets.h"
#include "../areas.h"

SCENARIO( "tran0152.json can be correctly parsed", "[Areas][tran0152]" ) {

  auto get_istream = [](const std::string &path) {
    return std::ifstream(path);
  };

  GIVEN( "a newly constructed Areas instance" ) {

    Areas areas = Areas();

    AND_GIVEN( "a valid tran0152.json file as an open std::istream" ) {

      const std::string test_file = "datasets/tran0152.json";
      auto stream                 = get_istream(test_file);

      REQUIRE( stream.is_open() );

      THEN( "the Areas instance will be populated without exception" ) {

        REQUIRE_NOTHROW( areas.populateFromWelshStatsJSON(stream, BethYw::InputFiles::DATASETS[3].COLS, nullptr, nullptr, nullptr) );

        AND_THEN( "the Areas instance has size 26" ) {

          REQUIRE( areas.size() == 26 );

        } // AND_THEN

        AND_THEN( "each Area in the Areas instance has the correct size (1)" ) {

          REQUIRE( areas.getArea("W06000001").size() == 1 );
          REQUIRE( areas.getArea("W06000002").size() == 1 );
          REQUIRE( areas.getArea("W06000003").size() == 1 );
          REQUIRE( areas.getArea("W06000004").size() == 1 );
          REQUIRE( areas.getArea("W06000005").size() == 1 );
          REQUIRE( areas.getArea("W06000006").size() == 1 );
          REQUIRE( areas.getArea("W06000008").size() == 1 );
          REQUIRE( areas.getArea("W06000009").size() == 1 );
          REQUIRE( areas.getArea("W06000010").size() == 1 );
          REQUIRE( areas.getArea("W06000011").size() == 1 );
          REQUIRE( areas.getArea("W06000012").size() == 1 );
          REQUIRE( areas.getArea("W06000013").size() == 1 );
          REQUIRE( areas.getArea("W06000014").size() == 1 );
          REQUIRE( areas.getArea("W06000015").size() == 1 );
          REQUIRE( areas.getArea("W06000016").size() == 1 );
          REQUIRE( areas.getArea("W06000018").size() == 1 );
          REQUIRE( areas.getArea("W06000019").size() == 1 );
          REQUIRE( areas.getArea("W06000020").size() == 1 );
          REQUIRE( areas.getArea("W06000021").size() == 1 );
          REQUIRE( areas.getArea("W06000022").size() == 1 );
          REQUIRE( areas.getArea("W06000023").size() == 1 );
          REQUIRE( areas.getArea("W06000024").size() == 1 );
          REQUIRE( areas.getArea("W19000001").size() == 1 );
          REQUIRE( areas.getArea("W19000004").size() == 1 );
          REQUIRE( areas.getArea("W92000004").size() == 1 );
          REQUIRE( areas.getArea("WXX000002").size() == 1 );

        } // AND_THEN

        AND_THEN( "each Measure in each Area in the Areas instance has the correct size (mixed)" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").size() == 17 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").size() == 17 );

        } // AND THEN

        AND_THEN( "each Measure in each Area in the Areas instance has the correct value (mixed)" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2002) == 64405.5 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2003) == 63205.5 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2004) == 60786.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2005) == 61223.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2006) == 68474.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2007) == 67318.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2008) == 55129.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2009) == 55533.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2010) == 58806.5 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2011) == 72391.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2012) == 71168.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2013) == 69523.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2014) == 67820.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2015) == 66592.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2016) == 64568.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2017) == 66689.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rail").getValue(2018) == 65883.0 );

          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2002) == 495433.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2003) == 505109.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2004) == 474339.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2005) == 464461.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2006) == 458504.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2007) == 567560.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2008) == 505054.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2009) == 529866.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2010) == 547619.5 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2011) == 568371.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2012) == 536432.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2013) == 472999.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2014) == 502141.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2015) == 561940.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2016) == 538758.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2017) == 542952.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rail").getValue(2018) == 555045.0 );

          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2002) == 263944.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2003) == 277374.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2004) == 248209.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2005) == 248170.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2006) == 260726.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2007) == 289620.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2008) == 303406.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2009) == 327286.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2010) == 355909.5 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2011) == 383181.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2012) == 378387.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2013) == 373073.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2014) == 353376.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2015) == 325794.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2016) == 313033.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2017) == 318795.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rail").getValue(2018) == 329429.0 );

          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2002) == 171358.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2003) == 175311.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2004) == 169003.5 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2005) == 169683.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2006) == 204783.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2007) == 211475.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2008) == 254309.5 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2009) == 259822.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2010) == 262846.99999 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2011) == 284120.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2012) == 282817.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2013) == 282980.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2014) == 247587.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2015) == 237023.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2016) == 230469.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2017) == 222616.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rail").getValue(2018) == 217189.0 );

          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2002) == 120880.5 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2003) == 129588.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2004) == 125396.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2005) == 119476.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2006) == 118240.5 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2007) == 128141.5 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2008) == 134080.5 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2009) == 143580.5 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2010) == 146612.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2011) == 158823.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2012) == 158174.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2013) == 157661.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2014) == 149721.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2015) == 145009.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2016) == 135282.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2017) == 126812.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rail").getValue(2018) == 118945.0 );

          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2002) == 107502.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2003) == 115375.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2004) == 114205.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2005) == 111603.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2006) == 117099.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2007) == 130580.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2008) == 148347.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2009) == 167146.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2010) == 171085.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2011) == 181352.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2012) == 185495.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2013) == 183653.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2014) == 170324.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2015) == 155915.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2016) == 147360.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2017) == 137357.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rail").getValue(2018) == 128059.0 );

          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2002) == 45031.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2003) == 48337.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2004) == 53226.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2005) == 63187.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2006) == 65860.5 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2007) == 71674.5 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2008) == 70311.5 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2009) == 80902.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2010) == 84395.5 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2011) == 85143.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2012) == 82315.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2013) == 75957.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2014) == 74089.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2015) == 88289.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2016) == 91858.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2017) == 95325.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rail").getValue(2018) == 85859.0 );

          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2002) == 119633.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2003) == 126246.5 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2004) == 128648.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2005) == 129405.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2006) == 147677.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2007) == 163596.5 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2008) == 169355.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2009) == 175995.5 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2010) == 189902.00001 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2011) == 205584.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2012) == 209237.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2013) == 210198.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2014) == 224394.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2015) == 218832.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2016) == 221970.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2017) == 217706.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rail").getValue(2018) == 213332.0 );

          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2002) == 314342.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2003) == 318446.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2004) == 330191.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2005) == 341403.5 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2006) == 362960.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2007) == 394865.5 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2008) == 424804.5 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2009) == 428922.5 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2010) == 461660.00001 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2011) == 478819.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2012) == 488659.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2013) == 480928.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2014) == 500910.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2015) == 498411.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2016) == 510780.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2017) == 493386.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rail").getValue(2018) == 473958.0 );

          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2002) == 483213.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2003) == 486588.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2004) == 482638.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2005) == 492177.5 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2006) == 559709.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2007) == 675331.5 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2008) == 772143.5 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2009) == 799166.5 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2010) == 852797.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2011) == 837559.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2012) == 848498.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2013) == 853520.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2014) == 884614.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2015) == 910878.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2016) == 914448.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2017) == 921736.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rail").getValue(2018) == 927841.0 );

          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2002) == 331150.5 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2003) == 334916.5 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2004) == 332312.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2005) == 332574.5 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2006) == 398316.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2007) == 465119.5 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2008) == 527378.5 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2009) == 554100.5 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2010) == 595304.99999 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2011) == 588700.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2012) == 603439.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2013) == 612583.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2014) == 624119.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2015) == 630894.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2016) == 622518.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2017) == 624088.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rail").getValue(2018) == 636648.0 );

          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2002) == 484026.5 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2003) == 543399.5 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2004) == 581725.5 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2005) == 655981.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2006) == 732386.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2007) == 823323.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2008) == 920504.5 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2009) == 941870.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2010) == 996008.49999 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2011) == 999193.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2012) == 985009.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2013) == 1160131.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2014) == 996239.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2015) == 1015275.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2016) == 1011850.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2017) == 1022102.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rail").getValue(2018) == 1032579.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2002) == 1022708.5 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2003) == 1038078.5 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2004) == 1027133.5 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2005) == 1182545.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2006) == 1296479.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2007) == 1381485.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2008) == 1406295.5 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2009) == 1388194.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2010) == 1412820.49999 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2011) == 1496071.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2012) == 1541840.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2013) == 1613460.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2014) == 1591876.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2015) == 1667483.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2016) == 1710500.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2017) == 1737788.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rail").getValue(2018) == 1789529.0 );

          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2002) == 4730870.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2003) == 4910371.5 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2004) == 5133400.5 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2005) == 5241435.5 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2006) == 5670668.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2007) == 6370185.5 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2008) == 6827560.5 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2009) == 7002814.5 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2010) == 7266364.49995 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2011) == 7380204.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2012) == 7500619.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2013) == 7733550.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2014) == 7995890.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2015) == 8470596.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2016) == 8758014.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2017) == 8982544.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rail").getValue(2018) == 9171249.0 );

          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2002) == 1759765.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2003) == 1850393.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2004) == 1883603.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2005) == 1861408.5 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2006) == 2002681.5 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2007) == 2138356.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2008) == 2230708.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2009) == 2333461.5 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2010) == 2334792.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2011) == 2327654.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2012) == 2337550.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2013) == 2355499.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2014) == 2335051.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2015) == 2319346.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2016) == 2462243.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2017) == 2454928.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rail").getValue(2018) == 2373410.0 );

          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2002) == 907687.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2003) == 911400.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2004) == 936902.5 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2005) == 922562.5 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2006) == 961872.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2007) == 1061672.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2008) == 1177442.5 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2009) == 1229200.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2010) == 1285820.49995 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2011) == 1314843.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2012) == 1324029.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2013) == 1372438.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2014) == 1414970.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2015) == 1409392.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2016) == 1463098.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2017) == 1496605.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rail").getValue(2018) == 1482916.0 );

          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2002) == 0.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2003) == 0.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2004) == 0.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2005) == 0.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2006) == 0.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2007) == 25913.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2008) == 144155.5 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2009) == 147574.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2010) == 158045.99999 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2011) == 157860.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2012) == 160294.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2013) == 163151.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2014) == 160275.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2015) == 168385.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2016) == 182746.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2017) == 185315.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rail").getValue(2018) == 175532.0 );

          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2002) == 90428.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2003) == 90453.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2004) == 96041.5 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2005) == 90563.5 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2006) == 104823.5 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2007) == 117869.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2008) == 123676.5 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2009) == 145964.5 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2010) == 148378.5 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2011) == 154704.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2012) == 161968.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2013) == 167889.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2014) == 168757.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2015) == 179782.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2016) == 185832.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2017) == 187275.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rail").getValue(2018) == 182364.0 );

          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2002) == 140524.5 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2003) == 149782.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2004) == 163522.5 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2005) == 167587.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2006) == 181327.5 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2007) == 193341.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2008) == 199665.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2009) == 211241.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2010) == 216382.5 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2011) == 222306.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2012) == 222577.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2013) == 224542.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2014) == 228752.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2015) == 247331.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2016) == 255295.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2017) == 257446.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rail").getValue(2018) == 258633.0 );

          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2002) == 477381.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2003) == 514985.5 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2004) == 537089.5 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2005) == 565369.5 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2006) == 604128.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2007) == 667952.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2008) == 683327.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2009) == 715964.5 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2010) == 746380.99999 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2011) == 726214.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2012) == 718151.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2013) == 744620.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2014) == 782299.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2015) == 870998.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2016) == 910044.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2017) == 930081.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rail").getValue(2018) == 958678.0 );

          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2002) == 66541.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2003) == 73830.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2004) == 75957.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2005) == 77122.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2006) == 82854.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2007) == 94276.5 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2008) == 96662.5 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2009) == 102039.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2010) == 107611.5 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2011) == 119283.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2012) == 116977.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2013) == 110873.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2014) == 113339.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2015) == 125538.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2016) == 130457.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2017) == 133671.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rail").getValue(2018) == 126303.0 );

          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2002) == 229052.5 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2003) == 195179.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2004) == 198217.5 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2005) == 189262.5 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2006) == 196020.5 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2007) == 196742.5 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2008) == 210567.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2009) == 259217.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2010) == 285325.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2011) == 295287.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2012) == 318348.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2013) == 372443.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2014) == 385521.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2015) == 392297.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2016) == 357006.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2017) == 336635.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rail").getValue(2018) == 329274.0 );

          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2002) == 1223524.5 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2003) == 1265963.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2004) == 1191939.5 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2005) == 1174617.5 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2006) == 1227827.5 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2007) == 1394696.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2008) == 1400327.5 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2009) == 1483235.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2010) == 1542879.99999 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2011) == 1648238.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2012) == 1612473.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2013) == 1539889.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2014) == 1490969.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2015) == 1492273.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2016) == 1429470.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2017) == 1415221.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rail").getValue(2018) == 1414550.0 );

          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2002) == 9842443.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2003) == 10204042.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2004) == 10557636.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2005) == 10876715.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2006) == 11750386.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2007) == 12976839.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2008) == 13923902.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2009) == 14375501.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2010) == 14850318.99986 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2011) == 15074336.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2012) == 15270385.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2013) == 15907723.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2014) == 16059630.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2015) == 16740885.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2016) == 17296628.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2017) == 17590719.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rail").getValue(2018) == 17754164.0 );

          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2002) == 12425878.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2003) == 12858369.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2004) == 13152547.5 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2005) == 13487202.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2006) == 14595590.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2007) == 16236399.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2008) == 17384885.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2009) == 17999862.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2010) == 18684869.99986 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2011) == 19037662.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2012) == 19231983.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2013) == 19791671.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2014) == 19972064.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2015) == 20706000.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2016) == 21218129.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2017) == 21491852.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rail").getValue(2018) == 21632655.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2002) == 1248338.5 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2003) == 1266197.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2004) == 1273789.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2005) == 1295560.5 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2006) == 1468662.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2007) == 1698913.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2008) == 1893681.5 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2009) == 1958185.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2010) == 2099664.00001 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2011) == 2110662.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2012) == 2149833.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2013) == 2157229.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2014) == 2234037.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2015) == 2259015.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2016) == 2269716.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2017) == 2256916.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rail").getValue(2018) == 2251779.0 );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN
  
} // SCENARIO