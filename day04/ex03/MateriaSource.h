// Copyright 2020 kkozlov

#ifndef DAY04_EX03_MATERIASOURCE_H_
#define DAY04_EX03_MATERIASOURCE_H_

#include "IMateriaSource.h"

#define SOURCE_CAPACITY 4

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &other);
  ~MateriaSource(void);

  MateriaSource &operator=(MateriaSource const &rhs);

  void LearnMateria(AMateria *m);
  AMateria *CreateMateria(std::string const &type);

 private:
  AMateria *learnedMateria_[SOURCE_CAPACITY];
};

#endif  // DAY04_EX03_MATERIASOURCE_H_
