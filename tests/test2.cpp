


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
#include "../datasets.h"

SCENARIO( "areas.csv can be correctly parsed", "[Areas][populateFromAuthorityCodeCSV]" ) {

  auto file_exists = [](const std::string &path) {
    // fstream destructor closes the file
    return std::ifstream(path).is_open();
  };
  
  const std::string test_file = "data/areas.csv";
  REQUIRE(file_exists(test_file));

  Areas data = Areas();
  GIVEN( "a default constructed Areas instance" ) {
    THEN( "there will be an object with 0 areas within" ) {
      REQUIRE(data.size() == 0);
    }

    InputFile input(test_file);
    std::istream &stream = input.open();
    
    THEN( "the CSV can be used to populate the object" ) {
      REQUIRE_NOTHROW(data.populate(stream, DataType::AuthorityCodeCSV));
      REQUIRE(data.size() == 12);
    }
  }
  

  GIVEN( "a fully parsed areas.csv" ) {
    InputFile input(test_file);
    std::istream &stream = input.open();
    data.populate(stream, DataType::AuthorityCodeCSV);
    
    THEN( "each expected area has been correctly imported as Area objects" ) {
      REQUIRE_NOTHROW(data.get("W06000001"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000001")));
      REQUIRE_NOTHROW(data.get("W06000002"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000002")));
      REQUIRE_NOTHROW(data.get("W06000003"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000003")));
      REQUIRE_NOTHROW(data.get("W06000004"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000004")));
      REQUIRE_NOTHROW(data.get("W06000005"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000005")));
      REQUIRE_NOTHROW(data.get("W06000006"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000006")));
      REQUIRE_NOTHROW(data.get("W06000008"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000008")));
      REQUIRE_NOTHROW(data.get("W06000009"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000009")));
      REQUIRE_NOTHROW(data.get("W06000010"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000010")));
      REQUIRE_NOTHROW(data.get("W06000011"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000011")));
      REQUIRE_NOTHROW(data.get("W06000012"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000012")));
      REQUIRE_NOTHROW(data.get("W06000023"));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (data.get("W06000023")));
    }

    THEN( "a fake area with an unexpected authority code throws an error" ) {
      REQUIRE_THROWS_AS(data.get("junk"), std::out_of_range);
    }
    
    THEN( "each area has been correctly imported with the correct names" ) {
      REQUIRE(data.get("W06000001").getName("eng") == "Isle of Anglesey");
      REQUIRE(data.get("W06000001").getName("cym") == "Ynys Môn");

      REQUIRE(data.get("W06000002").getName("eng") == "Gwynedd");
      REQUIRE(data.get("W06000002").getName("cym") == "Gwynedd");

      REQUIRE(data.get("W06000003").getName("eng") == "Conwy");
      REQUIRE(data.get("W06000003").getName("cym") == "Conwy");

      REQUIRE(data.get("W06000004").getName("eng") == "Denbighshire");
      REQUIRE(data.get("W06000004").getName("cym") == "Sir Ddinbych");

      REQUIRE(data.get("W06000005").getName("eng") == "Flintshire");
      REQUIRE(data.get("W06000005").getName("cym") == "Sir y Fflint");

      REQUIRE(data.get("W06000006").getName("eng") == "Wrexham");
      REQUIRE(data.get("W06000006").getName("cym") == "Wrecsam");

      REQUIRE(data.get("W06000008").getName("eng") == "Ceredigion");
      REQUIRE(data.get("W06000008").getName("cym") == "Ceredigion");

      REQUIRE(data.get("W06000009").getName("eng") == "Pembrokeshire");
      REQUIRE(data.get("W06000009").getName("cym") == "Sir Benfro");

      REQUIRE(data.get("W06000010").getName("eng") == "Carmarthenshire");
      REQUIRE(data.get("W06000010").getName("cym") == "Sir Gaerfyrddin");

      REQUIRE(data.get("W06000011").getName("eng") == "Swansea");
      REQUIRE(data.get("W06000011").getName("cym") == "Abertawe");

      REQUIRE(data.get("W06000012").getName("eng") == "Neath Port Talbot");
      REQUIRE(data.get("W06000012").getName("cym") == "Castell-nedd Port Talbot");

      REQUIRE(data.get("W06000023").getName("eng") == "Powys");
      REQUIRE(data.get("W06000023").getName("cym") == "Powys");
    }
  }
}
