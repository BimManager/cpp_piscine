// Copyright 2020 kkozlov

#ifndef DAY04_EX00_SORCERER_H_
#define DAY04_EX00_SORCERER_H_

#include <string>
#include <iostream>

#include "Victim.h"

class Sorcerer {
 public:
  Sorcerer(std::string const &name, std::string const &title);
  Sorcerer(Sorcerer const &other);
  ~Sorcerer(void);
  Sorcerer& operator=(Sorcerer const &rhs);

  std::string const& Name(void) const;
  std::string const& Title(void) const;

  void Polymorph(Victim const &victim) const;

 private:
  std::string name_;
  std::string title_;
};

std::ostream& operator<<(std::ostream &os, Sorcerer const &in);

#endif  // DAY04_EX00_SORCERER_H_
