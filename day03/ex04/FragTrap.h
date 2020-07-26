// Copyright 2020 kkozlov

#ifndef DAY03_EX02_FRAGTRAP_H__
#define DAY03_EX02_FRAGTRAP_H__

#include <string>
#include <iostream>

#include "ClapTrap.h"

class FragTrap : public virtual ClapTrap {
 public:
  FragTrap(void);
  FragTrap(int);
  explicit FragTrap(const std::string &name);  
  FragTrap(const FragTrap &other);
  ~FragTrap(void);
  FragTrap &operator=(const FragTrap &rhs);
  void VaultHunterDotExe(const std::string &target);

 private:
  static const char *availableAttacks_[];
  static const unsigned nbAttacks_;
};

#endif  // DAY03_EX02_FRAGTRAP_H__
