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
      delete materia;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  unsigned i = SOURCE_CAPACITY;
  if (&rhs != this) {
    while (i--) {
      if (learnedMateria_[i]) {
        delete learnedMateria_[i];
        learnedMateria_[i] = 0;
      }
    }
    i = SOURCE_CAPACITY;
    while (i--) {
      if (rhs.learnedMateria_[i])
        learnedMateria_[i] = rhs.learnedMateria_[i]->Clone();
    }
  }
  return *this;
}

void MateriaSource::LearnMateria(AMateria *materia) {
  unsigned i = -1;
  while (++i < SOURCE_CAPACITY)
    if (!learnedMateria_[i]) {
      learnedMateria_[i] = materia->Clone();
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
