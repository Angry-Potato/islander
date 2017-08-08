#include "places.h"
#include "place.h"
#include "geometry.h"
#include <forward_list>
#include <limits>

Place* Places::nearestNeighbour(Place* origin, std::forward_list<Place*>& places) {
  if (origin == NULL || places.empty()) {
    return NULL;
  }
  long nearestDistance = std::numeric_limits<long>::max();
  Place* nearestNeighbour = NULL;

  for (auto placeIterator = places.begin(); placeIterator != places.end(); placeIterator++) {
    if ((*placeIterator)->id() == origin->id()) {
      continue;
    }
    long distToPlace = Geometry::distanceBetween((*placeIterator)->position(), origin->position());
    if (distToPlace < nearestDistance) {
      nearestDistance = distToPlace;
      nearestNeighbour = (*placeIterator);
    }
  }

  return nearestNeighbour;
}
