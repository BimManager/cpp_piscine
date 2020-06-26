// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Human.hpp"

const PFN Human::dispatchTable[] = {
  &Human::MeleeAttack, &Human::RangedAttack, &Human::IntimidatingShout};
const char *Human::functionNames[] = {
  "MeleeAttack", "RangedAttack", "IntimidatingShout"};
const int Human::kNbFunctions = 3;

Human::Human(void) {
}

void Human::MeleeAttack(const std::string& target) {
  std::cout << "A melee attack on " << target << std::endl;
}

void Human::RangedAttack(const std::string& target) {
  std::cout << "A ranged attack on " << target << std::endl;
}

void Human::IntimidatingShout(const std::string& target) {
  std::cout << "An intimidateing shout on " << target << std::endl;
}

void Human::Action(const std::string& actionName, const std::string& target) {
  int i;

  i = Human::kNbFunctions;
  while (i--)
    if (0 == actionName.compare(functionNames[i])) {
      (this->*Human::dispatchTable[i])(target);
      return;
    }
  std::cout << actionName << " does not exist\n";
}
