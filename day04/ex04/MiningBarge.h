// Copyright 2020 kkozlov

#ifndef DAY04_EX04_MININGBARGE_H_
#define DAY04_EX04_MININGBARGE_H_

#include "IMiningLaser.h"
#include "IAsteroid.h"

#define NB_LASERS 4

class MiningBarge {
 public:
  MiningBarge(void);
  MiningBarge(MiningBarge const &other);
  ~MiningBarge(void);

  MiningBarge &operator=(MiningBarge const &rhs);

  void Equip(IMiningLaser *laser);
  void Mine(IAsteroid *asteroid) const;

 private:
  IMiningLaser *lasers_[NB_LASERS];
};

#endif  // DAY04_EX04_MININGBARGE_H_
