// Copyright 2020 kkozlov

#ifndef INCREMENTBYTE_H_
#define INCREMENTBYTE_H_

#include "IInstruction.h"

class IncrementByte : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new IncrementByte();
    return instance_;
  }

  inline int Execute(char **ptr) {
    ++**ptr;
    return 0;
  }
  
 private:
  inline IncrementByte(void) {}
  IncrementByte(IncrementByte const &rsh);
  IncrementByte &operator=(IncrementByte const &rsh);

  static IInstruction *instance_;
};

IInstruction *IncrementByte::instance_ = NULL;

#endif  // INCREMENTBYTE_H_
