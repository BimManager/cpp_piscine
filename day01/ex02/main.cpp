// Copyright 2020 kkozlov

#include "ZombieEvent.hpp"

#include <random>
#include <iostream>
#include <string>

static std::string generateRandomName(void) {
  std::random_device random;
  int	len;

  std::default_random_engine engine(random());
  std::uniform_int_distribution<int> uniform_dist(65, 128);
  len = uniform_dist(engine);
  std::string name(len, '0');
  while (len--) {
    name[len] = static_cast<char>(uniform_dist(engine));
  }
  return name;
}

static void randomChump(void) {
  ZombieEvent apocalypse;
  Zombie *aZombie;

  apocalypse.SetZombieType("Wierdos");
  aZombie = apocalypse.NewZombie(generateRandomName());
  aZombie->Announce();
  delete aZombie;
}

int main(void) {
  randomChump();
  return (0);
}
  
