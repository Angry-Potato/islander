#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

struct Vector2D {

  Vector2D(long x = 0, long y = 0) : _X(x), _Y(y) {};
  ~Vector2D() {};

  inline long magnitude() const {return sqrt(_X*_X + _Y*_Y);};
  inline long X() const {return _X;};
  inline long Y() const {return _Y;};

protected:
  long _X;
  long _Y;
};
#endif
