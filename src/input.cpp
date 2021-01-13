


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains the code responsible for opening and closing file
  streams. The actual handling of the data from that stream is handled
  by the functions in data.cpp. See the header file for additional comments.
  
  Each function you must implement has a TODO in its comment block. You may
  have to implement additional functions.
 */

#include <exception>
#include <fstream>

#include "input.h"

/*
  TODO: InputSource::InputSource(source)

  Constructor for an InputSource.

  @param source
    A unique identifier for a source (i.e. the location).
*/
InputSource::InputSource(const std::string &source) : mSource(source) {}

/*
  TODO: InputSource::getSource()

  @return
    A non-modifable value for the source passed into the construtor.
*/
const std::string& InputSource::getSource() const { return mSource; }

/*
  TODO: InputFile:InputFile(path)

  Constructor for a file-based source.

  @param path
    The complete path for a file to import.

  @example
    InputFile input("data/areas.csv");
*/
InputFile::InputFile(const std::string &path)
    : InputSource(path), mFileStream() {}

/*
  Close the file stream.

  TODO map: delete this whole function and comment
*/
InputFile::~InputFile() {
  mFileStream.close();
}

/*
  TODO:InputFile::open()

  Open a file stream to the file path retrievable from getSource()
  and return a reference to the stream.

  @return
    A standard input stream reference

  @throws
    std::runtime_error if there is an issue opening the file

  @example
    InputFile input("data/areas.csv");
    input.open();
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