// Copyright 2020 kkozlov

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <cstdlib>
#include <ctime>

#include "Data.h"

#define N_BYTES 20
#define STR_LEN 8

class Serializer {
 public:
  Serializer(void);
  ~Serializer(void);

  void *Serialize(void);
  Data *Deserialize(void *raw);

 private:
  Serializer(Serializer const &other);
  Serializer &operator=(Serializer const &rhs);

  char RandomCharGenerator(void);
};

#endif  // SERIALIZER_H_
