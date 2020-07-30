// Copyright 2020 kkozlov

#ifndef DAY04_EX01_RADSCORPION_H_
#define DAY04_EX01_RADSCORPION_H_

#include "Enemy.h"

class RadScorpion : public Enemy {
 public:
  RadScorpion(void);
  RadScorpion(RadScorpion const &other);
  ~RadScorpion(void);

  RadScorpion& operator=(RadScorpion const &rhs);
};

#endif  // DAY04_EX01_RADSCORPION_H_
