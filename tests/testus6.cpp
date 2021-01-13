


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

SCENARIO( "Statistics can be correctly calculated from imported data", "[Areas<>][popu1009][statistics]" ) {

  auto get_istream = [](const std::string &path) {
    return std::ifstream(path);
  };

  GIVEN( "a newly constructed Areas<> instance" ) {

    Areas<> areas = Areas<>();

    AND_GIVEN( "a valid popu1009.json file as an open std::istream" ) {

      const std::string test_file = "datasets/popu1009.json";
      auto stream                 = get_istream(test_file);

      REQUIRE( stream.is_open() );

      THEN( "the Areas<> instance will be populated without exception" ) {

        REQUIRE_NOTHROW( areas.populateFromWelshStatsJSON(stream, BethYw::InputFiles::DATASETS[0].COLS, nullptr, nullptr, nullptr) );

        AND_THEN( "the Areas<> instance has size 12" ) {

          REQUIRE( areas.size() == 12 );

        } // AND_THEN

        AND_THEN( "the difference between the first and last values will be correct ('mixed')" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("area").getDifference() == (711.6801 - 711.6801) );
          REQUIRE( areas.getArea("W06000001").getMeasure("dens").getDifference() == (98.41922 - 97.126504) );
          REQUIRE( areas.getArea("W06000001").getMeasure("pop").getDifference() == (70043.0 - 69123.0) );

          REQUIRE( areas.getArea("W06000002").getMeasure("area").getDifference() == (2534.7422 - 2534.7422) );
          REQUIRE( areas.getArea("W06000002").getMeasure("dens").getDifference() == (49.141092 - 45.372267) );
          REQUIRE( areas.getArea("W06000002").getMeasure("pop").getDifference() == (124560.0 - 115007.0) );

          REQUIRE( areas.getArea("W06000003").getMeasure("area").getDifference() == (1125.8409 - 1125.8409) );
          REQUIRE( areas.getArea("W06000003").getMeasure("dens").getDifference() == (104.102631 - 95.884774) );
          REQUIRE( areas.getArea("W06000003").getMeasure("pop").getDifference() == (117203.0 - 107951.0) );

          REQUIRE( areas.getArea("W06000004").getMeasure("area").getDifference() == (836.7704 - 836.7704) );
          REQUIRE( areas.getArea("W06000004").getMeasure("dens").getDifference() == (114.36351 - 106.833368) );
          REQUIRE( areas.getArea("W06000004").getMeasure("pop").getDifference() == (95696.0 - 89395.0) );

          REQUIRE( areas.getArea("W06000005").getMeasure("area").getDifference() == (439.7241 - 439.7241) );
          REQUIRE( areas.getArea("W06000005").getMeasure("dens").getDifference() == (354.995325 - 323.011634) );
          REQUIRE( areas.getArea("W06000005").getMeasure("pop").getDifference() == (156100.0 - 142036.0) );

          REQUIRE( areas.getArea("W06000006").getMeasure("area").getDifference() == (503.7739 - 503.7739) );
          REQUIRE( areas.getArea("W06000006").getMeasure("dens").getDifference() == (269.877022 - 246.499471) );
          REQUIRE( areas.getArea("W06000006").getMeasure("pop").getDifference() == (135957.0 - 124180.0) );

          REQUIRE( areas.getArea("W06000008").getMeasure("area").getDifference() == (1785.5105 - 1785.5105) );
          REQUIRE( areas.getArea("W06000008").getMeasure("dens").getDifference() == (40.713846 - 36.926694) );
          REQUIRE( areas.getArea("W06000008").getMeasure("pop").getDifference() == (72695.0 - 65933.0) );

          REQUIRE( areas.getArea("W06000009").getMeasure("area").getDifference() == (1618.3449 - 1618.3449) );
          REQUIRE( areas.getArea("W06000009").getMeasure("dens").getDifference() == (77.744861 - 69.482099) );
          REQUIRE( areas.getArea("W06000009").getMeasure("pop").getDifference() == (125818.0 - 112446.0) );

          REQUIRE( areas.getArea("W06000010").getMeasure("area").getDifference() == (2370.2762 - 2370.2762) );
          REQUIRE( areas.getArea("W06000010").getMeasure("dens").getDifference() == (79.64093 - 71.605579) );
          REQUIRE( areas.getArea("W06000010").getMeasure("pop").getDifference() == (188771.0 - 169725.0) );

          REQUIRE( areas.getArea("W06000011").getMeasure("area").getDifference() == (377.5964 - 377.5964) );
          REQUIRE( areas.getArea("W06000011").getMeasure("dens").getDifference() == (654.119054 - 608.435356) );
          REQUIRE( areas.getArea("W06000011").getMeasure("pop").getDifference() == (246993.0 - 229743.0) );

          REQUIRE( areas.getArea("W06000012").getMeasure("area").getDifference() == (441.2447 - 441.2447) );
          REQUIRE( areas.getArea("W06000012").getMeasure("dens").getDifference() == (324.797102 - 314.664403) );
          REQUIRE( areas.getArea("W06000012").getMeasure("pop").getDifference() == (143315.0 - 138844.0) );

          REQUIRE( areas.getArea("W06000023").getMeasure("area").getDifference() == (5180.6716 - 5180.6716) );
          REQUIRE( areas.getArea("W06000023").getMeasure("dens").getDifference() == (25.563288 - 23.105692) );
          REQUIRE( areas.getArea("W06000023").getMeasure("pop").getDifference() == (132435.0 - 119703.0) );

        } // AND_THEN

        AND_THEN( "the difference between the first and last values will be correct ('mixed')" ) {

          REQUIRE( std::to_string(areas.getArea("W06000001").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((711.6801 - 711.6801)/711.6801*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000001").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((98.41922 - 97.126504)/97.126504*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000001").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((70043.0 - 69123.0)/69123.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000002").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((2534.7422 - 2534.7422)/2534.7422*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000002").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((49.141092 - 45.372267)/45.372267*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000002").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((124560.0 - 115007.0)/115007.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000003").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((1125.8409 - 1125.8409)/1125.8409*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000003").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((104.102631 - 95.884774)/95.884774*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000003").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((117203.0 - 107951.0)/107951.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000004").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((836.7704 - 836.7704)/836.7704*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000004").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((114.36351 - 106.833368)/106.833368*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000004").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((95696.0 - 89395.0)/89395.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000005").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((439.7241 - 439.7241)/439.7241*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000005").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((354.995325 - 323.011634)/323.011634*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000005").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((156100.0 - 142036.0)/142036.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000006").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((503.7739 - 503.7739)/503.7739*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000006").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((269.877022 - 246.499471)/246.499471*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000006").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((135957.0 - 124180.0)/124180.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000008").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((1785.5105 - 1785.5105)/1785.5105*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000008").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((40.713846 - 36.926694)/36.926694*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000008").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((72695.0 - 65933.0)/65933.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000009").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((1618.3449 - 1618.3449)/1618.3449*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000009").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((77.744861 - 69.482099)/69.482099*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000009").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((125818.0 - 112446.0)/112446.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000010").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((2370.2762 - 2370.2762)/2370.2762*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000010").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((79.64093 - 71.605579)/71.605579*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000010").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((188771.0 - 169725.0)/169725.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000011").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((377.5964 - 377.5964)/377.5964*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000011").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((654.119054 - 608.435356)/608.435356*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000011").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((246993.0 - 229743.0)/229743.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000012").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((441.2447 - 441.2447)/441.2447*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000012").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((324.797102 - 314.664403)/314.664403*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000012").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((143315.0 - 138844.0)/138844.0*100.0) );

          REQUIRE( std::to_string(areas.getArea("W06000023").getMeasure("area").getDifferenceAsPercentage()) == std::to_string((5180.6716 - 5180.6716)/5180.6716*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000023").getMeasure("dens").getDifferenceAsPercentage()) == std::to_string((25.563288 - 23.105692)/23.105692*100.0) );
          REQUIRE( std::to_string(areas.getArea("W06000023").getMeasure("pop").getDifferenceAsPercentage()) == std::to_string((132435.0 - 119703.0)/119703.0*100.0) );

        } // AND_THEN

        AND_THEN( "the average/mean values will be correct ('mixed')" ) {

          REQUIRE( std::to_string(areas.getArea("W06000001").getMeasure("area").getAverage()) == std::to_string(((711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 + 711.6801 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000001").getMeasure("dens").getAverage()) == std::to_string(((97.126504 + 97.486216 + 98.03843 + 97.216432 + 96.147131 + 96.380382 + 95.701706 + 95.115769 + 95.517635 + 95.405225 + 95.275953 + 95.378528 + 95.745265 + 96.606607 + 97.08716 + 97.498862 + 97.937261 + 98.240769 + 98.195805 + 98.124143 + 98.236553 + 98.410789 + 98.461373 + 98.556922 + 98.268871 + 97.888082 + 98.069343 + 98.303999 + 98.41922 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000001").getMeasure("pop").getAverage()) == std::to_string(((69123.0 + 69379.0 + 69772.0 + 69187.0 + 68426.0 + 68592.0 + 68109.0 + 67692.0 + 67978.0 + 67898.0 + 67806.0 + 67879.0 + 68140.0 + 68753.0 + 69095.0 + 69388.0 + 69700.0 + 69916.0 + 69884.0 + 69833.0 + 69913.0 + 70037.0 + 70073.0 + 70141.0 + 69936.0 + 69665.0 + 69794.0 + 69961.0 + 70043.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000002").getMeasure("area").getAverage()) == std::to_string(((2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 + 2534.7422 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000002").getMeasure("dens").getAverage()) == std::to_string(((45.372267 + 45.53757 + 45.652374 + 45.894214 + 46.366056 + 46.350276 + 46.397618 + 46.310035 + 45.906838 + 46.039791 + 46.096996 + 46.294254 + 46.561737 + 46.837505 + 46.805943 + 46.975191 + 47.104593 + 47.241885 + 47.477807 + 47.79776 + 47.942943 + 48.133889 + 47.99423 + 48.090492 + 48.381646 + 48.653074 + 48.818377 + 48.990386 + 49.141092 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000002").getMeasure("pop").getAverage()) == std::to_string(((115007.0 + 115426.0 + 115717.0 + 116330.0 + 117526.0 + 117486.0 + 117606.0 + 117384.0 + 116362.0 + 116699.0 + 116844.0 + 117344.0 + 118022.0 + 118721.0 + 118641.0 + 119070.0 + 119398.0 + 119746.0 + 120344.0 + 121155.0 + 121523.0 + 122007.0 + 121653.0 + 121897.0 + 122635.0 + 123323.0 + 123742.0 + 124178.0 + 124560.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000003").getMeasure("area").getAverage()) == std::to_string(((1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 + 1125.8409 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000003").getMeasure("dens").getAverage()) == std::to_string(((95.884774 + 95.734664 + 96.054425 + 96.719705 + 96.763228 + 95.83681 + 96.082848 + 96.345763 + 96.214305 + 96.506531 + 97.415185 + 98.258999 + 98.813251 + 99.722794 + 99.813393 + 100.372975 + 101.060461 + 101.587178 + 101.811011 + 101.863416 + 102.435433 + 102.63706 + 102.955933 + 103.407151 + 103.433798 + 103.762441 + 103.800635 + 104.08309 + 104.102631 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000003").getMeasure("pop").getAverage()) == std::to_string(((107951.0 + 107782.0 + 108142.0 + 108891.0 + 108940.0 + 107897.0 + 108174.0 + 108470.0 + 108322.0 + 108651.0 + 109674.0 + 110624.0 + 111248.0 + 112272.0 + 112374.0 + 113004.0 + 113778.0 + 114371.0 + 114623.0 + 114682.0 + 115326.0 + 115553.0 + 115912.0 + 116420.0 + 116450.0 + 116820.0 + 116863.0 + 117181.0 + 117203.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000004").getMeasure("area").getAverage()) == std::to_string(((836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 + 836.7704 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000004").getMeasure("dens").getAverage()) == std::to_string(((106.833368 + 106.503528 + 106.809466 + 107.044895 + 107.450025 + 108.300915 + 108.29255 + 108.692898 + 109.359748 + 110.57394 + 111.225254 + 111.712843 + 112.183701 + 112.34862 + 112.310378 + 112.316353 + 112.970057 + 113.219827 + 112.867281 + 112.51832 + 112.239869 + 112.400008 + 112.955716 + 113.336944 + 113.335749 + 113.512619 + 113.721757 + 113.926114 + 114.36351 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000004").getMeasure("pop").getAverage()) == std::to_string(((89395.0 + 89119.0 + 89375.0 + 89572.0 + 89911.0 + 90623.0 + 90616.0 + 90951.0 + 91509.0 + 92525.0 + 93070.0 + 93478.0 + 93872.0 + 94010.0 + 93978.0 + 93983.0 + 94530.0 + 94739.0 + 94444.0 + 94152.0 + 93919.0 + 94053.0 + 94518.0 + 94837.0 + 94836.0 + 94984.0 + 95159.0 + 95330.0 + 95696.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000005").getMeasure("area").getAverage()) == std::to_string(((439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 + 439.7241 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000005").getMeasure("dens").getAverage()) == std::to_string(((323.011634 + 326.325075 + 327.589504 + 328.70384 + 329.397456 + 327.719131 + 328.940351 + 332.619931 + 333.90028 + 336.415493 + 338.005126 + 338.728307 + 339.249088 + 340.397536 + 340.872834 + 341.40726 + 342.9787 + 344.536495 + 345.637185 + 345.853229 + 347.185883 + 347.43604 + 348.452587 + 349.807982 + 350.412907 + 351.643224 + 352.846251 + 353.84233 + 354.995325 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000005").getMeasure("pop").getAverage()) == std::to_string(((142036.0 + 143493.0 + 144049.0 + 144539.0 + 144844.0 + 144106.0 + 144643.0 + 146261.0 + 146824.0 + 147930.0 + 148629.0 + 148947.0 + 149176.0 + 149681.0 + 149890.0 + 150125.0 + 150816.0 + 151501.0 + 151985.0 + 152080.0 + 152666.0 + 152776.0 + 153223.0 + 153819.0 + 154085.0 + 154626.0 + 155155.0 + 155593.0 + 156100.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000006").getMeasure("area").getAverage()) == std::to_string(((503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 + 503.7739 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000006").getMeasure("dens").getAverage()) == std::to_string(((246.499471 + 247.386774 + 248.02595 + 248.718721 + 248.982728 + 249.17329 + 249.391642 + 250.465536 + 251.912614 + 253.393437 + 255.154148 + 255.263323 + 255.896544 + 256.077181 + 256.561525 + 258.669613 + 260.55935 + 262.75875 + 264.592906 + 266.010208 + 268.116312 + 268.965899 + 269.567359 + 269.869082 + 268.807098 + 268.787248 + 269.110805 + 270.21249 + 269.877022 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000006").getMeasure("pop").getAverage()) == std::to_string(((124180.0 + 124627.0 + 124949.0 + 125298.0 + 125431.0 + 125527.0 + 125637.0 + 126178.0 + 126907.0 + 127653.0 + 128540.0 + 128595.0 + 128914.0 + 129005.0 + 129249.0 + 130311.0 + 131263.0 + 132371.0 + 133295.0 + 134009.0 + 135070.0 + 135498.0 + 135801.0 + 135953.0 + 135418.0 + 135408.0 + 135571.0 + 136126.0 + 135957.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000008").getMeasure("area").getAverage()) == std::to_string(((1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 + 1785.5105 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000008").getMeasure("dens").getAverage()) == std::to_string(((36.926694 + 37.824477 + 38.562641 + 39.16919 + 39.662606 + 39.545553 + 40.21651 + 40.614715 + 41.470493 + 41.97231 + 42.23834 + 42.284826 + 42.330191 + 42.438843 + 42.276425 + 42.196335 + 42.187374 + 41.988552 + 41.804291 + 42.126327 + 42.168892 + 42.526773 + 42.446684 + 42.079282 + 41.562903 + 41.257108 + 40.927231 + 40.880185 + 40.713846 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000008").getMeasure("pop").getAverage()) == std::to_string(((65933.0 + 67536.0 + 68854.0 + 69937.0 + 70818.0 + 70609.0 + 71807.0 + 72518.0 + 74046.0 + 74942.0 + 75417.0 + 75500.0 + 75581.0 + 75775.0 + 75485.0 + 75342.0 + 75326.0 + 74971.0 + 74642.0 + 75217.0 + 75293.0 + 75932.0 + 75789.0 + 75133.0 + 74211.0 + 73665.0 + 73076.0 + 72992.0 + 72695.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000009").getMeasure("area").getAverage()) == std::to_string(((1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 + 1618.3449 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000009").getMeasure("dens").getAverage()) == std::to_string(((69.482099 + 69.914639 + 69.753363 + 69.877564 + 69.360369 + 69.293635 + 68.984059 + 69.091576 + 69.000743 + 69.538947 + 69.860263 + 70.532555 + 71.151088 + 71.942637 + 72.422139 + 73.08578 + 73.927381 + 74.850546 + 75.115632 + 75.369595 + 75.764443 + 76.086995 + 76.235294 + 76.513974 + 76.418197 + 76.767937 + 77.060829 + 77.273392 + 77.744861 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000009").getMeasure("pop").getAverage()) == std::to_string(((112446.0 + 113146.0 + 112885.0 + 113086.0 + 112249.0 + 112141.0 + 111640.0 + 111814.0 + 111667.0 + 112538.0 + 113058.0 + 114146.0 + 115147.0 + 116428.0 + 117204.0 + 118278.0 + 119640.0 + 121134.0 + 121563.0 + 121974.0 + 122613.0 + 123135.0 + 123375.0 + 123826.0 + 123671.0 + 124237.0 + 124711.0 + 125055.0 + 125818.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000010").getMeasure("area").getAverage()) == std::to_string(((2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 + 2370.2762 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000010").getMeasure("dens").getAverage()) == std::to_string(((71.605579 + 71.411509 + 71.40729 + 71.705567 + 72.168805 + 72.204665 + 72.368781 + 72.581837 + 72.704185 + 72.934116 + 73.262348 + 73.674114 + 74.309062 + 74.880303 + 75.193347 + 75.731259 + 76.494883 + 77.002419 + 77.141221 + 77.20788 + 77.61163 + 77.768152 + 77.91033 + 78.036475 + 78.154183 + 78.368082 + 78.662563 + 79.133394 + 79.64093 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000010").getMeasure("pop").getAverage()) == std::to_string(((169725.0 + 169265.0 + 169255.0 + 169962.0 + 171060.0 + 171145.0 + 171534.0 + 172039.0 + 172329.0 + 172874.0 + 173652.0 + 174628.0 + 176133.0 + 177487.0 + 178229.0 + 179504.0 + 181314.0 + 182517.0 + 182846.0 + 183004.0 + 183961.0 + 184332.0 + 184669.0 + 184968.0 + 185247.0 + 185754.0 + 186452.0 + 187568.0 + 188771.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000011").getMeasure("area").getAverage()) == std::to_string(((377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 + 377.5964 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000011").getMeasure("dens").getAverage()) == std::to_string(((608.435356 + 608.083128 + 607.391914 + 604.452267 + 603.196958 + 601.698003 + 600.54598 + 597.733453 + 596.086191 + 594.483952 + 591.803841 + 595.225484 + 599.449571 + 604.285422 + 607.386617 + 611.216103 + 615.630869 + 620.077416 + 623.949275 + 628.47792 + 632.132616 + 634.169182 + 635.8853 + 638.157567 + 641.732813 + 647.41613 + 650.11213 + 652.723384 + 654.119054 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000011").getMeasure("pop").getAverage()) == std::to_string(((229743.0 + 229610.0 + 229349.0 + 228239.0 + 227765.0 + 227199.0 + 226764.0 + 225702.0 + 225080.0 + 224475.0 + 223463.0 + 224755.0 + 226350.0 + 228176.0 + 229347.0 + 230793.0 + 232460.0 + 234139.0 + 235601.0 + 237311.0 + 238691.0 + 239460.0 + 240108.0 + 240966.0 + 242316.0 + 244462.0 + 245480.0 + 246466.0 + 246993.0 +  0) / 29)) );

          REQUIRE( std::to_string(areas.getArea("W06000012").getMeasure("area").getAverage()) == std::to_string(((441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 + 441.2447 +  0) / 16)) );
          REQUIRE( std::to_string(areas.getArea("W06000012").getMeasure("dens").getAverage()) == std::to_string(((314.664403 + 313.875725 + 313.247955 + 308.411636 + 306.759492 + 308.747051 + 316.982844 + 318.310905 + 319.428199 + 321.087143 + 322.020865 + 323.870179 + 324.797102 +  0) / 13)) );
          REQUIRE( std::to_string(areas.getArea("W06000012").getMeasure("pop").getAverage()) == std::to_string(((138844.0 + 138496.0 + 136085.0 + 135356.0 + 134380.0 + 134931.0 + 137144.0 + 137670.0 + 139867.0 + 140453.0 + 140946.0 + 141678.0 + 142906.0 + 143315.0 +  0) / 14)) );

          REQUIRE( std::to_string(areas.getArea("W06000023").getMeasure("area").getAverage()) == std::to_string(((5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 + 5180.6716 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000023").getMeasure("dens").getAverage()) == std::to_string(((23.105692 + 23.234053 + 23.369943 + 23.433255 + 23.518765 + 23.926242 + 24.051708 + 24.212691 + 24.250138 + 24.347036 + 24.397995 + 24.542185 + 24.764164 + 25.009885 + 25.133807 + 25.293439 + 25.475848 + 25.646289 + 25.689719 + 25.648798 + 25.686052 + 25.675243 + 25.63104 + 25.629303 + 25.62023 + 25.544372 + 25.57873 + 25.565604 + 25.563288 +  0) / 29)) );
          REQUIRE( std::to_string(areas.getArea("W06000023").getMeasure("pop").getAverage()) == std::to_string(((119703.0 + 120368.0 + 121072.0 + 121400.0 + 121843.0 + 123954.0 + 124604.0 + 125438.0 + 125632.0 + 126134.0 + 126398.0 + 127145.0 + 128295.0 + 129568.0 + 130210.0 + 131037.0 + 131982.0 + 132865.0 + 133090.0 + 132878.0 + 133071.0 + 133015.0 + 132786.0 + 132777.0 + 132730.0 + 132337.0 + 132515.0 + 132447.0 + 132435.0 +  0) / 29)) );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN
  
} // SCENARIO