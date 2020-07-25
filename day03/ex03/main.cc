// Copyright 2020 kkozlov

#include <iostream>

#include "FragTrap.h"
#include "ScavTrap.h"
#include "NinjaTrap.h"

int main(void) {
  FragTrap bull("Bull");
  FragTrap donkey("Donkey");
  ScavTrap monkey("Monkey");
  ClapTrap base = monkey;
  NinjaTrap quack("Quack");

  bull.RangedAttack(donkey.Name());
  donkey.MeleeAttack(bull.Name());
  bull.TakeDamage(39);
  bull.BeRepaired(42);
  bull.VaultHunterDotExe("donkey");
  bull.VaultHunterDotExe("donkey");
  bull.VaultHunterDotExe("donkey");
  bull.VaultHunterDotExe("donkey");
  monkey.ChallengeNewcomer("bull");
  donkey = bull;
  std::cout << bull << std::endl;
  std::cout << donkey << std::endl;
  base = donkey;
  std::cout << base << std::endl;
  quack.NinjaShoebox(donkey);
  return (0);
}
