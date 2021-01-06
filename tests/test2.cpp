


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

#include "../datasets.h"
#include "../input.h"

SCENARIO( "areas.csv can be correctly parsed through populateFromAuthorityCodeCSV()", "[Areas][populateFromAuthorityCodeCSV]" ) {

  auto file_exists = [](const std::string &path) {
    // fstream destructor closes the file
    return std::ifstream(path).is_open();
  };
  
  const std::string test_file = "datasets/areas.csv";
  REQUIRE(file_exists(test_file));

  auto areas = Areas<>();
  GIVEN( "a default constructed Areas instance" ) {
    THEN( "it will have 0 Area instances within" ) {
      REQUIRE(areas.size() == 0);
    }

    InputFile input(test_file);
    std::istream &stream = input.open();
    
    THEN( "the CSV can be used to populate the object" ) {
      REQUIRE_NOTHROW(areas.populateFromAuthorityCodeCSV(
                      stream,
                      BethYw::InputFiles::AREAS.COLS,
                      nullptr));
      REQUIRE(areas.size() == 22);
    }
  }
  

  GIVEN( "a fully parsed areas.csv" ) {
    InputFile input(test_file);
    std::istream &stream = input.open();
    areas.populateFromAuthorityCodeCSV(
        stream,
        BethYw::InputFiles::AREAS.COLS,
        nullptr);

    THEN( "that Areas() will contain 22 Area instances" ) {
      REQUIRE(areas.size() == 22);
    }

    THEN( "and each area has been imported with the correct local authority code" ) {
      REQUIRE_NOTHROW(areas.at("W06000001"));
      REQUIRE_NOTHROW(areas.at("W06000002"));
      REQUIRE_NOTHROW(areas.at("W06000003"));
      REQUIRE_NOTHROW(areas.at("W06000004"));
      REQUIRE_NOTHROW(areas.at("W06000005"));
      REQUIRE_NOTHROW(areas.at("W06000006"));
      REQUIRE_NOTHROW(areas.at("W06000008"));
      REQUIRE_NOTHROW(areas.at("W06000009"));
      REQUIRE_NOTHROW(areas.at("W06000010"));
      REQUIRE_NOTHROW(areas.at("W06000011"));
      REQUIRE_NOTHROW(areas.at("W06000012"));
      REQUIRE_NOTHROW(areas.at("W06000013"));
      REQUIRE_NOTHROW(areas.at("W06000014"));
      REQUIRE_NOTHROW(areas.at("W06000015"));
      REQUIRE_NOTHROW(areas.at("W06000016"));
      REQUIRE_NOTHROW(areas.at("W06000018"));
      REQUIRE_NOTHROW(areas.at("W06000019"));
      REQUIRE_NOTHROW(areas.at("W06000020"));
      REQUIRE_NOTHROW(areas.at("W06000021"));
      REQUIRE_NOTHROW(areas.at("W06000022"));
      REQUIRE_NOTHROW(areas.at("W06000023"));
      REQUIRE_NOTHROW(areas.at("W06000024"));
  
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000001")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000002")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000003")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000004")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000005")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000006")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000008")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000009")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000010")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000011")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000012")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000013")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000014")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000015")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000016")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000018")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000019")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000020")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000021")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000022")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000023")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000024")));
    }

    THEN( "each area has been correctly imported with the correct names" ) {
      REQUIRE(areas.at("W06000001").getName("eng") == "Isle of Anglesey");
      REQUIRE(areas.at("W06000001").getName("cym") == "Ynys Môn");

      REQUIRE(areas.at("W06000002").getName("eng") == "Gwynedd");
      REQUIRE(areas.at("W06000002").getName("cym") == "Gwynedd");

      REQUIRE(areas.at("W06000003").getName("eng") == "Conwy");
      REQUIRE(areas.at("W06000003").getName("cym") == "Conwy");

      REQUIRE(areas.at("W06000004").getName("eng") == "Denbighshire");
      REQUIRE(areas.at("W06000004").getName("cym") == "Sir Ddinbych");

      REQUIRE(areas.at("W06000005").getName("eng") == "Flintshire");
      REQUIRE(areas.at("W06000005").getName("cym") == "Sir y Fflint");

      REQUIRE(areas.at("W06000006").getName("eng") == "Wrexham");
      REQUIRE(areas.at("W06000006").getName("cym") == "Wrecsam");

      REQUIRE(areas.at("W06000008").getName("eng") == "Ceredigion");
      REQUIRE(areas.at("W06000008").getName("cym") == "Ceredigion");

      REQUIRE(areas.at("W06000009").getName("eng") == "Pembrokeshire");
      REQUIRE(areas.at("W06000009").getName("cym") == "Sir Benfro");

      REQUIRE(areas.at("W06000010").getName("eng") == "Carmarthenshire");
      REQUIRE(areas.at("W06000010").getName("cym") == "Sir Gaerfyrddin");

      REQUIRE(areas.at("W06000011").getName("eng") == "Swansea");
      REQUIRE(areas.at("W06000011").getName("cym") == "Abertawe");

      REQUIRE(areas.at("W06000012").getName("eng") == "Neath Port Talbot");
      REQUIRE(areas.at("W06000012").getName("cym") == "Castell-nedd Port Talbot");

      REQUIRE(areas.at("W06000013").getName("eng") == "Bridgend");
      REQUIRE(areas.at("W06000013").getName("cym") == "Pen-y-bont ar Ogwr");

      REQUIRE(areas.at("W06000014").getName("eng") == "Vale of Glamorgan");
      REQUIRE(areas.at("W06000014").getName("cym") == "Bro Morgannwg");

      REQUIRE(areas.at("W06000015").getName("eng") == "Cardiff");
      REQUIRE(areas.at("W06000015").getName("cym") == "Caerdydd");

      REQUIRE(areas.at("W06000016").getName("eng") == "Rhondda Cynon Taf");
      REQUIRE(areas.at("W06000016").getName("cym") == "Rhondda Cynon Taf");

      REQUIRE(areas.at("W06000018").getName("eng") == "Caerphilly");
      REQUIRE(areas.at("W06000018").getName("cym") == "Caerffili");

      REQUIRE(areas.at("W06000019").getName("eng") == "Blaenau Gwent");
      REQUIRE(areas.at("W06000019").getName("cym") == "Blaenau Gwent");

      REQUIRE(areas.at("W06000020").getName("eng") == "Torfaen");
      REQUIRE(areas.at("W06000020").getName("cym") == "Torfaen");

      REQUIRE(areas.at("W06000021").getName("eng") == "Monmouthshire");
      REQUIRE(areas.at("W06000021").getName("cym") == "Sir Fynwy");

      REQUIRE(areas.at("W06000022").getName("eng") == "Newport");
      REQUIRE(areas.at("W06000022").getName("cym") == "Casnewydd");

      REQUIRE(areas.at("W06000023").getName("eng") == "Powys");
      REQUIRE(areas.at("W06000023").getName("cym") == "Powys");

      REQUIRE(areas.at("W06000024").getName("eng") == "Merthyr Tydfil");
      REQUIRE(areas.at("W06000024").getName("cym") == "Merthyr Tudful");
    }

    THEN( "a fake area with an unexpected authority code throws an error" ) {
      REQUIRE_THROWS_AS(areas.at("junk"), std::out_of_range);
    }
  }
}

SCENARIO( "areas.csv can be correctly parsed through populate()", "[Areas][populate]" ) {

  auto file_exists = [](const std::string &path) {
    // fstream destructor closes the file
    return std::ifstream(path).is_open();
  };
  
  const std::string test_file = "datasets/areas.csv";
  REQUIRE(file_exists(test_file));

  auto areas = Areas<>();
  GIVEN( "a default constructed Areas instance" ) {
    THEN( "it will have 0 Area instances within" ) {
      REQUIRE(areas.size() == 0);
    }

    InputFile input(test_file);
    std::istream &stream = input.open();
    
    THEN( "the CSV can be used to populate the object" ) {
      REQUIRE_NOTHROW(areas.populate(
                      stream,
                      DataType::AuthorityCodeCSV,
                      BethYw::InputFiles::AREAS.COLS,
                      nullptr));
      REQUIRE(areas.size() == 22);
    }
  }
  

  GIVEN( "a fully parsed areas.csv" ) {
    InputFile input(test_file);
    std::istream &stream = input.open();
    areas.populate(
        stream,
        DataType::AuthorityCodeCSV,
        BethYw::InputFiles::AREAS.COLS,
        nullptr);

    THEN( "that Areas() will contain 22 Area instances" ) {
      REQUIRE(areas.size() == 22);
    }

    THEN( "and each area has been imported with the correct local authority code" ) {
      REQUIRE_NOTHROW(areas.at("W06000001"));
      REQUIRE_NOTHROW(areas.at("W06000002"));
      REQUIRE_NOTHROW(areas.at("W06000003"));
      REQUIRE_NOTHROW(areas.at("W06000004"));
      REQUIRE_NOTHROW(areas.at("W06000005"));
      REQUIRE_NOTHROW(areas.at("W06000006"));
      REQUIRE_NOTHROW(areas.at("W06000008"));
      REQUIRE_NOTHROW(areas.at("W06000009"));
      REQUIRE_NOTHROW(areas.at("W06000010"));
      REQUIRE_NOTHROW(areas.at("W06000011"));
      REQUIRE_NOTHROW(areas.at("W06000012"));
      REQUIRE_NOTHROW(areas.at("W06000013"));
      REQUIRE_NOTHROW(areas.at("W06000014"));
      REQUIRE_NOTHROW(areas.at("W06000015"));
      REQUIRE_NOTHROW(areas.at("W06000016"));
      REQUIRE_NOTHROW(areas.at("W06000018"));
      REQUIRE_NOTHROW(areas.at("W06000019"));
      REQUIRE_NOTHROW(areas.at("W06000020"));
      REQUIRE_NOTHROW(areas.at("W06000021"));
      REQUIRE_NOTHROW(areas.at("W06000022"));
      REQUIRE_NOTHROW(areas.at("W06000023"));
      REQUIRE_NOTHROW(areas.at("W06000024"));
  
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000001")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000002")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000003")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000004")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000005")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000006")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000008")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000009")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000010")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000011")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000012")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000013")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000014")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000015")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000016")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000018")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000019")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000020")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000021")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000022")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000023")));
      REQUIRE_NOTHROW(dynamic_cast<Area&> (areas.at("W06000024")));
    }

    THEN( "each area has been correctly imported with the correct names" ) {
      REQUIRE(areas.at("W06000001").getName("eng") == "Isle of Anglesey");
      REQUIRE(areas.at("W06000001").getName("cym") == "Ynys Môn");

      REQUIRE(areas.at("W06000002").getName("eng") == "Gwynedd");
      REQUIRE(areas.at("W06000002").getName("cym") == "Gwynedd");

      REQUIRE(areas.at("W06000003").getName("eng") == "Conwy");
      REQUIRE(areas.at("W06000003").getName("cym") == "Conwy");

      REQUIRE(areas.at("W06000004").getName("eng") == "Denbighshire");
      REQUIRE(areas.at("W06000004").getName("cym") == "Sir Ddinbych");

      REQUIRE(areas.at("W06000005").getName("eng") == "Flintshire");
      REQUIRE(areas.at("W06000005").getName("cym") == "Sir y Fflint");

      REQUIRE(areas.at("W06000006").getName("eng") == "Wrexham");
      REQUIRE(areas.at("W06000006").getName("cym") == "Wrecsam");

      REQUIRE(areas.at("W06000008").getName("eng") == "Ceredigion");
      REQUIRE(areas.at("W06000008").getName("cym") == "Ceredigion");

      REQUIRE(areas.at("W06000009").getName("eng") == "Pembrokeshire");
      REQUIRE(areas.at("W06000009").getName("cym") == "Sir Benfro");

      REQUIRE(areas.at("W06000010").getName("eng") == "Carmarthenshire");
      REQUIRE(areas.at("W06000010").getName("cym") == "Sir Gaerfyrddin");

      REQUIRE(areas.at("W06000011").getName("eng") == "Swansea");
      REQUIRE(areas.at("W06000011").getName("cym") == "Abertawe");

      REQUIRE(areas.at("W06000012").getName("eng") == "Neath Port Talbot");
      REQUIRE(areas.at("W06000012").getName("cym") == "Castell-nedd Port Talbot");

      REQUIRE(areas.at("W06000013").getName("eng") == "Bridgend");
      REQUIRE(areas.at("W06000013").getName("cym") == "Pen-y-bont ar Ogwr");

      REQUIRE(areas.at("W06000014").getName("eng") == "Vale of Glamorgan");
      REQUIRE(areas.at("W06000014").getName("cym") == "Bro Morgannwg");

      REQUIRE(areas.at("W06000015").getName("eng") == "Cardiff");
      REQUIRE(areas.at("W06000015").getName("cym") == "Caerdydd");

      REQUIRE(areas.at("W06000016").getName("eng") == "Rhondda Cynon Taf");
      REQUIRE(areas.at("W06000016").getName("cym") == "Rhondda Cynon Taf");

      REQUIRE(areas.at("W06000018").getName("eng") == "Caerphilly");
      REQUIRE(areas.at("W06000018").getName("cym") == "Caerffili");

      REQUIRE(areas.at("W06000019").getName("eng") == "Blaenau Gwent");
      REQUIRE(areas.at("W06000019").getName("cym") == "Blaenau Gwent");

      REQUIRE(areas.at("W06000020").getName("eng") == "Torfaen");
      REQUIRE(areas.at("W06000020").getName("cym") == "Torfaen");

      REQUIRE(areas.at("W06000021").getName("eng") == "Monmouthshire");
      REQUIRE(areas.at("W06000021").getName("cym") == "Sir Fynwy");

      REQUIRE(areas.at("W06000022").getName("eng") == "Newport");
      REQUIRE(areas.at("W06000022").getName("cym") == "Casnewydd");

      REQUIRE(areas.at("W06000023").getName("eng") == "Powys");
      REQUIRE(areas.at("W06000023").getName("cym") == "Powys");

      REQUIRE(areas.at("W06000024").getName("eng") == "Merthyr Tydfil");
      REQUIRE(areas.at("W06000024").getName("cym") == "Merthyr Tudful");
    }

    THEN( "a fake area with an unexpected authority code throws an error" ) {
      REQUIRE_THROWS_AS(areas.at("junk"), std::out_of_range);
    }
  }
}
