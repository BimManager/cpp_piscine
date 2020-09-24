// Copyright 2020 kkozlov

#ifndef SHUNTINGYARD_H_
#define SHUNTINGYARD_H_

#include <stack>
#include <queue>
#include <list>
#include <iomanip>

#include "AToken.h"
#include "Number.h"

typedef int (*POPF)(int, int);

class ShuntingYard {
 public:
  ~ShuntingYard(void);

  void GeneratePostfix(std::list<AToken *> *tokens);
  void PrintPostfix(void);
  void ComputePostfix(void);

  static ShuntingYard *Create(void);

 private:
  std::queue<AToken *> outputQueue_;
  std::stack<AToken *> operatorStack_;
  std::list<Number *> evalStack_;
  static ShuntingYard *instance_;
  enum { TabSize = 128 };
  static POPF opf_tab[TabSize];

  ShuntingYard(void);
  ShuntingYard(ShuntingYard const &);
  ShuntingYard &operator=(ShuntingYard const &);

  void PrintEvalStack(void);

  static inline int Add(int a, int b) {
    std::cout << "OP Add"; return a + b; }
  static inline int Sub(int a, int b) {
    std::cout << "OP Subtact"; return a - b; }
  static inline int Mul(int a, int b) {
    std::cout << "OP Multiply"; return a * b; }
  static inline int Div(int a, int b) {
    std::cout << "OP Divide"; return a / b; }
};

#endif  // SHUNTINGYARD_H_
