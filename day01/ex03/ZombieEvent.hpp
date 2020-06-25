// Copyright 2020 kkozlov

#ifndef ZOMBIE_EVENT_H_
#define ZOMBIE_EVENT_H_

#include <string>

#include "Zombie.hpp"

class ZombieEvent {
 public:
  void SetZombieType(const std::string& type);
  Zombie *NewZombie(const std::string& name) const;
 private:
  std::string type_;
};

#endif
