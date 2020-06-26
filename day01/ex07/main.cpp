// Copyright 2020 kkozlov

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#define BUFFSIZE 42

static void replaceStrings(std::ifstream& ifs, std::ofstream& ofs,
                           const char *s1, const char *s2) {
  std::string line;
  std::string::const_iterator itBeg;
  std::string::const_iterator itEnd;
  std::string::size_type n;
  size_t len = std::strlen(s1);

  while (!ifs.eof()) {
    getline(ifs, line);
    itBeg = line.cbegin();
    n = 0;
    while (std::string::npos != (n = line.find(s1, n))) {
      itEnd = line.cbegin() + n;
      while (itBeg < itEnd)
        ofs << *itBeg++;
      ofs << s2;
      itBeg += len;
      n += len;
    }
    while (itBeg < line.cend())
      ofs << *itBeg++;
    if (!ifs.eof())
      ofs << std::endl;
  }
}

int main(int argc, char **argv) {
  if (4 != argc) {
    std::cout << "usage: ./replace filename string1 string2\n";
    return (0);
  } else if ('\0' == *argv[2] || '\0' == *argv[3]) {
    std::cout << "no empty string is permitted.\n";
    return (0);
  }
  std::string filename = std::string(argv[1]);
  std::ifstream ifs(filename, std::ios::binary);
  if (!ifs.is_open()) {
    std::cout << "the file cannot be opened.\n";
    return (1);
  }
  std::ofstream ofs(filename + ".replace", std::ios::binary);
  replaceStrings(ifs, ofs, argv[2], argv[3]);
  ifs.close();
  ofs.close();
  return (0);
}
