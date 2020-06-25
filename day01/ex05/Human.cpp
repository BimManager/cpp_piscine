// Copyright 2020 kkozlov

#include <string>

#include "Human.hpp"

Human::Human(void)
    : brain_() {
}

std::string Human::Identity(void) const {
  return this->brain_.Identity();
}

const Brain& Human::GetBrain(void) const {
  return this->brain_;
}
