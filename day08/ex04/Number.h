// Copyright 2020 kkozlov

#ifndef NUMBER_H_
#define NUMBER_H_

#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>

#include "AToken.h"

class Number : public AToken {
 public:
  inline explicit Number(int value)
      : value_(value) {
    std::stringstream buf;
    std::streambuf *old = std::cout.rdbuf(buf.rdbuf());
    std::cout << "Num(" << value_ << ')';
    formatted_ = buf.str();
    std::cout.rdbuf(old);
  }
  inline void Print(void) const {
    std::cout << formatted_;
  }
  inline int GetValue(void) const { return value_; }
  inline void SetValue(int value) { value_ = value; }

 private:
  int value_;
  std::string formatted_;

  Number(Number const &);
  Number &operator=(Number const &);
};

#endif  // NUMBER_H_
