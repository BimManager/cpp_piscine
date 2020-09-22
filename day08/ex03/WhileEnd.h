// Copyright 2020 kkozlov

#ifndef WHILEEND_H_
#define WHILEEND_H_

#include "IInstruction.h"

class WhileEnd : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new WhileEnd();
    return instance_;
  }

  inline int Execute(char **ptr) {
    (void)ptr;
    return 2;
  }

 private:
  inline WhileEnd(void) {}
  WhileEnd(WhileEnd const &rhs);
  WhileEnd &operator=(WhileEnd const &rhs);

  static IInstruction *instance_;
};

IInstruction *WhileEnd::instance_ = NULL;

#endif  // WHILEEND_H_
