// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Victim.h"

Victim::Victim(std::string const &name)
    : name_(name) {
  std::cout << "Some random victim called "
            << name_ << " just popped!\n";
}

Victim::Victim(Victim const &other)
    : name_(other.Name()) {
  std::cout << "Victim called " << other.Name()
            << " has been copied\n";
}

Victim::~Victim(void) {
  std::cout << "Victim " << name_
            << " died for no apparent reason.\n";
}

Victim& Victim::operator=(Victim const &rhs) {
  name_ = rhs.Name();
}

std::string const& Victim::Name(void) const {
  return name_;
}

void Victim::GetPolymorphed(void) const {
  std::cout << name_ << " has been turned into "
      "a cute little sheep!\n";
}

std::ostream& operator<<(std::ostream &os, Victim const &in) {
  os << "I am " << in.Name() << " and I like otters.\n";
  return os;
}
