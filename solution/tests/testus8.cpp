


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

SCENARIO( "envi0201.json can be correctly parsed", "[Areas][envi0201]" ) {

  auto get_istream = [](const std::string &path) {
    return std::ifstream(path);
  };

  GIVEN( "a newly constructed Areas instance" ) {

    Areas areas = Areas();

    AND_GIVEN( "a valid envi0201.json file as an open std::istream" ) {

      const std::string test_file = "datasets/envi0201.json";
      auto stream                 = get_istream(test_file);

      REQUIRE( stream.is_open() );

      THEN( "the Areas instance will be populated without exception" ) {

        REQUIRE_NOTHROW( areas.populateFromWelshStatsJSON(stream, BethYw::InputFiles::DATASETS[2].COLS, nullptr, nullptr, nullptr) );

        AND_THEN( "the Areas instance has size 30" ) {

          REQUIRE( areas.size() == 30 );

        } // AND_THEN

        AND_THEN( "each Area in the Areas instance has the correct size (30)" ) {

          REQUIRE( areas.getArea("W06000001").size() == 3 );
          REQUIRE( areas.getArea("W06000002").size() == 3 );
          REQUIRE( areas.getArea("W06000003").size() == 3 );
          REQUIRE( areas.getArea("W06000004").size() == 3 );
          REQUIRE( areas.getArea("W06000005").size() == 3 );
          REQUIRE( areas.getArea("W06000006").size() == 3 );
          REQUIRE( areas.getArea("W06000008").size() == 3 );
          REQUIRE( areas.getArea("W06000009").size() == 3 );
          REQUIRE( areas.getArea("W06000010").size() == 3 );
          REQUIRE( areas.getArea("W06000011").size() == 3 );
          REQUIRE( areas.getArea("W06000012").size() == 3 );
          REQUIRE( areas.getArea("W06000013").size() == 3 );
          REQUIRE( areas.getArea("W06000014").size() == 3 );
          REQUIRE( areas.getArea("W06000015").size() == 3 );
          REQUIRE( areas.getArea("W06000016").size() == 3 );
          REQUIRE( areas.getArea("W06000018").size() == 3 );
          REQUIRE( areas.getArea("W06000019").size() == 3 );
          REQUIRE( areas.getArea("W06000020").size() == 3 );
          REQUIRE( areas.getArea("W06000021").size() == 3 );
          REQUIRE( areas.getArea("W06000022").size() == 3 );
          REQUIRE( areas.getArea("W06000023").size() == 3 );
          REQUIRE( areas.getArea("W06000024").size() == 3 );
          REQUIRE( areas.getArea("W11000023").size() == 3 );
          REQUIRE( areas.getArea("W11000024").size() == 3 );
          REQUIRE( areas.getArea("W11000025").size() == 3 );
          REQUIRE( areas.getArea("W11000028").size() == 3 );
          REQUIRE( areas.getArea("W11000029").size() == 3 );
          REQUIRE( areas.getArea("W11000030").size() == 3 );
          REQUIRE( areas.getArea("W11000031").size() == 3 );
          REQUIRE( areas.getArea("W92000004").size() == 3 );

        } // AND_THEN

        AND_THEN( "each Measure in each Area in the Areas instance has the correct size (mixed)" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").size() == 12 );

          REQUIRE( areas.getArea("W06000002").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").size() == 12 );

          REQUIRE( areas.getArea("W06000003").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").size() == 12 );

          REQUIRE( areas.getArea("W06000004").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").size() == 12 );

          REQUIRE( areas.getArea("W06000005").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").size() == 12 );

          REQUIRE( areas.getArea("W06000006").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").size() == 12 );

          REQUIRE( areas.getArea("W06000008").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").size() == 12 );

          REQUIRE( areas.getArea("W06000009").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000010").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000011").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000012").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000013").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000014").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000015").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000016").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000018").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000019").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").size() == 12 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000020").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000021").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000022").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000023").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W06000024").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W11000023").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W11000024").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W11000025").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W11000028").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W11000029").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W11000030").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").size() == 11 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W11000031").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").size() == 12 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").size() == 11 );

          REQUIRE( areas.getArea("W92000004").getMeasure("no2").size() == 11 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").size() == 12 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").size() == 11 );

        } // AND THEN

        AND_THEN( "each Measure in each Area in the Areas instance has the correct value (mixed)" ) {

          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2007) == 7.4250068799986271 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2008) == 7.0453670168950067 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2009) == 5.8736632323168769 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2010) == 6.6102247037632129 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2011) == 5.3973555466864685 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2012) == 5.4687098138778116 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2013) == 5.4740443982149611 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2014) == 4.8111956896672223 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2015) == 4.4213722661923680 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2016) == 4.7431925967265915 );
          REQUIRE( areas.getArea("W06000001").getMeasure("no2").getValue(2017) == 4.5428825726151515 );

          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2007) == 12.1103429525885652 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2008) == 10.6011617393602389 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2009) == 10.3395372130908647 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2010) == 10.2856672161947367 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2011) == 11.2601005302821127 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2012) == 10.4143681427639779 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2013) == 10.8547376020883605 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2014) == 10.6409890186712797 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2015) == 9.4420983039552263 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2016) == 8.5379955325537176 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm10").getValue(2017) == 7.2225446404220841 );

          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2007) == 6.1997946115618874 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2008) == 6.4066902736715505 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2009) == 6.5665831906455173 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2010) == 7.0223927806297543 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2011) == 7.1931936101672326 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2012) == 6.9729023255875652 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2013) == 7.4299914554639103 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2014) == 7.1668671314981586 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2015) == 6.1396016110006803 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2016) == 5.3739570731763385 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2017) == 4.7473562012714288 );
          REQUIRE( areas.getArea("W06000001").getMeasure("pm2-5").getValue(2018) == 6.0910032386793926 );

          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2007) == 6.8619374771130574 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2008) == 6.5468747141288448 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2009) == 5.2895091217626947 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2010) == 6.1413773805676065 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2011) == 5.7552101628259182 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2012) == 5.6674185176278054 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2013) == 5.7611298789256815 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2014) == 4.9920745122874329 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2015) == 4.3833247290758375 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2016) == 4.9056185253550638 );
          REQUIRE( areas.getArea("W06000002").getMeasure("no2").getValue(2017) == 4.5435391738454653 );

          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2007) == 12.1815018614050239 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2008) == 10.5173608193196740 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2009) == 10.3592620339260787 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2010) == 10.0348495415798941 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2011) == 11.2760832208766660 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2012) == 10.3313573063137583 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2013) == 10.9936389973719021 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2014) == 10.6088746537054662 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2015) == 10.0553837663288846 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2016) == 8.6550223566181082 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm10").getValue(2017) == 7.2802128279742639 );

          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2007) == 6.3289764869205512 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2008) == 6.4350856913720469 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2009) == 6.7046216575845462 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2010) == 6.9778330411177434 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2011) == 7.3683382153280311 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2012) == 7.0056555319046304 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2013) == 7.7597340530552934 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2014) == 7.4482358380217892 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2015) == 6.7072078263664810 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2016) == 5.5472958515730434 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2017) == 4.8743772219440554 );
          REQUIRE( areas.getArea("W06000002").getMeasure("pm2-5").getValue(2018) == 6.2607324582523967 );

          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2007) == 9.5074776772931946 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2008) == 9.1511865854101017 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2009) == 8.0369023435021868 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2010) == 8.7702409825677801 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2011) == 8.1337578061644634 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2012) == 8.0611660863243428 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2013) == 8.1761756481543012 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2014) == 7.6140831996810226 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2015) == 5.5739792817638319 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2016) == 7.1030928164094520 );
          REQUIRE( areas.getArea("W06000003").getMeasure("no2").getValue(2017) == 6.5872292979716909 );

          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2007) == 12.7750172366049331 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2008) == 11.1825690337816638 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2009) == 11.1287569661902822 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2010) == 10.6955579772934747 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2011) == 11.8972431952188749 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2012) == 10.8154095063430805 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2013) == 11.3740355307405456 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2014) == 11.0959451044582575 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2015) == 10.3053657429411674 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2016) == 9.3906675819091348 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm10").getValue(2017) == 7.9058637781811080 );

          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2007) == 6.7089206095107358 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2008) == 7.0117389435029349 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2009) == 7.3150699733830822 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2010) == 7.5015601258100244 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2011) == 7.8664322361839576 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2012) == 7.4302394714587205 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2013) == 8.0152572459970920 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2014) == 7.7713164998027064 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2015) == 6.9069895675282172 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2016) == 6.0885003064640017 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2017) == 5.2886022482657202 );
          REQUIRE( areas.getArea("W06000003").getMeasure("pm2-5").getValue(2018) == 6.5811862058066490 );

          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2007) == 9.0284810873435013 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2008) == 8.5848944016928189 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2009) == 8.1545340912933880 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2010) == 8.6910505750710169 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2011) == 7.9908564215954610 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2012) == 8.1159154263004041 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2013) == 8.1390237731339255 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2014) == 7.4650787399472986 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2015) == 5.9598000543278979 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2016) == 6.5620822298544314 );
          REQUIRE( areas.getArea("W06000004").getMeasure("no2").getValue(2017) == 6.0618296673215086 );

          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2007) == 13.1246148375827299 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2008) == 11.6966340483044579 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2009) == 12.1077036802224950 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2010) == 11.3801739645411020 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2011) == 12.4890523657578323 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2012) == 11.2358390013055962 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2013) == 11.9165741728800217 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2014) == 11.7555484548763779 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2015) == 11.0902595664892717 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2016) == 10.0668164824981664 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm10").getValue(2017) == 8.7039786693117083 );

          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2007) == 6.9996599606846658 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2008) == 7.3478857419921770 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2009) == 7.9552247546707213 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2010) == 7.8983376192757415 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2011) == 8.2643296168025413 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2012) == 7.8067159194242536 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2013) == 8.5109359981160151 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2014) == 8.2999347720514284 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2015) == 7.5176293523639142 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2016) == 6.5991067452585099 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2017) == 5.8192846379120786 );
          REQUIRE( areas.getArea("W06000004").getMeasure("pm2-5").getValue(2018) == 6.8594184080978946 );

          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2007) == 13.4977131461402635 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2008) == 12.8891047084634797 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2009) == 13.9734888676376728 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2010) == 15.6855222517395549 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2011) == 12.7711311861619068 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2012) == 13.2259996074424672 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2013) == 12.3903591923146869 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2014) == 11.8162723106383326 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2015) == 9.3516434570828793 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2016) == 10.5198731869817171 );
          REQUIRE( areas.getArea("W06000005").getMeasure("no2").getValue(2017) == 9.0632039248879667 );

          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2007) == 14.6599392288236385 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2008) == 13.2619005704181294 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2009) == 13.8135506918633785 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2010) == 13.6951394248323146 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2011) == 14.8591855534993478 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2012) == 13.2241914891692554 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2013) == 13.1959876494135849 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2014) == 13.3131468439970169 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2015) == 12.0081770458471723 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2016) == 11.3918450247738448 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm10").getValue(2017) == 9.8148129037566691 );

          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2007) == 7.8965502850576070 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2008) == 8.5567909508630170 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2009) == 9.1022733611755674 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2010) == 9.3860568878389811 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2011) == 9.5980112313357187 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2012) == 9.1862846353502520 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2013) == 9.3200618500946947 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2014) == 9.1663419977237811 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2015) == 8.0212610664179313 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2016) == 7.5432006566066893 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2017) == 6.5529741031407795 );
          REQUIRE( areas.getArea("W06000005").getMeasure("pm2-5").getValue(2018) == 7.2760427373847506 );

          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2007) == 12.7393747649827434 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2008) == 11.8352410154185296 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2009) == 12.4478799399652273 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2010) == 14.0441777250677416 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2011) == 11.6756876482844517 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2012) == 11.7949807085506274 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2013) == 11.1997309983869241 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2014) == 10.2877704234412275 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2015) == 8.2618381115791869 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2016) == 9.1878748456020368 );
          REQUIRE( areas.getArea("W06000006").getMeasure("no2").getValue(2017) == 7.9653973230982053 );

          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2007) == 14.1469943575522344 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2008) == 12.9133162804465851 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2009) == 13.3600289182847240 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2010) == 12.9478294833333220 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2011) == 13.9908463973384535 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2012) == 12.4341050698321834 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2013) == 12.8959076904338415 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2014) == 12.7779894448556010 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2015) == 11.9226350801736027 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2016) == 11.5146913190461720 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm10").getValue(2017) == 9.9695164642585522 );

          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2007) == 7.7399419676118376 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2008) == 8.2957140578210072 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2009) == 8.8140619107200473 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2010) == 9.0072459058894348 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2011) == 9.2977428103204755 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2012) == 8.7943296115838891 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2013) == 9.3264291712738806 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2014) == 9.1945076816344204 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2015) == 8.0160571638997045 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2016) == 7.6180848407389841 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2017) == 6.7415958459619702 );
          REQUIRE( areas.getArea("W06000006").getMeasure("pm2-5").getValue(2018) == 7.4185923979945088 );

          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2007) == 7.1116968817300860 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2008) == 6.2270191000718965 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2009) == 5.5001048412669216 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2010) == 6.2195991845095173 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2011) == 5.8736053347007038 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2012) == 6.0013490981914978 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2013) == 6.1077181956880063 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2014) == 5.0783187006787102 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2015) == 4.5029124395543165 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2016) == 5.0086208268435610 );
          REQUIRE( areas.getArea("W06000008").getMeasure("no2").getValue(2017) == 3.9647822693494059 );

          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2007) == 13.2221637630348351 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2008) == 11.6613164444768256 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2009) == 11.3597951656243716 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2010) == 10.7478758171430214 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2011) == 11.8989243103496795 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2012) == 10.5155683579484313 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2013) == 11.3131502424323787 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2014) == 10.8603151213003502 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2015) == 10.2603233629363972 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2016) == 9.4390326908645942 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm10").getValue(2017) == 8.4402845898262743 );

          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2007) == 7.0542055876681193 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2008) == 7.0997833067059966 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2009) == 7.3307013108288473 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2010) == 7.3778285887625818 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2011) == 7.8635236614712002 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2012) == 7.2279808741218752 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2013) == 7.9160420095695982 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2014) == 7.5828151505606453 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2015) == 6.7468754838625372 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2016) == 5.7937538098072317 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2017) == 5.5570277728698978 );
          REQUIRE( areas.getArea("W06000008").getMeasure("pm2-5").getValue(2018) == 6.3451315336654839 );

          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2007) == 8.7682230292697101 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2008) == 9.3052704596721335 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2009) == 9.0419753428370555 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2010) == 9.0960078857139227 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2011) == 8.8778216147079773 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2012) == 9.5304706757923197 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2013) == 8.9156110973733740 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2014) == 7.6484806836845917 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2015) == 7.4782102523372635 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2016) == 7.4485917288948634 );
          REQUIRE( areas.getArea("W06000009").getMeasure("no2").getValue(2017) == 5.4335973949080425 );

          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2007) == 15.1173678065351589 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2008) == 13.4224968981523084 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2009) == 12.0726123200802438 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2010) == 12.7338180039592871 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2011) == 12.9254218974075790 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2012) == 11.9266151525011381 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2013) == 13.0592917481871766 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2014) == 12.6311872962700953 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2015) == 10.8973517951494927 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2016) == 11.1997334509742248 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm10").getValue(2017) == 9.8467093678351765 );

          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2007) == 8.1310690354538149 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2008) == 8.0025511015350282 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2009) == 7.6853393184964673 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2010) == 8.3924579984639708 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2011) == 8.2638909429603398 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2012) == 7.9704486610405863 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2013) == 8.7310294661673876 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2014) == 8.3785652626545155 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2015) == 6.9334541622291945 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2016) == 6.4697047202286408 );
          REQUIRE( areas.getArea("W06000009").getMeasure("pm2-5").getValue(2017) == 6.0988590064414694 );

          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2007) == 9.4017446526870826 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2008) == 8.7394525855774475 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2009) == 8.6436979319987571 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2010) == 8.9093666478860141 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2011) == 7.9119629898332699 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2012) == 8.2814924202925790 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2013) == 8.0081560408057988 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2014) == 6.5233033320569887 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2015) == 5.5402858395525934 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2016) == 6.8583000941704210 );
          REQUIRE( areas.getArea("W06000010").getMeasure("no2").getValue(2017) == 5.3919630550946687 );

          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2007) == 15.0698390814751517 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2008) == 13.0121142417093260 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2009) == 12.3421087831015463 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2010) == 12.4481269308633829 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2011) == 12.9597008660814657 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2012) == 11.8061897933292552 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2013) == 13.0702199162909591 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2014) == 12.6907363158147091 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2015) == 11.2670193725995669 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2016) == 10.9465970967219042 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm10").getValue(2017) == 9.7019331351517431 );

          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2007) == 8.1580624379259203 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2008) == 8.0700475596381071 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2009) == 8.0461069970761718 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2010) == 8.5215959546039854 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2011) == 8.6199508119041883 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2012) == 8.2123706333480935 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2013) == 9.3146809629943775 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2014) == 8.9769444641598259 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2015) == 7.5099431721294154 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2016) == 6.6660539965307959 );
          REQUIRE( areas.getArea("W06000010").getMeasure("pm2-5").getValue(2017) == 6.3428105702635377 );

          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2007) == 14.3127942819817275 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2008) == 13.9309185341640038 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2009) == 13.0798476070517548 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2010) == 13.9201701885689792 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2011) == 12.5018018323713821 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2012) == 12.9380519759084337 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2013) == 12.3434377627438385 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2014) == 10.8408213444493280 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2015) == 9.6051833179655021 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2016) == 11.1768118829020258 );
          REQUIRE( areas.getArea("W06000011").getMeasure("no2").getValue(2017) == 9.4560870076348187 );

          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2007) == 16.3373692762680347 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2008) == 14.0005934563934091 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2009) == 12.9573860378782740 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2010) == 13.1147455043959649 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2011) == 13.6973941041106773 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2012) == 12.1492057517253341 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2013) == 13.4154435090181201 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2014) == 13.4860734073898462 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2015) == 12.3106389020561671 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2016) == 11.8713071105072472 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm10").getValue(2017) == 10.4109770998365528 );

          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2007) == 8.7589447447200754 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2008) == 8.9418687776557774 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2009) == 8.5538379224853976 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2010) == 9.0548819749618734 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2011) == 9.2089578870725855 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2012) == 8.5365953600952718 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2013) == 9.4058708230282185 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2014) == 9.4483860656424695 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2015) == 8.2172058940747661 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2016) == 7.4545749755068723 );
          REQUIRE( areas.getArea("W06000011").getMeasure("pm2-5").getValue(2017) == 7.0257550743284663 );

          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2007) == 14.1627534113238403 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2008) == 13.4865159181856292 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2009) == 13.1691972551202033 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2010) == 13.5983558470527608 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2011) == 12.9746210168710847 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2012) == 13.3113135159051620 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2013) == 12.2842070939542724 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2014) == 11.5766986836335277 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2015) == 9.8648314211783285 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2016) == 11.6964100521256958 );
          REQUIRE( areas.getArea("W06000012").getMeasure("no2").getValue(2017) == 9.8304047590716486 );

          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2007) == 16.1128274822317555 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2008) == 14.3059735384466574 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2009) == 13.3510185169041732 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2010) == 13.0592368163273555 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2011) == 14.0368470112376141 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2012) == 12.3258305174565708 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2013) == 13.8367462844076761 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2014) == 13.5337425524957879 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2015) == 12.4515653859962867 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2016) == 11.8744156099313519 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm10").getValue(2017) == 10.6029053806935643 );

          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2007) == 8.7751000343101131 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2008) == 9.0524750557604278 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2009) == 8.7868276587008848 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2010) == 9.0106348654994746 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2011) == 9.4374175942434501 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2012) == 8.7630438540794391 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2013) == 9.8967827700852194 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2014) == 9.5780516413253357 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2015) == 8.2965949878308588 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2016) == 7.3596409383760373 );
          REQUIRE( areas.getArea("W06000012").getMeasure("pm2-5").getValue(2017) == 7.0392353703167257 );

          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2007) == 14.8018787873225032 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2008) == 14.1659800276507219 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2009) == 13.6527475276510404 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2010) == 14.7319055432625465 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2011) == 13.2264529812969775 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2012) == 13.1340228410517642 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2013) == 12.0790243746901619 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2014) == 11.5098080965025985 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2015) == 9.9580466210764578 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2016) == 11.9460187155099264 );
          REQUIRE( areas.getArea("W06000013").getMeasure("no2").getValue(2017) == 9.6325768597967399 );

          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2007) == 16.1345187286032898 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2008) == 14.3473628121556549 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2009) == 13.9341403878171034 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2010) == 13.1944819500177901 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2011) == 13.9269284516961250 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2012) == 12.1449394881363469 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2013) == 13.7920591429484647 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2014) == 13.4078093234572311 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2015) == 11.9359309055883073 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2016) == 12.0413478931551795 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm10").getValue(2017) == 10.7297779542893274 );

          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2007) == 8.9024911399114748 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2008) == 9.1772659452853291 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2009) == 9.2008076731819987 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2010) == 9.1266772536059549 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2011) == 9.4121274847962740 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2012) == 8.6601718406687166 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2013) == 9.9250798446669790 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2014) == 9.5343772015794749 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2015) == 7.8400207746637616 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2016) == 7.5395093240193404 );
          REQUIRE( areas.getArea("W06000013").getMeasure("pm2-5").getValue(2017) == 7.1462023719194244 );

          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2007) == 13.5243671676856428 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2008) == 13.1122191639152012 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2009) == 13.8459372702850510 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2010) == 15.1053706925351474 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2011) == 13.0132415499473905 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2012) == 13.2323116652252264 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2013) == 12.8859822807984114 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2014) == 12.0020818215152025 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2015) == 11.6334393640522333 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2016) == 12.7158903383756429 );
          REQUIRE( areas.getArea("W06000014").getMeasure("no2").getValue(2017) == 9.3574476060118494 );

          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2007) == 15.9973151505418237 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2008) == 14.1670806840526579 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2009) == 14.3800952916450843 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2010) == 13.3941945577432150 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2011) == 13.9689876994811143 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2012) == 12.0436485454816642 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2013) == 13.4039093470746166 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2014) == 12.9991025702413448 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2015) == 12.3035125472179565 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2016) == 12.1575585985776016 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm10").getValue(2017) == 10.8802022212825099 );

          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2007) == 8.9930373402555986 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2008) == 9.1686704457780174 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2009) == 9.6416850007758053 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2010) == 9.3970963235795597 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2011) == 9.5955048176197584 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2012) == 8.6720526016745386 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2013) == 9.6018607773723355 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2014) == 9.1792017884850612 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2015) == 8.2062522697561322 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2016) == 7.7774990327366656 );
          REQUIRE( areas.getArea("W06000014").getMeasure("pm2-5").getValue(2017) == 7.3117890195551804 );

          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2007) == 21.6854928828269380 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2008) == 22.1359713734490785 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2009) == 22.6732378949882196 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2010) == 23.9548785647773031 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2011) == 23.0057824233203129 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2012) == 22.4990636688865525 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2013) == 21.5435573405496242 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2014) == 21.1293168957934361 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2015) == 19.3903630748505403 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2016) == 20.9177113157809325 );
          REQUIRE( areas.getArea("W06000015").getMeasure("no2").getValue(2017) == 17.2512643075042271 );

          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2007) == 18.3441999868047545 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2008) == 16.3619759540629380 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2009) == 16.1165762627353912 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2010) == 15.6843188253870333 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2011) == 16.5473291528784498 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2012) == 14.0101633366491354 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2013) == 15.5859292761661928 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2014) == 15.3571788633806702 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2015) == 15.2582815943729293 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2016) == 14.3256461733725904 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm10").getValue(2017) == 12.9035774811455877 );

          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2007) == 9.9882469719630512 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2008) == 10.8818295965491796 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2009) == 10.8499545309620951 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2010) == 11.0206379610833343 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2011) == 11.3033964406529423 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2012) == 10.3943603508106042 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2013) == 11.1630444991231510 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2014) == 10.8525787604267751 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2015) == 10.1327746343429384 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2016) == 9.3105219731256100 );
          REQUIRE( areas.getArea("W06000015").getMeasure("pm2-5").getValue(2017) == 8.7800529645354810 );

          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2007) == 13.3787275114293253 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2008) == 13.1438835102024684 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2009) == 13.5733416198631689 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2010) == 14.2215455525761665 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2011) == 12.6705760095913769 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2012) == 12.6707819643675881 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2013) == 11.8815912543686272 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2014) == 10.8246408563872337 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2015) == 9.1551565372379348 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2016) == 11.4813464866510707 );
          REQUIRE( areas.getArea("W06000016").getMeasure("no2").getValue(2017) == 8.9351918136633105 );

          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2007) == 15.9895635024362843 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2008) == 14.2626975218178039 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2009) == 13.8689748344116912 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2010) == 13.3311400524246620 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2011) == 14.1889318147515434 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2012) == 12.3292558731024201 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2013) == 14.8185386956599456 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2014) == 14.2056450541429308 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2015) == 13.2449705284413166 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2016) == 12.1081653743944735 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm10").getValue(2017) == 10.8212198574939727 );

          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2007) == 8.8450725030498642 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2008) == 9.1746680670826645 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2009) == 9.2048295730237927 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2010) == 9.3280691331577645 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2011) == 9.6656235207986054 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2012) == 8.8957545048461163 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2013) == 11.1081083528542650 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2014) == 10.5127292171679133 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2015) == 9.0867293556600347 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2016) == 7.7812397924891841 );
          REQUIRE( areas.getArea("W06000016").getMeasure("pm2-5").getValue(2017) == 7.3096346905138084 );

          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2007) == 15.2270698820136707 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2008) == 14.8048198278234703 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2009) == 15.8862562508085840 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2010) == 16.2431064433812116 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2011) == 14.8189271841052264 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2012) == 14.4690510585341278 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2013) == 13.5944467953923100 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2014) == 12.4890642636681269 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2015) == 11.3936531182723409 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2016) == 13.1103662165772259 );
          REQUIRE( areas.getArea("W06000018").getMeasure("no2").getValue(2017) == 10.3036777033261390 );

          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2007) == 16.5730439772133070 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2008) == 14.6727637483707734 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2009) == 14.6651498418688046 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2010) == 13.9112561724938683 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2011) == 14.9760570790595214 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2012) == 12.8644548033725538 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2013) == 15.2596207208012178 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2014) == 14.7676601892440942 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2015) == 13.6700181901179686 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2016) == 12.4651647222921982 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm10").getValue(2017) == 11.3103727414902558 );

          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2007) == 9.1740623029002073 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2008) == 9.5883881579904806 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2009) == 9.7978648340984281 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2010) == 9.8213155829376177 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2011) == 10.2490742698882414 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2012) == 9.4570782368194980 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2013) == 11.4680656646000853 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2014) == 10.9565928773419254 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2015) == 9.3648650127916990 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2016) == 8.1238959143778754 );
          REQUIRE( areas.getArea("W06000018").getMeasure("pm2-5").getValue(2017) == 7.6800592911858715 );

          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2007) == 13.2622894520022175 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2008) == 12.5425833779305905 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2009) == 13.1055699644616887 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2010) == 13.8935045391393531 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2011) == 11.4768915157013982 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2012) == 10.9505817839103491 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2013) == 10.4270610599302388 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2014) == 9.1851941861243683 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2015) == 8.0496722470058719 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2016) == 10.1430018076782851 );
          REQUIRE( areas.getArea("W06000019").getMeasure("no2").getValue(2017) == 7.5500087117307368 );

          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2007) == 15.7415645406524069 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2008) == 13.9837197525326971 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2009) == 13.8682912765712425 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2010) == 13.3065501439806765 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2011) == 14.0291151011618685 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2012) == 12.1667335555622115 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2013) == 14.3260035605560833 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2014) == 13.8503293007400142 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2015) == 12.6374985082152309 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2016) == 11.8254706917649057 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2017) == 10.7458402855470582 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm10").getValue(2018) == 11.6894543995612145 );

          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2007) == 8.8311785012377337 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2008) == 9.0874204768384457 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2009) == 9.2862611415863382 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2010) == 9.4535158788120820 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2011) == 9.6834902579159137 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2012) == 8.8901731957467367 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2013) == 10.7890135519503879 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2014) == 10.3880517312703323 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2015) == 8.7464883253835246 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2016) == 7.7439251938979071 );
          REQUIRE( areas.getArea("W06000019").getMeasure("pm2-5").getValue(2017) == 7.3349369828227849 );

          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2007) == 15.2080417320946942 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2008) == 14.4223720654953132 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2009) == 15.7966928529283313 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2010) == 15.9690618264798108 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2011) == 15.0560627582489205 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2012) == 14.3593347191816397 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2013) == 13.3156223828194033 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2014) == 11.9896893864478277 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2015) == 11.3197276446569109 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2016) == 13.0437264324131547 );
          REQUIRE( areas.getArea("W06000020").getMeasure("no2").getValue(2017) == 9.8578053944030036 );

          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2007) == 16.6193401839041765 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2008) == 14.6865077916776684 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2009) == 15.1653400618820903 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2010) == 14.1129981601579600 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2011) == 15.1324048837883494 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2012) == 12.9947219604998825 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2013) == 14.6712486084752587 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2014) == 14.1234648400284890 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2015) == 12.9555172765317233 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2016) == 12.5082579969166188 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm10").getValue(2017) == 11.3928837414213946 );

          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2007) == 9.3349132494057945 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2008) == 9.6546491260626347 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2009) == 10.2059914084241605 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2010) == 10.0132764970959904 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2011) == 10.4696485319826012 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2012) == 9.6382833213922271 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2013) == 10.8644471059561478 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2014) == 10.4005410559099989 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2015) == 8.8948317019946012 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2016) == 8.2838216915773328 );
          REQUIRE( areas.getArea("W06000020").getMeasure("pm2-5").getValue(2017) == 7.8331763967220314 );

          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2007) == 13.6393009470651536 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2008) == 12.0353579601971046 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2009) == 12.7796003143763741 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2010) == 13.1821812945665880 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2011) == 12.0520537819179734 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2012) == 11.5369890341800176 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2013) == 11.0630712080988177 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2014) == 9.9588852624077045 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2015) == 7.6142611852320217 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2016) == 11.1394022932391602 );
          REQUIRE( areas.getArea("W06000021").getMeasure("no2").getValue(2017) == 8.2231934856570752 );

          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2007) == 15.7293391494285903 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2008) == 14.2629262890595105 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2009) == 14.4731550304088687 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2010) == 13.4776483957437234 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2011) == 14.5767961556427475 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2012) == 12.5792956504696166 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2013) == 14.0044109393911120 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2014) == 13.8369298938427866 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2015) == 12.0399150996592345 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2016) == 12.3509253349701907 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm10").getValue(2017) == 11.5107541974746313 );

          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2007) == 9.0298953652866654 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2008) == 9.1544166872798508 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2009) == 9.5695500817599448 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2010) == 9.3944814624113527 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2011) == 9.9840376646667768 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2012) == 9.1280569426742872 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2013) == 10.1171384849489762 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2014) == 9.8278292061324903 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2015) == 8.1038590668125952 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2016) == 7.9031436843021086 );
          REQUIRE( areas.getArea("W06000021").getMeasure("pm2-5").getValue(2017) == 7.6762324350753340 );

          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2007) == 23.9495974543871545 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2008) == 22.5046134123243824 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2009) == 24.6049911795036440 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2010) == 24.8602147405637163 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2011) == 22.3556929943934294 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2012) == 21.8269185859994661 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2013) == 20.0481900022659343 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2014) == 18.8997842185556115 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2015) == 16.1752449043743474 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2016) == 19.2666876238833709 );
          REQUIRE( areas.getArea("W06000022").getMeasure("no2").getValue(2017) == 16.3997034238370071 );

          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2007) == 18.5139642441121967 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2008) == 16.7556616871473879 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2009) == 16.3051479962252911 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2010) == 15.5268184545586617 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2011) == 16.8165722402480226 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2012) == 14.4973499807896194 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2013) == 15.5709968177969212 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2014) == 15.4338753151086201 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2015) == 14.6381797871030952 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2016) == 14.0738504307785387 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm10").getValue(2017) == 12.9745428177247928 );

          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2007) == 10.2206890604445727 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2008) == 11.1059467300226980 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2009) == 11.0513593662807971 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2010) == 10.9535535247138128 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2011) == 11.5203433551419204 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2012) == 10.7729307510398965 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2013) == 11.1857543036822679 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2014) == 11.0480876483183977 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2015) == 9.8129793474207676 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2016) == 9.0057459187094192 );
          REQUIRE( areas.getArea("W06000022").getMeasure("pm2-5").getValue(2017) == 8.7353682582708889 );

          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2007) == 7.9215396048459868 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2008) == 7.1470226780073546 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2009) == 6.5555712147857602 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2010) == 7.5521535619527265 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2011) == 7.0651483122588997 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2012) == 5.9525577531833188 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2013) == 6.1254256683238298 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2014) == 5.1767994700704506 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2015) == 4.3771813277660253 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2016) == 5.1158746954112541 );
          REQUIRE( areas.getArea("W06000023").getMeasure("no2").getValue(2017) == 3.8539368102946451 );

          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2007) == 13.3251657249934345 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2008) == 11.8417514029205371 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2009) == 11.9169136885903592 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2010) == 10.8989823458047016 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2011) == 12.2026990792647920 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2012) == 10.5479875929030617 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2013) == 11.5704473625158789 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2014) == 11.1610412170350977 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2015) == 10.0485167810273007 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2016) == 9.7293004885590740 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm10").getValue(2017) == 8.8905704214674551 );

          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2007) == 7.4285763877617930 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2008) == 7.4874549682865977 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2009) == 7.8962471900396809 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2010) == 7.7117537561939283 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2011) == 8.3224595504668688 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2012) == 7.5214347786095031 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2013) == 8.3923231119003018 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2014) == 8.0473266729672756 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2015) == 6.7206651164641378 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2016) == 6.2022643468364445 );
          REQUIRE( areas.getArea("W06000023").getMeasure("pm2-5").getValue(2017) == 5.9669435058268726 );

          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2007) == 13.2991009654502443 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2008) == 12.2945779325982384 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2009) == 12.3534813592629759 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2010) == 12.7281613567021839 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2011) == 11.7545725284926888 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2012) == 11.4440937391875653 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2013) == 10.8005246139515868 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2014) == 9.6710705048380821 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2015) == 8.2267637408776359 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2016) == 10.5175104891248364 );
          REQUIRE( areas.getArea("W06000024").getMeasure("no2").getValue(2017) == 8.1815135059618211 );

          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2007) == 15.7652449767093311 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2008) == 13.9855880984336890 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2009) == 13.6241692877313710 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2010) == 12.9374293384412985 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2011) == 14.0730287403604671 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2012) == 12.1950946541395958 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2013) == 14.5386244968218167 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2014) == 13.9543236606860704 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2015) == 12.9717734622408276 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2016) == 11.8996000194904345 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm10").getValue(2017) == 10.7689986751194519 );

          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2007) == 8.7392424644092427 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2008) == 8.9706004191765917 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2009) == 9.0260521791474052 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2010) == 9.0557020391671341 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2011) == 9.6100414865336745 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2012) == 8.8176540483873841 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2013) == 10.8999601591276610 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2014) == 10.3959451333831667 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2015) == 8.9296243316646221 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2016) == 7.6730940155372134 );
          REQUIRE( areas.getArea("W06000024").getMeasure("pm2-5").getValue(2017) == 7.2944632887817949 );

          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2007) == 10.2723495311317650 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2008) == 9.7501109967995145 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2009) == 9.5261985053612228 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2010) == 10.6387545061932220 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2011) == 9.1398311395962337 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2012) == 9.2597790745516730 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2013) == 9.0011409593377611 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2014) == 8.3063255424980784 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2015) == 6.6643672731198297 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2016) == 7.5691515547735560 );
          REQUIRE( areas.getArea("W11000023").getMeasure("no2").getValue(2017) == 6.7673697054765915 );

          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2007) == 13.3345890580160028 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2008) == 11.8747547852619298 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2009) == 12.0784902906032863 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2010) == 11.7361975820017379 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2011) == 12.8712507368759742 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2012) == 11.5979170750838728 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2013) == 12.0319684832668953 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2014) == 11.8769073564698352 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2015) == 10.9757132289799954 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2016) == 10.1263092493045909 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm10").getValue(2017) == 8.6624384175674765 );

          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2007) == 7.0931544336430896 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2008) == 7.4871387837792149 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2009) == 7.9083199727458111 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2010) == 8.1267326426566397 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2011) == 8.4292489286424282 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2012) == 8.0170419148296451 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2013) == 8.5260542366385955 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2014) == 8.3149762493796866 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2015) == 7.3420062507148429 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2016) == 6.6124152975768676 );
          REQUIRE( areas.getArea("W11000023").getMeasure("pm2-5").getValue(2017) == 5.7979108878692010 );

          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2007) == 7.9215396048459868 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2008) == 7.1470226780073546 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2009) == 6.5555712147857602 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2010) == 7.5521535619527265 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2011) == 7.0651483122588997 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2012) == 5.9525577531833188 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2013) == 6.1254256683238298 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2014) == 5.1767994700704506 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2015) == 4.3771813277660253 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2016) == 5.1158746954112541 );
          REQUIRE( areas.getArea("W11000024").getMeasure("no2").getValue(2017) == 3.8539368102946451 );

          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2007) == 13.3251657249934345 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2008) == 11.8417514029205371 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2009) == 11.9169136885903592 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2010) == 10.8989823458047016 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2011) == 12.2026990792647920 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2012) == 10.5479875929030617 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2013) == 11.5704473625158789 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2014) == 11.1610412170350977 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2015) == 10.0485167810273007 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2016) == 9.7293004885590740 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm10").getValue(2017) == 8.8905704214674551 );

          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2007) == 7.4285763877617930 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2008) == 7.4874549682865977 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2009) == 7.8962471900396809 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2010) == 7.7117537561939283 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2011) == 8.3224595504668688 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2012) == 7.5214347786095031 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2013) == 8.3923231119003018 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2014) == 8.0473266729672756 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2015) == 6.7206651164641378 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2016) == 6.2022643468364445 );
          REQUIRE( areas.getArea("W11000024").getMeasure("pm2-5").getValue(2017) == 5.9669435058268726 );

          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2007) == 8.7418772496336261 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2008) == 8.4229884221774821 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2009) == 8.1523971719353009 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2010) == 8.4371077911903827 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2011) == 7.8201849820061667 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2012) == 8.2300384327964333 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2013) == 7.9234697374085970 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2014) == 6.6018424408010241 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2015) == 5.9648955668070651 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2016) == 6.6942985214629201 );
          REQUIRE( areas.getArea("W11000025").getMeasure("no2").getValue(2017) == 5.1340487995939753 );

          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2007) == 14.7150714526893843 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2008) == 12.8759362932025926 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2009) == 12.0622454706886827 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2010) == 12.2034095218362667 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2011) == 12.7395411853472751 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2012) == 11.5888450747021096 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2013) == 12.7190357412201254 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2014) == 12.3120183783848209 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2015) == 10.9526974526179438 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2016) == 10.7391057044655327 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm10").getValue(2017) == 9.5089762349268703 );

          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2007) == 7.9285025873711608 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2008) == 7.8563300257270614 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2009) == 7.7895315359318549 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2010) == 8.2538863619736865 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2011) == 8.3564794965000357 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2012) == 7.9394860001455063 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2013) == 8.8505357461027062 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2014) == 8.5103913993413327 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2015) == 7.1760517299098042 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2016) == 6.4349836552846976 );
          REQUIRE( areas.getArea("W11000025").getMeasure("pm2-5").getValue(2017) == 6.1141881868060332 );

          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2007) == 16.9076827156002958 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2008) == 15.9569720941303854 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2009) == 17.2304894115927796 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2010) == 17.6005655393434561 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2011) == 15.9173351868796516 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2012) == 15.4216501399702438 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2013) == 14.3994374779770299 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2014) == 13.2330148410019595 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2015) == 11.5952446126981626 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2016) == 14.0057427031706116 );
          REQUIRE( areas.getArea("W11000028").getMeasure("no2").getValue(2017) == 11.1474534428685221 );

          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2007) == 16.8290927841982466 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2008) == 15.0473661394971128 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2009) == 15.0289960441664810 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2010) == 14.2081304879854604 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2011) == 15.2878579269623156 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2012) == 13.1683097852143675 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2013) == 14.9334093745531318 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2014) == 14.5763452192459729 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2015) == 13.4202668010957698 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2016) == 12.7887286511817513 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm10").getValue(2017) == 11.7172928582354528 );

          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2007) == 9.3960675652054581 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2008) == 9.8490348896117631 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2009) == 10.0790657980560224 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2010) == 10.0247181235023106 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2011) == 10.4946366636895783 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2012) == 9.6976899599324762 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2013) == 11.0046545082721866 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2014) == 10.6441511424082269 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2015) == 9.1297933445745479 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2016) == 8.2939987355678014 );
          REQUIRE( areas.getArea("W11000028").getMeasure("pm2-5").getValue(2017) == 7.9346048062952933 );

          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2007) == 19.4379901945597549 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2008) == 19.6618286595326404 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2009) == 20.2721477476138633 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2010) == 21.5632552561825519 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2011) == 20.3245992029876815 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2012) == 20.0264128391715150 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2013) == 19.2446198620378240 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2014) == 18.7113487000703647 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2015) == 17.3455015669182105 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2016) == 18.7605438573259537 );
          REQUIRE( areas.getArea("W11000029").getMeasure("no2").getValue(2017) == 15.1605649206052281 );

          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2007) == 17.6978841361213661 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2008) == 15.7601785268524817 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2009) == 15.6442418625784564 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2010) == 15.0653981010358645 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2011) == 15.8555147548064956 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2012) == 13.4854382313375758 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2013) == 15.0065135630081804 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2014) == 14.7324830547145116 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2015) == 14.4793523406167166 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2016) == 13.7554171020789455 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm10").getValue(2017) == 12.3676768051181946 );

          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2007) == 9.7141723463509612 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2008) == 10.4121145499125015 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2009) == 10.5212971089932874 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2010) == 10.5818655107473584 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2011) == 10.8451391065533804 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2012) == 9.9347968777576092 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2013) == 10.7484862356023634 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2014) == 10.4092718096247016 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2015) == 9.6249093168564567 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2016) == 8.9073212183799155 );
          REQUIRE( areas.getArea("W11000029").getMeasure("pm2-5").getValue(2017) == 8.3911764278240049 );

          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2007) == 13.8205572609141301 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2008) == 13.3562061740185309 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2009) == 13.4340393835043441 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2010) == 14.1828771776505154 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2011) == 12.7250998350469863 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2012) == 12.6534723912329696 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2013) == 11.7987901875464011 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2014) == 10.8901073393751063 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2015) == 9.2900733670703727 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2016) == 11.5019302173165214 );
          REQUIRE( areas.getArea("W11000030").getMeasure("no2").getValue(2017) == 9.0602342595424890 );

          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2007) == 16.0056566414519106 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2008) == 14.2525199369893204 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2009) == 13.8567813036162228 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2010) == 13.2338979868757618 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2011) == 14.0887433268297502 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2012) == 12.2517443678190304 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2013) == 14.4495896184551270 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2014) == 13.9139727069408234 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2015) == 12.7837781056352567 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2016) == 12.0582314001754710 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm10").getValue(2017) == 10.7844016407292001 );

          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2007) == 8.8491774705702419 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2008) == 9.1480936349980366 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2009) == 9.1794124359703663 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2010) == 9.2265018042674593 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2011) == 9.5763804029134440 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2012) == 8.8093491502516275 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2013) == 10.6983973516394801 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2014) == 10.1809233293954439 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2015) == 8.6614135070778518 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2016) == 7.6880527117318509 );
          REQUIRE( areas.getArea("W11000030").getMeasure("pm2-5").getValue(2017) == 7.2543975484833243 );

          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2007) == 14.2566588875969775 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2008) == 13.7650120627164014 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2009) == 13.1130805191276998 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2010) == 13.8009559987773585 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2011) == 12.6765025871242607 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2012) == 13.0757686146571820 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2013) == 12.3216915431060552 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2014) == 11.1116079525671209 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2015) == 9.7006732994450125 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2016) == 11.3674542722007341 );
          REQUIRE( areas.getArea("W11000031").getMeasure("no2").getValue(2017) == 9.5933191247392156 );

          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2007) == 16.2533618129647764 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2008) == 14.1145985814345265 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2009) == 13.1038004070521022 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2010) == 13.0941824967595752 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2011) == 13.8228171911845863 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2012) == 12.2143717031424398 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2013) == 13.5705047299497442 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2014) == 13.5036127037793365 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2015) == 12.3624695724336670 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2016) == 11.8724452929551451 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2017) == 10.4813425240508365 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm10").getValue(2018) == 12.0033654800745117 );

          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2007) == 8.7649886713781247 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2008) == 8.9831604310004035 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2009) == 8.6404999724473543 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2010) == 9.0384908128374662 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2011) == 9.2933705774982402 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2012) == 8.6201443897702674 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2013) == 9.5865283795287599 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2014) == 9.4960989772453806 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2015) == 8.2464044883570100 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2016) == 7.4197413958909380 );
          REQUIRE( areas.getArea("W11000031").getMeasure("pm2-5").getValue(2017) == 7.0306979409961823 );

          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2007) == 13.6060037576976520 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2008) == 13.1486233329092979 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2009) == 13.3129875843076804 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2010) == 14.1096668927729976 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2011) == 12.8286574417788937 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2012) == 12.7624146214393486 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2013) == 12.1536607792590975 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2014) == 11.2187484675915840 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2015) == 9.8268864788086676 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2016) == 11.3565306596963859 );
          REQUIRE( areas.getArea("W92000004").getMeasure("no2").getValue(2017) == 9.2677371676948168 );

          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2007) == 15.5634874513732198 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2008) == 13.7991359641457417 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2009) == 13.5481038731491537 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2010) == 13.1141602654884300 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2011) == 14.0303471804865063 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2012) == 12.3070031249585978 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2013) == 13.6363331392749429 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2014) == 13.3409194942897027 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2015) == 12.3688317414648799 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2016) == 11.7468299358932023 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2017) == 10.4623496871172127 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm10").getValue(2018) == 11.7916208584532221 );

          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2007) == 8.4976769370296729 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2008) == 8.8420344523633925 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2009) == 8.9712920026296057 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2010) == 9.1270277038215978 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2011) == 9.4456120687736010 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2012) == 8.7848782915896165 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2013) == 9.8094530283766961 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2014) == 9.5010742951497260 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2015) == 8.2870775587904482 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2016) == 7.5028816410844519 );
          REQUIRE( areas.getArea("W92000004").getMeasure("pm2-5").getValue(2017) == 7.0147761669978140 );

        } // AND_THEN

      } // THEN

    } // AND_GIVEN

  } // GIVEN
  
} // SCENARIO