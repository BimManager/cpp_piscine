// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Serializer.h"

Serializer::Serializer(void) {}

Serializer::~Serializer(void) {}

void *Serializer::Serialize(void) {
  void *data;
  char *ch_p;
  int i;

  srand(clock());
  data = malloc(N_BYTES);
  ch_p = reinterpret_cast<char *>(data);
  *reinterpret_cast<int *>(ch_p + STR_LEN) = rand() + INT_MAX - RAND_MAX;
  i = -1;
  while (++i < STR_LEN) {
    *(ch_p + i) = RandomCharGenerator();
    std::cout << *(ch_p + i);
  }
  std::cout << std::endl;
  std::cout << *reinterpret_cast<int *>(ch_p + STR_LEN) << std::endl;
  i = STR_LEN + sizeof(int) - 1;
  while (++i < N_BYTES) {
    *(ch_p + i) = RandomCharGenerator();
    std::cout << *(ch_p + i);
  }
  std::cout << std::endl;
  return data;
}

char Serializer::RandomCharGenerator(void) {
  static char alphnum[] = {
    '1', '2', '3', '4', '5', '6', '7',
    '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'G', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U',
    'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'g', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z',
  };
  srand(clock());
  return alphnum[static_cast<int>((rand() % sizeof(alphnum)))];
}

Data *Serializer::Deserialize(void *raw) {
  Data *data;
  char *ch_p;

  data = new Data();
  ch_p = reinterpret_cast<char *>(raw);
  data->s1 = std::string(ch_p, STR_LEN);
  data->n = *reinterpret_cast<int *>(ch_p + STR_LEN);
  data->s2 = std::string(ch_p + sizeof(int) + STR_LEN, STR_LEN);
  return data;
}
