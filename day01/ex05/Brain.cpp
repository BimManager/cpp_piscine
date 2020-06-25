// Copyright 2020 kkozlov

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "Brain.hpp"

Brain::Brain(void) {
}

std::string Brain::Identity(void) const {
  std::stringstream buffer;
  std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
  std::cout << std::setbase(16) << this;
  std::string address = buffer.str();
  std::cout.rdbuf(old);
  return address;
}

