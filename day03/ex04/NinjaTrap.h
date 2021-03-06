// Copyright 2020 kkozlov

#ifndef DAY03_EX04_NINJATRAP_H_
#define DAY03_EX04_NINJATRAP_H_

#include <string>

#include "ClapTrap.h"

class NinjaTrap : public virtual ClapTrap {
 public:
  explicit NinjaTrap(const std::string &name);
  NinjaTrap(const NinjaTrap &other);
  ~NinjaTrap(void);
  NinjaTrap& operator=(const NinjaTrap &rhs);
  void NinjaShoebox(const ClapTrap &target);

 protected:
  NinjaTrap(void);
};

#endif  // DAY03_EX04_NINJATRAP_H_
