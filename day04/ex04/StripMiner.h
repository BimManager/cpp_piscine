// Copyright 2020 kkozlov

#ifndef DAY04_EX04_STRIPMINER_H_
#define DAY04_EX04_STRIPMINER_H_

#include "IMiningLaser.h"

class StripMiner : public IMiningLaser {
 public:
  StripMiner(void);
  StripMiner(StripMiner const &other);
  ~StripMiner(void);

  StripMiner &operator=(StripMiner const &rhs);

  void Mine(IAsteroid *);
};

#endif  // DAY04_EX04_STRIPMINER_H_
