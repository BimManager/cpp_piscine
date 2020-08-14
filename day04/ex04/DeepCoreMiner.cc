// Copyright 2020 kkozlov

#include <iostream>

#include "DeepCoreMiner.h"

DeepCoreMiner::DeepCoreMiner(void) {
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &other) {
}

DeepCoreMiner::~DeepCoreMiner(void) {
}

DeepCoreMiner &DeepCoreMiner::operator=(DeepCoreMiner const &rhs) {
  return *this;
}

void DeepCoreMiner::Mine(IAsteroid *asteroid) {
  std::cout << "* mining deep ... got " << asteroid->BeMined(this)
            << "! *" << std::endl;
}
