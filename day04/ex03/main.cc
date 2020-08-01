// Copyright 2020 kkozlov

#include <iostream>

#include "Character.h"
#include "Ice.h"

int main(void) {
  Character john("John");
  Character alex("Alex");
  Ice ice;

  std::cout << john.Name() << std::endl;
  john.Equip(&ice);
  john.Use(0, alex);
  john.Use(1, alex);
  john.Use(42, alex);
  return 0;
}
