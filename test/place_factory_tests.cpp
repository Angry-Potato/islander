#include "../src/place_factory.h"
#include "../src/place.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "doctest.h"

TEST_SUITE("PlaceFactory::create") {
  TEST_CASE("Given empty string") {
    std::string input = "";

    SUBCASE("Returns NULL") {
      CHECK(PlaceFactory::create(input) == (Place*)NULL);
    }
  }
  // TEST_CASE("Given invalid string") {
  //   std::string input = "Some days I like guacamole but other days I do not";
  //
  //   SUBCASE("Returns NULL") {
  //     CHECK(PlaceFactory::create(input) == (Place*)NULL);
  //   }
  // }
  TEST_CASE("Given valid string") {
    std::string input = "place0 1312573 8418602";

    Place* place = PlaceFactory::create(input);

    SUBCASE("Returns NULL") {
      CHECK(place->id() == "place0");
      CHECK(place->X() == 1312573);
      CHECK(place->Y() == 8418602);
    }

    delete place;
  }
}
TEST_SUITE("PlaceFactory::isValidName") {
  TEST_CASE("Given empty string") {
    std::string input = "";

    SUBCASE("Returns false") {
      CHECK(PlaceFactory::isValidName(input) == false);
    }
  }
  TEST_CASE("Given not empty string") {
    std::string input = "anything";

    SUBCASE("Returns true") {
      CHECK(PlaceFactory::isValidName(input) == true);
    }
  }
}
TEST_SUITE("PlaceFactory::isValidNumber") {
  TEST_CASE("Given empty string") {
    std::string input = "";

    SUBCASE("Returns false") {
      CHECK(PlaceFactory::isValidNumber(input) == false);
    }
  }
  TEST_CASE("Given string with no numbers") {
    std::string input = "anything";

    SUBCASE("Returns false") {
      CHECK(PlaceFactory::isValidNumber(input) == false);
    }
  }
  TEST_CASE("Given string with only numbers") {
    std::string input = "832749";

    SUBCASE("Returns true") {
      CHECK(PlaceFactory::isValidNumber(input) == true);
    }
  }
}
TEST_SUITE("PlaceFactory::longFromString") {
  TEST_CASE("Given string of numbers") {
    std::string input = "4444321";

    SUBCASE("Returns numbers") {
      CHECK(PlaceFactory::longFromString(input) == 4444321);
    }
  }
}
