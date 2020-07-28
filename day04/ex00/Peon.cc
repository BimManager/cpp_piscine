// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Peon.h"

Peon::Peon(std::string const &name)
    : Victim(name) {
  std::cout << "Zog, zog.\n";
}

Peon::Peon(Peon const &other)
    : Victim(other) {
}

Peon::~Peon(void) {
  std::cout << "Bleuark...\n";
}

void Peon::GetPolymorphed(void) const {
  std::cout << Name() << " has been turned into "
      "a pink pony!\n";
}

