// Copyright 2020 kkozlov

#include <stdlib.h>

#include <iostream>
#include <string>

#include "ClapTrap.h"
#include "ScavTrap.h"

const char *ScavTrap::availableChallenges_[] = {
  "chopping their head off", "taking their trousers off",
  "taking the mickey out of them", "shooting them in the foot",
  "smashing their skull"
};

const unsigned ScavTrap::nbChallenges_ = 5;

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3) {
  std::cout << "ScavTrap named " << name_ << " has been initialised.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other) {
  std::cout << "ScavTrap named " << other.name_ << " has been copied.\n";
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap going by the name of "
            << name_ << " has been destroyed.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  if (this == &rhs) {
    return *this;
  }
  std::cout << "ScavTrap named " << name_
            << " has been reassigned to " << rhs.name_ << std::endl;
  return *this;
}

void ScavTrap::ChallengeNewcomer(const std::string &target) {
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
  std::cout << name_ << " challenges " << target << " by "
            << availableChallenges_[rand_r(&now) % nbChallenges_]
            << std::endl;
}

std::ostream &operator<<(std::ostream& os, const ScavTrap& ft) {
  os << ft.Name();
  return os;
}
