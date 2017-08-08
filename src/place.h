#ifndef PLACE_H
#define PLACE_H

#include <string>
#include "vector2d.h"

struct Place {

  Place(std::string id = "", long x = 0, long y = 0) : _id(id), _position(new Vector2D(x, y)) {};
  ~Place() {
    delete _position;
  };

  inline long X() const {return _position->X();};
  inline long Y() const {return _position->Y();};
  inline std::string id() const {return _id;};
  inline const Vector2D position() const {return *_position;};

  inline bool operator==(const Place& rhs) const {
    return this->id() == rhs.id() && this->position() == rhs.position();
  };
protected:
  std::string _id;
  Vector2D* _position;
};
#endif
