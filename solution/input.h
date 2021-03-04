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

  TODO: Read the block comments with TODO in input.cpp to know which 
  functions and member variables you need to declare in these classes.
 */

#include <string>
#include <fstream>

/*
  InputSource is an abstract/purely virtual base class for all input source 
  types. In future versions of our application, we may support multiple input 
  data sources such as files and web pages. Therefore, this virtual class 
  will allow us to mix/match sources as needed.

  TODO: Based on your implementation of this class and of dervived classes,
  there may be additional constructors or functions you implement here,
  and perhaps additional operators you may wish to overload.
*/
class InputSource {
protected:
  const std::string mSource;
  InputSource(const std::string& source);

public:
  virtual ~InputSource() = default;

  virtual const std::string& getSource() const;
  virtual std::istream& open() = 0;
};

/*
  Source data that is contained within a file. For now, our application will
  only work with files (and in particular, the files in the data directory).

  TODO: You should read the various block comments in the corresponding 
  implementation file to know what to declare.
*/

class InputFile : public InputSource {
protected:
  std::ifstream mFileStream;

public:
  InputFile(const std::string& path);
  virtual ~InputFile();

  virtual std::istream& open();
};

#endif // INPUT_H_