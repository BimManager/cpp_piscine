// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "AMateria.h"

AMateria::AMateria(std::string const &type)
    : type_(type) {
}

AMateria::AMateria(AMateria const &other)
    : type_(other.Type()), xp_(other.XP()) {
}

AMateria::~AMateria(void) {
}

AMateria &AMateria::operator=(AMateria const &rhs) {
  type_ = rhs.Type();
  xp_ = rhs.XP();
}

std::string const &AMateria::Type(void) const {
  return type_;
}

unsigned AMateria::XP(void) const {
  return xp_;
}

void AMateria::SetType(std::string const &type) {
  type_ = type;
}

void AMateria::SetXP(unsigned xp) {
  xp_ = xp;
}

void AMateria::Use(ICharacter &target) {
  xp_ += 10;
}
