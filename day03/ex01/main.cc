// Copyright 2020 kkozlov

#include <iostream>

#include "ScavTrap.h"

int main(void) {
  ScavTrap bull("Bull");
  ScavTrap donkey("Donkey");

  bull.RangedAttack(donkey.Name());
  donkey.MeleeAttack(bull.Name());
  bull.TakeDamage(39);
  bull.BeRepaired(42);
  bull.ChallengeNewcomer("donkey");
  bull.ChallengeNewcomer("donkey");
  bull.ChallengeNewcomer("donkey");
  bull.ChallengeNewcomer("donkey");
  std::cout << bull << std::endl;
  return (0);
}
