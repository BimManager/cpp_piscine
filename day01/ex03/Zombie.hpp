// Copyright 2020 kkozlov

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>

class Zombie {
 public:
  Zombie(const std::string& type, const std::string& name);
  ~Zombie(void);
  void Announce(void) const;
  
 private:
  std::string type_;
  std::string name_;

  Zombie(const Zombie& other);
  Zombie& operator=(const Zombie& other);
};

#endif
