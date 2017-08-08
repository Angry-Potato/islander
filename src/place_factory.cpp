#include "place_factory.h"
#include "place.h"
#include <string>
#include <sstream>

Place* PlaceFactory::create(std::string raw) {
  if (raw == "") {
    return NULL;
  }
  std::stringstream ss;
  ss.str(raw);
  std::string name;
  std::getline(ss, name, ' ');
  std::string XCoord;
  std::getline(ss, XCoord, ' ');
  std::string YCoord;
  std::getline(ss, YCoord, ' ');
  if (!isValidName(name) || !isValidNumber(XCoord) || !isValidNumber(YCoord)) {
    return NULL;
  }
  return new Place(name, longFromString(XCoord), longFromString(YCoord));
}
