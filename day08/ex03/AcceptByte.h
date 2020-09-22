// Copyright 2020 kkozlov

#ifndef ACCEPTBYTE_H_
#define ACCEPTBYTE_H_

#include <iostream>

#include "IInstruction.h"

class AcceptByte : public IInstruction {
 public:
  inline static IInstruction *Create(void) {
    if (!instance_)
      instance_ = new AcceptByte();
    return instance_;
  }

  inline int Execute(char **ptr) {
    std::cin >> **ptr;
    return 0;
  }

 private:
  inline AcceptByte(void) {}
  AcceptByte(AcceptByte const &rhs);
  AcceptByte &operator=(AcceptByte const &rhs);

  static IInstruction *instance_;
};

IInstruction *AcceptByte::instance_ = NULL;

#endif  // ACCEPTBYTE_H_
