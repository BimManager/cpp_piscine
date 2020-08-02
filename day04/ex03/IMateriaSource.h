// Copyright 2020 kkozlov

#ifndef DAY04_EX03_IMATERIASOURCE_H_
#define DAY04_EX03_IMATERIASOURCE_H_

#include <string>

#include "AMateria.h"

class AMateira;

class IMateriaSource {
 public:
  virtual ~IMateriaSource(void) {}
  virtual void LearnMateria(AMateria *) = 0;
  virtual AMateria *CreateMateria(std::string const &type) = 0;
};

#endif  // DAY04_EX03_IMATERIASOURCE_H_
