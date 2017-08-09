#include "islands.h"
#include "place.h"
#include <forward_list>
#include <iostream>

Place* Islands::find(std::forward_list<Place*>& places) {
  if (places.empty()) {
    return NULL;
  }

  long initialSize = listSize(places);
  if (initialSize < 3) {
    return places.front();
  }

  Place* potentialIsland = Places::firstPotentialIsland(places);
  long potentialsRemaining = initialSize;
  printf("Beginning search..\n");
  while (potentialsRemaining > 1) {
    if (potentialIsland == NULL || !potentialIsland->isPotentialIsland()) {
      potentialIsland = Places::firstPotentialIsland(places);
    }
    if (!potentialIsland->hasNearestPlace()) {
      potentialIsland->setNearestPlace(Places::nearestNeighbour(potentialIsland, places));
    }
    potentialIsland = nextPotentialIsland(potentialIsland, places, potentialsRemaining);
  }
  printf("\nEnd of search.\n");
  potentialIsland = Places::firstPotentialIsland(places);
  return potentialIsland;
}

Place* Islands::nextPotentialIsland(Place* potentialIsland, std::forward_list<Place*>& places, long& potentialsRemaining) {
  if (potentialIsland == NULL || places.empty() || potentialsRemaining < 0) {
    potentialsRemaining = 0;
    return NULL;
  }
  for (auto placesIterator = places.begin(); placesIterator != places.end(); ++placesIterator) {
    printf("\rPotential islands left to eliminate: %ld       ", potentialsRemaining);
    Place* newPotentialIsland = *placesIterator;
    if (*newPotentialIsland == *potentialIsland || !newPotentialIsland->isPotentialIsland()) {
      continue;
    }
    if (!newPotentialIsland->hasNearestPlace()) {
      newPotentialIsland->setNearestPlace(Places::nearestNeighbour(newPotentialIsland, places));
    }
    if (newPotentialIsland->distanceToNearestPlace() < potentialIsland->distanceToNearestPlace()) {
      newPotentialIsland->notPotentialIsland(potentialsRemaining);
    }
    else {
      potentialIsland->notPotentialIsland(potentialsRemaining);
      if (newPotentialIsland->isPotentialIsland()) {
        return newPotentialIsland;
      }
      potentialIsland = newPotentialIsland;
    }
  }
  return NULL;
}
