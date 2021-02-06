


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
#include <tuple>

#include "../lib_cxxopts.hpp"
#include "../lib_cxxopts_argv.hpp"

#include "../bethyw.h"

SCENARIO( "the years program argument can be parsed correctly [extended]", "[args][years][extended]" ) {

  GIVEN( "a --years argument with a value" ) {

    WHEN( "the value is numeric, but not nil and not four digits long ('25')" ) {

      Argv argv({"test", "--years", "25"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      const std::string exceptionMessage = "Invalid input for years argument";
      
      THEN( "a std::invalid_argument exception is thrown with the message '" + exceptionMessage + "'" ) {

        REQUIRE_THROWS_AS(   BethYw::parseYearsArg(args), std::invalid_argument );
        REQUIRE_THROWS_WITH( BethYw::parseYearsArg(args), exceptionMessage      );
      
      } // THEN

    } // WHEN

    WHEN( "the value is two numeric values, but one is not nil and not four digits long ('25-2010')" ) {

      Argv argv({"test", "--years", "25"});
      auto** actual_argv = argv.argv();
      auto argc          = argv.argc();

      auto cxxopts = BethYw::cxxoptsSetup();
      auto args    = cxxopts.parse(argc, actual_argv);

      const std::string exceptionMessage = "Invalid input for years argument";
      
      THEN( "a std::invalid_argument exception is thrown with the message '" + exceptionMessage + "'" ) {

        REQUIRE_THROWS_AS(   BethYw::parseYearsArg(args), std::invalid_argument );
        REQUIRE_THROWS_WITH( BethYw::parseYearsArg(args), exceptionMessage      );
      
      } // THEN

    } // WHEN

  } // GIVEN

} // SCENARIO