// Copyright 2020 kkozlov

#include <string>

#include "AsteroBocal.h"

AsteroBocal::AsteroBocal(void)
    : name_("Astero Bocal") {}

AsteroBocal::AsteroBocal(AsteroBocal const &other) {}

AsteroBocal::~AsteroBocal(void) {}

AsteroBocal &AsteroBocal::operator=(AsteroBocal const &rhs) {
  return *this;
}

std::string const &AsteroBocal::Name(void) const {
  return name_;
}

std::string const &AsteroBocal::BeMined(DeepCoreMiner *) const {
  return "Thorite";
}

std::string const &AsteroBocal::BeMined(StripMiner *) const {
  return "Flavium";
}
