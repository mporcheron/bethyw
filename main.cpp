


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  You don't need to modify this file at all. All the action is happens in
  BethYw::run().

  When your coursework is marked, this file will be substituted by fresh copy
  so any changes you make will have no effect on your mark.
 */

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