// Copyright 2020 kkozlov

#ifndef DAY04_EX03_CHARACTER_H_
#define DAY04_EX03_CHARACTER_H_

#include <string>

#include "ICharacter.h"
#include "AMateria.h"

#define INVENTORY_CAPACITY 4

class Character : public ICharacter {
 public:
  explicit Character(std::string const &name);
  Character(Character const &other);
  ~Character(void);

  Character &operator=(Character const &rhs);

  std::string const &Name(void) const;
  void Equip(AMateria *m);
  void Unequip(unsigned idx);
  void Use(unsigned idx, ICharacter &targert);

 private:
  std::string name_;
  AMateria *inventory_[INVENTORY_CAPACITY];
};

#endif  // DAY04_EX03_CHARACTER_H_
