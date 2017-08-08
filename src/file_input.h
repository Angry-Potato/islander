#ifndef FILE_INPUT_H
#define FILE_INPUT_H

#include <fstream>
#include <string>

class FileInput {
public :
  std::ifstream fileStream;

  FileInput(const char* file) : fileStream(file) {};
  ~FileInput() {};

  std::string next();
};
#endif
