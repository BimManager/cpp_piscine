// Copyright 2020 kkozlov

#ifndef DAY03_EX00_FRAGTRAP_H__
#define DAY03_EX00_FRAGTRAP_H__

#include <string>
#include <iostream>

class FragTrap {
 public:
  explicit FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  ~FragTrap(void);
  FragTrap &operator=(const FragTrap &rhs);

  const std::string &Name(void) const;

  void RangedAttack(const std::string &target) const;
  void MeleeAttack(const std::string &target) const;
  void TakeDamage(unsigned amount);
  void BeRepaired(unsigned amount);
  void VaultHunterDotExe(const std::string &target);

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

  static const char *availableAttacks_[];
  static const unsigned nbAttacks_;
};

std::ostream &operator<<(std::ostream &os, const FragTrap &ft);

#endif  // DAY03_EX00_FRAGTRAP_H__
