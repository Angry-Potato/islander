#include "../src/file_input.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "doctest.h"

TEST_SUITE("FileInput") {
  TEST_CASE("File exists with contents") {
    std::string line1 = "Writing this to a file.";
    std::string line2 = "Writing this to the same file.";
    std::ofstream myfile;
    myfile.open("test/example.txt");
    myfile << line1 << std::endl;
    myfile << line2 << std::endl;
    myfile.close();

    REQUIRE(std::ifstream("test/example.txt"));

    SUBCASE("Can read one line at a time") {
      FileInput reader("test/example.txt");
      CHECK(reader.next() == line1);
      CHECK(reader.next() == line2);
    }
    SUBCASE("Returns EOF const at the end of a file") {
      FileInput reader("test/example.txt");

      CHECK(reader.next() == line1);
      CHECK(reader.next() == line2);
      CHECK(reader.next() == std::to_string(EOF));
    }

    REQUIRE(remove("test/example.txt") == 0);
  }
}
