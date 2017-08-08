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
  long potentialsRemaining = size(places)
  while potentialsRemaining > 1
    if (potentialIsland == NULL) {
      potentialIsland = places.first
    }
    if (potentialIsland->nearestPlace == NULL) {
      potentialIsland->nearestPlace = Places::nearest(potentialIsland, places)
    }
    potentialIsland = nextPotentialIsland(potentialIsland, places, &potentialsRemaining)

  return potentialIsland


    function nextPotentialIsland::
      for each innerloopplace in places
        if (innerloopplace->nearestPlace == NULL) {
          innerloopplace->nearestPlace = Places::nearest(innerloopplace, places)
        }
        if innerloopplace->distToNearestPlace < potentialIsland->distToNearestPlace
          innerloopplace->isPotentialIsland = false
          innerloopplace->nearestPlace->isPotentialIsland = false
          AND if innerloopplace->nearestPlace->nearestPlace != innerloopplace
            innerloopplace->nearestPlace->nearestPlace->isPotentialIsland = false
            innerloopplace->nearestPlace->nearestPlace->nearestPlace->isPotentialIsland = false
          potentialsRemaining -= however many get falsified
        else
          potentialIsland->isPotentialIsland = false
          potentialIsland->nearestPlace->isPotentialIsland = false
          same recursive call here for setting not potential
          potentialsRemaining -= however many get falsified
          return innerloopplace
        return NULL


  */
  return new Place();
}
