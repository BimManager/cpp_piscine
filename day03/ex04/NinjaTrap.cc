// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "ClapTrap.h"
#include "NinjaTrap.h"

NinjaTrap::NinjaTrap(const std::string &name)
    : ClapTrap(name) {
  hitPoints_ = 60;
  maxHitPoints_ = 60;
  energyPoints_ = 120;
  maxEnergyPoints_ = 120;
  level_ = 1;
  meleeAttackDamage_ = 60;
  rangedAttackDamage_ = 5;
  armorDamageReduction_ = 0;
  std::cout << "NinjaTrap named " << name_
            << " has been initialised\n";
}

NinjaTrap::NinjaTrap(const NinjaTrap &other)
    : ClapTrap(other) {
  std::cout << "NinjaTrap has been copied from "
            << other.Name() << std::endl;
}

NinjaTrap::~NinjaTrap(void) {
  std::cout << "NinjaTrap called " << name_
            << " has been destroyed\n";
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &rhs) {
  if (&rhs == this)
    return *this;
  std::cout << "NinjaTrap " << name_
            << "has been reassigned to "
            << rhs.name_ << std::endl;
  return *this;
}

void NinjaTrap::NinjaShoebox(const ClapTrap &target) {
  std::cout << "NinjaTrap " << name_
            << " is doing something funny to "
            << target.Name() << std::endl;
}
