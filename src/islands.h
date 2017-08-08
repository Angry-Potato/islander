#ifndef ISLANDS_H
#define ISLANDS_H

#include <forward_list>

class Place;
struct Islands {
  static Place* find(std::forward_list<Place*>& places);
  static inline int listSize(std::forward_list<Place*>& list) {return std::distance(list.begin(), list.end());};
};
#endif
