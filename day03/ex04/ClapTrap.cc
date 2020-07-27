// Copyright 2020 kkozlov

#include <stdlib.h>

#include <iostream>
#include <string>

#include "ClapTrap.h"

ClapTrap::ClapTrap(void)
    : name_("none") {
}

ClapTrap::ClapTrap(const std::string &name)
    : name_(name) {
}

ClapTrap::ClapTrap(const std::string &name, unsigned hitPoints,
                   unsigned maxHitPoints, unsigned energyPoints,
                   unsigned maxEnergyPoints,
                   unsigned level, unsigned meleeAttackDamage,
                   unsigned rangedAttackDamage, unsigned armorDamageReduction)
    : name_(name), hitPoints_(hitPoints), maxHitPoints_(maxHitPoints),
      energyPoints_(energyPoints), maxEnergyPoints_(maxEnergyPoints), level_(level),
      meleeAttackDamage_(meleeAttackDamage),
      rangedAttackDamage_(rangedAttackDamage),
      armorDamageReduction_(armorDamageReduction) {
  std::cout << "ClapTrap named " << name_ << " has been initialised.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name_(other.name_), hitPoints_(other.hitPoints_),
      maxHitPoints_(other.maxHitPoints_), energyPoints_(other.energyPoints_),
      maxEnergyPoints_(other.maxEnergyPoints_), level_(other.level_),
      meleeAttackDamage_(other.meleeAttackDamage_),
      rangedAttackDamage_(other.rangedAttackDamage_), armorDamageReduction_(
          other.armorDamageReduction_) {
  std::cout << "ClapTrap named " << other.name_ << " has been copied.\n";
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap going by the name of "
            << name_ << " has been destroyed.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  if (this == &rhs) {
    return *this;
  }
  name_ = rhs.name_;
  hitPoints_ = rhs.hitPoints_;
  maxHitPoints_ = rhs.maxHitPoints_;
  energyPoints_ = rhs.energyPoints_;
  maxEnergyPoints_ = rhs.maxEnergyPoints_;
  level_ = rhs.level_;
  meleeAttackDamage_ = rhs.meleeAttackDamage_;
  rangedAttackDamage_ = rhs.rangedAttackDamage_;
  armorDamageReduction_ = rhs.armorDamageReduction_;
  std::cout << "ClapTrap named " << name_
            << " has been reassigned to " << rhs.name_ << std::endl;
  return *this;
}

const std::string &ClapTrap::Name(void) const {
  return name_;
}

void ClapTrap::RangedAttack(const std::string &target) const {
  std::cout << name_ << " attacks " << target
            << " at range, causing " << rangedAttackDamage_
            << " points of damage!\n";
}

void ClapTrap::MeleeAttack(const std::string &target) const {
  std::cout << name_ << " attacks " << target
            << " with a melee weapon, causing " << meleeAttackDamage_
            << " point of damage!\n";
}

void ClapTrap::TakeDamage(unsigned amount) {
  hitPoints_ -= amount;
  if (0 > hitPoints_) {
    hitPoints_ = 0;
  }
  std::cout << name_ << " has been damaged by " << amount
            << "; Hit Points: " << hitPoints_ << std::endl;
}

void ClapTrap::BeRepaired(unsigned amount) {
  hitPoints_ += amount;
  if (hitPoints_ > maxHitPoints_) {
    hitPoints_ = maxHitPoints_;
  }
  std::cout << name_ << " has been repaired by " << amount
            << "; Hit Points: " << hitPoints_ << std::endl;
}

unsigned ClapTrap::HitPoints(void) const {
  return hitPoints_;
}

unsigned ClapTrap::MaxHitPoints(void) const {
  return maxHitPoints_;
}

unsigned ClapTrap::EnergyPoints(void) const {
  return energyPoints_;
}

unsigned ClapTrap::MaxEnergyPoints(void) const {
  return maxEnergyPoints_;
}

unsigned ClapTrap::Level(void) const {
  return level_;
}

unsigned ClapTrap::MeleeAttackDamage(void) const {
  return meleeAttackDamage_;
}

unsigned ClapTrap::RangedAttackDamage(void) const {
  return rangedAttackDamage_;
}

unsigned ClapTrap::ArmorDamageReduction(void) const {
  return armorDamageReduction_;
}

std::ostream &operator<<(std::ostream& os, const ClapTrap& in) {
  os << "Name: " << in.Name() << std::endl;
  os << "Hit Points: " << in.HitPoints() << std::endl;
  os << "Max Hit Points: " << in.MaxHitPoints() << std::endl;
  os << "Energy Points: " << in.EnergyPoints() << std::endl;
  os << "Max Energy Points: " << in.MaxEnergyPoints() << std::endl;
  os << "Level: "<< in.Level() << std::endl;
  os << "Melee Attack Damage: " << in.MeleeAttackDamage() << std::endl;
  os << "Ranged Attack Damage: " << in.RangedAttackDamage() << std::endl;
  os << "Armor Damage Reduction: " << in.ArmorDamageReduction() << std::endl;
  return os;
}
