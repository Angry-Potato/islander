#include "../src/islands.h"
#include "../src/place.h"
#include <forward_list>
#include "doctest.h"

TEST_SUITE("Islands") {
  TEST_CASE("Given empty list of places") {
    std::forward_list<Place*> places;

    SUBCASE("Returns NULL") {
      CHECK(Islands::find(places) == (Place*)NULL);
    }
  }
  TEST_CASE("Given list of one place") {
    Place place("hey");
    std::forward_list<Place*> places = { &place };
    SUBCASE("Returns the only element") {
      CHECK(*Islands::find(places) == place);
    }
  }
  TEST_CASE("Given list of two places") {
    Place place1("hey");
    Place place2("there");
    std::forward_list<Place*> places = { &place1, &place2 };
    SUBCASE("Returns the first place") {
      CHECK(*Islands::find(places) == place1);
    }
  }
  TEST_CASE("Given list of places") {
    Place place0("place0", 1000000, 1000000);
    Place place1("place1", 2000000, 2000000);
    Place place2("place2", 1000000, 2000000);
    Place place3("place3", 2000000, 1000000);
    Place island("place4", 5000000, 5000000); //<-- this is the island!
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
      &place0, &place1, &place2, &place3, &island, &place5, &place6,
      &place7, &place8, &place9, &place10, &place11, &place12, &place13,
      &place14, &place15, &place16
    };

    SUBCASE("Returns island") {
      CHECK(*Islands::find(places) == island);
    }
  }
}
TEST_SUITE("Islands::listSize") {
  TEST_CASE("Given empty list") {
    std::forward_list<Place*> places;

    SUBCASE("Returns 0") {
      CHECK(Islands::listSize(places) == 0);
    }
  }
  TEST_CASE("Given populated list") {
    Place place1("hey");
    Place place2("there");
    std::forward_list<Place*> places = { &place1, &place2 };

    SUBCASE("Returns correct size") {
      CHECK(Islands::listSize(places) == 2);
    }
  }
}
TEST_SUITE("Islands::secondElement") {
  TEST_CASE("Given empty list") {
    std::forward_list<Place*> places;

    SUBCASE("Returns NULL") {
      CHECK(Islands::secondElement(places) == (Place*)NULL);
    }
  }
  TEST_CASE("Given list of 1") {
    Place place1("hey");
    std::forward_list<Place*> places = { &place1 };

    SUBCASE("Returns NULL") {
      CHECK(Islands::secondElement(places) == (Place*)NULL);
    }
  }
  TEST_CASE("Given list of 3") {
    Place place1("hey");
    Place place2("there");
    Place place3("pal");
    std::forward_list<Place*> places = { &place1, &place2, &place3 };

    SUBCASE("Returns second element") {
      CHECK(*Islands::secondElement(places) == place2);
    }
  }
}
