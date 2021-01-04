


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  You must not modify this file as it will be replaced with a fresh copy
  during marking.
 */

#include <exception>
#include <iostream>

#include "bethyw.h"

int main(int argc, char *argv[]) {
  try {
    BethYw::run(argc, argv);
  } catch(std::exception &ex) {
    std::cerr << "Uncaught exception: " << ex.what() << std::endl;
    std::exit(2);
  } catch(...) {
    std::cerr << "Uncaught exception: unknown" << std::endl;
    std::exit(2);
  }

  return 0;
}