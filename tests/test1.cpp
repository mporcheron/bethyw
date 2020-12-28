


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

#include "../sources.h"

SCENARIO( "a InputFile can be constructed with a valid filename", "[InputFile][import]" ) {

  auto file_exists = [](const std::string &path) {
    // fstream destructor closes the file
    return std::ifstream(path).is_open();
  };
  
  const std::string test_file = "data/areas.csv";
  REQUIRE(file_exists(test_file));

  GIVEN( "a valid constructed InputSource instance" ) {
    InputFile input(test_file);

    THEN( "the source is set correctly" ) {
      REQUIRE(input.getSource() == test_file);
    }

    THEN( "the file is read without an exception thrown" ) {
      REQUIRE_NOTHROW(input.open());
      REQUIRE_NOTHROW(dynamic_cast<std::istream&> (input.open()));
    }
    
    std::istream &stream = input.open();

    THEN( "the stream remains open after the open() returns" ) {
      REQUIRE_NOTHROW(stream.seekg(1, stream.beg));
      REQUIRE_FALSE(stream.eof());
      REQUIRE_FALSE(stream.fail());
    }
  }
}


SCENARIO( "a InputFile can be constructed with an invalid filename", "[InputFile][import]" ) {

  auto file_exists = [](const std::string &path) {
    // fstream destructor closes the file
    return std::ifstream(path).is_open();
  };
  
  const std::string test_file = "data/jibberish.json";
  REQUIRE_FALSE(file_exists(test_file));

  GIVEN( "a valid constructed InputSource instance" ) {
    InputFile input(test_file);

    THEN( "the source is set correctly" ) {
      REQUIRE(input.getSource() == test_file);
    }

    THEN( "the file is read and an std::runtime_error thrown" ) {
      REQUIRE_THROWS_AS(input.open(), std::runtime_error);
      REQUIRE_THROWS_WITH(input.open(), "InputFile::import: Failed to open file");
    }
  }
}
