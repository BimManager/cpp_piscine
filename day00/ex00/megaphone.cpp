// Copyright 2020 kkozlov

#include <iostream>

#define TO_UPPER(c) ((c) & '_')
#define DEFAULT_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE\a *"

int main(int argc, char **argv) {
  if (2 == argc) {
    while (*argv[1]) {
      if ('a' <= *argv[1] && 'z' >= *argv[1])
        std::cout << static_cast<char>(TO_UPPER(*(argv[1]++)));
      else
        std::cout << *(argv[1]++);
    }
  } else {
    std::cout << DEFAULT_MESSAGE;
  }
  std::cout << std::endl;
  return (0);
}
