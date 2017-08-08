#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <math.h>

class Vector2D;
struct Geometry {
  static long distanceBetween(Vector2D* a, Vector2D* b);
};
#endif
