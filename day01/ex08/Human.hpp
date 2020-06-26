// Copyright 2020 kkozlov

#ifndef HUMAN_HPP_
#define HUMAN_HPP_

#include <string>

class Human;

typedef void (Human::*PFN) (const std::string&);

class Human {
 public:
  Human(void);
  void Action(const std::string& actionName, const std::string& target);
 private:
  void MeleeAttack(const std::string& target);
  void RangedAttack(const std::string& target);
  void IntimidatingShout(const std::string& target);

  static const PFN dispatchTable[];
  static const char *functionNames[];
  static const int kNbFunctions;
};

#endif  // HUMAN_HPP_
