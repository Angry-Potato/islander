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

    SUBCASE("nearestPlace is NULL by default") {
      CHECK(sut.nearestPlace() == (Place*)NULL);
    }

    SUBCASE("distanceToNearestPlace is 0 by default") {
      CHECK(sut.distanceToNearestPlace() == 0);
    }

    SUBCASE("isPotentialIsland is true by default") {
      CHECK(sut.isPotentialIsland() == true);
    }

    SUBCASE("hasNearestPlace is false by default") {
      CHECK(sut.hasNearestPlace() == false);
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
TEST_SUITE("Place::distanceToNearestPlace") {
  TEST_CASE("Place with no nearestPlace set") {
    Place sut;

    SUBCASE("Returns 0") {
      CHECK(sut.distanceToNearestPlace() == 0);
    }
  }
  TEST_CASE("Place and nearestPlace both on the X axis") {
    long p1X = 1;
    long p2X = 5;
    Place sut("guys", p1X, 0);
    Place place("gals", p2X, 0);
    sut.setNearestPlace(&place);

    SUBCASE("Should just be difference in X") {
      CHECK(sut.distanceToNearestPlace() == p2X - p1X);
    }
  }
  TEST_CASE("Place and nearestPlace both on the Y axis") {
    long p1Y = 1;
    long p2Y = 5;
    Place sut("guys", 0, p1Y);
    Place place("gals", 0, p2Y);
    sut.setNearestPlace(&place);

    SUBCASE("Should just be difference in Y") {
      CHECK(sut.distanceToNearestPlace() == p2Y - p1Y);
    }
  }
  TEST_CASE("Place and nearestPlace at different positions") {
    long p1X = 1;
    long p1Y = 1;
    long p2X = 5;
    long p2Y = 5;
    Place sut("red lorry", p1X, p1Y);
    Place place("yellow lorry", p2X, p2Y);
    sut.setNearestPlace(&place);

    SUBCASE("Distance between should be root(difference in X + difference in Y)") {
      long XDiff = p1X - p2X;
      long YDiff = p1Y - p2Y;
      long expected = sqrt(XDiff*XDiff + YDiff*YDiff);
      CHECK(sut.distanceToNearestPlace() == expected);
    }
    SUBCASE("Distance between should be the same if both are each others nearest place") {
      place.setNearestPlace(&sut);
      CHECK(sut.distanceToNearestPlace() == place.distanceToNearestPlace());
    }
  }
}
TEST_SUITE("Place::setNearestPlace") {
  TEST_CASE("Setting nearest place on place as NULL") {
    Place sut;

    SUBCASE("Returns false") {
      CHECK(sut.setNearestPlace((Place*)NULL) == false);
    }
  }
  TEST_CASE("Setting nearest place on place as itself") {
    Place sut;

    SUBCASE("Returns false") {
      CHECK(sut.setNearestPlace(&sut) == false);
    }
  }
  TEST_CASE("Setting nearest place") {
    Place sut;
    Place place;

    SUBCASE("Returns true") {
      CHECK(sut.setNearestPlace(&place) == true);
    }
  }
}
TEST_SUITE("Place::notPotentialIsland") {
  TEST_CASE("Setting notPotentialIsland on place with no nearestPlace") {
    Place sut;
    long potentialsRemaining = 1;
    sut.notPotentialIsland(potentialsRemaining);

    REQUIRE(sut.nearestPlace() == (Place*)NULL);
    SUBCASE("isPotentialIsland returns false") {
      CHECK(sut.isPotentialIsland() == false);
    }
    SUBCASE("potentialsRemaining is decremented") {
      CHECK(potentialsRemaining == 0);
    }
  }
  TEST_CASE("Setting notPotentialIsland on place with a nearestPlace") {
    Place sut("thing one", 1, 2);
    Place place("thing two", 3, 4);
    Place otherPlace("thing three", 5, 6);
    sut.setNearestPlace(&place);
    place.setNearestPlace(&otherPlace);
    long potentialsRemaining = 5;
    sut.notPotentialIsland(potentialsRemaining);

    SUBCASE("sut.isPotentialIsland returns false") {
      CHECK(sut.isPotentialIsland() == false);
    }
    SUBCASE("place.isPotentialIsland returns false") {
      CHECK(place.isPotentialIsland() == false);
      CHECK(sut.nearestPlace()->isPotentialIsland() == false);
    }
    SUBCASE("otherPlace.isPotentialIsland returns false") {
      CHECK(otherPlace.isPotentialIsland() == false);
      CHECK(sut.nearestPlace()->nearestPlace()->isPotentialIsland() == false);
    }
    SUBCASE("potentialsRemaining is decremented") {
      CHECK(potentialsRemaining == 2);
    }
  }
  TEST_CASE("Setting notPotentialIsland on place with a nearestPlace cyclic chain") {
    Place sut("thing one", 1, 2);
    Place place("thing two", 3, 4);
    sut.setNearestPlace(&place);
    place.setNearestPlace(&sut);
    long potentialsRemaining = 3;
    sut.notPotentialIsland(potentialsRemaining);

    SUBCASE("sut.isPotentialIsland returns false") {
      CHECK(sut.isPotentialIsland() == false);
      CHECK(place.nearestPlace()->isPotentialIsland() == false);
    }
    SUBCASE("place.isPotentialIsland returns false") {
      CHECK(place.isPotentialIsland() == false);
      CHECK(sut.nearestPlace()->isPotentialIsland() == false);
    }
    SUBCASE("potentialsRemaining is decremented") {
      CHECK(potentialsRemaining == 1);
    }
  }
}
