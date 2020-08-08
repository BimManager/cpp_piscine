// Copyright 2020 kkozlov

#include <string>

#include "Character.h"

Character::Character(std::string const &name)
    : name_(name) {
}

Character::Character(Character const &other)
    : name_(other.Name()) {
}

Character::~Character(void) {
  unsigned i = INVENTORY_CAPACITY;
  while (i--)
    if (inventory_[i])
      delete inventory_[i];
}

Character &Character::operator=(Character const &rhs) {
  if (&rhs != this) {
    unsigned i = INVENTORY_CAPACITY;
    while (i--)
      if (inventory_[i])
        delete inventory_[i];
    i = INVENTORY_CAPACITY;
    while (i--)
      if (rhs.inventory_[i])
        inventory_[i] = rhs.inventory_[i]->Clone();
    name_ = rhs.Name();
  }
  return *this;
}

std::string const &Character::Name(void) const {
  return name_;
}

void Character::Equip(AMateria *m) {
  unsigned i = -1;
  while (++i < INVENTORY_CAPACITY) {
    if (!inventory_[i]) {
      inventory_[i] = m->Clone();
      break;
    }
  }
}

void Character::Unequip(unsigned idx) {
  if (idx >= INVENTORY_CAPACITY) return;
  if (inventory_[idx]) {
    delete inventory_[idx];
    inventory_[idx] = 0;
  }
}

void Character::Use(unsigned idx, ICharacter &target) {
  if (idx >= INVENTORY_CAPACITY || !inventory_[idx]) return;
  inventory_[idx]->Use(target);
}
