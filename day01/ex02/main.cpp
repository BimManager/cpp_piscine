// Copyright 2020 kkozlov

#include <iostream>
#include <string>
#include <ctime>

#include "ZombieEvent.hpp"

static std::string generateRandomName(void) {
  int len;

  len = 4 + rand() % 6;
  std::string name(len, '0');
  while (len--) {
    name[len] = 97 + rand() % 26;
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
