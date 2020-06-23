// Copyright 2020 kkozlov

#ifndef PONY_H_
#define PONY_H_

#include <string>
#include <iostream>

class Pony {
 public:
  Pony(std::string name);
  ~Pony(void);
  void Gallop(void);
 private:
  std::string name_;

  Pony(const Pony& other);
  const Pony& operator=(const Pony& other);
};

#endif
