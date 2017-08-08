#include "../src/vector2d.h"
#include "doctest.h"
#include <math.h>

TEST_SUITE("Vector2D") {
  TEST_CASE("Default constructor") {
    Vector2D sut;

    SUBCASE("Initialises to 0,0 by default") {
      CHECK(sut.X() == 0);
      CHECK(sut.Y() == 0);
    }

    SUBCASE("Magnitude is 0 by default") {
      CHECK(sut.magnitude() == 0);
    }
  }
  TEST_CASE("Vector2D of 3,5") {
    long x = 3;
    long y = 5;
    Vector2D sut(x, y);

    SUBCASE("Initialises to 3,5") {
      CHECK(sut.X() == x);
      CHECK(sut.Y() == y);
    }

    SUBCASE("Magnitude is root(3^2 + 5^2)") {
      CHECK(sut.magnitude() == (long)sqrt(x*x + y*y));
    }
  }
}
