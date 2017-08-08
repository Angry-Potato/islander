#include "islands.h"
#include "place.h"
#include <forward_list>

Place* Islands::find(std::forward_list<Place*>& places) {
  if (places.empty()) {
    return NULL;
  }

  long potentialsRemaining = listSize(places);
  if (potentialsRemaining < 3) {
    return places.front();
  }

  Place* potentialIsland = Places::firstPotentialIsland(places);
  while (potentialsRemaining > 1) {
    if (potentialIsland == NULL || !potentialIsland->isPotentialIsland()) {
      potentialIsland = Places::firstPotentialIsland(places);
    }
    if (!potentialIsland->hasNearestPlace()) {
      potentialIsland->setNearestPlace(Places::nearestNeighbour(potentialIsland, places));
    }
    potentialIsland = nextPotentialIsland(potentialIsland, places, potentialsRemaining);
  }
  potentialIsland = Places::firstPotentialIsland(places);
  return potentialIsland;
}

Place* Islands::nextPotentialIsland(Place* potentialIsland, std::forward_list<Place*>& places, long& potentialsRemaining) {
  if (potentialIsland == NULL || places.empty() || potentialsRemaining < 0) {
    potentialsRemaining = 0;
    return NULL;
  }
  for (auto placesIterator = places.begin(); placesIterator != places.end(); ++placesIterator) {
    Place* newPotentialIsland = *placesIterator;
    if (*newPotentialIsland == *potentialIsland) {
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
      return newPotentialIsland;
    }
  }
  return NULL;
}
