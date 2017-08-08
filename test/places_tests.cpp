#include <forward_list>
#include "../src/places.h"
#include "../src/place.h"
#include "doctest.h"
#include <string>

TEST_SUITE("Places::nearestNeighbour") {
  TEST_CASE("Given empty list, and valid origin") {
    Place origin("hey");
    std::forward_list<Place*> places;

    SUBCASE("Returns NULL") {
      CHECK(Places::nearestNeighbour(&origin, places) == (Place*)NULL);
    }
  }
  TEST_CASE("Given NULL origin, and valid list") {
    Place origin("hey");
    std::forward_list<Place*> places = { &origin };

    SUBCASE("Returns NULL") {
      CHECK(Places::nearestNeighbour((Place*)NULL, places) == (Place*)NULL);
    }
  }
  TEST_CASE("Given valid origin, and list containing only origin") {
    Place origin("hey");
    std::forward_list<Place*> places = { &origin };

    SUBCASE("Returns NULL") {
      CHECK(Places::nearestNeighbour(&origin, places) == (Place*)NULL);
    }
  }
  TEST_CASE("Given valid origin, and valid list") {
    Place origin("hey", 1, 1);
    Place p1("neighbour", 1, 2);
    Place p2("alien", 3, 2);
    Place p3("house", 1, 3);
    std::forward_list<Place*> places = { &origin, &p1, &p2, &p3 };

    SUBCASE("Returns nearest neighbour") {
      CHECK(*Places::nearestNeighbour(&origin, places) == p1);
    }
  }
}
TEST_SUITE("Places::firstPotentialIsland") {
  TEST_CASE("Given empty list") {
    std::forward_list<Place*> places;

    SUBCASE("Returns NULL") {
      CHECK(Places::firstPotentialIsland(places) == (Place*)NULL);
    }
  }
  TEST_CASE("Given list with potential islands") {
    Place place0("place0", 1000000, 1000000);
    Place place1("place1", 2000000, 2000000);
    Place place2("place2", 1000000, 2000000);
    Place place3("place3", 2000000, 1000000);
    Place place4("place4", 5000000, 5000000);
    Place place5("place5", 8000000, 8000000);
    Place place6("place6", 9000000, 9000000);
    Place place7("place7", 8000000, 9000000);
    Place place8("place8", 9000000, 8000000);
    Place place9("place9", 1000000, 8000000);
    Place place10("place10", 2000000, 9000000);
    Place place11("place11", 1000000, 9000000);
    Place place12("place12", 2000000, 8000000);
    Place place13("place13", 8000000, 1000000);
    Place place14("place14", 9000000, 2000000);
    Place place15("place15", 8000000, 2000000);
    Place place16("place16", 9000000, 1000000);

    std::forward_list<Place*> places = {
      &place0, &place1, &place2, &place3, &place4, &place5, &place6,
      &place7, &place8, &place9, &place10, &place11, &place12, &place13,
      &place14, &place15, &place16
    };
    long potentialsRemaining = 17;
    place0.notPotentialIsland(potentialsRemaining);
    place1.notPotentialIsland(potentialsRemaining);
    place2.notPotentialIsland(potentialsRemaining);

    SUBCASE("Returns first potential island") {
      CHECK(*Places::firstPotentialIsland(places) == place3);
    }
  }
  TEST_CASE("Given list with no potential islands") {
    Place place0("place0", 1000000, 1000000);
    Place place1("place1", 2000000, 2000000);
    Place place2("place2", 1000000, 2000000);

    std::forward_list<Place*> places = {
      &place0, &place1, &place2
    };
    long potentialsRemaining = 17;
    place0.notPotentialIsland(potentialsRemaining);
    place1.notPotentialIsland(potentialsRemaining);
    place2.notPotentialIsland(potentialsRemaining);

    SUBCASE("Returns NULL") {
      CHECK(Places::firstPotentialIsland(places) == (Place*)NULL);
    }
  }
}
