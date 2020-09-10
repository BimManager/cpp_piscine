// Copyright 2020 kkozlov

#include <iostream>
#include <string>

template<class T>
inline void Swap(T *t1, T *t2) {
  T tmp = *t1;
  *t1 = *t2;
  *t2 = tmp;
}

template<class T>
inline void Swap(T &t1, T &t2) {
  T tmp(t1);
  t1 = t2;
  t2 = tmp;
}

template<>
inline void Swap<int>(int &a, int &b) {
  std::cout << "an explicit specialization for int" << std::endl;
  int tmp(a);
  a = b;
  b = tmp;
}

template<class T>
inline T &Min(T &t1, T  &t2) {
  return t1 < t2 ? t1 : t2;
}

template<class T>
inline T &Max(T &t1, T &t2) {
  return t2 < t1 ? t1 : t2;
}

static void UnitTests(void) {
  std::cout << __FUNCTION__ << std::endl;
  int a = 2;
  int b = 4;
  std::cout << "before swap: " << a << ' ' << b  << std::endl;
  ::Swap(a, b);
  std::cout << "after swap: " << a << ' ' << b  << std::endl;
  std::cout << "min: " << ::Min(a, b)  << std::endl;
  std::cout << "max: " << ::Max(a, b)  << std::endl;
  std::string s1("Foo");
  std::string s2("Baz");
  std::cout << "before swap: " << s1 << ' ' << s2  << std::endl;
  ::Swap(s1, s2);
  std::cout << "after swap: " << s1 << ' ' << s2  << std::endl;
  std::cout << "min: " << ::Min(s1, s2)  << std::endl;
  std::cout << "max: " << ::Max(s1, s2)  << std::endl;
}

int main(void) {
  UnitTests();
  return 0;
}
