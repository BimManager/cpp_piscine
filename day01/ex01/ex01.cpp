// Copyright 2020 kkozlov

#include <string>
#include <iostream>

void memoryLeak(void) {
  std::string *panthere;

  panthere = new std::string("String panthere");
  std::cout << *panthere << std::endl;
  delete panthere;
}

int main(void) {
  memoryLeak();
  return (0);
}
