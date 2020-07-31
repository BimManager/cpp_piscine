// Copyright 2020 kkozlov

#ifndef DAY04_EX02_ISPACEMARINE_H_
#define DAY04_EX02_ISPACEMARINE_H_

class ISpaceMarine {
 public:
  virtual ~ISpaceMarine(void) {}
  virtual ISpaceMarine *Clone(void) const = 0;
  virtual void BattleCry(void) const = 0;
  virtual void RangedAttack(void) const = 0;
  virtual void MeleeAttack(void) const = 0;
};

#endif  // DAY04_EX02_ISPACEMARINE_H_
