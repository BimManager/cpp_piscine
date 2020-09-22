// Copyright 2020 kkozlov

#ifndef IINSTRUCTION_H_
#define IINSTRUCTION_H_

#include <iterator>

class IInstruction {
 public:
  virtual ~IInstruction(void) {}
  virtual int Execute(char **) = 0;
};

#endif  // IINSTRUCTION_H_
