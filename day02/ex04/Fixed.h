// Copyright 2020 kkozlov

#ifndef DAY02_EX02_FIXED_H_
#define DAY02_EX02_FIXED_H_

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  explicit Fixed(int nb);
  explicit Fixed(double fl);
  ~Fixed(void);
  Fixed(const Fixed& other);

  Fixed& operator=(const Fixed& other);
  Fixed& operator++(void);
  Fixed operator++(int);
  Fixed& operator--(void);
  Fixed operator--(int);
  
  int GetRawBits(void) const;
  void SetRawBits(const int raw);
  double ToFloat(void) const;
  int ToInt(void) const;
 private:
  int rawValue_;
  static const int nbFracBits_;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

bool operator<(const Fixed& lhs, const Fixed& rhs);
bool operator>(const Fixed& lhs, const Fixed& rhs);
bool operator<=(const Fixed& lhs, const Fixed& rhs);
bool operator>=(const Fixed& lhs, const Fixed& rhs);
bool operator==(const Fixed& lhs, const Fixed& rhs);
bool operator!=(const Fixed& lhs, const Fixed& rhs);

Fixed operator+(const Fixed& lhs, const Fixed& rhs);
Fixed operator-(const Fixed& lhs, const Fixed& rhs);
Fixed operator*(const Fixed& lhs, const Fixed& rhs);
Fixed operator/(const Fixed& lhs, const Fixed& rhs);

inline Fixed& FixedMin(Fixed& a, Fixed& b) {
  return (a.GetRawBits() <= b.GetRawBits() ? a : b);
}

inline const Fixed& FixedMin(const Fixed& a, const Fixed& b) {
  return (a.GetRawBits() <= b.GetRawBits() ? a : b);
}

inline Fixed& FixedMax(Fixed& a, Fixed& b) {
  return (a.GetRawBits() >= b.GetRawBits() ? a : b);
}

inline const Fixed& FixedMax(const Fixed& a, const Fixed& b) {
  return (a.GetRawBits() >= b.GetRawBits() ? a : b);
}


#endif  // DAY02_EX02_FIXED_H_
