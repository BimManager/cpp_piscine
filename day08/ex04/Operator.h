// Copyright 2020 kkozlov

#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <cstdlib>

#include <iostream>
#include <string>

#include "AToken.h"

class Operator : public AToken {
 public:
  static AToken *Create(char value) {
    return new Operator(value);
  }
  inline void Print(void) const { std::cout << formatted_; }
  inline char GetValue(void) const { return value_; }
  inline int GetPrecedence(void) const { return precedence_; }

 private:
  char value_;
  std::string formatted_;
  int precedence_;

  inline explicit Operator(char value)
      : value_(value) {
    std::stringstream buf;
    std::streambuf *old = std::cout.rdbuf(buf.rdbuf());
    std::cout << "Op(" << value_ << ')';
    formatted_ = buf.str();
    std::cout.rdbuf(old);
    if ('+' == value || '-' == value)
      precedence_ = 100;
    else if ('*' == value || '/' == value)
      precedence_ = 200;
    else
      precedence_ = 0;
  }

  Operator(Operator const &);
  Operator &operator=(Operator const &);
};

#endif  // OPERATOR_H_
