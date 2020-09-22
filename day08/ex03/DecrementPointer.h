// Copyright 2020 kkozlov

#ifndef DECREMENTPOINTER_H_
#define DECREMENTPOINTER_H_

#include "IInstruction.h"

class DecrementPointer : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new DecrementPointer();
    return instance_;
  }

  inline int Execute(char **ptr) {
    --*ptr;
    return 0;
  }

 private:
  inline DecrementPointer(void) { }
  DecrementPointer(DecrementPointer const &rhs);
  DecrementPointer &operator=(DecrementPointer const &rhs);

  static IInstruction *instance_;
};

IInstruction *DecrementPointer::instance_ = NULL;

#endif  // DECREMENTPOINTER_H_
