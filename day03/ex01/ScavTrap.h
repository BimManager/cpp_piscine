// Copyright 2020 kkozlov

#ifndef DAY03_EX01_SCAVTRAP_H__
#define DAY03_EX01_SCAVTRAP_H__

#include <string>
#include <iostream>

class ScavTrap {
 public:
  explicit ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ~ScavTrap(void);
  ScavTrap &operator=(const ScavTrap &rhs);

  const std::string &Name(void) const;

  void RangedAttack(const std::string &target) const;
  void MeleeAttack(const std::string &target) const;
  void TakeDamage(unsigned amount);
  void BeRepaired(unsigned amount);
  void ChallengeNewcomer(const std::string &target);

 private:
  std::string name_;
  unsigned hitPoints_;
  unsigned maxHitPoints_;
  unsigned energyPoints_;
  unsigned maxEnergyPoints_;
  unsigned level_;
  unsigned meleeAttackDamage_;
  unsigned rangedAttackDamage_;
  unsigned armorDamageReduction_;

  static const char *availableChallenges_[];
  static const unsigned nbChallenges_;
};

std::ostream &operator<<(std::ostream &os, const ScavTrap &ft);

#endif  // DAY03_EX01_SCAVTRAP_H_
