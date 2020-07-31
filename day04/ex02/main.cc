// Copyright 2020 kkozlov

#include <iostream>

#include "TacticalMarine.h"
#include "AssaultTerminator.h"
#include "Squad.h"

int main(void) {
  ISpaceMarine *bob = new TacticalMarine();
  ISpaceMarine *jim = new AssaultTerminator();

  bob->BattleCry();
  ISpaceMarine *keith = bob->Clone();
  delete bob;
  keith->RangedAttack();
  keith->MeleeAttack();

  ISquad *vlc = new Squad();
  std::cout << "Count: " << vlc->Push(bob) << std::endl;
  std::cout << "Count: " << vlc->Push(keith) << std::endl;
  std::cout << "Count: " << vlc->Push(keith) << std::endl;
  //  delete bob;
  //  delete jim;
  for (int i = 0; i < vlc->Count(); ++i) {
    ISpaceMarine *cur = vlc->Unit(i);
    cur->BattleCry();
    cur->RangedAttack();
    cur->MeleeAttack();
  }
  delete vlc;
  return 0;
}
