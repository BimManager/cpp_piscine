// Copyright 2020 kkozlov

#ifndef DAY02_EX01_FIXED_H_
#define DAY02_EX01_FIXED_H_

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  explicit Fixed(int nb);
  explicit Fixed(double fl);
  ~Fixed(void);
  Fixed(const Fixed& other);

  Fixed& operator=(const Fixed& other);
  //  friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

  int GetRawBits(void) const;
  void SetRawBits(const int raw);
  double ToFloat(void) const;
  int ToInt(void) const;
 private:
  int rawValue_;
  static const int nbFracBits_;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif  // DAY02_EX01_FIXED_H_
