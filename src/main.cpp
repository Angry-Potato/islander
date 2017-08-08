#include <iostream>
#include <forward_list>
#include "place.h"
#include "file_input.h"
#include <string>
#include "place_factory.h"
#include "islands.h"
#include <fstream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " <filename>" << std::endl;
  }
  else {
    std::cout << "Let me find that island for you.." << std::endl;
    std::forward_list<Place*> places;
    FileInput input(argv[1]);
    std::cout << "Reading input.." << std::endl;
    for (std::string line = input.next(); line != std::to_string(EOF); line = input.next()) {
      Place* place = PlaceFactory::create(line);
      if (place != NULL) {
        places.push_front(place);
      }
    }
    long size = Islands::listSize(places);
    if (size == 0) {
      std::cout << "Input is empty or in unreadable format. Make sure each line is in the format <place_name> <x_coord> <y_coord>" << std::endl;
      return 1;
    }

    std::cout << "That is " << size << " places to check, this may be a while.." << std::endl;
    Place* island = Islands::find(places);
    if (island != NULL) {
      std::cout << "island found: " << island->id() << std::endl;
    }
    else {
      std::cout << "island not found :( I am ashamed." << std::endl;
    }
  }
  return 0;
}
