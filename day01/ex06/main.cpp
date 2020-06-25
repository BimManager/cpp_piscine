// Copyright 2020 kkozlov

#include <iostream>
#include <string>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.Attack();
    club.SetType("some other type of club");
    bob.Attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.SetWeapon(club);
    jim.Attack();
    club.SetType("some other type of club");
    jim.Attack();
  }
  {
    Weapon club = Weapon("simple club");
    HumanB john("John");
    john.Attack();
    john.SetWeapon(club);
    john.Attack();
  }
  return (0);
}
