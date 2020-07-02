// Copyright 2020 kkozlov

#include <iostream>

#include "Fixed.h"

const int Fixed::nbFracBits_ = 8;

Fixed::Fixed(void)
    : rawValue_(0) {
  std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other) {
  rawValue_ = other.rawValue_;
  std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this == &other)
    return *this;
  std::cout << "Assignment operator called\n";
  rawValue_ = other.rawValue_;
  return *this;
}

int Fixed::GetRawBits(void) const {
  std::cout << "GetRawBits member function called\n";
  return (rawValue_);
}

void Fixed::SetRawBits(const int raw) {
  std::cout << "SetRawBits member function called\n";
  rawValue_ = raw;
}

