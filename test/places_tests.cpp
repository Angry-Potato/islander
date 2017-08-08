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
