// Copyright 2020 kkozlov

#ifndef DAY02_EX00_FIXED_H_
#define DAY02_EX00_FIXED_H_

class Fixed {
 public:
  Fixed(void);
  ~Fixed(void);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);

  int GetRawBits(void) const;
  void SetRawBits(const int raw);
 private:
  int rawValue_;
  static const int nbFracBits_;
};

#endif  // DAY02_EX00_FIXED_H_
