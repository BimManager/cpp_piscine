// Copyright 2020 kkozlov

#ifndef ATOKEN_H_
#define ATOKEN_H_

#include <string>

class AToken {
 public:
  virtual ~AToken(void) = 0;

  virtual void Print(void) const = 0;

 protected:
  AToken(void) {}

 private:
  AToken(AToken const &);
  AToken &operator=(AToken const &);
};

inline AToken::~AToken(void) {}

#endif  // ATOKEN_H_
