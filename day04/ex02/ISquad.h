// Copyright 2020 kkozlov

#ifndef DAY04_EX02_ISQUAD_H_
#define DAY04_EX02_ISQUAD_H_

#include "ISpaceMarine.h"

class ISquad {
 public:
  virtual ~ISquad(void) {}
  virtual int Count(void) const = 0;
  virtual ISpaceMarine *Unit(int) const = 0;
  virtual int Push(ISpaceMarine *) = 0;
};

#endif  // DAY04_EX02_ISQUAD_H_
