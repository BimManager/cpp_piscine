// Copyright 2020 kkozlov

#include <stdlib.h>

#include <iostream>
#include <string>

#include "ClapTrap.h"
#include "FragTrap.h"

const char *FragTrap::availableAttacks_[] = {
  "chopping their head off", "taking their trousers off",
  "taking the mickey out of them", "shooting them in the foot",
  "smashing their skull"
};

const unsigned FragTrap::nbAttacks_ = 5;

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name, 100, 100, 50, 1, 30, 20, 5) {
  std::cout << "FragTrap named " << name_ << " has been initialised.\n";
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other) {
  std::cout << "FragTrap named " << other.name_ << " has been copied.\n";
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap going by the name of "
            << name_ << " has been destroyed.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  if (this == &rhs) {
    return *this;
  }
  std::cout << "FragTrap named " << name_
            << " has been reassigned to " << rhs.name_ << std::endl;
  return *this;
}

void FragTrap::VaultHunterDotExe(const std::string &target) {
  unsigned attackCost;
  unsigned now;

  now = (unsigned)time(NULL);
  attackCost = 25;
  if (energyPoints_ < attackCost) {
    std::cout << name_ << " is out of energy. Energy points: "
              << energyPoints_ << std::endl;
    return;
  }
  energyPoints_ -= attackCost;
  std::cout << name_ << " attacks " << target << " by "
            << availableAttacks_[rand_r(&now) % nbAttacks_]
            << std::endl;
}
