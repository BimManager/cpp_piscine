// Copyright 2020 kkozlov

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <list>
#include <stack>

#include "AToken.h"

typedef AToken *(*PFN)(char);

class Tokenizer {
 public:
  Tokenizer(void);
  ~Tokenizer(void);

  int ParseExpr(char const *expr, std::list<AToken *> **list);

 private:
  Tokenizer(Tokenizer const &);
  Tokenizer &operator=(Tokenizer const &);

  int ParseNumber(char const *it, int *res);

  enum { TabSize = 128 };
  static PFN token_tab[TabSize];
  std::stack<char> parensChecker_;
};

#endif  // TOKENIZER_H_
