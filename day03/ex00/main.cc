// Copyright 2020 kkozlov

#include <iostream>

#include "FragTrap.h"

int main(void) {
  FragTrap bull("Bull");
  FragTrap donkey("Donkey");

  bull.RangedAttack(donkey.Name());
  donkey.MeleeAttack(bull.Name());
  bull.TakeDamage(39);
  bull.BeRepaired(42);
  bull.VaultHunterDotExe("donkey");
  bull.VaultHunterDotExe("donkey");
  bull.VaultHunterDotExe("donkey");
  bull.VaultHunterDotExe("donkey");
  std::cout << bull << std::endl;
  return (0);
}
