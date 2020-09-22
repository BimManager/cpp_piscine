// Copyright 2020 kkozlov

#ifndef DATAPOINTER_H_
#define DATAPOINTER_H_

#include <cstddef>
#include <cstdlib>
#include <cstring>

#include <stack>
#include <list>
#include <iterator>

#include "IInstruction.h"
#include "IncrementPointer.h"
#include "DecrementPointer.h"
#include "IncrementByte.h"
#include "DecrementByte.h"
#include "WhileStart.h"
#include "WhileEnd.h"
#include "AcceptByte.h"
#include "OutputByte.h"

class DataPointer {
 public:
  DataPointer(void);
  ~DataPointer(void);

  void RunInstruction(std::list<IInstruction *>::iterator &it);

 private:
  static std::size_t const kNbBytes;
  std::stack<std::list<IInstruction *>::iterator> loops_;
  char  *raw_p;

  DataPointer(DataPointer const &rhs);
  DataPointer &operator=(DataPointer const &rhs);

  void Execute(IncrementPointer *op, std::list<IInstruction *>::iterator *it);
  void Execute(DecrementPointer *op, std::list<IInstruction *>::iterator *it);
  void Execute(IncrementByte *op, std::list<IInstruction *>::iterator *it);
  void Execute(DecrementByte *op, std::list<IInstruction *>::iterator *it);
  void Execute(WhileStart *op, std::list<IInstruction *>::iterator *it);
  void Execute(WhileEnd *op, std::list<IInstruction *>::iterator *it);
};

#endif  // DATAPOINTER_H_
