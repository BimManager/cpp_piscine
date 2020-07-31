// Copyright 2020 kkozlov

#ifndef DAY04_EX02_SQUAD_H_
#define DAY04_EX02_SQUAD_H_

#include "ISquad.h"
#include "ISpaceMarine.h"

#define INIT_CAPACITY 128

class Squad : public ISquad {
 public:
  Squad(void);
  Squad(Squad const &other);
  ~Squad(void);

  Squad &operator=(Squad const &rhs);

  int Count(void) const;
  ISpaceMarine *Unit(int) const;
  int Push(ISpaceMarine *);

 private:
  int count_;
  int capacity_;
  ISpaceMarine **marines_;
};

#endif  // DAY04_EX02_SQUAD_H_

