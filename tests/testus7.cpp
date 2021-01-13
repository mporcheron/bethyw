


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

SCENARIO( "econ0080.json can be correctly parsed", "[Areas<>][econ0080]" ) {

  auto get_istream = [](const std::string &path) {
    return std::ifstream(path);
  };

  GIVEN( "a newly constructed Areas<> instance" ) {

    Areas<> areas = Areas<>();

    AND_GIVEN( "a valid econ0080.json file as an open std::istream" ) {

      const std::string test_file = "datasets/econ0080.json";
      auto stream                 = get_istream(test_file);

      REQUIRE( stream.is_open() );

      THEN( "the Areas<> instance will be populated without exception" ) {

        REQUIRE_NOTHROW( areas.populateFromWelshStatsJSON(stream, BethYw::InputFiles::DATASETS[1].COLS, nullptr, nullptr, nullptr) );

        AND_THEN( "the Areas<> instance has size 44" ) {

          REQUIRE( areas.size() == 44 );

        } // AND_THEN

        AND_THEN( "each Area in the Areas<> instance has the correct size (8)" ) {

          REQUIRE( areas.getArea("E12000001").size() == 8 );
          REQUIRE( areas.getArea("E12000002").size() == 8 );
          REQUIRE( areas.getArea("E12000003").size() == 8 );
          REQUIRE( areas.getArea("E12000004").size() == 8 );
          REQUIRE( areas.getArea("E12000005").size() == 8 );
          REQUIRE( areas.getArea("E12000006").size() == 8 );
          REQUIRE( areas.getArea("E12000007").size() == 8 );
          REQUIRE( areas.getArea("E12000008").size() == 8 );
          REQUIRE( areas.getArea("E12000009").size() == 8 );
          REQUIRE( areas.getArea("E92000001").size() == 8 );
          REQUIRE( areas.getArea("K02000001").size() == 8 );
          REQUIRE( areas.getArea("K03000001").size() == 8 );
          REQUIRE( areas.getArea("N92000002").size() == 8 );
          REQUIRE( areas.getArea("S92000003").size() == 8 );
          REQUIRE( areas.getArea("UKL1").size() == 8 );
          REQUIRE( areas.getArea("UKL2").size() == 8 );
          REQUIRE( areas.getArea("W06000001").size() == 8 );
          REQUIRE( areas.getArea("W06000002").size() == 8 );
          REQUIRE( areas.getArea("W06000003").size() == 8 );
          REQUIRE( areas.getArea("W06000004").size() == 8 );
          REQUIRE( areas.getArea("W06000005").size() == 8 );
          REQUIRE( areas.getArea("W06000006").size() == 8 );
          REQUIRE( areas.getArea("W06000008").size() == 8 );
          REQUIRE( areas.getArea("W06000009").size() == 8 );
          REQUIRE( areas.getArea("W06000010").size() == 8 );
          REQUIRE( areas.getArea("W06000011").size() == 8 );
          REQUIRE( areas.getArea("W06000012").size() == 8 );
          REQUIRE( areas.getArea("W06000013").size() == 8 );
          REQUIRE( areas.getArea("W06000014").size() == 8 );
          REQUIRE( areas.getArea("W06000015").size() == 8 );
          REQUIRE( areas.getArea("W06000016").size() == 8 );
          REQUIRE( areas.getArea("W06000018").size() == 8 );
          REQUIRE( areas.getArea("W06000019").size() == 8 );
          REQUIRE( areas.getArea("W06000020").size() == 8 );
          REQUIRE( areas.getArea("W06000021").size() == 8 );
          REQUIRE( areas.getArea("W06000022").size() == 8 );
          REQUIRE( areas.getArea("W06000023").size() == 8 );
          REQUIRE( areas.getArea("W06000024").size() == 8 );
          REQUIRE( areas.getArea("W19000001").size() == 8 );
          REQUIRE( areas.getArea("W19000002").size() == 8 );
          REQUIRE( areas.getArea("W19000003").size() == 8 );
          REQUIRE( areas.getArea("W19000004").size() == 8 );
          REQUIRE( areas.getArea("W92000004").size() == 8 );
          REQUIRE( areas.getArea("WXX000002").size() == 8 );

        } // AND_THEN

        AND_THEN( "each Measure in each Area in the Areas<> instance has the correct size (mixed)" ) {

          REQUIRE( areas.getArea("E12000001").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E12000001").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E12000001").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E12000001").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E12000001").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("E12000002").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E12000002").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E12000002").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E12000002").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E12000002").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("E12000003").getMeasure("a").size() == 2 );
          REQUIRE( areas.getArea("E12000003").getMeasure("b").size() == 2 );
          REQUIRE( areas.getArea("E12000003").getMeasure("d").size() == 2 );
          REQUIRE( areas.getArea("E12000003").getMeasure("pa").size() == 2 );
          REQUIRE( areas.getArea("E12000003").getMeasure("pb").size() == 2 );
          REQUIRE( areas.getArea("E12000003").getMeasure("pd").size() == 2 );
          REQUIRE( areas.getArea("E12000003").getMeasure("rb").size() == 2 );
          REQUIRE( areas.getArea("E12000003").getMeasure("rd").size() == 2 );

          REQUIRE( areas.getArea("E12000004").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E12000004").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E12000004").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E12000004").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E12000004").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("E12000005").getMeasure("a").size() == 2 );
          REQUIRE( areas.getArea("E12000005").getMeasure("b").size() == 2 );
          REQUIRE( areas.getArea("E12000005").getMeasure("d").size() == 2 );
          REQUIRE( areas.getArea("E12000005").getMeasure("pa").size() == 2 );
          REQUIRE( areas.getArea("E12000005").getMeasure("pb").size() == 2 );
          REQUIRE( areas.getArea("E12000005").getMeasure("pd").size() == 2 );
          REQUIRE( areas.getArea("E12000005").getMeasure("rb").size() == 2 );
          REQUIRE( areas.getArea("E12000005").getMeasure("rd").size() == 2 );

          REQUIRE( areas.getArea("E12000006").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E12000006").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E12000006").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E12000006").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E12000006").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("E12000007").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E12000007").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E12000007").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E12000007").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E12000007").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("E12000008").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E12000008").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E12000008").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E12000008").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E12000008").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("E12000009").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E12000009").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E12000009").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E12000009").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E12000009").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("E92000001").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("E92000001").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("E92000001").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("E92000001").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("E92000001").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("K02000001").getMeasure("a").size() == 2 );
          REQUIRE( areas.getArea("K02000001").getMeasure("b").size() == 2 );
          REQUIRE( areas.getArea("K02000001").getMeasure("d").size() == 2 );
          REQUIRE( areas.getArea("K02000001").getMeasure("pa").size() == 2 );
          REQUIRE( areas.getArea("K02000001").getMeasure("pb").size() == 2 );
          REQUIRE( areas.getArea("K02000001").getMeasure("pd").size() == 2 );
          REQUIRE( areas.getArea("K02000001").getMeasure("rb").size() == 2 );
          REQUIRE( areas.getArea("K02000001").getMeasure("rd").size() == 2 );

          REQUIRE( areas.getArea("K03000001").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("K03000001").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("K03000001").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("K03000001").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("K03000001").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("N92000002").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("N92000002").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("N92000002").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("N92000002").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("N92000002").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("S92000003").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("S92000003").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("S92000003").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("S92000003").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("S92000003").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("UKL1").getMeasure("a").size() == 2 );
          REQUIRE( areas.getArea("UKL1").getMeasure("b").size() == 2 );
          REQUIRE( areas.getArea("UKL1").getMeasure("d").size() == 2 );
          REQUIRE( areas.getArea("UKL1").getMeasure("pa").size() == 2 );
          REQUIRE( areas.getArea("UKL1").getMeasure("pb").size() == 2 );
          REQUIRE( areas.getArea("UKL1").getMeasure("pd").size() == 2 );
          REQUIRE( areas.getArea("UKL1").getMeasure("rb").size() == 2 );
          REQUIRE( areas.getArea("UKL1").getMeasure("rd").size() == 2 );

          REQUIRE( areas.getArea("UKL2").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("UKL2").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("UKL2").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("UKL2").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("UKL2").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000001").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000001").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000001").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000002").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000002").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000002").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000003").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000003").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000003").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000004").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000005").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000005").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000005").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000006").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000006").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000006").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000008").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000008").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000008").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000009").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000009").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000009").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000010").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000010").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000010").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000011").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000012").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000012").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000012").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000013").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000014").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000014").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000014").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000015").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000015").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000015").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000016").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000018").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000018").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000018").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000019").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000019").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000019").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000020").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000020").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000020").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000021").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000021").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000021").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000022").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000023").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000023").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000023").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W06000024").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W06000024").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W06000024").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W19000001").getMeasure("a").size() == 2 );
          REQUIRE( areas.getArea("W19000001").getMeasure("b").size() == 2 );
          REQUIRE( areas.getArea("W19000001").getMeasure("d").size() == 2 );
          REQUIRE( areas.getArea("W19000001").getMeasure("pa").size() == 2 );
          REQUIRE( areas.getArea("W19000001").getMeasure("pb").size() == 2 );
          REQUIRE( areas.getArea("W19000001").getMeasure("pd").size() == 2 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rb").size() == 2 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rd").size() == 2 );

          REQUIRE( areas.getArea("W19000002").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W19000002").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W19000002").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W19000002").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W19000002").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W19000003").getMeasure("a").size() == 2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("b").size() == 2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("d").size() == 2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("pa").size() == 2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("pb").size() == 2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("pd").size() == 2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("rb").size() == 2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("rd").size() == 2 );

          REQUIRE( areas.getArea("W19000004").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("W19000004").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("W19000004").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rd").size() == 3 );

          REQUIRE( areas.getArea("W92000004").getMeasure("a").size() == 2 );
          REQUIRE( areas.getArea("W92000004").getMeasure("b").size() == 2 );
          REQUIRE( areas.getArea("W92000004").getMeasure("d").size() == 2 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pa").size() == 2 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pb").size() == 2 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pd").size() == 2 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rb").size() == 2 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rd").size() == 2 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("a").size() == 3 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("b").size() == 3 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("d").size() == 3 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pa").size() == 3 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pb").size() == 3 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pd").size() == 3 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rb").size() == 3 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rd").size() == 3 );

        } // AND_THEN

        AND_THEN( "each year in each Measure in each Area in the Areas<> instance has the correct value (mixed)" ) {

          REQUIRE( areas.getArea("E12000001").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("a").getValue(2004) == 56855.0 );

          REQUIRE( areas.getArea("E12000001").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("b").getValue(2004) == 7645.0 );

          REQUIRE( areas.getArea("E12000001").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("d").getValue(2004) == 6420.0 );

          REQUIRE( areas.getArea("E12000001").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pa").getValue(2004) == 348.0 );

          REQUIRE( areas.getArea("E12000001").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pb").getValue(2004) == 47.0 );

          REQUIRE( areas.getArea("E12000001").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("pd").getValue(2004) == 39.0 );

          REQUIRE( areas.getArea("E12000001").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("rb").getValue(2004) == 13.4 );

          REQUIRE( areas.getArea("E12000001").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000001").getMeasure("rd").getValue(2004) == 11.3 );

          REQUIRE( areas.getArea("E12000002").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("a").getValue(2004) == 214085.0 );

          REQUIRE( areas.getArea("E12000002").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("b").getValue(2004) == 28845.0 );

          REQUIRE( areas.getArea("E12000002").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("d").getValue(2004) == 24890.0 );

          REQUIRE( areas.getArea("E12000002").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pa").getValue(2004) == 488.0 );

          REQUIRE( areas.getArea("E12000002").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pb").getValue(2004) == 66.0 );

          REQUIRE( areas.getArea("E12000002").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("pd").getValue(2004) == 57.0 );

          REQUIRE( areas.getArea("E12000002").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("rb").getValue(2004) == 13.5 );

          REQUIRE( areas.getArea("E12000002").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000002").getMeasure("rd").getValue(2004) == 11.6 );

          REQUIRE( areas.getArea("E12000003").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("a").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000003").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("b").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000003").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("d").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000003").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("pa").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000003").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("pb").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000003").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("pd").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000003").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("rb").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000003").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000003").getMeasure("rd").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000004").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("a").getValue(2004) == 147345.0 );

          REQUIRE( areas.getArea("E12000004").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("b").getValue(2004) == 18805.0 );

          REQUIRE( areas.getArea("E12000004").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("d").getValue(2004) == 16175.0 );

          REQUIRE( areas.getArea("E12000004").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pa").getValue(2004) == 533.0 );

          REQUIRE( areas.getArea("E12000004").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pb").getValue(2004) == 68.0 );

          REQUIRE( areas.getArea("E12000004").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("pd").getValue(2004) == 58.0 );

          REQUIRE( areas.getArea("E12000004").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("rb").getValue(2004) == 12.8 );

          REQUIRE( areas.getArea("E12000004").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000004").getMeasure("rd").getValue(2004) == 11.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("a").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("b").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("d").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("pa").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("pb").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("pd").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("rb").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000005").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000005").getMeasure("rd").getValue(2003) == -999.0 );

          REQUIRE( areas.getArea("E12000006").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("a").getValue(2004) == 220265.0 );

          REQUIRE( areas.getArea("E12000006").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("b").getValue(2004) == 27600.0 );

          REQUIRE( areas.getArea("E12000006").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("d").getValue(2004) == 23500.0 );

          REQUIRE( areas.getArea("E12000006").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pa").getValue(2004) == 629.0 );

          REQUIRE( areas.getArea("E12000006").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pb").getValue(2004) == 79.0 );

          REQUIRE( areas.getArea("E12000006").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("pd").getValue(2004) == 67.0 );

          REQUIRE( areas.getArea("E12000006").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("rb").getValue(2004) == 12.5 );

          REQUIRE( areas.getArea("E12000006").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000006").getMeasure("rd").getValue(2004) == 10.7 );

          REQUIRE( areas.getArea("E12000007").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("a").getValue(2004) == 358785.0 );

          REQUIRE( areas.getArea("E12000007").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("b").getValue(2004) == 53620.0 );

          REQUIRE( areas.getArea("E12000007").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("d").getValue(2004) == 47975.0 );

          REQUIRE( areas.getArea("E12000007").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pa").getValue(2004) == 707.0 );

          REQUIRE( areas.getArea("E12000007").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pb").getValue(2004) == 106.0 );

          REQUIRE( areas.getArea("E12000007").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("pd").getValue(2004) == 95.0 );

          REQUIRE( areas.getArea("E12000007").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("rb").getValue(2004) == 14.9 );

          REQUIRE( areas.getArea("E12000007").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000007").getMeasure("rd").getValue(2004) == 13.4 );

          REQUIRE( areas.getArea("E12000008").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("a").getValue(2004) == 353770.0 );

          REQUIRE( areas.getArea("E12000008").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("b").getValue(2004) == 44345.0 );

          REQUIRE( areas.getArea("E12000008").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("d").getValue(2004) == 39280.0 );

          REQUIRE( areas.getArea("E12000008").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pa").getValue(2004) == 679.0 );

          REQUIRE( areas.getArea("E12000008").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pb").getValue(2004) == 85.0 );

          REQUIRE( areas.getArea("E12000008").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("pd").getValue(2004) == 75.0 );

          REQUIRE( areas.getArea("E12000008").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("rb").getValue(2004) == 12.5 );

          REQUIRE( areas.getArea("E12000008").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000008").getMeasure("rd").getValue(2004) == 11.1 );

          REQUIRE( areas.getArea("E12000009").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("a").getValue(2004) == 196850.0 );

          REQUIRE( areas.getArea("E12000009").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("b").getValue(2004) == 24110.0 );

          REQUIRE( areas.getArea("E12000009").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("d").getValue(2004) == 20750.0 );

          REQUIRE( areas.getArea("E12000009").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pa").getValue(2004) == 622.0 );

          REQUIRE( areas.getArea("E12000009").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pb").getValue(2004) == 76.0 );

          REQUIRE( areas.getArea("E12000009").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("pd").getValue(2004) == 66.0 );

          REQUIRE( areas.getArea("E12000009").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("rb").getValue(2004) == 12.2 );

          REQUIRE( areas.getArea("E12000009").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E12000009").getMeasure("rd").getValue(2004) == 10.5 );

          REQUIRE( areas.getArea("E92000001").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("a").getValue(2004) == 1885265.0 );

          REQUIRE( areas.getArea("E92000001").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("b").getValue(2004) == 248450.0 );

          REQUIRE( areas.getArea("E92000001").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("d").getValue(2004) == 215995.0 );

          REQUIRE( areas.getArea("E92000001").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pa").getValue(2004) == 582.0 );

          REQUIRE( areas.getArea("E92000001").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pb").getValue(2004) == 77.0 );

          REQUIRE( areas.getArea("E92000001").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("pd").getValue(2004) == 67.0 );

          REQUIRE( areas.getArea("E92000001").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("rb").getValue(2004) == 13.2 );

          REQUIRE( areas.getArea("E92000001").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("E92000001").getMeasure("rd").getValue(2004) == 11.5 );

          REQUIRE( areas.getArea("K02000001").getMeasure("a").getValue(2002) == 2115915.0 );
          REQUIRE( areas.getArea("K02000001").getMeasure("a").getValue(2003) == 2136405.0 );

          REQUIRE( areas.getArea("K02000001").getMeasure("b").getValue(2002) == 242540.0 );
          REQUIRE( areas.getArea("K02000001").getMeasure("b").getValue(2003) == 267000.0 );

          REQUIRE( areas.getArea("K02000001").getMeasure("d").getValue(2002) == 213345.0 );
          REQUIRE( areas.getArea("K02000001").getMeasure("d").getValue(2003) == 232385.0 );

          REQUIRE( areas.getArea("K02000001").getMeasure("pa").getValue(2002) == 555.0 );
          REQUIRE( areas.getArea("K02000001").getMeasure("pa").getValue(2003) == 557.0 );

          REQUIRE( areas.getArea("K02000001").getMeasure("pb").getValue(2002) == 64.0 );
          REQUIRE( areas.getArea("K02000001").getMeasure("pb").getValue(2003) == 70.0 );

          REQUIRE( areas.getArea("K02000001").getMeasure("pd").getValue(2002) == 56.0 );
          REQUIRE( areas.getArea("K02000001").getMeasure("pd").getValue(2003) == 61.0 );

          REQUIRE( areas.getArea("K02000001").getMeasure("rb").getValue(2002) == 11.5 );
          REQUIRE( areas.getArea("K02000001").getMeasure("rb").getValue(2003) == 12.5 );

          REQUIRE( areas.getArea("K02000001").getMeasure("rd").getValue(2002) == 10.1 );
          REQUIRE( areas.getArea("K02000001").getMeasure("rd").getValue(2003) == 10.9 );

          REQUIRE( areas.getArea("K03000001").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("a").getValue(2004) == 2106730.0 );

          REQUIRE( areas.getArea("K03000001").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("b").getValue(2004) == 274350.0 );

          REQUIRE( areas.getArea("K03000001").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("d").getValue(2004) == 239705.0 );

          REQUIRE( areas.getArea("K03000001").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pa").getValue(2004) == 560.0 );

          REQUIRE( areas.getArea("K03000001").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pb").getValue(2004) == 73.0 );

          REQUIRE( areas.getArea("K03000001").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("pd").getValue(2004) == 64.0 );

          REQUIRE( areas.getArea("K03000001").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("rb").getValue(2004) == 13.0 );

          REQUIRE( areas.getArea("K03000001").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("K03000001").getMeasure("rd").getValue(2004) == 11.4 );

          REQUIRE( areas.getArea("N92000002").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("a").getValue(2004) == 51825.0 );

          REQUIRE( areas.getArea("N92000002").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("b").getValue(2004) == 5730.0 );

          REQUIRE( areas.getArea("N92000002").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("d").getValue(2004) == 3910.0 );

          REQUIRE( areas.getArea("N92000002").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pa").getValue(2004) == 471.0 );

          REQUIRE( areas.getArea("N92000002").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pb").getValue(2004) == 52.0 );

          REQUIRE( areas.getArea("N92000002").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("pd").getValue(2004) == 36.0 );

          REQUIRE( areas.getArea("N92000002").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("rb").getValue(2004) == 11.1 );

          REQUIRE( areas.getArea("N92000002").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("N92000002").getMeasure("rd").getValue(2004) == 7.5 );

          REQUIRE( areas.getArea("S92000003").getMeasure("a").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("a").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("a").getValue(2004) == 135255.0 );

          REQUIRE( areas.getArea("S92000003").getMeasure("b").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("b").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("b").getValue(2004) == 14375.0 );

          REQUIRE( areas.getArea("S92000003").getMeasure("d").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("d").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("d").getValue(2004) == 14720.0 );

          REQUIRE( areas.getArea("S92000003").getMeasure("pa").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pa").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pa").getValue(2004) == 407.0 );

          REQUIRE( areas.getArea("S92000003").getMeasure("pb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pb").getValue(2004) == 43.0 );

          REQUIRE( areas.getArea("S92000003").getMeasure("pd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("pd").getValue(2004) == 44.0 );

          REQUIRE( areas.getArea("S92000003").getMeasure("rb").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("rb").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("rb").getValue(2004) == 10.6 );

          REQUIRE( areas.getArea("S92000003").getMeasure("rd").getValue(2002) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("rd").getValue(2003) == -999.0 );
          REQUIRE( areas.getArea("S92000003").getMeasure("rd").getValue(2004) == 10.9 );

          REQUIRE( areas.getArea("UKL1").getMeasure("a").getValue(2002) == 48205.0 );
          REQUIRE( areas.getArea("UKL1").getMeasure("a").getValue(2003) == 50215.0 );

          REQUIRE( areas.getArea("UKL1").getMeasure("b").getValue(2002) == 5335.0 );
          REQUIRE( areas.getArea("UKL1").getMeasure("b").getValue(2003) == 6740.0 );

          REQUIRE( areas.getArea("UKL1").getMeasure("d").getValue(2002) == 4535.0 );
          REQUIRE( areas.getArea("UKL1").getMeasure("d").getValue(2003) == 5040.0 );

          REQUIRE( areas.getArea("UKL1").getMeasure("pa").getValue(2002) == 416.0 );
          REQUIRE( areas.getArea("UKL1").getMeasure("pa").getValue(2003) == 430.0 );

          REQUIRE( areas.getArea("UKL1").getMeasure("pb").getValue(2002) == 46.0 );
          REQUIRE( areas.getArea("UKL1").getMeasure("pb").getValue(2003) == 58.0 );

          REQUIRE( areas.getArea("UKL1").getMeasure("pd").getValue(2002) == 39.0 );
          REQUIRE( areas.getArea("UKL1").getMeasure("pd").getValue(2003) == 43.0 );

          REQUIRE( areas.getArea("UKL1").getMeasure("rb").getValue(2002) == 11.1 );
          REQUIRE( areas.getArea("UKL1").getMeasure("rb").getValue(2003) == 13.4 );

          REQUIRE( areas.getArea("UKL1").getMeasure("rd").getValue(2002) == 9.4 );
          REQUIRE( areas.getArea("UKL1").getMeasure("rd").getValue(2003) == 10.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("a").getValue(2002) == 32970.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("a").getValue(2003) == 33755.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("a").getValue(2004) == 34570.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("b").getValue(2002) == 3635.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("b").getValue(2003) == 4305.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("b").getValue(2004) == 4500.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("d").getValue(2002) == 3355.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("d").getValue(2003) == 3560.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("d").getValue(2004) == 3690.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("pa").getValue(2002) == 489.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pa").getValue(2003) == 496.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pa").getValue(2004) == 502.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("pb").getValue(2002) == 54.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pb").getValue(2003) == 63.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pb").getValue(2004) == 65.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("pd").getValue(2002) == 50.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pd").getValue(2003) == 52.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("pd").getValue(2004) == 54.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("rb").getValue(2002) == 11.0 );
          REQUIRE( areas.getArea("UKL2").getMeasure("rb").getValue(2003) == 12.8 );
          REQUIRE( areas.getArea("UKL2").getMeasure("rb").getValue(2004) == 13.0 );

          REQUIRE( areas.getArea("UKL2").getMeasure("rd").getValue(2002) == 10.2 );
          REQUIRE( areas.getArea("UKL2").getMeasure("rd").getValue(2003) == 10.5 );
          REQUIRE( areas.getArea("UKL2").getMeasure("rd").getValue(2004) == 10.7 );

          REQUIRE( areas.getArea("W06000001").getMeasure("a").getValue(2002) == 1835.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("a").getValue(2003) == 1900.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("a").getValue(2004) == 1975.0 );

          REQUIRE( areas.getArea("W06000001").getMeasure("b").getValue(2002) == 180.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("b").getValue(2003) == 220.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("b").getValue(2004) == 270.0 );

          REQUIRE( areas.getArea("W06000001").getMeasure("d").getValue(2002) == 160.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("d").getValue(2003) == 200.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("d").getValue(2004) == 195.0 );

          REQUIRE( areas.getArea("W06000001").getMeasure("pa").getValue(2002) == 439.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pa").getValue(2003) == 453.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pa").getValue(2004) == 466.0 );

          REQUIRE( areas.getArea("W06000001").getMeasure("pb").getValue(2002) == 43.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pb").getValue(2003) == 52.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pb").getValue(2004) == 64.0 );

          REQUIRE( areas.getArea("W06000001").getMeasure("pd").getValue(2002) == 38.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pd").getValue(2003) == 48.0 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pd").getValue(2004) == 46.0 );

          REQUIRE( areas.getArea("W06000001").getMeasure("rb").getValue(2002) == 9.8 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rb").getValue(2003) == 11.6 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rb").getValue(2004) == 13.7 );

          REQUIRE( areas.getArea("W06000001").getMeasure("rd").getValue(2002) == 8.7 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rd").getValue(2003) == 10.5 );
          REQUIRE( areas.getArea("W06000001").getMeasure("rd").getValue(2004) == 9.9 );

          REQUIRE( areas.getArea("W06000002").getMeasure("a").getValue(2002) == 4155.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("a").getValue(2003) == 4295.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("a").getValue(2004) == 4310.0 );

          REQUIRE( areas.getArea("W06000002").getMeasure("b").getValue(2002) == 445.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("b").getValue(2003) == 470.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("b").getValue(2004) == 435.0 );

          REQUIRE( areas.getArea("W06000002").getMeasure("d").getValue(2002) == 330.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("d").getValue(2003) == 370.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("d").getValue(2004) == 410.0 );

          REQUIRE( areas.getArea("W06000002").getMeasure("pa").getValue(2002) == 573.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pa").getValue(2003) == 586.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pa").getValue(2004) == 581.0 );

          REQUIRE( areas.getArea("W06000002").getMeasure("pb").getValue(2002) == 61.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pb").getValue(2003) == 64.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pb").getValue(2004) == 59.0 );

          REQUIRE( areas.getArea("W06000002").getMeasure("pd").getValue(2002) == 45.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pd").getValue(2003) == 51.0 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pd").getValue(2004) == 55.0 );

          REQUIRE( areas.getArea("W06000002").getMeasure("rb").getValue(2002) == 10.7 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rb").getValue(2003) == 10.9 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rb").getValue(2004) == 10.1 );

          REQUIRE( areas.getArea("W06000002").getMeasure("rd").getValue(2002) == 7.9 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rd").getValue(2003) == 8.6 );
          REQUIRE( areas.getArea("W06000002").getMeasure("rd").getValue(2004) == 9.5 );

          REQUIRE( areas.getArea("W06000003").getMeasure("a").getValue(2002) == 3460.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("a").getValue(2003) == 3590.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("a").getValue(2004) == 3735.0 );

          REQUIRE( areas.getArea("W06000003").getMeasure("b").getValue(2002) == 345.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("b").getValue(2003) == 465.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("b").getValue(2004) == 515.0 );

          REQUIRE( areas.getArea("W06000003").getMeasure("d").getValue(2002) == 315.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("d").getValue(2003) == 355.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("d").getValue(2004) == 415.0 );

          REQUIRE( areas.getArea("W06000003").getMeasure("pa").getValue(2002) == 534.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pa").getValue(2003) == 550.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pa").getValue(2004) == 565.0 );

          REQUIRE( areas.getArea("W06000003").getMeasure("pb").getValue(2002) == 53.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pb").getValue(2003) == 71.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pb").getValue(2004) == 78.0 );

          REQUIRE( areas.getArea("W06000003").getMeasure("pd").getValue(2002) == 49.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pd").getValue(2003) == 54.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pd").getValue(2004) == 63.0 );

          REQUIRE( areas.getArea("W06000003").getMeasure("rb").getValue(2002) == 10.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rb").getValue(2003) == 13.0 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rb").getValue(2004) == 13.8 );

          REQUIRE( areas.getArea("W06000003").getMeasure("rd").getValue(2002) == 9.1 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rd").getValue(2003) == 9.9 );
          REQUIRE( areas.getArea("W06000003").getMeasure("rd").getValue(2004) == 11.1 );

          REQUIRE( areas.getArea("W06000004").getMeasure("a").getValue(2002) == 2955.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("a").getValue(2003) == 3045.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("a").getValue(2004) == 3095.0 );

          REQUIRE( areas.getArea("W06000004").getMeasure("b").getValue(2002) == 325.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("b").getValue(2003) == 375.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("b").getValue(2004) == 380.0 );

          REQUIRE( areas.getArea("W06000004").getMeasure("d").getValue(2002) == 260.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("d").getValue(2003) == 325.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("d").getValue(2004) == 335.0 );

          REQUIRE( areas.getArea("W06000004").getMeasure("pa").getValue(2002) == 525.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pa").getValue(2003) == 537.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pa").getValue(2004) == 543.0 );

          REQUIRE( areas.getArea("W06000004").getMeasure("pb").getValue(2002) == 58.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pb").getValue(2003) == 66.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pb").getValue(2004) == 67.0 );

          REQUIRE( areas.getArea("W06000004").getMeasure("pd").getValue(2002) == 46.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pd").getValue(2003) == 57.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pd").getValue(2004) == 59.0 );

          REQUIRE( areas.getArea("W06000004").getMeasure("rb").getValue(2002) == 11.0 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rb").getValue(2003) == 12.3 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rb").getValue(2004) == 12.3 );

          REQUIRE( areas.getArea("W06000004").getMeasure("rd").getValue(2002) == 8.8 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rd").getValue(2003) == 10.7 );
          REQUIRE( areas.getArea("W06000004").getMeasure("rd").getValue(2004) == 10.8 );

          REQUIRE( areas.getArea("W06000005").getMeasure("a").getValue(2002) == 4320.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("a").getValue(2003) == 4350.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("a").getValue(2004) == 4415.0 );

          REQUIRE( areas.getArea("W06000005").getMeasure("b").getValue(2002) == 480.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("b").getValue(2003) == 470.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("b").getValue(2004) == 605.0 );

          REQUIRE( areas.getArea("W06000005").getMeasure("d").getValue(2002) == 405.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("d").getValue(2003) == 480.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("d").getValue(2004) == 465.0 );

          REQUIRE( areas.getArea("W06000005").getMeasure("pa").getValue(2002) == 450.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pa").getValue(2003) == 453.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pa").getValue(2004) == 458.0 );

          REQUIRE( areas.getArea("W06000005").getMeasure("pb").getValue(2002) == 50.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pb").getValue(2003) == 49.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pb").getValue(2004) == 63.0 );

          REQUIRE( areas.getArea("W06000005").getMeasure("pd").getValue(2002) == 42.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pd").getValue(2003) == 50.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pd").getValue(2004) == 48.0 );

          REQUIRE( areas.getArea("W06000005").getMeasure("rb").getValue(2002) == 11.1 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rb").getValue(2003) == 10.8 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rb").getValue(2004) == 13.7 );

          REQUIRE( areas.getArea("W06000005").getMeasure("rd").getValue(2002) == 9.4 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rd").getValue(2003) == 11.0 );
          REQUIRE( areas.getArea("W06000005").getMeasure("rd").getValue(2004) == 10.5 );

          REQUIRE( areas.getArea("W06000006").getMeasure("a").getValue(2002) == 3285.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("a").getValue(2003) == 3340.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("a").getValue(2004) == 3345.0 );

          REQUIRE( areas.getArea("W06000006").getMeasure("b").getValue(2002) == 325.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("b").getValue(2003) == 365.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("b").getValue(2004) == 415.0 );

          REQUIRE( areas.getArea("W06000006").getMeasure("d").getValue(2002) == 290.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("d").getValue(2003) == 350.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("d").getValue(2004) == 315.0 );

          REQUIRE( areas.getArea("W06000006").getMeasure("pa").getValue(2002) == 396.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pa").getValue(2003) == 402.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pa").getValue(2004) == 402.0 );

          REQUIRE( areas.getArea("W06000006").getMeasure("pb").getValue(2002) == 39.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pb").getValue(2003) == 44.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pb").getValue(2004) == 50.0 );

          REQUIRE( areas.getArea("W06000006").getMeasure("pd").getValue(2002) == 35.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pd").getValue(2003) == 42.0 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pd").getValue(2004) == 38.0 );

          REQUIRE( areas.getArea("W06000006").getMeasure("rb").getValue(2002) == 9.9 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rb").getValue(2003) == 10.9 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rb").getValue(2004) == 12.4 );

          REQUIRE( areas.getArea("W06000006").getMeasure("rd").getValue(2002) == 8.8 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rd").getValue(2003) == 10.5 );
          REQUIRE( areas.getArea("W06000006").getMeasure("rd").getValue(2004) == 9.4 );

          REQUIRE( areas.getArea("W06000008").getMeasure("a").getValue(2002) == 2650.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("a").getValue(2003) == 2820.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("a").getValue(2004) == 2930.0 );

          REQUIRE( areas.getArea("W06000008").getMeasure("b").getValue(2002) == 295.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("b").getValue(2003) == 345.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("b").getValue(2004) == 365.0 );

          REQUIRE( areas.getArea("W06000008").getMeasure("d").getValue(2002) == 200.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("d").getValue(2003) == 240.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("d").getValue(2004) == 240.0 );

          REQUIRE( areas.getArea("W06000008").getMeasure("pa").getValue(2002) == 543.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pa").getValue(2003) == 576.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pa").getValue(2004) == 596.0 );

          REQUIRE( areas.getArea("W06000008").getMeasure("pb").getValue(2002) == 60.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pb").getValue(2003) == 70.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pb").getValue(2004) == 74.0 );

          REQUIRE( areas.getArea("W06000008").getMeasure("pd").getValue(2002) == 41.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pd").getValue(2003) == 49.0 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pd").getValue(2004) == 49.0 );

          REQUIRE( areas.getArea("W06000008").getMeasure("rb").getValue(2002) == 11.1 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rb").getValue(2003) == 12.2 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rb").getValue(2004) == 12.5 );

          REQUIRE( areas.getArea("W06000008").getMeasure("rd").getValue(2002) == 7.5 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rd").getValue(2003) == 8.5 );
          REQUIRE( areas.getArea("W06000008").getMeasure("rd").getValue(2004) == 8.2 );

          REQUIRE( areas.getArea("W06000009").getMeasure("a").getValue(2002) == 4100.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("a").getValue(2003) == 4280.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("a").getValue(2004) == 4460.0 );

          REQUIRE( areas.getArea("W06000009").getMeasure("b").getValue(2002) == 430.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("b").getValue(2003) == 575.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("b").getValue(2004) == 610.0 );

          REQUIRE( areas.getArea("W06000009").getMeasure("d").getValue(2002) == 375.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("d").getValue(2003) == 405.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("d").getValue(2004) == 375.0 );

          REQUIRE( areas.getArea("W06000009").getMeasure("pa").getValue(2002) == 595.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pa").getValue(2003) == 618.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pa").getValue(2004) == 635.0 );

          REQUIRE( areas.getArea("W06000009").getMeasure("pb").getValue(2002) == 62.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pb").getValue(2003) == 83.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pb").getValue(2004) == 87.0 );

          REQUIRE( areas.getArea("W06000009").getMeasure("pd").getValue(2002) == 54.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pd").getValue(2003) == 58.0 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pd").getValue(2004) == 53.0 );

          REQUIRE( areas.getArea("W06000009").getMeasure("rb").getValue(2002) == 10.5 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rb").getValue(2003) == 13.4 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rb").getValue(2004) == 13.7 );

          REQUIRE( areas.getArea("W06000009").getMeasure("rd").getValue(2002) == 9.1 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rd").getValue(2003) == 9.5 );
          REQUIRE( areas.getArea("W06000009").getMeasure("rd").getValue(2004) == 8.4 );

          REQUIRE( areas.getArea("W06000010").getMeasure("a").getValue(2002) == 5220.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("a").getValue(2003) == 5480.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("a").getValue(2004) == 5720.0 );

          REQUIRE( areas.getArea("W06000010").getMeasure("b").getValue(2002) == 615.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("b").getValue(2003) == 750.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("b").getValue(2004) == 735.0 );

          REQUIRE( areas.getArea("W06000010").getMeasure("d").getValue(2002) == 480.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("d").getValue(2003) == 530.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("d").getValue(2004) == 510.0 );

          REQUIRE( areas.getArea("W06000010").getMeasure("pa").getValue(2002) == 489.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pa").getValue(2003) == 508.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pa").getValue(2004) == 524.0 );

          REQUIRE( areas.getArea("W06000010").getMeasure("pb").getValue(2002) == 58.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pb").getValue(2003) == 69.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pb").getValue(2004) == 67.0 );

          REQUIRE( areas.getArea("W06000010").getMeasure("pd").getValue(2002) == 45.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pd").getValue(2003) == 49.0 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pd").getValue(2004) == 47.0 );

          REQUIRE( areas.getArea("W06000010").getMeasure("rb").getValue(2002) == 11.8 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rb").getValue(2003) == 13.7 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rb").getValue(2004) == 12.8 );

          REQUIRE( areas.getArea("W06000010").getMeasure("rd").getValue(2002) == 9.2 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rd").getValue(2003) == 9.7 );
          REQUIRE( areas.getArea("W06000010").getMeasure("rd").getValue(2004) == 8.9 );

          REQUIRE( areas.getArea("W06000011").getMeasure("a").getValue(2002) == 5695.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("a").getValue(2003) == 5925.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("a").getValue(2004) == 6170.0 );

          REQUIRE( areas.getArea("W06000011").getMeasure("b").getValue(2002) == 645.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("b").getValue(2003) == 975.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("b").getValue(2004) == 895.0 );

          REQUIRE( areas.getArea("W06000011").getMeasure("d").getValue(2002) == 675.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("d").getValue(2003) == 680.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("d").getValue(2004) == 665.0 );

          REQUIRE( areas.getArea("W06000011").getMeasure("pa").getValue(2002) == 401.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pa").getValue(2003) == 412.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pa").getValue(2004) == 424.0 );

          REQUIRE( areas.getArea("W06000011").getMeasure("pb").getValue(2002) == 45.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pb").getValue(2003) == 68.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pb").getValue(2004) == 61.0 );

          REQUIRE( areas.getArea("W06000011").getMeasure("pd").getValue(2002) == 48.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pd").getValue(2003) == 47.0 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pd").getValue(2004) == 46.0 );

          REQUIRE( areas.getArea("W06000011").getMeasure("rb").getValue(2002) == 11.3 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rb").getValue(2003) == 16.5 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rb").getValue(2004) == 14.5 );

          REQUIRE( areas.getArea("W06000011").getMeasure("rd").getValue(2002) == 11.9 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rd").getValue(2003) == 11.5 );
          REQUIRE( areas.getArea("W06000011").getMeasure("rd").getValue(2004) == 10.8 );

          REQUIRE( areas.getArea("W06000012").getMeasure("a").getValue(2002) == 2675.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("a").getValue(2003) == 2830.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("a").getValue(2004) == 2880.0 );

          REQUIRE( areas.getArea("W06000012").getMeasure("b").getValue(2002) == 285.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("b").getValue(2003) == 435.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("b").getValue(2004) == 435.0 );

          REQUIRE( areas.getArea("W06000012").getMeasure("d").getValue(2002) == 280.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("d").getValue(2003) == 315.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("d").getValue(2004) == 310.0 );

          REQUIRE( areas.getArea("W06000012").getMeasure("pa").getValue(2002) == 318.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pa").getValue(2003) == 331.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pa").getValue(2004) == 334.0 );

          REQUIRE( areas.getArea("W06000012").getMeasure("pb").getValue(2002) == 34.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pb").getValue(2003) == 51.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pb").getValue(2004) == 50.0 );

          REQUIRE( areas.getArea("W06000012").getMeasure("pd").getValue(2002) == 33.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pd").getValue(2003) == 37.0 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pd").getValue(2004) == 36.0 );

          REQUIRE( areas.getArea("W06000012").getMeasure("rb").getValue(2002) == 10.7 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rb").getValue(2003) == 15.4 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rb").getValue(2004) == 15.1 );

          REQUIRE( areas.getArea("W06000012").getMeasure("rd").getValue(2002) == 10.5 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rd").getValue(2003) == 11.1 );
          REQUIRE( areas.getArea("W06000012").getMeasure("rd").getValue(2004) == 10.8 );

          REQUIRE( areas.getArea("W06000013").getMeasure("a").getValue(2002) == 3235.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("a").getValue(2003) == 3385.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("a").getValue(2004) == 3470.0 );

          REQUIRE( areas.getArea("W06000013").getMeasure("b").getValue(2002) == 430.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("b").getValue(2003) == 475.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("b").getValue(2004) == 515.0 );

          REQUIRE( areas.getArea("W06000013").getMeasure("d").getValue(2002) == 320.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("d").getValue(2003) == 350.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("d").getValue(2004) == 380.0 );

          REQUIRE( areas.getArea("W06000013").getMeasure("pa").getValue(2002) == 394.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pa").getValue(2003) == 408.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pa").getValue(2004) == 414.0 );

          REQUIRE( areas.getArea("W06000013").getMeasure("pb").getValue(2002) == 52.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pb").getValue(2003) == 57.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pb").getValue(2004) == 61.0 );

          REQUIRE( areas.getArea("W06000013").getMeasure("pd").getValue(2002) == 39.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pd").getValue(2003) == 42.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pd").getValue(2004) == 45.0 );

          REQUIRE( areas.getArea("W06000013").getMeasure("rb").getValue(2002) == 13.3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rb").getValue(2003) == 14.0 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rb").getValue(2004) == 14.8 );

          REQUIRE( areas.getArea("W06000013").getMeasure("rd").getValue(2002) == 9.9 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rd").getValue(2003) == 10.3 );
          REQUIRE( areas.getArea("W06000013").getMeasure("rd").getValue(2004) == 11.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("a").getValue(2002) == 3565.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("a").getValue(2003) == 3670.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("a").getValue(2004) == 3735.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("b").getValue(2002) == 420.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("b").getValue(2003) == 505.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("b").getValue(2004) == 520.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("d").getValue(2002) == 400.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("d").getValue(2003) == 405.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("d").getValue(2004) == 420.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("pa").getValue(2002) == 478.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pa").getValue(2003) == 487.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pa").getValue(2004) == 489.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("pb").getValue(2002) == 56.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pb").getValue(2003) == 67.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pb").getValue(2004) == 68.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("pd").getValue(2002) == 54.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pd").getValue(2003) == 54.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pd").getValue(2004) == 55.0 );

          REQUIRE( areas.getArea("W06000014").getMeasure("rb").getValue(2002) == 11.8 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rb").getValue(2003) == 13.8 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rb").getValue(2004) == 13.9 );

          REQUIRE( areas.getArea("W06000014").getMeasure("rd").getValue(2002) == 11.2 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rd").getValue(2003) == 11.0 );
          REQUIRE( areas.getArea("W06000014").getMeasure("rd").getValue(2004) == 11.2 );

          REQUIRE( areas.getArea("W06000015").getMeasure("a").getValue(2002) == 9610.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("a").getValue(2003) == 9695.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("a").getValue(2004) == 9950.0 );

          REQUIRE( areas.getArea("W06000015").getMeasure("b").getValue(2002) == 1110.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("b").getValue(2003) == 1315.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("b").getValue(2004) == 1370.0 );

          REQUIRE( areas.getArea("W06000015").getMeasure("d").getValue(2002) == 1120.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("d").getValue(2003) == 1090.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("d").getValue(2004) == 1160.0 );

          REQUIRE( areas.getArea("W06000015").getMeasure("pa").getValue(2002) == 469.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pa").getValue(2003) == 467.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pa").getValue(2004) == 468.0 );

          REQUIRE( areas.getArea("W06000015").getMeasure("pb").getValue(2002) == 54.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pb").getValue(2003) == 63.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pb").getValue(2004) == 64.0 );

          REQUIRE( areas.getArea("W06000015").getMeasure("pd").getValue(2002) == 55.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pd").getValue(2003) == 52.0 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pd").getValue(2004) == 55.0 );

          REQUIRE( areas.getArea("W06000015").getMeasure("rb").getValue(2002) == 11.6 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rb").getValue(2003) == 13.6 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rb").getValue(2004) == 13.8 );

          REQUIRE( areas.getArea("W06000015").getMeasure("rd").getValue(2002) == 11.7 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rd").getValue(2003) == 11.2 );
          REQUIRE( areas.getArea("W06000015").getMeasure("rd").getValue(2004) == 11.7 );

          REQUIRE( areas.getArea("W06000016").getMeasure("a").getValue(2002) == 4715.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("a").getValue(2003) == 4845.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("a").getValue(2004) == 4925.0 );

          REQUIRE( areas.getArea("W06000016").getMeasure("b").getValue(2002) == 535.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("b").getValue(2003) == 590.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("b").getValue(2004) == 745.0 );

          REQUIRE( areas.getArea("W06000016").getMeasure("d").getValue(2002) == 425.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("d").getValue(2003) == 525.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("d").getValue(2004) == 570.0 );

          REQUIRE( areas.getArea("W06000016").getMeasure("pa").getValue(2002) == 321.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pa").getValue(2003) == 328.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pa").getValue(2004) == 329.0 );

          REQUIRE( areas.getArea("W06000016").getMeasure("pb").getValue(2002) == 36.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pb").getValue(2003) == 40.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pb").getValue(2004) == 50.0 );

          REQUIRE( areas.getArea("W06000016").getMeasure("pd").getValue(2002) == 29.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pd").getValue(2003) == 36.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pd").getValue(2004) == 38.0 );

          REQUIRE( areas.getArea("W06000016").getMeasure("rb").getValue(2002) == 11.3 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rb").getValue(2003) == 12.2 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rb").getValue(2004) == 15.1 );

          REQUIRE( areas.getArea("W06000016").getMeasure("rd").getValue(2002) == 9.0 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rd").getValue(2003) == 10.8 );
          REQUIRE( areas.getArea("W06000016").getMeasure("rd").getValue(2004) == 11.6 );

          REQUIRE( areas.getArea("W06000018").getMeasure("a").getValue(2002) == 3370.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("a").getValue(2003) == 3550.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("a").getValue(2004) == 3605.0 );

          REQUIRE( areas.getArea("W06000018").getMeasure("b").getValue(2002) == 375.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("b").getValue(2003) == 525.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("b").getValue(2004) == 490.0 );

          REQUIRE( areas.getArea("W06000018").getMeasure("d").getValue(2002) == 340.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("d").getValue(2003) == 350.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("d").getValue(2004) == 415.0 );

          REQUIRE( areas.getArea("W06000018").getMeasure("pa").getValue(2002) == 312.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pa").getValue(2003) == 326.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pa").getValue(2004) == 328.0 );

          REQUIRE( areas.getArea("W06000018").getMeasure("pb").getValue(2002) == 35.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pb").getValue(2003) == 48.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pb").getValue(2004) == 45.0 );

          REQUIRE( areas.getArea("W06000018").getMeasure("pd").getValue(2002) == 31.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pd").getValue(2003) == 32.0 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pd").getValue(2004) == 38.0 );

          REQUIRE( areas.getArea("W06000018").getMeasure("rb").getValue(2002) == 11.1 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rb").getValue(2003) == 14.8 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rb").getValue(2004) == 13.6 );

          REQUIRE( areas.getArea("W06000018").getMeasure("rd").getValue(2002) == 10.1 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rd").getValue(2003) == 9.9 );
          REQUIRE( areas.getArea("W06000018").getMeasure("rd").getValue(2004) == 11.5 );

          REQUIRE( areas.getArea("W06000019").getMeasure("a").getValue(2002) == 1195.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("a").getValue(2003) == 1220.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("a").getValue(2004) == 1220.0 );

          REQUIRE( areas.getArea("W06000019").getMeasure("b").getValue(2002) == 95.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("b").getValue(2003) == 165.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("b").getValue(2004) == 165.0 );

          REQUIRE( areas.getArea("W06000019").getMeasure("d").getValue(2002) == 125.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("d").getValue(2003) == 120.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("d").getValue(2004) == 120.0 );

          REQUIRE( areas.getArea("W06000019").getMeasure("pa").getValue(2002) == 277.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pa").getValue(2003) == 282.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pa").getValue(2004) == 280.0 );

          REQUIRE( areas.getArea("W06000019").getMeasure("pb").getValue(2002) == 22.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pb").getValue(2003) == 38.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pb").getValue(2004) == 38.0 );

          REQUIRE( areas.getArea("W06000019").getMeasure("pd").getValue(2002) == 29.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pd").getValue(2003) == 28.0 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pd").getValue(2004) == 28.0 );

          REQUIRE( areas.getArea("W06000019").getMeasure("rb").getValue(2002) == 7.9 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rb").getValue(2003) == 13.5 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rb").getValue(2004) == 13.5 );

          REQUIRE( areas.getArea("W06000019").getMeasure("rd").getValue(2002) == 10.5 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rd").getValue(2003) == 9.8 );
          REQUIRE( areas.getArea("W06000019").getMeasure("rd").getValue(2004) == 9.8 );

          REQUIRE( areas.getArea("W06000020").getMeasure("a").getValue(2002) == 1935.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("a").getValue(2003) == 2015.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("a").getValue(2004) == 2085.0 );

          REQUIRE( areas.getArea("W06000020").getMeasure("b").getValue(2002) == 225.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("b").getValue(2003) == 255.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("b").getValue(2004) == 315.0 );

          REQUIRE( areas.getArea("W06000020").getMeasure("d").getValue(2002) == 170.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("d").getValue(2003) == 160.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("d").getValue(2004) == 235.0 );

          REQUIRE( areas.getArea("W06000020").getMeasure("pa").getValue(2002) == 343.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pa").getValue(2003) == 356.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pa").getValue(2004) == 368.0 );

          REQUIRE( areas.getArea("W06000020").getMeasure("pb").getValue(2002) == 40.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pb").getValue(2003) == 45.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pb").getValue(2004) == 56.0 );

          REQUIRE( areas.getArea("W06000020").getMeasure("pd").getValue(2002) == 30.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pd").getValue(2003) == 28.0 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pd").getValue(2004) == 42.0 );

          REQUIRE( areas.getArea("W06000020").getMeasure("rb").getValue(2002) == 11.6 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rb").getValue(2003) == 12.7 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rb").getValue(2004) == 15.1 );

          REQUIRE( areas.getArea("W06000020").getMeasure("rd").getValue(2002) == 8.8 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rd").getValue(2003) == 7.9 );
          REQUIRE( areas.getArea("W06000020").getMeasure("rd").getValue(2004) == 11.3 );

          REQUIRE( areas.getArea("W06000021").getMeasure("a").getValue(2002) == 3330.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("a").getValue(2003) == 3480.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("a").getValue(2004) == 3625.0 );

          REQUIRE( areas.getArea("W06000021").getMeasure("b").getValue(2002) == 365.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("b").getValue(2003) == 500.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("b").getValue(2004) == 500.0 );

          REQUIRE( areas.getArea("W06000021").getMeasure("d").getValue(2002) == 365.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("d").getValue(2003) == 330.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("d").getValue(2004) == 370.0 );

          REQUIRE( areas.getArea("W06000021").getMeasure("pa").getValue(2002) == 631.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pa").getValue(2003) == 649.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pa").getValue(2004) == 667.0 );

          REQUIRE( areas.getArea("W06000021").getMeasure("pb").getValue(2002) == 69.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pb").getValue(2003) == 93.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pb").getValue(2004) == 92.0 );

          REQUIRE( areas.getArea("W06000021").getMeasure("pd").getValue(2002) == 69.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pd").getValue(2003) == 62.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pd").getValue(2004) == 68.0 );

          REQUIRE( areas.getArea("W06000021").getMeasure("rb").getValue(2002) == 11.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rb").getValue(2003) == 14.4 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rb").getValue(2004) == 13.8 );

          REQUIRE( areas.getArea("W06000021").getMeasure("rd").getValue(2002) == 11.0 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rd").getValue(2003) == 9.5 );
          REQUIRE( areas.getArea("W06000021").getMeasure("rd").getValue(2004) == 10.2 );

          REQUIRE( areas.getArea("W06000022").getMeasure("a").getValue(2002) == 3525.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("a").getValue(2003) == 3660.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("a").getValue(2004) == 3720.0 );

          REQUIRE( areas.getArea("W06000022").getMeasure("b").getValue(2002) == 430.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("b").getValue(2003) == 525.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("b").getValue(2004) == 495.0 );

          REQUIRE( areas.getArea("W06000022").getMeasure("d").getValue(2002) == 360.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("d").getValue(2003) == 425.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("d").getValue(2004) == 455.0 );

          REQUIRE( areas.getArea("W06000022").getMeasure("pa").getValue(2002) == 410.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pa").getValue(2003) == 422.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pa").getValue(2004) == 427.0 );

          REQUIRE( areas.getArea("W06000022").getMeasure("pb").getValue(2002) == 50.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pb").getValue(2003) == 61.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pb").getValue(2004) == 57.0 );

          REQUIRE( areas.getArea("W06000022").getMeasure("pd").getValue(2002) == 42.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pd").getValue(2003) == 49.0 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pd").getValue(2004) == 52.0 );

          REQUIRE( areas.getArea("W06000022").getMeasure("rb").getValue(2002) == 12.2 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rb").getValue(2003) == 14.3 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rb").getValue(2004) == 13.3 );

          REQUIRE( areas.getArea("W06000022").getMeasure("rd").getValue(2002) == 10.2 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rd").getValue(2003) == 11.6 );
          REQUIRE( areas.getArea("W06000022").getMeasure("rd").getValue(2004) == 12.2 );

          REQUIRE( areas.getArea("W06000023").getMeasure("a").getValue(2002) == 5335.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("a").getValue(2003) == 5560.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("a").getValue(2004) == 5780.0 );

          REQUIRE( areas.getArea("W06000023").getMeasure("b").getValue(2002) == 505.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("b").getValue(2003) == 625.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("b").getValue(2004) == 595.0 );

          REQUIRE( areas.getArea("W06000023").getMeasure("d").getValue(2002) == 415.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("d").getValue(2003) == 480.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("d").getValue(2004) == 505.0 );

          REQUIRE( areas.getArea("W06000023").getMeasure("pa").getValue(2002) == 692.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pa").getValue(2003) == 714.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pa").getValue(2004) == 733.0 );

          REQUIRE( areas.getArea("W06000023").getMeasure("pb").getValue(2002) == 66.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pb").getValue(2003) == 80.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pb").getValue(2004) == 75.0 );

          REQUIRE( areas.getArea("W06000023").getMeasure("pd").getValue(2002) == 54.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pd").getValue(2003) == 62.0 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pd").getValue(2004) == 64.0 );

          REQUIRE( areas.getArea("W06000023").getMeasure("rb").getValue(2002) == 9.5 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rb").getValue(2003) == 11.2 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rb").getValue(2004) == 10.3 );

          REQUIRE( areas.getArea("W06000023").getMeasure("rd").getValue(2002) == 7.8 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rd").getValue(2003) == 8.6 );
          REQUIRE( areas.getArea("W06000023").getMeasure("rd").getValue(2004) == 8.7 );

          REQUIRE( areas.getArea("W06000024").getMeasure("a").getValue(2002) == 1010.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("a").getValue(2003) == 1035.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("a").getValue(2004) == 1060.0 );

          REQUIRE( areas.getArea("W06000024").getMeasure("b").getValue(2002) == 110.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("b").getValue(2003) == 120.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("b").getValue(2004) == 155.0 );

          REQUIRE( areas.getArea("W06000024").getMeasure("d").getValue(2002) == 80.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("d").getValue(2003) == 115.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("d").getValue(2004) == 125.0 );

          REQUIRE( areas.getArea("W06000024").getMeasure("pa").getValue(2002) == 287.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pa").getValue(2003) == 293.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pa").getValue(2004) == 299.0 );

          REQUIRE( areas.getArea("W06000024").getMeasure("pb").getValue(2002) == 31.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pb").getValue(2003) == 34.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pb").getValue(2004) == 44.0 );

          REQUIRE( areas.getArea("W06000024").getMeasure("pd").getValue(2002) == 23.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pd").getValue(2003) == 33.0 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pd").getValue(2004) == 35.0 );

          REQUIRE( areas.getArea("W06000024").getMeasure("rb").getValue(2002) == 10.9 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rb").getValue(2003) == 11.6 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rb").getValue(2004) == 14.6 );

          REQUIRE( areas.getArea("W06000024").getMeasure("rd").getValue(2002) == 7.9 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rd").getValue(2003) == 11.1 );
          REQUIRE( areas.getArea("W06000024").getMeasure("rd").getValue(2004) == 11.8 );

          REQUIRE( areas.getArea("W19000001").getMeasure("a").getValue(2002) == 20010.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("a").getValue(2003) == 20520.0 );

          REQUIRE( areas.getArea("W19000001").getMeasure("b").getValue(2002) == 2100.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("b").getValue(2003) == 2365.0 );

          REQUIRE( areas.getArea("W19000001").getMeasure("d").getValue(2002) == 1760.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("d").getValue(2003) == 2080.0 );

          REQUIRE( areas.getArea("W19000001").getMeasure("pa").getValue(2002) == 483.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("pa").getValue(2003) == 493.0 );

          REQUIRE( areas.getArea("W19000001").getMeasure("pb").getValue(2002) == 51.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("pb").getValue(2003) == 57.0 );

          REQUIRE( areas.getArea("W19000001").getMeasure("pd").getValue(2002) == 42.0 );
          REQUIRE( areas.getArea("W19000001").getMeasure("pd").getValue(2003) == 50.0 );

          REQUIRE( areas.getArea("W19000001").getMeasure("rb").getValue(2002) == 10.5 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rb").getValue(2003) == 11.5 );

          REQUIRE( areas.getArea("W19000001").getMeasure("rd").getValue(2002) == 8.8 );
          REQUIRE( areas.getArea("W19000001").getMeasure("rd").getValue(2003) == 10.1 );

          REQUIRE( areas.getArea("W19000002").getMeasure("a").getValue(2002) == 7985.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("a").getValue(2003) == 8380.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("a").getValue(2004) == 8710.0 );

          REQUIRE( areas.getArea("W19000002").getMeasure("b").getValue(2002) == 800.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("b").getValue(2003) == 970.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("b").getValue(2004) == 960.0 );

          REQUIRE( areas.getArea("W19000002").getMeasure("d").getValue(2002) == 615.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("d").getValue(2003) == 720.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("d").getValue(2004) == 745.0 );

          REQUIRE( areas.getArea("W19000002").getMeasure("pa").getValue(2002) == 635.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pa").getValue(2003) == 661.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pa").getValue(2004) == 680.0 );

          REQUIRE( areas.getArea("W19000002").getMeasure("pb").getValue(2002) == 64.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pb").getValue(2003) == 76.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pb").getValue(2004) == 75.0 );

          REQUIRE( areas.getArea("W19000002").getMeasure("pd").getValue(2002) == 49.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pd").getValue(2003) == 57.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("pd").getValue(2004) == 58.0 );

          REQUIRE( areas.getArea("W19000002").getMeasure("rb").getValue(2002) == 10.0 );
          REQUIRE( areas.getArea("W19000002").getMeasure("rb").getValue(2003) == 11.6 );
          REQUIRE( areas.getArea("W19000002").getMeasure("rb").getValue(2004) == 11.0 );

          REQUIRE( areas.getArea("W19000002").getMeasure("rd").getValue(2002) == 7.7 );
          REQUIRE( areas.getArea("W19000002").getMeasure("rd").getValue(2003) == 8.6 );
          REQUIRE( areas.getArea("W19000002").getMeasure("rd").getValue(2004) == 8.6 );

          REQUIRE( areas.getArea("W19000003").getMeasure("a").getValue(2002) == 17690.0 );
          REQUIRE( areas.getArea("W19000003").getMeasure("a").getValue(2003) == 18515.0 );

          REQUIRE( areas.getArea("W19000003").getMeasure("b").getValue(2002) == 1975.0 );
          REQUIRE( areas.getArea("W19000003").getMeasure("b").getValue(2003) == 2735.0 );

          REQUIRE( areas.getArea("W19000003").getMeasure("d").getValue(2002) == 1810.0 );
          REQUIRE( areas.getArea("W19000003").getMeasure("d").getValue(2003) == 1930.0 );

          REQUIRE( areas.getArea("W19000003").getMeasure("pa").getValue(2002) == 440.0 );
          REQUIRE( areas.getArea("W19000003").getMeasure("pa").getValue(2003) == 456.0 );

          REQUIRE( areas.getArea("W19000003").getMeasure("pb").getValue(2002) == 49.0 );
          REQUIRE( areas.getArea("W19000003").getMeasure("pb").getValue(2003) == 67.0 );

          REQUIRE( areas.getArea("W19000003").getMeasure("pd").getValue(2002) == 45.0 );
          REQUIRE( areas.getArea("W19000003").getMeasure("pd").getValue(2003) == 47.0 );

          REQUIRE( areas.getArea("W19000003").getMeasure("rb").getValue(2002) == 11.2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("rb").getValue(2003) == 14.8 );

          REQUIRE( areas.getArea("W19000003").getMeasure("rd").getValue(2002) == 10.2 );
          REQUIRE( areas.getArea("W19000003").getMeasure("rd").getValue(2003) == 10.4 );

          REQUIRE( areas.getArea("W19000004").getMeasure("a").getValue(2002) == 35490.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("a").getValue(2003) == 36555.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("a").getValue(2004) == 37395.0 );

          REQUIRE( areas.getArea("W19000004").getMeasure("b").getValue(2002) == 4095.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("b").getValue(2003) == 4975.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("b").getValue(2004) == 5270.0 );

          REQUIRE( areas.getArea("W19000004").getMeasure("d").getValue(2002) == 3705.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("d").getValue(2003) == 3870.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("d").getValue(2004) == 4250.0 );

          REQUIRE( areas.getArea("W19000004").getMeasure("pa").getValue(2002) == 399.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pa").getValue(2003) == 407.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pa").getValue(2004) == 411.0 );

          REQUIRE( areas.getArea("W19000004").getMeasure("pb").getValue(2002) == 46.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pb").getValue(2003) == 55.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pb").getValue(2004) == 58.0 );

          REQUIRE( areas.getArea("W19000004").getMeasure("pd").getValue(2002) == 42.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pd").getValue(2003) == 43.0 );
          REQUIRE( areas.getArea("W19000004").getMeasure("pd").getValue(2004) == 47.0 );

          REQUIRE( areas.getArea("W19000004").getMeasure("rb").getValue(2002) == 11.5 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rb").getValue(2003) == 13.6 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rb").getValue(2004) == 14.1 );

          REQUIRE( areas.getArea("W19000004").getMeasure("rd").getValue(2002) == 10.4 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rd").getValue(2003) == 10.6 );
          REQUIRE( areas.getArea("W19000004").getMeasure("rd").getValue(2004) == 11.4 );

          REQUIRE( areas.getArea("W92000004").getMeasure("a").getValue(2002) == 81175.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("a").getValue(2003) == 83970.0 );

          REQUIRE( areas.getArea("W92000004").getMeasure("b").getValue(2002) == 8970.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("b").getValue(2003) == 11045.0 );

          REQUIRE( areas.getArea("W92000004").getMeasure("d").getValue(2002) == 7890.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("d").getValue(2003) == 8600.0 );

          REQUIRE( areas.getArea("W92000004").getMeasure("pa").getValue(2002) == 443.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pa").getValue(2003) == 454.0 );

          REQUIRE( areas.getArea("W92000004").getMeasure("pb").getValue(2002) == 49.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pb").getValue(2003) == 60.0 );

          REQUIRE( areas.getArea("W92000004").getMeasure("pd").getValue(2002) == 43.0 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pd").getValue(2003) == 47.0 );

          REQUIRE( areas.getArea("W92000004").getMeasure("rb").getValue(2002) == 11.1 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rb").getValue(2003) == 13.2 );

          REQUIRE( areas.getArea("W92000004").getMeasure("rd").getValue(2002) == 9.7 );
          REQUIRE( areas.getArea("W92000004").getMeasure("rd").getValue(2003) == 10.2 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("a").getValue(2002) == 25675.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("a").getValue(2003) == 26895.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("a").getValue(2004) == 27940.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("b").getValue(2002) == 2775.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("b").getValue(2003) == 3705.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("b").getValue(2004) == 3635.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("d").getValue(2002) == 2425.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("d").getValue(2003) == 2650.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("d").getValue(2004) == 2605.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("pa").getValue(2002) == 487.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pa").getValue(2003) == 504.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pa").getValue(2004) == 518.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("pb").getValue(2002) == 53.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pb").getValue(2003) == 69.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pb").getValue(2004) == 67.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("pd").getValue(2002) == 46.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pd").getValue(2003) == 50.0 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("pd").getValue(2004) == 48.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("rb").getValue(2002) == 10.8 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rb").getValue(2003) == 13.8 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rb").getValue(2004) == 13.0 );

          REQUIRE( areas.getArea("WXX000002").getMeasure("rd").getValue(2002) == 9.4 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rd").getValue(2003) == 9.9 );
          REQUIRE( areas.getArea("WXX000002").getMeasure("rd").getValue(2004) == 9.3 );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN
  
} // SCENARIO