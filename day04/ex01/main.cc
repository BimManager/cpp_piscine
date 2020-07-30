// Copyright 2020 kkozlov

#include "PlasmaRifle.h"
#include "PowerFist.h"
#include "SuperMutant.h"
#include "RadScorpion.h"
#include "Character.h"

int main(void) {
  Character* zaz = new Character("zaz");

  std::cout << *zaz;

  Enemy* b = new RadScorpion();

  AWeapon* pr = new PlasmaRifle();
  AWeapon* pf = new PowerFist();

  zaz->Equip(pr);
  std::cout << *zaz;
  zaz->Equip(pf);

  zaz->Attack(b);
  std::cout << *zaz;
  zaz->Equip(pr);
  std::cout << *zaz;
  zaz->Attack(b);
  std::cout << *zaz;
  zaz->Attack(b);
  std::cout << *zaz;

  return 0;
}
