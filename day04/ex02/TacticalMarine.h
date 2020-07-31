// Copyright 2020 kkozlov

#ifndef DAY04_EX02_TACTICALMARINE_H_
#define DAY04_EX02_TACTICALMARINE_H_

#include "ISpaceMarine.h"

class TacticalMarine : public ISpaceMarine {
 public:
  TacticalMarine(void);
  TacticalMarine(TacticalMarine const &other);
  ~TacticalMarine(void);

  TacticalMarine& operator=(TacticalMarine const &rhs);

  TacticalMarine *Clone(void) const;
  void BattleCry(void) const;
  void RangedAttack(void) const;
  void MeleeAttack(void) const;
};

#endif  // DAY04_EX02_TACTICALMARINE_H_
