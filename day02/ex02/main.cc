// Copyright 2020 kkozlov

#include <climits>

#include <iostream>

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

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42);
  Fixed const d(b);
  Fixed e(10);

  a = Fixed(1234.432);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.ToInt() << " as integer" << std::endl;
  std::cout << "b is " << b.ToInt() << " as integer" << std::endl;
  std::cout << "c is " << c.ToInt() << " as integer" << std::endl;
  std::cout << "d is " << d.ToInt() << " as integer" << std::endl;

  bool cmp(a < b);
  std::cout << a << " < " << b << ": " << cmp << std::endl;
  cmp = a > b;
  std::cout << a << " >  " << b << ": " << cmp << std::endl;
  cmp = a <= b;
  std::cout << a << " <= " << b << ": " << cmp << std::endl;
  cmp = a >= b;
  std::cout << a << " >= " << b << ": " << cmp << std::endl;
  cmp = a == b;
  std::cout << a << " == " << b << ": " << cmp << std::endl;
  cmp = a != b;
  std::cout << a << " != " << b << ": " << cmp << std::endl;
  Fixed ans = a + b;
  std::cout << a << " + " << b << " = " << ans << std::endl;
  ans = a - b;
  std::cout << a << " - " << b << " = " << ans << std::endl;
  ans = a * b;
  std::cout << a << " * " << b << " = " << ans << std::endl;
  ans = a / b;
  std::cout << a << " / " << b << " = " << ans << std::endl;
  std::cout << a << "; ++a; " << ++a << std::endl;
  std::cout << a << "; ++a; " << ++a << std::endl;
  std::cout << a << "; ++a; " << ++a << std::endl;
  std::cout << e << "; ++e; " << ++e << std::endl;
  std::cout << a << "; --a; " << --a << std::endl;
  std::cout << a << "; --a; " << --a << std::endl;
  std::cout << a << "; --a; " << --a << std::endl;
  std::cout << a << "; a++; " << a++ << ": " << a  << std::endl;
  int bits = a.GetRawBits();
  bitsput(&bits, sizeof(int));
    std::cout << a << "; ++a; " << ++a << std::endl;
  //  std::cout << a << "; a--; " << a-- << ": " << a  << std::endl;
  bits = a.GetRawBits();
  bitsput(&bits, sizeof(int));
  std::cout << "Min(" << a << ',' << e << ") = ";
  e = FixedMin(a, e);
  std::cout << e << std::endl;
  std::cout << "Min(" << a << ',' << d << ") = ";
  e = FixedMin(a, d);
  std::cout << e << std::endl;
  std::cout << "Max(" << a << ',' << e << ") = ";
  e = FixedMax(a, e);
  std::cout << e << std::endl;
  std::cout << "Max(" << a << ',' << c << ") = ";
  e = FixedMax(a, c);
  std::cout << e << std::endl;
  return 0;
}
