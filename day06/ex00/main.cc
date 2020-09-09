// Copyright 2020 kkozlov

#include <cstdlib>

#include <iostream>

#include "ScalarConverter.h"

int main(int argc, char **argv) {
  if (2 != argc) {
    std::cout << "Usage: " << argv[0] << " value"  << std::endl;
    return 0;
  }
  ScalarConverter converter(argv[1]);
  converter.Print();
  return 0;
}
