// Copyright 2020 kkozlov

#include <cctype>
#include <cerrno>

#include <limits>

#include "Tokenizer.h"
#include "Number.h"
#include "Operator.h"
#include "OpeningParen.h"
#include "ClosingParen.h"

PFN Tokenizer::token_tab[TabSize] = {
  ['+'] = &Operator::Create,
  ['-'] = &Operator::Create,
  ['*'] = &Operator::Create,
  ['/'] = &Operator::Create,
  ['('] = &OpeningParen::Create,
  [')'] = &ClosingParen::Create
};

Tokenizer::Tokenizer(void) {}

Tokenizer::~Tokenizer(void) {}

int Tokenizer::ParseExpr(char const *expr, std::list<AToken *> **list) {
  *list = new std::list<AToken *>();
  int value;
  AToken *lastToken = NULL;
  AToken *token = NULL;
  while (*expr) {
    lastToken = (*list)->empty() ? NULL : (*list)->back();
    while (isspace(*expr))
      ++expr;
    if (std::isdigit(*expr) || ('-' == *expr && std::isdigit(*(expr + 1)))) {
      if (ParseNumber(expr, &value)) {
        return 1;
      } else {
        if (lastToken && dynamic_cast<Number *>(lastToken))
          return 1;
        (*list)->push_back(new Number(value));
        lastToken = (*list)->back();
      }
      while (isnumber(*expr) || '-' == *expr)
        ++expr;
    }
    while (isspace(*expr))
      ++expr;
    if (token_tab[static_cast<int>(*expr)]) {
      token = (*token_tab[static_cast<int>(*expr)])(*expr);
      if (lastToken && dynamic_cast<Operator *>(lastToken)
          && dynamic_cast<Operator *>(token))
        return 5;
      (*list)->push_back(token);
      lastToken = token;
      if ('(' == *expr) {
        parensChecker_.push(*expr);
      } else if (')' == *expr) {
        if (parensChecker_.empty())
          return 2;
        parensChecker_.pop();
      }
      ++expr;
    } else if (*expr) {
      return 1;
    }
  }
  if (!parensChecker_.empty())
    return 3;
  if (lastToken && dynamic_cast<Operator *>(lastToken))
    return 4;
  return 0;
}

int Tokenizer::ParseNumber(char const *it, int *res) {
  long value = std::strtol(it, NULL, 10);
  if (errno || (value > std::numeric_limits<int>::max()
                || value < std::numeric_limits<int>::min()))
    return 1;
  *res = static_cast<int>(value);
  return 0;
}
