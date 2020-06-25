// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
    : name_(name), weapon_(0) {
}

void HumanB::SetWeapon(const Weapon& weapon) {
  weapon_ = &weapon;
}

void HumanB::Attack(void) {
  if (!weapon_) {
    std::cout << name_ << " has no weapon.\n";
    return;
  }
  std::cout << name_ << " attacks with his "
            << weapon_->GetType() << std::endl;
}
