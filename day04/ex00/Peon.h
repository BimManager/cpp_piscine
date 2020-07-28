// Copyright 2020 kkozlov

#ifndef DAY04_EX00_PEON_H_
#define DAY04_EX00_PEON_H_

#include <string>
#include <iostream>

#include "Victim.h"

class Peon : public Victim {
 public:
  explicit Peon(std::string const &name);
  Peon(Peon const &other);
  ~Peon(void);

  Peon& operator=(Peon const &rhs);

  virtual void GetPolymorphed(void) const;
};

#endif  // DAY04_EX00_PEON_H_
