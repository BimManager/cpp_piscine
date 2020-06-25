// Copyright 2020 kkozlov

#ifndef HUMAN_A_HPP_
#define HUMAN_A_HPP_

#include <string>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(const std::string& name, const Weapon& weapon);
  void Attack(void);
 private:
  std::string name_;
  const Weapon& weapon_;
};

#endif
