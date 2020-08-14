// Copyright 2020 kkozlov

#ifndef DAY04_EX04_IMININGLASER_H_
#define DAY04_EX04_IMININGLASER_H_

#include "IAsteroid.h"

class IAsteroid;

class IMiningLaser {
 public:
  virtual ~IMiningLaser(void) {}
  virtual void Mine(IAsteroid *) = 0;
};

#endif  // DAY04_EX04_IMININGLASER_H_
