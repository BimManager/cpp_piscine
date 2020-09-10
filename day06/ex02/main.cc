// Copyright 2020 kkozlov

#include <cstdlib>
#include <ctime>

#include <string>
#include <iostream>
#include <stdexcept>

#define N_CLASSES 3

class Base {
 public:
  virtual ~Base(void) {}
};

class A : public Base {
 public:
  static Base *Initialize(void) {
    return new A();
  }
};

class B : public Base {
 public:
  static Base *Initialize(void) {
    return new B();
  }
};

class C : public Base {
 public:
  static Base *Initialize(void) {
    return new C();
  }
};

typedef Base *(*PFN)(void);

PFN initializers[] = {
  &A::Initialize, &B::Initialize, &C::Initialize
};

Base *Generate(void) {
  std::srand(std::clock());
  int rnd = rand() % N_CLASSES;
  std::cout << "rnd: " << rnd << std::endl;
  return (*initializers[rnd])();
}

void IdentifyFromPointer(Base *base) {
  if (dynamic_cast<A *>(base))
    std::cout << "A";
  if (dynamic_cast<B *>(base))
    std::cout << "B";
  if (dynamic_cast<C *>(base))
    std::cout << "C";
  std::cout << std::endl;
}

void IdentifyFromReference(Base &base) {
  try {
    A a = dynamic_cast<A &>(base);
    std::cout << "A" << std::endl;
  } catch (std::bad_cast) {
    try {
      B b = dynamic_cast<B &>(base);
      std::cout << "B" << std::endl;
    } catch (std::bad_cast) {
      try {
        C c = dynamic_cast<C &>(base);
        std::cout << "C" << std::endl;
      } catch (std::bad_cast) {
        std::cout << "It is none of the classes" << std::endl;
      }
    }
  }
}

int main(void) {
  Base *base = Generate();
  IdentifyFromPointer(base);
  IdentifyFromReference(*base);
  return 0;
}
