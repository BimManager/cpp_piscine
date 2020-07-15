// Copyright 2020 kkozlov

#include <climits>

#include <iostream>
#include <sstream>
#include <string>

#include "Fixed.h"

static void bitsput(const void *pv, size_t width) {
  char	i;

  while (width--) {
    i = CHAR_BIT;
    while (i--)
      std::cout << ((*((char *)pv + width) & (1U << i)) ? '1' : '0');
    if (width)
      std::cout << ' ';
  }
  std::cout << std::endl;
}



int main(int argc, char **argv) {
  if (2 != argc) {
    std::cout << "usage: ./eval_expr \"( 42.42 + 3.25 ) / 12\"\n";
    return 1;
  }
  bitsput(&argc, sizeof(int));
  std::istringstream iss(argv[1]);
  std::string token;
  while (std::getline(iss, token, ' ')) {
    std::cout << token << std::endl;
  }
  (void)argv;
  return 0;
}
