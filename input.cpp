


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains the code responsible for opening and closing file
  streams. The actual handling of the data from that stream is handled
  by the functions in parse.cpp. See the header file for additional comments.
  
  Each function you must implement has a TODO in its comment block. 
 */

#include <exception>
#include <fstream>

#include "input.h"

InputSource::InputSource(const std::string &source) : mSource(source) {}

const std::string& InputSource::getSource() const { return mSource; }

 // TODO map: replace constructor with
// InputFile::InputFile(const std::string &path) : InputSource(path) {}
InputFile::InputFile(const std::string &path)
    : InputSource(path), mFileStream() {}

/*
  Close the file.

  TODO map: delete this whole function
*/
InputFile::~InputFile() {
  mFileStream.close();
}

/*
  TODO: open a file stream to the file path retrievable from getSource()
  and return a reference to the stream. Throw a std::runtime_error
  if there is an exception opening the file.

  You may need to modify the class definition for InputFile in input.h…
*/
std::istream &InputFile::open() noexcept(false) {
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