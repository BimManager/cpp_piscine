// Copyright 2020 kkozlov

#ifndef DAY04_EX04_DEEPCOREMINER_H_
#define DAY04_EX04_DEEPCOREMINER_H_

#include "IMiningLaser.h"

class DeepCoreMiner : public IMiningLaser {
 public:
  DeepCoreMiner(void);
  DeepCoreMiner(DeepCoreMiner const &other);
  ~DeepCoreMiner(void);

  DeepCoreMiner &operator=(DeepCoreMiner const &rhs);

  void Mine(IAsteroid *);
};

#endif  // DAY04_EX04_DEEPCOREMINER_H_
