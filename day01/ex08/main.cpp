// Copyright 2020 kkozlov

#include "Human.hpp"

int main(void) {
  Human john;
  john.Action("MeleeAttack", "Baz");
  john.Action("RangedAttack", "Foo");
  john.Action("IntimidatingShout", "Bar");
  john.Action("RandomAttack", "Bar");
  return (0);
}
