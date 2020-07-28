// Copyright 2020 kkozlov

#ifndef DAY03_EX04_FRAGTRAP_H_
#define DAY03_EX04_FRAGTRAP_H_

#include <string>
#include <iostream>

#include "ClapTrap.h"

class FragTrap : public virtual ClapTrap {
 public:
  explicit FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  ~FragTrap(void);
  void VaultHunterDotExe(const std::string &target);

 protected:
  FragTrap(void);

 private:
  static const char *availableAttacks_[];
  static const unsigned nbAttacks_;
};

#endif  // DAY03_EX04_FRAGTRAP_H_
