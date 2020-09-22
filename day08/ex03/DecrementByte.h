// Copyright 2020 kkozlov

#ifndef DECREMENTBYTE_H_
#define DECREMENTBYTE_H_

#include "IInstruction.h"

class DecrementByte : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new DecrementByte();
    return instance_;
  }

  inline int Execute(char **ptr) {
    --**ptr;
    return 0;
  }

 private:
  inline DecrementByte(void) {}
  DecrementByte(DecrementByte const &rhs);
  DecrementByte &operator=(DecrementByte const &rhs);

  static IInstruction *instance_;
};

IInstruction *DecrementByte::instance_ = NULL;

#endif  // DECREMENTBYTE_H_
