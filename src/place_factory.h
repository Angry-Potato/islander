#ifndef PLACE_FACTORY_H
#define PLACE_FACTORY_H

#include <algorithm>
#include <string>
#include <sstream>

class Place;
struct PlaceFactory {
  static Place* create(std::string raw);
  static inline bool isValidName(std::string name) {return name != "";};
  static inline bool isValidNumber(std::string number) {
    return number != "" && std::all_of(number.begin(), number.end(), ::isdigit);
  };
  static inline long longFromString(std::string number) {
    std::stringstream str2(number);
    long converted;
    str2 >> converted;
    return converted;
  };
};
#endif
