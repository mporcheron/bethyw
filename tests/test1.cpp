


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

#include "../libs/cxxopts/cxxopts.hpp"
#include "../libs/cxxopts/argv.hpp"

#include "../bethyw.h"
#include "../datasets.h"

SCENARIO( "the datasets program argument can be parsed correctly", "[args][datasets]" ) {

  GIVEN( "a --datasets program argument and value" ) {

    WHEN( "the value is an invalid dataset ('invalid')" ) {

      Argv argv({"test", "--datasets", "invalid"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      const std::string exceptionMessage = "No dataset matches key: invalid";

      THEN( "a std::invalid_argument exception is thrown with the message '" + exceptionMessage + "'" ) {

        REQUIRE_THROWS_AS(   BethYw::parseDatasetsArg(args), std::invalid_argument );
        REQUIRE_THROWS_WITH( BethYw::parseDatasetsArg(args), exceptionMessage );

      } // THEN

    } // WHEN

    WHEN( "the value is a valid datase ('popden')" ) {

      Argv argv({"test", "--datasets", "popden"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseDatasetsArg(args) );

        AND_THEN( "the response is a container with 1 value" ) {

          auto datasets = BethYw::parseDatasetsArg(args);
          REQUIRE( datasets.size() == 1 );

        } // AND_THEN

        AND_THEN( "the container contains InputFileSource objects" ) {

          auto datasets = BethYw::parseDatasetsArg(args);
          REQUIRE_NOTHROW( dynamic_cast<BethYw::InputFileSource&> (datasets.at(0)) );

        } // AND_THEN

        AND_THEN ( "the correct InputFileSource instance is returned by numerical index" ) {

          auto datasets = BethYw::parseDatasetsArg(args);
          REQUIRE( datasets.at(0).NAME == "Population density" );

        } // AND_THEN

      } //THEN

    } // WHEN

    WHEN( "the program argument value contains two valid datasets ('popden' and 'biz') " ) {

      Argv argv({"test", "--datasets", "popden,biz"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      THEN( "the argument value is parsed without exception" ) {

        REQUIRE_NOTHROW( BethYw::parseDatasetsArg(args) );

        AND_THEN( "the response is a container with 2 values" ) {

          auto datasets = BethYw::parseDatasetsArg(args);
          REQUIRE( datasets.size() == 2 );

        } // AND_THEN

        AND_THEN ( "the correct InputFileSource instances are returned by numerical index" ) {

          auto datasets = BethYw::parseDatasetsArg(args);
          REQUIRE( datasets.at(0).NAME == "Population density" );
          REQUIRE( datasets.at(1).NAME == "Active Businesses" );

        } // AND_THEN

      } //THEN

    } // WHEN

    WHEN( "the program argument value contains one valid ('popden') and one invalid ('invalid') datasets" ) {

      Argv argv({"test", "--datasets", "popden,invalid"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      const std::string exceptionMessage = "No dataset matches key: invalid";

      THEN( "a std::invalid_argument exception is thrown with the message '" + exceptionMessage + "'" ) {

        REQUIRE_THROWS_AS(   BethYw::parseDatasetsArg(args), std::invalid_argument );
        REQUIRE_THROWS_WITH( BethYw::parseDatasetsArg(args), exceptionMessage );

      } // THEN

    } // WHEN

  } // GIVEN

} // SCENARIO