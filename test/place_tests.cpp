#include "../src/place.h"
#include "doctest.h"
#include <string>

TEST_SUITE("Place") {
  TEST_CASE("Default constructor") {
    Place sut;

    SUBCASE("Initialises to 0,0 by default") {
      CHECK(sut.X() == 0);
      CHECK(sut.Y() == 0);
    }

    SUBCASE("Id is empty string by default") {
      CHECK(sut.id() == "");
    }
  }
  TEST_CASE("Place called pants at 3,5") {
    long x = 3;
    long y = 5;
    std::string id = "pants";
    Place sut(id, x, y);

    SUBCASE("Initialises to 3,5") {
      CHECK(sut.X() == x);
      CHECK(sut.Y() == y);
    }

    SUBCASE("Id is pants") {
      CHECK(sut.id() == id);
    }

    SUBCASE("It equals itself") {
      CHECK(sut == sut);
    }
  }
  TEST_CASE("Places called pants at 3,5, and tops at 9, 15") {
    Place sut1("pants", 3, 5);
    Place sut2("tops", 9, 15);

    SUBCASE("They are not equal") {
      CHECK((sut1 == sut2) == false);
    }
  }
}
