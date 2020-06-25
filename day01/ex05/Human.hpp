// Copyright 2020 kkozlov

#ifndef HUMAN_HPP_
#define HUMAN_HPP_

#include <string>

#include "Brain.hpp"

class Human {
 public:
  Human(void);
  std::string Identity(void) const;
  const Brain& GetBrain(void) const;
 private:
  const Brain brain_;

  Human(const Human& other);
  Human& operator=(const Human& other);
};
#endif
