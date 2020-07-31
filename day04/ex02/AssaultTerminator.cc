// Copyright 2020 kkozlov

#include <iostream>

#include "AssaultTerminator.h"

AssaultTerminator::AssaultTerminator(void) {
  std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &other) {
}

AssaultTerminator::~AssaultTerminator(void) {
  std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &rhs) {
}

AssaultTerminator *AssaultTerminator::Clone(void) const {
  return new AssaultTerminator();
}

void AssaultTerminator::BattleCry(void) const {
  std::cout << "This code is unclear. PURIFY IT!" << std::endl;
}

void AssaultTerminator::RangedAttack(void) const {
  std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::MeleeAttack(void) const {
  std::cout << "* attacks with chainfists *" << std::endl;
}
