// Copyright 2020 kkozlov

#include <iostream>

#include "StripMiner.h"

StripMiner::StripMiner(void) {
}

StripMiner::StripMiner(StripMiner const &other) {
}

StripMiner::~StripMiner(void) {
}

StripMiner &StripMiner::operator=(StripMiner const &rhs) {
  return *this;
}

void StripMiner::Mine(IAsteroid *asteroid) {
  std::cout << "* strip mining ... got " << asteroid->BeMined(this)
            << "! *" << std::endl;
}
