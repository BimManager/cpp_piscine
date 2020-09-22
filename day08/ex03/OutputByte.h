// Copyright 2020 kkozlov

#ifndef OUTPUTBYTE_H_
#define OUTPUTBYTE_H_

#include <iostream>

#include "IInstruction.h"

class OutputByte : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new OutputByte();
    return instance_;
  }

  inline int Execute(char **ptr) {
    std::cout << **ptr;
    return 0;
  }

 private:
  inline OutputByte(void) {}
  OutputByte(OutputByte const &rhs);
  OutputByte &operator=(OutputByte const &rhs);

  static IInstruction *instance_;
};

IInstruction *OutputByte::instance_ = NULL;

#endif  // OUTPUTBYTE_H_
