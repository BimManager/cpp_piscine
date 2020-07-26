// Copyright 2020 kkozlov

#ifndef DAY03_EX04_NINJATRAP_H_
#define DAY03_EX04_NINJATRAP_H_

#include <string>

#include "FragTrap.h"
#include "NinjaTrap.h"

class SuperTrap : public FragTrap, public NinjaTrap {
 public:
  SuperTrap(const std::string &name);
  SuperTrap(const SuperTrap &other);
  ~SuperTrap(void);
  SuperTrap& operator=(const SuperTrap &rhs);
};

#endif  // DAY03_EX04_NINJATRAP_H_
