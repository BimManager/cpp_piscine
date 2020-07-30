// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "PowerFist.h"

PowerFist::PowerFist(void)
    : AWeapon("Power Fist", 8, 50) {
}

PowerFist::PowerFist(PowerFist const &other)
    : AWeapon(other) {
}

PowerFist::~PowerFist(void) {
}

PowerFist& PowerFist::operator=(PowerFist const &rhs) {
  if (&rhs == this)
    return *this;
  SetName(rhs.Name());
  SetAPCost(rhs.APCost());
  SetDamage(rhs.Damage());
  return *this;
}

void PowerFist::Attack(void) const {
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
