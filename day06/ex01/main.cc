// Copyright 2020 kkozlov

#include <iostream>

#include "Serializer.h"

int main(void) {
  Serializer serializer;
  void *raw;
  Data *data;

  std::cout << "serialization:\n";
  raw = serializer.Serialize();
  std::cout << "deserialization:\n";
  data = serializer.Deserialize(raw);
  std::cout << data->s1 << std::endl;
  std::cout << data->n << std::endl;
  std::cout << data->s2 << std::endl;
  free(raw);
  delete data;
  return 0;
}
