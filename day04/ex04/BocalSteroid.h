// Copyright 2020 kkozlov

#ifndef DAY04_EX04_BOCALSTEROID_H_
#define DAY04_EX04_BOCALSTEROID_H_

#include <string>

#include "IAsteroid.h"

class DeepCoreMiner;
class StripMiner;

class BocalSteroid : public IAsteroid {
 public:
  BocalSteroid(void);
  BocalSteroid(BocalSteroid const &other);
  ~BocalSteroid(void);

  BocalSteroid &operator=(BocalSteroid const &rhs);

  std::string const &BeMined(DeepCoreMiner *) const;
  std::string const &BeMined(StripMiner *) const;
  std::string const &Name(void) const;

 private:
  std::string name_;
};

#endif  // DAY04_EX04_BOCALSTEROID_H_
