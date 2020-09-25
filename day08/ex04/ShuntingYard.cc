// Copyright 2020 kkozlov

#include <iostream>

#include "ShuntingYard.h"
#include "Number.h"
#include "Operator.h"
#include "OpeningParen.h"
#include "ClosingParen.h"

ShuntingYard *ShuntingYard::instance_ = NULL;
POPF ShuntingYard::opf_tab[TabSize] = {
  ['+'] = &Add, ['-'] = &Sub,
  ['*'] = &Mul, ['/'] = &Div
};

ShuntingYard::ShuntingYard(void) {}

ShuntingYard::~ShuntingYard(void) {
  if (instance_) {
    AToken *token;

    while (!outputQueue_.empty()) {
      token = outputQueue_.front();
      outputQueue_.pop();
      delete token;
    }
    while (!operatorStack_.empty()) {
      token = operatorStack_.top();
      operatorStack_.pop();
      delete token;
    }
    while (!evalStack_.empty()) {
      token = evalStack_.front();
      evalStack_.pop_front();
      delete token;
    }
    delete instance_;
  }
}

ShuntingYard *ShuntingYard::Create(void) {
  if (!instance_)
    instance_ = new ShuntingYard();
  return instance_;
}

void ShuntingYard::GeneratePostfix(std::list<AToken *> *tokens) {
  AToken *token;
  Operator *nextOp;
  Operator *topOp;
  while (!tokens->empty()) {
    token = tokens->front();
    tokens->pop_front();
    if (dynamic_cast<Number *>(token)) {
      outputQueue_.push(token);
    } else if ((nextOp = dynamic_cast<Operator *>(token))) {
      while (!operatorStack_.empty() &&
             ((topOp = dynamic_cast<Operator *>(operatorStack_.top()))
              && topOp->GetPrecedence() >= nextOp->GetPrecedence())) {
        outputQueue_.push(topOp);
        operatorStack_.pop();
      }
      operatorStack_.push(token);
    } else if (dynamic_cast<OpeningParen *>(token)) {
      operatorStack_.push(token);
    } else {
      while ((topOp = dynamic_cast<Operator *>(operatorStack_.top()))) {
        outputQueue_.push(topOp);
        operatorStack_.pop();
      }
      delete operatorStack_.top();
      operatorStack_.pop();
      delete token;
    }
  }
  while (!operatorStack_.empty()) {
    topOp = dynamic_cast<Operator *>(operatorStack_.top());
    operatorStack_.pop();
    outputQueue_.push(topOp);
  }
}

void ShuntingYard::PrintPostfix(void) {
  AToken *token;

  std::cout << "Postfix: ";
  outputQueue_.push(NULL);
  while ((token = outputQueue_.front())) {
    outputQueue_.pop();
    outputQueue_.push(token);
    token->Print();
    if (outputQueue_.front())
      std::cout << ' ';
  }
  outputQueue_.pop();
  std::cout << std::endl;
}

void ShuntingYard::PrintEvalStack(void) {
  std::list<Number *>::iterator begIt = evalStack_.begin();
  std::list<Number *>::iterator endIt = evalStack_.end();
  std::cout << " | ST ";
  while (begIt != endIt) {
    std::cout << (*begIt)->GetValue();
    ++begIt;
    if (begIt != endIt)
      std::cout << ' ';
  }
}

void ShuntingYard::ComputePostfix(void) {
  AToken *token;
  Number *num1;
  Number *num2;
  Operator *op;
  while (!outputQueue_.empty()) {
    token = outputQueue_.front();
    outputQueue_.pop();
    std::cout << std::left << std::setw(20);
    if ((num1 = dynamic_cast<Number *>(token))) {
      num1->Print();
      evalStack_.push_back(num1);
      std::cout << std::left << std::setw(15) << "| OP Push";
    } else if ((op = dynamic_cast<Operator *>(token))) {
      std::cout << std::left << std::setw(20);
      op->Print();
      num2 = evalStack_.back();
      evalStack_.pop_back();
      num1 = evalStack_.back();
      evalStack_.pop_back();
      std::cout << "| ";
      std::cout << std::left << std::setw(13);
      num1->SetValue(((*opf_tab[static_cast<int>(op->GetValue())])(
          num1->GetValue(), num2->GetValue())));
      delete num2;
      evalStack_.push_back(num1);
    }
    PrintEvalStack();
    std::cout << '\n';
  }
  std::cout << "Result: " << (evalStack_.back())->GetValue() << std::endl;
  delete evalStack_.back();
}
