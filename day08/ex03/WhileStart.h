// Copyright 2020 kkozlov

#ifndef WHILESTART_H_
#define WHILESTART_H_

#include "IInstruction.h"

class WhileStart : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new WhileStart();
    return instance_;
  }

  inline int Execute(char **ptr) {
    (void)ptr;
    return 1;
  }

 private:
  inline WhileStart(void) {}
  WhileStart(WhileStart const &rhs);
  WhileStart &operator=(WhileStart const &rhs);

  static IInstruction *instance_;
};

IInstruction *WhileStart::instance_ = NULL;

#endif  // WHILESTART_H_
