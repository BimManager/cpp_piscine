// Copyright 2020 kkozlov

#ifndef CLOSINGPAREN_H_
#define CLOSINGPAREN_H_

#include <cstdlib>

#include <iostream>

#include "AToken.h"

class ClosingParen : public AToken {
 public:
  inline static AToken *Create(char value) {
    return new ClosingParen(value);
  }
  inline void Print(void) const { std::cout << "ParClose"; }
  inline char GetValue(void) const { return value_; }

 private:
  char value_;

  inline explicit ClosingParen(char value)
      : value_(value) {}

  ClosingParen(ClosingParen const &);
  ClosingParen &operator=(ClosingParen const &);
};

#endif  // CLOSINGPAREN_H_
