// Copyright 2020 kkozlov

#ifndef HUMAN_B_HPP_
#define HUMAN_B_HPP_

#include <string>

#include "Weapon.hpp"

class HumanB {
 public:
  explicit HumanB(const std::string& name);
  void SetWeapon(const Weapon& weapon);
  void Attack(void);
 private:
  std::string name_;
  const Weapon* weapon_;
};

#endif
