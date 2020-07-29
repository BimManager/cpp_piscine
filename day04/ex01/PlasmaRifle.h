// Copyright 2020 kkozlov

#ifndef DAY04_EX01_PLASMARIFLE_H_
#define DAY04_EX01_PLASMARIFLE_H_

#include <string>

#include "AWeapon.h"

class PlasmaRifle : public AWeapon {
 public:
  PlasmaRifle(void);
  PlasmaRifle(PlasmaRifle const &other);
  ~PlasmaRifle(void);

  PlasmaRifle& operator=(PlasmaRifle const &rhs);

  virtual void Attack(void) const;
};

#endif  // DAY04_EX01_PLASMARIFLE_H_
