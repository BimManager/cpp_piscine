// Copyright 2020 kkozlov

#ifndef DAY04_EX03_ICHARACTER_H_
#define DAY04_EX03_ICHARACTER_H_

#include <string>

#include "AMateria.h"

class AMateria;

class ICharacter {
 public:
  virtual ~ICharacter(void) {}
  virtual std::string const &Name(void) const = 0;
  virtual void Equip(AMateria *m) = 0;
  virtual void Unequip(unsigned idx) = 0;
  virtual void Use(unsigned idx, ICharacter &target) = 0;
};

#endif  // DAY04_EX03_ICHARACTER_H_
