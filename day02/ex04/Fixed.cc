// Copyright 2020 kkozlov

#include <cmath>
#include <climits>

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

Fixed& Fixed::operator++(void) {
  ++rawValue_;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return tmp;
}


Fixed& Fixed::operator--(void) {
  unsigned frac = 0xff & rawValue_;
  rawValue_ >>= nbFracBits_;
  --rawValue_;
  rawValue_ <<= nbFracBits_;
  rawValue_ ^= frac;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return tmp;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  return os << fixed.ToFloat();
}

bool operator<(const Fixed& lhs, const Fixed& rhs) {
  std::cout << "< operator called\n";
  return lhs.GetRawBits() < rhs.GetRawBits();
}

bool operator>(const Fixed& lhs, const Fixed& rhs) {
  return rhs < lhs;
}

bool operator<=(const Fixed& lhs, const Fixed& rhs) {
  return !(lhs > rhs);
}

bool operator>=(const Fixed& lhs, const Fixed& rhs) {
  return !(lhs < rhs);
}

bool operator==(const Fixed& lhs, const Fixed& rhs) {
  return (lhs <= rhs) && (lhs >= rhs);
}

bool operator!=(const Fixed& lhs, const Fixed& rhs) {
  return !(lhs == rhs);
}

Fixed operator+(const Fixed& lhs, const Fixed& rhs) {
  Fixed sum;
  sum.SetRawBits(lhs.GetRawBits() + rhs.GetRawBits());
  return sum;
}

Fixed operator-(const Fixed& lhs, const Fixed& rhs) {
  Fixed diff;
  diff.SetRawBits(lhs.GetRawBits() - rhs.GetRawBits());
  return diff;
}

Fixed operator*(const Fixed& lhs, const Fixed& rhs) {
  Fixed product;
  product.SetRawBits((lhs.GetRawBits() * rhs.GetRawBits()) >> 8);
  return product;
}

Fixed operator/(const Fixed& lhs, const Fixed& rhs) {
  Fixed quotient;
  quotient.SetRawBits((lhs.GetRawBits() * (1 << 8)) / rhs.GetRawBits());
  return quotient;
}
