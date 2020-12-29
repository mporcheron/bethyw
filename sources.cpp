


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains numerous functions you must implement. Each function you
  must implement as a TODO comment inside it. See sources.h for explanations
  of how the code is organised for the classes in this file.
 */

#include <exception>
#include <fstream>

#include "sources.h"






InputSource::InputSource(const std::string &source)
    : mSource(source)
{}

const std::string InputSource::getSource() const {
  return mSource;
}





InputFile::InputFile(const std::string &path)
    : InputSource(path), mFileStream() {} // TODO map: remove mFileStream

InputFile::~InputFile() { 
    mFileStream.close(); // TODO map: remove mFileStream
}

std::istream& InputFile::open() noexcept(false) {
  // TODO: Implement this function, which will read the contents of the file 
  // stored in the member variable mSource.
  //
  // Throw a std::runtime_error if you have an issue with the text: 
  // "InputFile::import: Failed to open file" (no quotes).
  //
  // Return an open stream so that code outside this function can convert the 
  // data into the internal data objects.
  mFileStream.open(mSource, std::ifstream::in);

  if (!mFileStream.is_open()) {
    throw std::runtime_error("InputFile::import: Failed to open file");
  }

  return mFileStream;
}