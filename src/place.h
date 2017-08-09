#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <limits>
#include "vector2d.h"
#include "geometry.h"

struct Place {

  Place(std::string id = "", long x = 0, long y = 0) : _id(id), _position(new Vector2D(x, y)) {
    _nearestPlace = (Place*)0;
    _isPotentialIsland = true;
    _distanceToNearestPlace = -1;
  };
  ~Place() {
    delete _position;
  };

  inline const long X() const {return _position->X();};
  inline const long Y() const {return _position->Y();};
  inline const bool isPotentialIsland() const {return _isPotentialIsland;};
  inline const std::string id() const {return _id;};
  inline const Vector2D position() const {return *_position;};
  inline const bool hasNearestPlace() const {return _nearestPlace != (Place*)0;};
  inline const Place* nearestPlace() const {return _nearestPlace;};
  //TODO: optimise
  inline const long distanceToNearestPlace() const {
    return _distanceToNearestPlace;
  };

  inline void notPotentialIsland(long& potentialsRemaining) {
    potentialsRemaining -= _isPotentialIsland ? 1 : 0;
    _isPotentialIsland = false;
    if (hasNearestPlace()) {
      if (_nearestPlace->hasNearestPlace() && _id == _nearestPlace->nearestPlace()->id()) {
        potentialsRemaining -= _nearestPlace->_isPotentialIsland ? 1 : 0;
        _nearestPlace->_isPotentialIsland = false;
      }
      else {
        _nearestPlace->notPotentialIsland(potentialsRemaining);
      }
    }
  };
  inline bool setNearestPlace(Place* place) {
    if (place == (Place*)0 || _id == place->_id) {
      return false;
    }
    _nearestPlace = place;
    _distanceToNearestPlace = Geometry::distanceBetween(*_position, *_nearestPlace->_position);
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
  long _distanceToNearestPlace;
};
#endif
