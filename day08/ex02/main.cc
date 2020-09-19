// Copyright 2020 kkozlov

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>

#include "MutantStack.hpp"

static void IntStackUnitTests(void) {
  MutantStack<int> intStack;
  intStack.push(5);
  intStack.push(42);
  intStack.push(19);
  MutantStack<int>::iterator iBegIt = intStack.begin();
  MutantStack<int>::iterator iEndIt = intStack.end();
  std::cout << __FUNCTION__ << std::endl;
  ++iBegIt;
  --iBegIt;
  while (iBegIt != iEndIt) {
    std::cout << *iBegIt << std::endl;
    ++iBegIt;
  }
  std::cout << '\n';
  intStack.pop();
  iBegIt = intStack.begin();
  iEndIt = intStack.end();
  while (iBegIt != iEndIt) {
    std::cout << *iBegIt << std::endl;
    ++iBegIt;
  }
}

static void StrStackUnitTests(void) {
  MutantStack<std::string> strStack;
  strStack.push("Foo");
  strStack.push("Baz");
  strStack.push("Bar");
  MutantStack<std::string>::iterator sBegIt = strStack.begin();
  MutantStack<std::string>::iterator sEndIt = strStack.end();
    std::cout << __FUNCTION__ << std::endl;
  ++sBegIt;
  --sBegIt;
  while (sBegIt != sEndIt) {
    std::cout << *sBegIt << std::endl;
    ++sBegIt;
  }
  std::cout << '\n';
  strStack.pop();
  sBegIt = strStack.begin();
  sEndIt = strStack.end();
  while (sBegIt != sEndIt) {
    std::cout << *sBegIt << std::endl;
    ++sBegIt;
  }
  strStack.pop();
    strStack.pop();
    strStack.pop();
}

static void CopyStacksUnitTests(void) {
  MutantStack<int> stackA;
  std::cout << __FUNCTION__ << std::endl;
  stackA.push(std::rand());
  stackA.push(std::rand());
  MutantStack<int> stackB(stackA);
  stackA.pop();
  MutantStack<int>::iterator begIt = stackB.begin();
  MutantStack<int>::iterator endIt = stackB.end();
  while (begIt != endIt) {
    std::cout << *begIt << std::endl;
    ++begIt;
  }
  stackA = stackB;
  begIt = stackA.begin();
  endIt = stackA.end();
  while (begIt != endIt) {
    std::cout << *begIt << std::endl;
    ++begIt;
  }
}

int main(void) {
  std::srand(std::clock());
  IntStackUnitTests();
  StrStackUnitTests();
  CopyStacksUnitTests();
  return 0;
}
