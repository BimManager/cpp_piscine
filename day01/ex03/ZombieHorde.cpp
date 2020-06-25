// Copyright 2020 kkozlov

#include <ctime>

#include <string>

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int n)
    : nbZombies_(n) {
  this->rawMemory_ = operator new[](n * sizeof(Zombie));
  this->zombies_ = static_cast<Zombie*>(this->rawMemory_);
  while (n--)
    new (&this->zombies_[n]) Zombie("42 Students", GenerateRandomName());
}

ZombieHorde::~ZombieHorde(void) {
  while (nbZombies_--)
    this->zombies_[nbZombies_].~Zombie();
  operator delete[](this->rawMemory_);
}

void ZombieHorde::Announce(void) const {
  int i;

  i = -1;
  while (++i < nbZombies_)
    zombies_[i].Announce();
}

std::string ZombieHorde::GenerateRandomName(void) {
  int len;

  len = 4 + rand() % 6;
  std::string name(len, '0');
  while (len--) {
    name[len] = 97 + rand() % 26;
  }
  return name;
}
