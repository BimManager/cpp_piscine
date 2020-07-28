// Copyright 2020 kkozlov

#ifndef DAY03_EX04_SUPERTRAP_H_
#define DAY03_EX04_SUPERTRAP_H_

#include <string>

#include "FragTrap.h"
#include "NinjaTrap.h"

class SuperTrap : public FragTrap, public NinjaTrap {
 public:
  explicit SuperTrap(const std::string &name);
  SuperTrap(const SuperTrap &other);
  ~SuperTrap(void);

  SuperTrap& operator=(const SuperTrap &rhs);

  void RangedAttack(std::string const &target) const;
  void MeleeAttack(std::string const &target) const;
};

#endif  // DAY03_EX04_SUPERTRAP_H_
