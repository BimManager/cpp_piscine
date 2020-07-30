// Copyright 2020 kkozlov

#include <iostream>

#include "SuperMutant.h"

SuperMutant::SuperMutant(void)
    : Enemy(170, "Super Mutant") {
  std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &other)
    : Enemy(other.HP(), other.Type()) {
}

SuperMutant::~SuperMutant(void) {
  std::cout << "Aaargh..." << std::endl;
}

SuperMutant& SuperMutant::operator=(SuperMutant const &rhs) {
  if (&rhs == this)
    return *this;
  SetType(rhs.Type());
  SetHP(rhs.HP());
  return *this;
}

void SuperMutant::TakeDamage(int take) {
  int hp = HP();
  if (take < 3 || hp < 0)
    return;
  SetHP(hp + 3 - take);
}
