// Copyright 2020 kkozlov

#include <iostream>
#include <queue>
#include <list>

#include "Tokenizer.h"
#include "ShuntingYard.h"
#include "AToken.h"

int main(int argc, char **argv) {
  if (2 != argc || !*argv[1]) {
    std::cout << "Usage: " << argv[0] << " '3 + 1 * (5 - 3) / 2'" << std::endl;
    return 1;
  } else {
    std::list<AToken*> *list;
    Tokenizer tokenizer;
    if (tokenizer.ParseExpr(argv[1], &list)) {
      std::cerr << "Error parsing the expression: " << argv[1] << std::endl;
      return 2;
    }
      std::list<AToken *>::iterator startIt = list->begin();
      std::list<AToken *>::iterator endIt = list->end();
      std::cout << "Tokens: ";
      while (startIt != endIt) {
        (*startIt)->Print();
        ++startIt;
        if (startIt != endIt)
          std::cout << ' ';
      }
      std::cout << std::endl;
      ShuntingYard *yard = ShuntingYard::Create();
      yard->GeneratePostfix(list);
      delete list;
      yard->PrintPostfix();
            std::cout << std::endl;
      yard->ComputePostfix();
    return 0;
  }
}
