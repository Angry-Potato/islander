#include "file_input.h"
#include <fstream>
#include <string>
#include <iostream>

std::string FileInput::next() {
  std::string line;
  std::getline(fileStream, line);
  return fileStream.eof() ? std::to_string(EOF) : line.c_str();
}
