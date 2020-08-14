// Copyright 2020 kkozlov

#include "MiningBarge.h"

MiningBarge::MiningBarge(void) {
  unsigned i = NB_LASERS;
  while (i--)
    lasers_[i] = 0;
}

MiningBarge::MiningBarge(MiningBarge const &other) {
  unsigned i = NB_LASERS;
  while (i--)
    if (other.lasers_[i])
      lasers_[i] = other.lasers_[i];
}

MiningBarge::~MiningBarge(void) {}

MiningBarge &MiningBarge::operator=(MiningBarge const &rhs) {
  if (&rhs != this) {
    unsigned i = NB_LASERS;
    while (i--)
      if (rhs.lasers_[i])
        lasers_[i] = rhs.lasers_[i];
  }
  return *this;
}

void MiningBarge::Equip(IMiningLaser *laser) {
  unsigned i = -1;
  while (++i < NB_LASERS)
    if (!lasers_[i]) {
      lasers_[i] = laser;
      return;
    }
}

void MiningBarge::Mine(IAsteroid *asteroid) const {
  unsigned i = -1;
  while (++i < NB_LASERS)
    if (lasers_[i]) {
      lasers_[i]->Mine(asteroid);
    }
}

