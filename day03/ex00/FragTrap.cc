// Copyright 2020 kkozlov

#include <stdlib.h>

#include <iostream>
#include <string>

#include "FragTrap.h"

const char *FragTrap::availableAttacks_[] = {
  "chopping their head off", "taking their trousers off",
  "taking the mickey out of them", "shooting them in the foot",
  "smashing their skull"
};

const unsigned FragTrap::nbAttacks_ = 5;

FragTrap::FragTrap(const std::string &name)
    : name_(name), hitPoints_(100), maxHitPoints_(100),
      energyPoints_(50), level_(1), meleeAttackDamage_(20),
      rangedAttackDamage_(15), armorDamageReduction_(3) {
  std::cout << "FragTrap named " << name_ << " has been initialised.\n";
}

FragTrap::FragTrap(const FragTrap &other) {
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

const std::string &FragTrap::Name(void) const {
  return name_;
}

void FragTrap::RangedAttack(const std::string &target) const {
  std::cout << name_ << " attacks " << target
            << " at range, causing " << rangedAttackDamage_
            << " points of damage!\n";
}

void FragTrap::MeleeAttack(const std::string &target) const {
  std::cout << name_ << " attacks " << target
            << " with a melee weapon, causing " << meleeAttackDamage_
            << " point of damage!\n";
}

void FragTrap::TakeDamage(unsigned amount) {
  hitPoints_ -= amount;
  if (0 > hitPoints_) {
    hitPoints_ = 0;
  }
  std::cout << name_ << " has been damaged by " << amount
            << "; Hit Points: " << hitPoints_ << std::endl;
}

void FragTrap::BeRepaired(unsigned amount) {
  hitPoints_ += amount;
  if (hitPoints_ > maxHitPoints_) {
    hitPoints_ = maxHitPoints_;
  }
  std::cout << name_ << " has been repaired by " << amount
            << "; Hit Points: " << hitPoints_ << std::endl;
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

std::ostream &operator<<(std::ostream& os, const FragTrap& ft) {
  os << ft.Name();
  return os;
}
