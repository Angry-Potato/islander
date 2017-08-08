#ifndef PLACES_H
#define PLACES_H

#include <forward_list>

class Place;
struct Places {
  static Place* nearestNeighbour(Place* origin, std::forward_list<Place*>& places);
  static Place* firstPotentialIsland(std::forward_list<Place*>& places);
};
#endif
