// Copyright 2020 kkozlov

#include "Pony.hpp"

static void ponyOnTheHeap(void) {
  Pony *aPony;

  std::cout << "Ponies on the heap" << std::endl;
  aPony = new Pony("Baz");
  aPony->Gallop();
  delete aPony;
}

static void ponyOnTheStack(void) {
  std::cout << "Ponies on the stack" << std::endl;
  Pony aPony("Foo");
  aPony.Gallop();
}

int main(void) {
  ponyOnTheHeap();
  ponyOnTheStack();
  return (0);
}
