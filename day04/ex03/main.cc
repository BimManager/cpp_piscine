// Copyright 2020 kkozlov

#include <iostream>

#include "Character.h"
#include "Ice.h"
#include "Cure.h"
#include "MateriaSource.h"

void myTests(void);

int main(void) {
  IMateriaSource* src = new MateriaSource();
  Ice *ice = new Ice();
  delete ice;
  Cure *cure = new Cure();
  Cure *clone = cure->Clone();
  delete clone;
  src->LearnMateria(new Ice());
  src->LearnMateria(new Cure());
  ICharacter* zaz = new Character("zaz");
  AMateria* tmp;
  tmp = src->CreateMateria("ice");
  zaz->Equip(tmp);
  tmp = src->CreateMateria("cure");
  zaz->Equip(tmp);
  ICharacter* bob = new Character("bob");
  zaz->Use(0, *bob);
  zaz->Use(1, *bob);
  delete bob;
  delete zaz;
  MateriaSource srcClone = MateriaSource();
  srcClone = *dynamic_cast<MateriaSource *>(src);
  delete src;
  tmp = srcClone.CreateMateria("ice");
  std::cout << tmp->Type() << std::endl;
  return 0;
}

void myTests(void) {
  Character john("John");
  Character alex("Alex");
  Ice ice;
  Cure cure;
  MateriaSource src;
  std::cout << john.Name() << std::endl;
  john.Equip(&ice);
  john.Use(0, alex);
  john.Use(1, alex);
  john.Use(42, alex);
  john.Equip(&cure);
  john.Use(1, alex);
  src.LearnMateria(&ice);
  src.LearnMateria(&cure);
  AMateria *materia = src.CreateMateria("ice");
  if (materia) {
    materia->Use(alex);
  }
}
