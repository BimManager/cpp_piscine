// Copyright 2020 kkozlov

#include <iostream>
#include <string>

#include "Array.h"

int main(void) {
  Array<int> arrayInt1(5);
  Array<int> arrayInt2(arrayInt1);
  Array<std::string> arrayStr1(2);
  Array<std::string> arrayStr2 = arrayStr1;

  arrayInt1[0] = 42;
  arrayInt1[2] = 42;
  arrayInt1.PrintElements();
  arrayInt2.PrintElements();
  arrayStr1.PrintElements();
  arrayStr1[0] = std::string("Foo");
  arrayStr1[1] = std::string("Baz");
  arrayStr1.PrintElements();
  arrayStr2.PrintElements();
  arrayStr2 = arrayStr1;
  arrayStr2.PrintElements();
  std::cout << arrayInt1.Size() << '\n';
  return 0;
}
