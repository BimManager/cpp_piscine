// Copyright 2020 kkozlov

#include <iostream>

#include "RadScorpion.h"

RadScorpion::RadScorpion(void)
    : Enemy(80, "RadScorpion") {
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &other)
    : Enemy(other.HP(), other.Type()) {
}

RadScorpion::~RadScorpion(void) {
  std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion& RadScorpion::operator=(RadScorpion const &rhs) {
  if (&rhs == this)
    return *this;
  SetType(rhs.Type());
  SetHP(rhs.HP());
  return *this;
}
