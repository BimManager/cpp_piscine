// Copyright 2020 kkozlov

#ifndef OPENINGPAREN_H_
#define OPENINGPAREN_H_

#include <cstdlib>

#include <iostream>

#include "AToken.h"

class OpeningParen : public AToken {
 public:
  inline static AToken *Create(char value) {
    return new OpeningParen(value);
  }
  inline void Print(void) const { std::cout << "ParOpen"; }
  inline char GetValue(void) const { return value_; }

 private:
  char value_;

  inline explicit OpeningParen(int  value)
      : value_(value) {}

  OpeningParen(OpeningParen const &);
  OpeningParen &operator=(OpeningParen const &);
};

#endif  // OPENINGPAREN_H_
