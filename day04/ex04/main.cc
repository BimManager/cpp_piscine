// Copyright 2020 kkozlov

#include "DeepCoreMiner.h"
#include "StripMiner.h"
#include "AsteroBocal.h"
#include "BocalSteroid.h"
#include "MiningBarge.h"

int main(void) {
  IMiningLaser *deep = new DeepCoreMiner();
  IMiningLaser *strip = new StripMiner();
  AsteroBocal *astero = new AsteroBocal();
  BocalSteroid *steroid = new BocalSteroid();
  MiningBarge *barge = new MiningBarge();

  barge->Mine(astero);
  barge->Equip(deep);
  barge->Mine(astero);
  barge->Mine(steroid);
  barge->Equip(strip);
  barge->Mine(astero);
  barge->Mine(steroid);
  delete barge;
  delete steroid;
  delete astero;
  delete deep;
  delete strip;
  return (0);
}
