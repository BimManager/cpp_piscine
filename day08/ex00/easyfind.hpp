// Copyright 2020 kkozlov

#include <algorithm>
#include <iterator>

template<typename Container>
int easyfind(Container &container, int target) {
  typename Container::iterator it =
      std::find(std::begin(container), std::end(container), target);
  if (it == container.end())
    return -1;
  return it - container.begin();
}
