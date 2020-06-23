// Copyright 2020 kkozlov

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>

class Zombie {
 public:
  Zombie(std::string type, std::string name);
  void Announce(void) const;
 private:
  std::string type_;
  std::string name_;

  Zombie(const Zombie& other);
  const Zombie& operator=(const Zombie& other);
};

#endif
