#include "islands.h"
#include "place.h"
#include <forward_list>

Place* Islands::find(std::forward_list<Place*>& places) {
  if (places.empty()) {
    return NULL;
  }
  if (listSize(places) < 3) {
    return places.front();
  }
  /*
  Place* potentialIsland
  Place* nextPotentialIsland
  for each place in places
    if (potentialIsland == NULL) {
      potentialIsland = place
    }
    if (potentialIsland->nearestPlace == NULL) {
      potentialIsland->nearestPlace = Places::nearest(potentialIsland, places)
    }
    nextPotentialIsland = nextPotentialIsland(potentialIsland, places)
    if (nextPotentialIsland == potentialIsland) {
      return potentialIsland
    }




    function nextPotentialIsland::
      for each innerloopplace in places 
        if (innerloopplace->nearestPlace == NULL) {
          innerloopplace->nearestPlace = Places::nearest(innerloopplace, places)
        }
        if innerloopplace->distToNearestPlace < potentialIsland->distToNearestPlace
          innerloopplace->isPotentialIsland = false
          innerloopplace->nearestPlace->isPotentialIsland = false
        else
          potentialIsland->isPotentialIsland = false
          potentialIsland->nearestPlace->isPotentialIsland = false
          return innerloopplace
        return potentialIsland


  */
  return new Place();
}
