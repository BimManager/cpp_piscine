// Copyright 2020 kkozlov

#ifndef DAY04_EX01_POWERFIST_H_
#define DAY04_EX01_POWERFIST_H_

#include "AWeapon.h"

class PowerFist : public AWeapon {
 public:
  PowerFist(void);
  PowerFist(PowerFist const &other);
  ~PowerFist(void);

  PowerFist& operator=(PowerFist const &rhs);

  virtual void Attack(void) const;
};

#endif  // DAY04_EX01_POWERFIST_H_
