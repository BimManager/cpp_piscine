// Copyright 2020 kkozlov

#ifndef INCREMENTPOINTER_H_
#define INCREMENTPOINTER_H_

#include "IInstruction.h"

class IncrementPointer : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new IncrementPointer();
    return instance_;
  }

  inline int Execute(char **ptr) {
    ++*ptr;
    return 0;
  }

 private:
  inline IncrementPointer(void) { }
  IncrementPointer(IncrementPointer const &rhs);
  IncrementPointer &operator=(IncrementPointer const &rhs);

  static IInstruction *instance_;
};

IInstruction *IncrementPointer::instance_ = NULL;

#endif  // INCREMENTPOINTER_H_
