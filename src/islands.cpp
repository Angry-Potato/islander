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
  for each place in places
    if (potentialIsland == NULL) {
      potentialIsland = place
    }




  */
  return new Place();
}
