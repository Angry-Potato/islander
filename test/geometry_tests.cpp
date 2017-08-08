#include "../src/geometry.h"
#include "../src/vector2d.h"
#include "doctest.h"
#include <math.h>

TEST_SUITE("Geometry::distanceBetween") {
  TEST_CASE("Vectors both on the X axis") {
    long v1X = 1;
    long v2X = 5;
    Vector2D v1(v1X, 0);
    Vector2D v2(v2X, 0);

    SUBCASE("Distance between should just be difference in X") {
      CHECK(Geometry::distanceBetween(v1, v2) == v2X - v1X);
    }
  }
  TEST_CASE("Vectors both on the Y axis") {
    long v1Y = 1;
    long v2Y = 5;
    Vector2D v1(0, v1Y);
    Vector2D v2(0, v2Y);

    SUBCASE("Distance between should just be difference in Y") {
      CHECK(Geometry::distanceBetween(v1, v2) == v2Y - v1Y);
    }
  }
  TEST_CASE("Vectors are at the same position") {
    Vector2D v1(5, 22);
    Vector2D v2(5, 22);

    SUBCASE("Distance between should be 0") {
      CHECK(Geometry::distanceBetween(v1, v2) == 0);
    }
  }
  TEST_CASE("Vectors at different positions") {
    long v1X = 1;
    long v1Y = 1;
    long v2X = 5;
    long v2Y = 5;
    Vector2D v1(v1X, v1Y);
    Vector2D v2(v2X, v2Y);

    SUBCASE("Distance between should be root(difference in X + difference in Y)") {
      long XDiff = v1X - v2X;
      long YDiff = v1Y - v2Y;
      long expected = sqrt(XDiff*XDiff + YDiff*YDiff);
      CHECK(Geometry::distanceBetween(v1, v2) == expected);
    }
    SUBCASE("Distance between should be the same, regardless of order") {
      CHECK(Geometry::distanceBetween(v1, v2) == Geometry::distanceBetween(v2, v1));
    }
  }
}
