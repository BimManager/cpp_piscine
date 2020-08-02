// Copyright 2020 kkozlov

#ifndef DAY04_EX03_CURE_H_
#define DAY04_EX03_CURE_H_

#include "AMateria.h"

class Cure : public AMateria {
 public:
  Cure(void);
  Cure(Cure const &other);
  ~Cure(void);

  Cure &operator=(Cure const &rhs);

  Cure *Clone(void) const;
  void Use(ICharacter &target);
};

#endif  // DAY04_EX03_CURE_H_
