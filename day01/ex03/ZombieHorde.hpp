// Copyright 2020 kkozlov

#ifndef ZOMBIE_HORDE_HPP_
#define ZOMBIE_HORDE_HPP_

#include <string>

#include "Zombie.hpp"

class ZombieHorde {
 public:
  explicit ZombieHorde(int n);
  ~ZombieHorde(void);
  void Announce(void) const;
 private:
  void *rawMemory_;
  Zombie *zombies_;
  int  nbZombies_;

  ZombieHorde(const ZombieHorde& other);
  ZombieHorde& operator=(const ZombieHorde& other);

  std::string GenerateRandomName(void);
};

#endif  // ZOMBIE_HORDE_HPP_
