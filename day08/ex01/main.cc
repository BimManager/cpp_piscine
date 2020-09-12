// Copyright 2020 kkozlov

#include <ctime>
#include <cstdlib>

#include <iostream>

#include "Span.h"

static int *GenerateNRandomNumbers(unsigned n) {
  std::srand(std::clock());
  int *nums = new int[n];
  while (n--) {
    nums[n] = std::rand();
    if (n & 1)
      nums[n] = -nums[n];
  }
  return nums;
}

static void TestAddNumber(void) {
  unsigned n = 5;
  Span sp(n);

  sp.AddNumber(5);
  sp.AddNumber(3);
  sp.AddNumber(9);
  sp.AddNumber(17);
  sp.AddNumber(11);
  while (n--)
    std::cout << sp[n] << ' ';
  std::cout << "\nsize: " << sp.Size() << std::endl;
  std::cout << "max span: " << sp.LongestSpan() << std::endl;
  std::cout << "min span: " << sp.ShortestSpan() << std::endl;
}

static void TestAddRange(unsigned n) {
  Span sp(n);
  int *nums = GenerateNRandomNumbers(n);

  sp.AddRange(nums, nums + n);
  delete[] nums;
  while (n--)
    std::cout << sp[n] << ' ';
  std::cout << "\nsize: " << sp.Size() << std::endl;
  std::cout << "max span: " << sp.LongestSpan() << std::endl;
  std::cout << "min span: " << sp.ShortestSpan() << std::endl;
}

int main(void) {
  TestAddNumber();
  TestAddRange(1000);
  return 0;
}
