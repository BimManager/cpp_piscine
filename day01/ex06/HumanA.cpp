// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon)
    : name_(name), weapon_(weapon) {
}

void HumanA::Attack(void) {
  std::cout << name_ << " attacks with his "
            << weapon_.GetType() << std::endl;
}
