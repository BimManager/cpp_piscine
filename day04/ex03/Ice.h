// Copyright 2020 kkozlov

#ifndef DAY04_EX03_ICE_H_
#define DAY04_EX03_ICE_H_

#include "AMateria.h"

class Ice : public AMateria {
 public:
  Ice(void);
  Ice(Ice const &other);
  ~Ice(void);

  Ice &operator=(Ice const &rhs);

  Ice *Clone(void) const;
  void Use(ICharacter &target);
};

#endif  // DAY04_EX03_ICE_H_
