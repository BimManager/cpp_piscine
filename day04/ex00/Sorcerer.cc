// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Sorcerer.h"

Sorcerer::Sorcerer(std::string const &name, std::string const &title)
    : name_(name), title_(title) {
  std::cout << name_ << ", " << title_ << " is born!\n";
}

Sorcerer::Sorcerer(Sorcerer const &other)
    : name_(other.Name()), title_(other.Title()) {
  std::cout << name_ << " has been copied\n";
}

Sorcerer::~Sorcerer(void) {
  std::cout << name_ << ", " << title_ << ", is dead. "
      "Consequences will never be the same!\n";
}

Sorcerer& Sorcerer::operator=(Sorcerer const &other) {
  if (&other == this)
    return *this;
  name_ = other.Name();
  title_ = other.Title();
  return *this;
}

std::string const& Sorcerer::Name(void) const {
  return name_;
}

std::string const& Sorcerer::Title(void) const {
  return title_;
}

void Sorcerer::Polymorph(Victim const &victim) const {
  victim.GetPolymorphed();
}

std::ostream& operator<<(std::ostream &os, Sorcerer const &in) {
  os << "I am " << in.Name() << ", " << in.Title()
     << ", and I like ponies.\n";
  return os;
}
