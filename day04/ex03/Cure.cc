// Copyright 2020 kkozlov

#include <iostream>

#include "Cure.h"

Cure::Cure(void)
    : AMateria("cure") {
}

Cure::Cure(Cure const &other)
    : AMateria(other.Type()) {
  SetXP(other.XP());
}

Cure::~Cure(void) {
}

Cure &Cure::operator=(Cure const &rhs) {
  if (&rhs != this) {
    SetType(rhs.Type());
    SetXP(rhs.XP());
  }
  return *this;
}

Cure *Cure::Clone(void) const {
  Cure *cure  = new Cure(*this);
  return cure;
}

void Cure::Use(ICharacter &target) {
  std::cout << "* heals " << target.Name()
            << "'s wounds *" << std::endl;
}
