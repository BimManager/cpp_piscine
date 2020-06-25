// Copyright 2020 kkozlov

#include <iostream>
#include <string>
#include <ctime>

#include "ZombieEvent.hpp"
#include "ZombieHorde.hpp"

static void testZombieHorde(void) {
  ZombieHorde aHorde(7);

  aHorde.Announce();
}

int main(void) {
  testZombieHorde();
  return (0);
}
  
