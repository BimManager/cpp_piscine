// Copyright 2020 kkozlov

#ifndef DAY03_EX02_SCAVTRAP_H__
#define DAY03_EX02_SCAVTRAP_H__

#include <string>
#include <iostream>

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
 public:
  explicit ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ~ScavTrap(void);
  ScavTrap &operator=(const ScavTrap &rhs);
  void ChallengeNewcomer(const std::string &target);

 private:
  static const char *availableChallenges_[];
  static const unsigned nbChallenges_;
};

#endif  // DAY03_EX02_SCAVTRAP_H_
