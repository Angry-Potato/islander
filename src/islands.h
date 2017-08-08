#ifndef ISLANDS_H
#define ISLANDS_H

#include <forward_list>

class Place;
struct Islands {
  static Place* find(std::forward_list<Place*>& places);
};
#endif
