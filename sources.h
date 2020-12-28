#ifndef SOURCE_H_
#define SOURCE_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: Dr Martin Porcheron

  This file contains input source handlers. There are two classes: InputSource
  and InputFile. InputSource is abstract (i.e. it contains a pure virtual 
  function). InputFile is a concrete derivation of InputSource, for input
  from files.

  Although only one class derives from InputSource, we have implemented our 
  code this way to support future expansion of input from different sources 
  (e.g. the web).
 */

#include <cstring>
#include <fstream>

#include "data.h"





const char DIR_SEP =
#ifdef _WIN32
                            '\\';
#else
                            '/';
#endif





// A virtual input source. In future versions of our application, we may
// support multiple input data sources such as files and web pages. Therefore,
// we can have a base virtual class that will allow us to mix/match sources
// as appropriate.
//
// However, as data types (e.g. JSON or CSV) may be common between sources),
// the InputSource class will have an implementation for parsing the data.
//
// We also use templating here here. The templated item (T) is the class
// that'll store the data i
class InputSource {
protected:
  const std::string mSource; 
  
public:
  // All input sources have a source
  InputSource(const std::string &source);

  virtual ~InputSource() = default;

  virtual const std::string getSource() const {
    return mSource;
  }
  
  // Every input source will have it's own mechanism for opening the source.
  virtual std::istream& open() noexcept(false) = 0;
};





// Input from a OS file.
class InputFile : public InputSource {
protected:  // TODO map: remove mFileStream
  std::ifstream mFileStream;

public:
  // Construct a InputFile object, taking in the path.
  InputFile(const std::string &path);

  virtual ~InputFile();

  // Open a file specified in the constructor and throws a std::runtime_error 
  // exception if the file cannot be opened.
  virtual std::istream& open() noexcept(false);
};





// This namespace stores all the files in the data directory as const char* 
// consts, allowing for them to be substituted at compile-time into our code
namespace InputFiles {
  const char* const AREAS = "areas.csv";
  const char* const POPULATION_DENSITY = "popu1009.json";
};





#endif // SOURCE_H_