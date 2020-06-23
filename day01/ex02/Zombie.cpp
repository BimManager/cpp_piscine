// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name)
    : type_(type), name_(name) {
}

void Zombie::Announce(void) const {
  std::cout << '<' << this->name_ << ' '
            << '(' << this->type_ << ")> "
            << "Braiiiiiiinnnsss..."
            << std::endl;
}
