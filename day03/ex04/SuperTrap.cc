// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "SuperTrap.h"

SuperTrap::SuperTrap(const std::string &name)
    : ClapTrap(name), FragTrap(), NinjaTrap() {
  hitPoints_ = FragTrap::HitPoints();
  maxHitPoints_ = FragTrap::MaxHitPoints();
  energyPoints_ = NinjaTrap::EnergyPoints();
  maxEnergyPoints_ = NinjaTrap::MaxEnergyPoints();
  meleeAttackDamage_ = NinjaTrap::MeleeAttackDamage();
  rangedAttackDamage_ = FragTrap::RangedAttackDamage();
  armorDamageReduction_ = NinjaTrap::ArmorDamageReduction();
  std::cout << "SuperTrap named " << name_
            << " has been initialised\n";
}

SuperTrap::SuperTrap(const SuperTrap &other)
    : ClapTrap(other), FragTrap(other), NinjaTrap(other) {
  std::cout << "SuperTrap named " << name_
            << " has been copied from "
            << other.name_;
}

SuperTrap::~SuperTrap(void) {
  std::cout << "SuperTrap " << Name()
            << " is about to be destroyed\n";
}

SuperTrap& SuperTrap::operator=(const SuperTrap &rhs) {
  if (&rhs == this)
    return *this;
  std::cout << "SuperTrap " << Name()
            << "has been reassigned from "
            << rhs.Name() << std::endl;
  return *this;
}

void SuperTrap::RangedAttack(std::string const &target) const {
  FragTrap::RangedAttack(target);
}

void SuperTrap::MeleeAttack(std::string const &target) const {
  NinjaTrap::MeleeAttack(target);
}


