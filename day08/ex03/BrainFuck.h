// Copyright 2020 kkozlov

#ifndef BRAINFUCK_H_
#define BRAINFUCK_H_

#include <cstddef>

#include <string>
#include <list>
#include <stack>

#include "IInstruction.h"

typedef IInstruction *(*PFN)(void);

class BrainFuck {
 public:
  ~BrainFuck(void);
  static BrainFuck *GetInstance(void);
  int ReadFromFile(std::string const &filename);
  int Run(void);

 private:
  BrainFuck(void);
  BrainFuck(BrainFuck const &);
  BrainFuck &operator=(BrainFuck const &);

  int ParseLine(std::string &line);

  enum { TAB_SIZE = 128 };
  static PFN ops_tab_[TAB_SIZE];
  std::list<IInstruction *> ops_;
  std::stack<std::list<IInstruction *>::iterator> loops_;
  static std::size_t const kBufSize_;
  char *ptr_;
  static BrainFuck *instance_;
};

#endif  // BRAINFUCK_H_
