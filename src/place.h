#ifndef PLACE_H
#define PLACE_H

#include <string>
#include "vector2d.h"
#include "geometry.h"

struct Place {

  Place(std::string id = "", long x = 0, long y = 0) : _id(id), _position(new Vector2D(x, y)) {
    _nearestPlace = (Place*)0;
    _isPotentialIsland = true;
  };
  ~Place() {
    delete _position;
  };

  inline const long X() const {return _position->X();};
  inline const long Y() const {return _position->Y();};
  inline const bool isPotentialIsland() const {return _isPotentialIsland;};
  inline const std::string id() const {return _id;};
  inline const Vector2D position() const {return *_position;};
  inline const Place* nearestPlace() const {return _nearestPlace;};
  //TODO: optimise
  inline const long distanceToNearestPlace() const {return _nearestPlace == (Place*)0 ? 0 : Geometry::distanceBetween(*_position, _nearestPlace->position());};

  inline void notPotentialIsland() {
    _isPotentialIsland = false;
    if (_nearestPlace != (Place*)0) {
      _nearestPlace->notPotentialIsland();
    }
  };
  inline bool setNearestPlace(Place* place) {
    if (this == place || place == (Place*)0) {
      return false;
    }
    _nearestPlace = place;
    return true;
  };

  inline const bool operator==(const Place& rhs) const {
    return this->id() == rhs.id() && this->position() == rhs.position();
  };
protected:
  bool _isPotentialIsland;
  std::string _id;
  Vector2D* _position;
  Place* _nearestPlace;
};
#endif
