// Copyright 2020 kkozlov

#ifndef DAY03_EX02_CLAPTRAP_H__
#define DAY03_EX02_CLAPTRAP_H__

#include <string>
#include <iostream>

class ClapTrap {
 public:
  ClapTrap(const std::string &name, unsigned hitPoints, unsigned maxHitPoints,
           unsigned energyPoints, unsigned level, unsigned meleeAttackDamage,
           unsigned rangedAttackDamage, unsigned armorDamageReduction);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap(void);
  ClapTrap &operator=(const ClapTrap &rhs);
  const std::string &Name(void) const;
  void RangedAttack(const std::string &target) const;
  void MeleeAttack(const std::string &target) const;
  void TakeDamage(unsigned amount);
  void BeRepaired(unsigned amount);

 protected:
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

#endif  // DAY03_EX02_CLAPTRAP_H__
