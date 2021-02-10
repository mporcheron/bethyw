


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
#include <unordered_set>

#include "../lib_cxxopts.hpp"
#include "../lib_cxxopts_argv.hpp"

#include "../bethyw.h"

SCENARIO( "the program argument areas accept ALL in capitals too", "[args][ALL]" ) {

  GIVEN( "a --datasets program argument with a value 'ALL'" ) {

    WHEN( "the value is 'ALL'" ) {

      Argv argv({"test", "--datasets", "ALL"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseDatasetsArg(args) );
        
        AND_THEN( "the response is a container with 7 values" ) {

          auto areas = BethYw::parseDatasetsArg(args);
          REQUIRE( areas.size() == 7 );

        } // AND_THEN

      } // THEN

    } // WHEN

    WHEN( "the value is multiple comma-separated areas ('pop', 'ALL')" ) {

      Argv argv({"test", "--areas", "pop,ALL"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseDatasetsArg(args) );
        
        AND_THEN( "the response is a container with 7 values" ) {

          auto areas = BethYw::parseDatasetsArg(args);
          REQUIRE( areas.size() == 7 );
      
        } // AND_THEN

      } // THEN

    } // WHEN

  } // GIVEN

  GIVEN( "a --areas program argument with a value 'ALL'" ) {

    WHEN( "the value is 'ALL'" ) {

      Argv argv({"test", "--areas", "ALL"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseAreasArg(args) );
        
        AND_THEN( "the response is a container with 0 values" ) {

          auto areas = BethYw::parseAreasArg(args);
          REQUIRE( areas.size() == 0 );

        } // AND_THEN

      } // THEN

    } // WHEN

    WHEN( "the value is multiple comma-separated areas ('W06000011', 'ALL')" ) {

      Argv argv({"test", "--areas", "W06000011,ALL"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseAreasArg(args) );
        
        AND_THEN( "the response is a container with 0 values" ) {

          auto areas = BethYw::parseAreasArg(args);
          REQUIRE( areas.size() == 0 );
      
        } // AND_THEN

      } // THEN

    } // WHEN

  } // GIVEN

  GIVEN( "a --measures program argument with a value 'ALL'" ) {

    WHEN( "the value is 'ALL'" ) {

      Argv argv({"test", "--measures", "ALL"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseMeasuresArg(args) );
        
        AND_THEN( "the response is a container with 0 values" ) {

          auto areas = BethYw::parseMeasuresArg(args);
          REQUIRE( areas.size() == 0 );

        } // AND_THEN

      } // THEN

    } // WHEN

    WHEN( "the value is multiple comma-separated areas ('pop', 'ALL')" ) {

      Argv argv({"test", "--measures", "pop,ALL"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseMeasuresArg(args) );
        
        AND_THEN( "the response is a container with 0 values" ) {

          auto areas = BethYw::parseMeasuresArg(args);
          REQUIRE( areas.size() == 0 );
      
        } // AND_THEN

      } // THEN

    } // WHEN

  } // GIVEN

} // SCENARIO
