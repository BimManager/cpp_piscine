// Copyright 2020 kkozlov

#include <string>

#include "BocalSteroid.h"

BocalSteroid::BocalSteroid(void)
    : name_("Bocal Steroid") {}

BocalSteroid::BocalSteroid(BocalSteroid const &other) {}

BocalSteroid::~BocalSteroid(void) {}

BocalSteroid &BocalSteroid::operator=(BocalSteroid const &rhs) {
  return *this;
}

std::string const &BocalSteroid::BeMined(DeepCoreMiner *) const {
  return "Zazium";
}

std::string const &BocalSteroid::BeMined(StripMiner *) const {
  return "Krpite";
}

std::string const &BocalSteroid::Name(void) const {
  return name_;
}
