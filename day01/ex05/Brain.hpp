// Copyright 2020 kkozlov

#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <string>

class Brain {
 public:
  Brain(void);
  std::string Identity(void) const;
 private:
  Brain(const Brain& other);
  Brain& operator=(const Brain& other);
};

#endif  // BRAIN_HPP_
