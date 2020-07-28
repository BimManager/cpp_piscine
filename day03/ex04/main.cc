// Copyright 2020 kkozlov

#include <iostream>

#include "FragTrap.h"
#include "ScavTrap.h"
#include "NinjaTrap.h"
#include "SuperTrap.h"

int main(void) {
  FragTrap tiger("FragTrap");
  NinjaTrap quack("NinjaTrap");
  SuperTrap sluggard("SuperTrap");

  std::cout << tiger << std::endl;
  std::cout << quack << std::endl;
  std::cout << sluggard << std::endl;
  sluggard.MeleeAttack("Quack");
  sluggard.RangedAttack("Tiget");
  return (0);
}
