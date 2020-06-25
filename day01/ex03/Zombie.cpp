// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(const std::string& type, const std::string& name)
    : type_(type), name_(name) {
}

Zombie::~Zombie(void) {
  std::cout << "Zombie " << this->name_ << " has been killed.\n";
}

void Zombie::Announce(void) const {
  std::cout << '<' << this->name_ << ' '
            << '(' << this->type_ << ")> "
            << "Braiiiiiiinnnsss..."
            << std::endl;
}
