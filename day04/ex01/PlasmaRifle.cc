// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "PlasmaRifle.h"

PlasmaRifle::PlasmaRifle(void)
    : AWeapon("PlasmaRifle", 5, 21) {
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other)
    : AWeapon(other) {
}

PlasmaRifle::~PlasmaRifle(void) {
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const &rhs) {
  if (&rhs == this)
    return *this;
  SetName(rhs.Name());
  SetAPCost(rhs.APCost());
  SetDamage(rhs.Damage());
  return *this;
}

void PlasmaRifle::Attack(void) const {
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
