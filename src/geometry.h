#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <math.h>

class Vector2D;
struct Geometry {
  static long distanceBetween(const Vector2D a, const Vector2D b);
};
#endif
