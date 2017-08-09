#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

struct Vector2D {

  Vector2D(long x = 0, long y = 0) : _X(x), _Y(y) {};
  ~Vector2D() {};

  inline const long magnitude() const {return sqrt(_X*_X + _Y*_Y);};
  inline const long X() const {return _X;};
  inline const long Y() const {return _Y;};

  inline const bool operator==(const Vector2D& rhs) const {
    return this->X() == rhs.X() && this->Y() == rhs.Y();
  };
protected:
  long _X;
  long _Y;
};
#endif
