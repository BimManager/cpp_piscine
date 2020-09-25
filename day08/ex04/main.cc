// Copyright 2020 kkozlov

#include <sys/types.h>
#include <unistd.h>
#include <cstdio>

#include <iostream>
#include <queue>
#include <list>

#include "Tokenizer.h"
#include "ShuntingYard.h"
#include "AToken.h"

static void LeaksChecker(void) {
  pid_t pid = getpid();
  char buf[128];
  std::snprintf(buf, sizeof(buf), "leaks %u", pid);
  std::system(buf);
}

static void PrintTokens(std::list<AToken *> *tokens) {
  std::list<AToken *>::iterator startIt = tokens->begin();
  std::list<AToken *>::iterator endIt = tokens->end();
  std::cout << "Tokens: ";
  while (startIt != endIt) {
    (*startIt)->Print();
    ++startIt;
    if (startIt != endIt)
      std::cout << ' ';
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  if (2 != argc || !*argv[1]) {
    std::cout << "Usage: " << argv[0] << " '3 + 1 * (5 - 3) / 2'" << std::endl;
    return 1;
  } else {
    std::list<AToken*> *tokens;
    Tokenizer tokenizer;
    if (tokenizer.ParseExpr(argv[1], &tokens)) {
      std::cerr << "Error parsing the expression: " << argv[1] << std::endl;
      return 2;
    }
    PrintTokens(tokens);
    ShuntingYard *yard = ShuntingYard::Create();
    yard->GeneratePostfix(tokens);
    delete tokens;
    yard->PrintPostfix();
    yard->ComputePostfix();
  }
  LeaksChecker();
  return 0;
}
