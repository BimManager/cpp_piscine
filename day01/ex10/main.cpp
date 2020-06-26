// Copyright 2020 kkozlov

#include <iostream>
#include <fstream>
#include <string>

static void readFromFile(const char *filename) {
  std::ifstream ifs(filename, std::ios_base::binary);
  if (!ifs.is_open()) {
    std::cerr << "cato9tales: " << filename
              << ": No such file or directory" << std::endl;
    return;
  }
  std::string line;
  while (getline(ifs, line)) {
    std::cout << line;
    if (!ifs.eof())
      std::cout << std::endl;
  }
  ifs.close();
}

static void readFromStdin(void) {
  std::string line;
  while (getline(std::cin, line)) {
    std::cout << line << std::endl;
  }
}

int main(int argc, char **argv) {
  int i;
  if (1 == argc) {
    readFromStdin();
  } else {
    i = 0;
    while (++i < argc)
      readFromFile(argv[i]);
  }
  return (0);
}
