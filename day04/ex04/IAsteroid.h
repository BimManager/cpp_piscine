// Copyright 2020 kkozlov

#ifndef DAY04_EX04_IASTEROID_H_
#define DAY04_EX04_IASTEROID_H_

#include <string>

class DeepCoreMiner;
class StripMiner;

class IAsteroid {
 public:
  ~IAsteroid(void) {}
  virtual std::string const &BeMined(DeepCoreMiner *) const = 0;
  virtual std::string const &BeMined(StripMiner *) const = 0;
  virtual std::string const &Name(void) const = 0;
};

#endif  // DAY04_EX04_IASTEROID_H_
