// Copyright 2020 kkozlov

#include <string>

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
    : type_(type) {
}

const std::string& Weapon::GetType(void) const {
  return type_;
}

void Weapon::SetType(const std::string& newType) {
  type_ = newType;
}
