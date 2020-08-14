// Copyright 2020 kkozlov

#ifndef DAY04_EX04_ASTEROBOCAL_H_
#define DAY04_EX04_ASTEROBOCAL_H_

#include <string>

#include "IAsteroid.h"
#include "DeepCoreMiner.h"
#include "StripMiner.h"

class AsteroBocal : public IAsteroid {
 public:
  AsteroBocal(void);
  AsteroBocal(AsteroBocal const &other);
  ~AsteroBocal(void);

  AsteroBocal &operator=(AsteroBocal const &rhs);

  std::string const &BeMined(DeepCoreMiner *) const;
  std::string const &BeMined(StripMiner *) const;
  std::string const &Name(void) const;

 private:
  std::string name_;
};

#endif  // DAY04_EX04_ASTEROBOCAL_H_
