// Copyright 2020 kkozlov

#include <iostream>
#include <string>


#include "Human.hpp"

int main(void) {
  Human bob;

  std::cout << bob.Identity() << std::endl;
  std::cout << bob.GetBrain().Identity() << std::endl;
  return (0);
}
