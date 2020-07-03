// Copyright 2020 kkozlov

#include <iostream>

#include "Fixed.h"

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42);
  Fixed const d(b);

  a = Fixed(1234.432);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.ToInt() << " as integer" << std::endl;
  std::cout << "b is " << b.ToInt() << " as integer" << std::endl;
  std::cout << "c is " << c.ToInt() << " as integer" << std::endl;
  std::cout << "d is " << d.ToInt() << " as integer" << std::endl;

  return (0);
}
