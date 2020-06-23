// Copyright 2020 kkozlov

#include "Pony.hpp"

Pony::Pony(std::string name)
    : name_(name) {
  std::cout << "A pony named " << this->name_
            << " has been initialized." << std::endl;
}

Pony::~Pony(void) {
  std::cout << "A pony called " << this->name_
            << " has been knackered." << std::endl;
}

void Pony::Gallop(void) {
  std::cout << "Pony " << this->name_
            << " is galloping." << std::endl;
}

