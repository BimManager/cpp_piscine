// Copyright 2020 kkozlov

#ifndef DAY03_EX04_CLAPTRAP_H_
#define DAY03_EX04_CLAPTRAP_H_

#include <string>
#include <iostream>

class ClapTrap {
 public:

  explicit ClapTrap(const std::string &name);
  ClapTrap(const std::string &name, unsigned hitPoints, unsigned maxHitPoints,
           unsigned energyPoints, unsigned maxEnergyPoints, unsigned level,
           unsigned meleeAttackDamage, unsigned rangedAttackDamage,
           unsigned armorDamageReduction);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap(void);
  ClapTrap &operator=(const ClapTrap &rhs);
  void RangedAttack(const std::string &target) const;
  void MeleeAttack(const std::string &target) const;
  void TakeDamage(unsigned amount);
  void BeRepaired(unsigned amount);
  const std::string &Name(void) const;
  unsigned HitPoints(void) const;
  unsigned MaxHitPoints(void) const;
  unsigned EnergyPoints(void) const;
  unsigned MaxEnergyPoints(void) const;
  unsigned Level(void) const;
  unsigned MeleeAttackDamage(void) const;
  unsigned RangedAttackDamage(void) const;
  unsigned ArmorDamageReduction(void) const;

 protected:
  ClapTrap(void);

  std::string name_;
  unsigned hitPoints_;
  unsigned maxHitPoints_;
  unsigned energyPoints_;
  unsigned maxEnergyPoints_;
  unsigned level_;
  unsigned meleeAttackDamage_;
  unsigned rangedAttackDamage_;
  unsigned armorDamageReduction_;
};

std::ostream &operator<<(std::ostream &os, const ClapTrap &ft);

#endif  // DAY03_EX04_CLAPTRAP_H_
