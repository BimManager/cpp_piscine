// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Sorcerer.h"
#include "Victim.h"
#include "Peon.h"

int main(void) {
  Sorcerer robert("Robert", "the Magnificent");
  Victim jim("Jimmy");
  Peon joe("Joe");

  std::cout << robert << jim << joe;

  robert.Polymorph(jim);
  robert.Polymorph(joe);

  return 0;
}
