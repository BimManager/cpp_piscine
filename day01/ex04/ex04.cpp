// Copyright 2020 kkozlov

#include <string>
#include <iostream>

int main(void) {
  const std::string kMessage = "HI, THIS IS BRAIN";
  const std::string *pMessage = &kMessage;
  const std::string& refMessage = kMessage;

  std::cout << *pMessage << " displayed via a pointer.\n";
  std::cout << refMessage << " brought to you through a reference.\n";
  return (0);
}
