// Copyright 2020 kkozlov

#ifndef DAY04_EX02_ASSAULTTERMINATOR_H_
#define DAY04_EX02_ASSAULTTERMINATOR_H_

#include "ISpaceMarine.h"

class AssaultTerminator : public ISpaceMarine {
 public:
  AssaultTerminator(void);
  AssaultTerminator(AssaultTerminator const &other);
  ~AssaultTerminator(void);

  AssaultTerminator &operator=(AssaultTerminator const &rhs);

  AssaultTerminator *Clone(void) const;
  void BattleCry(void) const;
  void RangedAttack(void) const;
  void MeleeAttack(void) const;
};

#endif  // DAY04_EX02_ASSAULTTERMINATOR_H_
