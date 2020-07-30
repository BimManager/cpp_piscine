// Copyright 2020 kkozlov

#ifndef DAY04_EX01_CHARACTER_H_
#define DAY04_EX01_CHARACTER_H_

#include <string>
#include <iostream>

#include "AWeapon.h"
#include "Enemy.h"

class Character {
 public:
  explicit Character(std::string const &name);
  Character(Character const &other);
  ~Character(void);

  Character& operator=(Character const &rhs);

  std::string const& Name(void) const;
  int AP(void) const;
  AWeapon* Weapon(void) const;

  void RecoverAP(void);
  void Equip(AWeapon *weapon);
  void Attack(Enemy *enemy);

 private:
  std::string name_;
  int ap_;
  AWeapon *weapon_;
};

std::ostream& operator<<(std::ostream &os, Character const &in);

#endif  // DAY04_EX01_CHARACTER_H_
