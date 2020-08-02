// Copyright 2020 kkozlov

#include <string>
#include <iostream>
#include <iomanip>

#include "MateriaSource.h"


MateriaSource::MateriaSource(void) {
  unsigned i = SOURCE_CAPACITY;
  while (i--)
    learnedMateria_[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
  unsigned i = SOURCE_CAPACITY;
  AMateria *materia;
  while (i--)
    if ((materia =other.learnedMateria_[i])) {
      learnedMateria_[i] = materia->Clone();
    }
}

MateriaSource::~MateriaSource(void) {
  unsigned i = SOURCE_CAPACITY;
  AMateria *materia;
  while (i--)
    if ((materia = learnedMateria_[i])) {
      std::cout << materia->Type() << std::endl;
      std::cout << std::setbase(16) << materia << std::endl;
      materia->~AMateria();
      operator delete(materia);
      //      delete materia;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (&rhs != this) {
  }
  return *this;
}

void MateriaSource::LearnMateria(AMateria *materia) {
  unsigned i = -1;
  while (++i < SOURCE_CAPACITY) 
    if (!learnedMateria_[i]) {
      learnedMateria_[i] = materia->Clone();
      std::cout << std::setbase(16) << learnedMateria_[i] << std::endl;
      break;
    }
}

AMateria *MateriaSource::CreateMateria(std::string const &type) {
  unsigned i = -1;
  AMateria *ret = NULL;
  while (++i < SOURCE_CAPACITY) {
    if ((ret = learnedMateria_[i]) && 0 == type.compare(ret->Type())) {
      return ret->Clone();
    }
  }
    return ret;
}
  
  
