// Copyright 2020 kkozlov

#ifndef DAY04_EX01_AWEAPON_H_
#define DAY04_EX01_AWEAPON_H_

#include <string>
#include <iostream>

class AWeapon {
 public:
  AWeapon(std::string const &name, int apcost, int damage);
  AWeapon(AWeapon const &other);
  ~AWeapon(void);

  AWeapon& operator=(AWeapon const &rhs);

  std::string const& Name(void) const;
  int APCost(void) const;
  int Damage(void) const;

  void SetName(std::string const &name);
  void SetAPCost(int apcost);
  void SetDamage(int damage);

  virtual void Attack(void) const = 0;

 private:
  std::string name_;
  int apcost_;
  int damage_;
};

std::ostream& operator<<(std::ostream &os, AWeapon const &in);

#endif  // DAY04_EX01_AWEAPON_H_
