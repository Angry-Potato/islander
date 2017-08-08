#ifndef PLACE_H
#define PLACE_H

#include <string>
#include "vector2d.h"

struct Place {

  Place(std::string id = "", long x = 0, long y = 0) : _id(id), _position(new Vector2D(x, y)) {
    _nearestPlace = (Place*)0;
  };
  ~Place() {
    delete _position;
  };

  inline const long X() const {return _position->X();};
  inline const long Y() const {return _position->Y();};
  inline const std::string id() const {return _id;};
  inline const Vector2D position() const {return *_position;};
  inline const Place nearestPlace() const {return *_nearestPlace;};

  inline void setNearestPlace(Place* place) {_nearestPlace = place;};

  inline const bool operator==(const Place& rhs) const {
    return this->id() == rhs.id() && this->position() == rhs.position();
  };
protected:
  std::string _id;
  Vector2D* _position;
  Place* _nearestPlace;
};
#endif
