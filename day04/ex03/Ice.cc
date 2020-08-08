// Copyright 2020 kkozlov

#include <iostream>

#include "Ice.h"

Ice::Ice(void)
    : AMateria("ice") {
}

Ice::Ice(Ice const &other)
    : AMateria(other.Type()) {
  SetXP(other.XP());
}

Ice::~Ice(void) {
}

Ice &Ice::operator=(Ice const &rhs) {
  if (&rhs != this) {
    SetType(rhs.Type());
    SetXP(rhs.XP());
  }
  return *this;
}

Ice *Ice::Clone(void) const {
  Ice *clone = new Ice(*this);
  return clone;
}

void Ice::Use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at "
            << target.Name() << " *" << std::endl;
}
