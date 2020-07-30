// Copyright 2020 kkozlov

#ifndef DAY04_EX01_ENEMY_H_
#define DAY04_EX01_ENEMY_H_

#include <string>
#include <iostream>

class Enemy {
 public:
  Enemy(int hp, std::string const &type);
  Enemy(Enemy const &other);
  virtual ~Enemy(void);

  Enemy& operator=(Enemy const &rhs);

  std::string const& Type(void) const;
  int HP(void) const;

  void SetType(std::string const &type);
  void SetHP(int hp);

  virtual void TakeDamage(int);

 private:
  std::string type_;
  int hp_;
};

std::ostream &operator<<(std::ostream &os, Enemy const &in);

#endif  // DAY04_EX01_ENEMY_H_
