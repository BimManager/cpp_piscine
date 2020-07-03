// Copyright 2020 kkozlov

#include <cmath>

#include <iostream>

#include "Fixed.h"

const int Fixed::nbFracBits_ = 8;

Fixed::Fixed(void)
    : rawValue_(0) {
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(int nb) {
  rawValue_ = (nb << nbFracBits_);
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(double fl) {
  rawValue_ = static_cast<int>(round(fl * (1 << nbFracBits_)));
  std::cout << "Float constructor called\n";
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  return os << fixed.ToFloat();
}

int Fixed::GetRawBits(void) const {
  std::cout << "GetRawBits member function called\n";
  return (rawValue_);
}

void Fixed::SetRawBits(const int raw) {
  std::cout << "SetRawBits member function called\n";
  rawValue_ = raw;
}

int Fixed::ToInt(void) const {
  return rawValue_ >> nbFracBits_;
}

double Fixed::ToFloat(void) const {
  return static_cast<double>(rawValue_) /
      static_cast<double>(1 << nbFracBits_);
}
