// Copyright 2020 kkozlov

#include <string>

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

void ZombieEvent::SetZombieType(const std::string& type) {
  this->type_ = type;
}

Zombie *ZombieEvent::NewZombie(const std::string& name) const {
  Zombie *zombie;

  zombie = new Zombie(this->type_, name);
  return (zombie);
}


