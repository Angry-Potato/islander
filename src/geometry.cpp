#include "geometry.h"
#include "vector2d.h"

long Geometry::squaredDistanceBetween(const Vector2D a, const Vector2D b) {
  long XDiff = a.X() - b.X();
  long YDiff = a.Y() - b.Y();
  if (XDiff == 0) {
    return YDiff < 0 ? -YDiff : YDiff;
  }
  else if (YDiff == 0) {
    return XDiff < 0 ? -XDiff : XDiff;
  }
  return XDiff*XDiff + YDiff*YDiff;
}
