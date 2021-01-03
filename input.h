#ifndef INPUT_H_
#define INPUT_H_

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

#include <string>
#include <fstream>

/*
  InputSource is an abstract/purely virtual base class for all input source 
  types. In future versions of our application, we may support multiple input 
  data sources such as files and web pages. Therefore, this virtual class 
  will allow us to mix/match sources as needed. For now, we can just ignore
  it and focus on InputFile (next class down!).
*/
class InputSource {
protected:
  const std::string mSource;

public:
  InputSource(const std::string &source);
  virtual ~InputSource() = default;

  virtual const std::string& getSource() const;
  virtual std::istream &open() noexcept(false) = 0;
};

/*
  Source data that is contained within a file. For now, our application will
  only work with files (and in particular, the files in the data directory).
*/
// TODO map: replace code with:
// class InputFile : public InputSource {
// public:
//   InputFile(const std::string &path);
//   virtual ~InputFile() = default;
//
//   /*
//     Open a file specified in the constructor and throw a std::runtime_error
//     exception if the file cannot be opened.
//   */
//   virtual std::istream &open() noexcept(false);
// };
class InputFile : public InputSource {
protected:
  std::ifstream mFileStream;

public:
  InputFile(const std::string &path);
  virtual ~InputFile();

  /*
    Open a file specified in the constructor and throw a std::runtime_error
    exception if the file cannot be opened.
  */
  virtual std::istream &open() noexcept(false);
};

#endif // INPUT_H_