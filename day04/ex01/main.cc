// Copyright 2020 kkozlov

#include "PlasmaRifle.h"
#include "PowerFist.h"

int main(void) {
  PlasmaRifle rifle;
  PowerFist fist;

  std::cout << rifle;
  rifle.Attack();
  std::cout << fist;
  fist.Attack();
  return 0;
}
