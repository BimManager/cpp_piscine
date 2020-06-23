// Copyright 2020 kkozlov

#include <string>

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

void ZombieEvent::SetZombieType(std::string type) {
  this->type_ = type;
}

Zombie *ZombieEvent::NewZombie(std::string name) const {
  Zombie *zombie;

  zombie = new Zombie(this->type_, name);
  return (zombie);
}


