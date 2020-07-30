// Copyright 2020 kkozlov

#ifndef DAY04_EX01_SUPERMUTANT_H_
#define DAY04_EX01_SUPERMUTANT_H_

#include "Enemy.h"

class SuperMutant : public Enemy {
 public:
  SuperMutant(void);
  SuperMutant(SuperMutant const &other);
  ~SuperMutant(void);

  SuperMutant& operator=(SuperMutant const &rhs);

  void TakeDamage(int take);
};

#endif  // DAY04_EX01_SUPERMUTANT_H_
