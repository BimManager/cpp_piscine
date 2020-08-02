// Copyright 2020 kkozlov

#include <iostream>

#include "Character.h"
#include "Ice.h"
#include "Cure.h"
#include "MateriaSource.h"

void myTests(void);

int main(void) {
  IMateriaSource* src = new MateriaSource();
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
  delete src;  
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
