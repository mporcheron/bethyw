


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  Catch2 test script — https://github.com/catchorg/Catch2
  Catch2 is licensed under the BOOST license.
 */

#include "../libs/catch2/catch.hpp"

#include <fstream>
#include <string>

#include "../datasets.h"
#include "../src/areas.h"

SCENARIO( "complete-popu1009-popden.csv can be correctly parsed", "[Areas<>][complete-popu1009-popden]" ) {

  auto get_istream = [](const std::string &path) {
    return std::ifstream(path);
  };

  GIVEN( "a newly constructed Areas<> instance" ) {

    Areas<> areas = Areas<>();

    AND_GIVEN( "a valid complete-popu1009-popden.csv file as an open std::istream" ) {

      const std::string test_file = "datasets/complete-popu1009-popden.csv";
      auto stream                 = get_istream(test_file);

      REQUIRE( stream.is_open() );

      THEN( "the Areas<> instance will be populated without exception" ) {

        REQUIRE_NOTHROW( areas.populateFromAuthorityByYearCSV(stream, BethYw::InputFiles::DATASETS[4].COLS, nullptr, nullptr) );

        AND_THEN( "the Areas<> instance has size 22" ) {

          REQUIRE( areas.size() == 22 );

        } // AND_THEN

        AND_THEN( "each Area in the Areas<> instance has the correct size (1)" ) {

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

        } // AND_THEN

        AND_THEN( "each Measure in each Area in the Areas<> instance has the correct size (11)" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").size() == 11 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").size() == 11 );

        } // AND THEN

        AND_THEN( "each Measure in each Area in the Areas<> instance has the correct value (mixed)" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2001) == 95.275953 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2011) == 98.236553 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2012) == 98.410789 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2013) == 98.461373 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2014) == 98.556922 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2015) == 98.268871 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2016) == 97.888082 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2017) == 98.069343 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2018) == 98.303999 );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getValue(2019) == 98.41922 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(1991) == 45.372267 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2001) == 46.096996 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2011) == 47.942943 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2012) == 48.133889 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2013) == 47.99423 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2014) == 48.090492 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2015) == 48.381646 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2016) == 48.653074 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2017) == 48.818377 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2018) == 48.990386 );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getValue(2019) == 49.141092 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(1991) == 95.884774 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2001) == 97.415185 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2011) == 102.435433 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2012) == 102.63706 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2013) == 102.955933 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2014) == 103.407151 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2015) == 103.433798 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2016) == 103.762441 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2017) == 103.800635 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2018) == 104.08309 );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getValue(2019) == 104.102631 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(1991) == 106.833368 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2001) == 111.225254 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2011) == 112.239869 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2012) == 112.400008 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2013) == 112.955716 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2014) == 113.336944 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2015) == 113.335749 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2016) == 113.512619 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2017) == 113.721757 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2018) == 113.926114 );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getValue(2019) == 114.36351 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(1991) == 323.011634 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2001) == 338.005126 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2011) == 347.185883 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2012) == 347.43604 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2013) == 348.452587 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2014) == 349.807982 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2015) == 350.412907 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2016) == 351.643224 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2017) == 352.846251 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2018) == 353.84233 );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getValue(2019) == 354.995325 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(1991) == 246.499471 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2001) == 255.154148 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2011) == 268.116312 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2012) == 268.965899 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2013) == 269.567359 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2014) == 269.869082 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2015) == 268.807098 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2016) == 268.787248 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2017) == 269.110805 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2018) == 270.21249 );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getValue(2019) == 269.877022 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(1991) == 23.105692 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2001) == 24.397995 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2011) == 25.686052 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2012) == 25.675243 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2013) == 25.63104 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2014) == 25.629303 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2015) == 25.62023 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2016) == 25.544372 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2017) == 25.57873 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2018) == 25.565604 );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getValue(2019) == 25.563288 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(1991) == 36.926694 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2001) == 42.23834 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2011) == 42.168892 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2012) == 42.526773 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2013) == 42.446684 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2014) == 42.079282 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2015) == 41.562903 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2016) == 41.257108 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2017) == 40.927231 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2018) == 40.880185 );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getValue(2019) == 40.713846 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(1991) == 69.482099 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2001) == 69.860263 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2011) == 75.764443 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2012) == 76.086995 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2013) == 76.235294 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2014) == 76.513974 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2015) == 76.418197 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2016) == 76.767937 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2017) == 77.060829 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2018) == 77.273392 );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getValue(2019) == 77.744861 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(1991) == 71.605579 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2001) == 73.262348 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2011) == 77.61163 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2012) == 77.768152 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2013) == 77.91033 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2014) == 78.036475 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2015) == 78.154183 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2016) == 78.368082 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2017) == 78.662563 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2018) == 79.133394 );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getValue(2019) == 79.64093 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(1991) == 608.435356 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2001) == 591.803841 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2011) == 632.132616 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2012) == 634.169182 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2013) == 635.8853 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2014) == 638.157567 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2015) == 641.732813 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2016) == 647.41613 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2017) == 650.11213 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2018) == 652.723384 );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getValue(2019) == 654.119054 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(1991) == 314.664403 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2001) == 304.547567 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2011) == 317.012306 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2012) == 317.467836 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2013) == 316.982844 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2014) == 318.310905 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2015) == 319.428199 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2016) == 321.087143 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2017) == 322.020865 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2018) == 323.870179 );
          REQUIRE( areas.getArea("W06000013").getMeasure("dens").getValue(2019) == 324.797102 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(1991) == 516.286448 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2001) == 513.32774 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2011) == 555.894048 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2012) == 557.325552 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2013) == 560.383946 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2014) == 563.378541 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2015) == 567.254367 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2016) == 571.835978 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2017) == 575.344957 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2018) == 577.689593 );
          REQUIRE( areas.getArea("W06000014").getMeasure("dens").getValue(2019) == 586.354378 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(1991) == 356.499742 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2001) == 360.196011 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2011) == 382.548777 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2012) == 383.512102 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2013) == 384.834787 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2014) == 386.565148 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2015) == 386.477573 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2016) == 389.228636 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2017) == 394.661307 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2018) == 399.115553 );
          REQUIRE( areas.getArea("W06000015").getMeasure("dens").getValue(2019) == 403.409748 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(1991) == 2107.490601 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2001) == 2200.799302 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2011) == 2451.718585 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2012) == 2475.012048 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2013) == 2499.299138 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2014) == 2518.341295 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2015) == 2537.269895 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2016) == 2563.33132 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2017) == 2574.601893 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2018) == 2585.191121 );
          REQUIRE( areas.getArea("W06000016").getMeasure("dens").getValue(2019) == 2604.034553 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(1991) == 553.853328 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2001) == 546.763859 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2011) == 552.570764 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2012) == 555.491899 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2013) == 556.79804 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2014) == 558.460187 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2015) == 559.655518 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2016) == 561.544 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2017) == 563.779058 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2018) == 566.146144 );
          REQUIRE( areas.getArea("W06000018").getMeasure("dens").getValue(2019) == 568.817367 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(1991) == 534.732871 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2001) == 504.341553 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2011) == 528.065983 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2012) == 528.568468 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2013) == 529.474734 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2014) == 529.905434 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2015) == 531.619264 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2016) == 535.809623 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2017) == 537.954154 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2018) == 540.017928 );
          REQUIRE( areas.getArea("W06000019").getMeasure("dens").getValue(2019) == 541.301057 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(1991) == 615.077298 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2001) == 611.223489 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2011) == 644.519822 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2012) == 645.356196 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2013) == 646.134889 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2014) == 648.669246 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2015) == 649.516435 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2016) == 650.543877 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2017) == 651.776808 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2018) == 652.584341 );
          REQUIRE( areas.getArea("W06000020").getMeasure("dens").getValue(2019) == 652.786225 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(1991) == 668.32892 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2001) == 643.808995 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2011) == 642.079908 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2012) == 642.024724 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2013) == 641.638439 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2014) == 640.617542 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2015) == 639.642631 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2016) == 640.406004 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2017) == 640.212862 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2018) == 641.169378 );
          REQUIRE( areas.getArea("W06000021").getMeasure("dens").getValue(2019) == 642.539771 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(1991) == 723.643124 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2001) == 723.253303 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2011) == 725.464941 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2012) == 726.706004 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2013) == 726.833293 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2014) == 728.320977 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2015) == 730.055283 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2016) == 731.861189 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2017) == 734.009182 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2018) == 740.254275 );
          REQUIRE( areas.getArea("W06000022").getMeasure("dens").getValue(2019) == 747.50972 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(1991) == 94.465686 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2001) == 100.089414 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2011) == 107.773018 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2012) == 108.042721 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2013) == 108.645726 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2014) == 108.98845 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2015) == 109.300552 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2016) == 109.855269 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2017) == 110.225081 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2018) == 110.875196 );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getValue(2019) == 111.402825 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(1991) == 711.651408 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2001) == 723.013331 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2011) == 765.787321 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2012) == 768.36122 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2013) == 770.80905 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2014) == 772.794629 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2015) == 777.201773 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2016) == 785.186111 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2017) == 795.728589 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2018) == 805.273025 );
          REQUIRE( areas.getArea("W06000024").getMeasure("dens").getValue(2019) == 812.490446 );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN
  
} // SCENARIO