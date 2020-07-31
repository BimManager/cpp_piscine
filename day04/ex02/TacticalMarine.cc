// Copyright 2020 kkozlov

#include <iostream>

#include "TacticalMarine.h"

TacticalMarine::TacticalMarine(void) {
  std::cout << "Tactical Marine is ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &other) {
}

TacticalMarine::~TacticalMarine(void) {
  std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine& TacticalMarine::operator=(TacticalMarine const &rhs) {
  if (&rhs == this)
    return *this;
}

TacticalMarine *TacticalMarine::Clone(void) const {
  TacticalMarine *marine_p;
  marine_p = new TacticalMarine();
  return marine_p;
}

void TacticalMarine::BattleCry(void) const {
  std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::RangedAttack(void) const {
  std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::MeleeAttack(void) const {
  std::cout << "* attacks with a chainsword *" << std::endl;
}

