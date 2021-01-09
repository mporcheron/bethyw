


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
#include <type_traits>

#include "../libs/cxxopts/cxxopts.hpp"
#include "../libs/cxxopts/argv.hpp"
#include "../bethyw.h"

SCENARIO( "the datasets program argument can be parsed correctly", "[args][datasets]" ) {

  GIVEN( "a --datasets argument and value" ) {
    
    WHEN( "the value is 'invalid'" ) {

      Argv argv({"test", "--datasets", "invalid"});
      auto** actual_argv = argv.argv();
      auto argc = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args = cxxopts.parse(argc, actual_argv);
      
      const std::string exceptionMessage = "No dataset matches key: invalid";
    
      THEN( "a std::invalid_argument exception should be thrown with the message '" + exceptionMessage + "'" ) { 

        REQUIRE_THROWS_AS( BethYw::parseDatasetsArg(args), std::invalid_argument );
        REQUIRE_THROWS_WITH(  BethYw::parseDatasetsArg(args), exceptionMessage );

      }

    }

    WHEN( "the value is valid" ) {

      Argv argv({"test", "--datasets", "popden"});
      auto** actual_argv = argv.argv();
      auto argc = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args = cxxopts.parse(argc, actual_argv);

      THEN( "a valid std::vector containing the correct InputFileSource is returned" ) { 

        REQUIRE_NOTHROW( BethYw::parseDatasetsArg(args) );
        
        auto datasets = BethYw::parseDatasetsArg(args);
        
        REQUIRE( datasets.size() == 1 );
        REQUIRE( datasets.at(0).NAME == "Population density" );

      }

    }

    WHEN( "the value contains two valid values" ) {

      Argv argv({"test", "--datasets", "popden,biz"});
      auto** actual_argv = argv.argv();
      auto argc = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args = cxxopts.parse(argc, actual_argv);

      THEN( "a valid std::vector containing the correct InputFileSources is returned" ) { 

        REQUIRE_NOTHROW( BethYw::parseDatasetsArg(args) );
        
        auto datasets = BethYw::parseDatasetsArg(args);
        
        REQUIRE( datasets.size() == 2 );
        REQUIRE( datasets.at(0).NAME == "Population density" );
        REQUIRE( datasets.at(1).NAME == "Active Businesses" );

      }

    }

    WHEN( "the value contains one valid and one invalid name" ) {

      Argv argv({"test", "--datasets", "popden,invalid"});
      auto** actual_argv = argv.argv();
      auto argc = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args = cxxopts.parse(argc, actual_argv);

      const std::string exceptionMessage = "No dataset matches key: invalid";
    
      THEN( "a std::invalid_argument exception should be thrown with the message '" + exceptionMessage + "'" ) { 

        REQUIRE_THROWS_AS( BethYw::parseDatasetsArg(args), std::invalid_argument );

      }

    }

  }

}

    // WHEN( "the value is 'all'" ) {
    //
    //   Argv argv({"test", "--datasets", "all"});
    //   auto** actual_argv = argv.argv();
    //   auto argc = argv.argc();
    //
    //   auto cxxopts = BethYw::cxxoptsSetup();
    //   auto args = cxxopts.parse(argc, actual_argv);
    //
    //   THEN( "all 7 datasets are imported in order" ) {
    //
    //     REQUIRE_NOTHROW( BethYw::parseDatasetsArg(args) );
    //
    //     auto datasets = BethYw::parseDatasetsArg(args);
    //
    //     REQUIRE( datasets.size() == 7 );
    //     REQUIRE( datasets.at(0).NAME == "Population density" );
    //     REQUIRE( datasets.at(1).NAME == "Active Businesses" );
    //     REQUIRE( datasets.at(2).NAME == "Air Quality Indicators" );
    //     REQUIRE( datasets.at(3).NAME == "Rail passenger journeys" );
    //     REQUIRE( datasets.at(4).NAME == "Population density" );
    //     REQUIRE( datasets.at(5).NAME == "Population" );
    //     REQUIRE( datasets.at(6).NAME == "Land area" );
    //
    //   }
    //
    // }

  }

}