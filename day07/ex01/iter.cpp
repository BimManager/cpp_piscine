// Copyright 2020 kkozlov

#include <cstddef>

#include <iostream>

template<class T>
void Iter(T *arr, std::size_t n, void (*pfn)(T&)) {
  std::size_t i = -1;
  while (++i < n)
    (*pfn)(arr[i]);
}

template<class T>
void Print(T &elem) {
  std::cout << elem << std::endl;
}

template<class T>
void Increment(T &elem) {
  ++elem;
}

template<>
void Increment<char *>(char *&str) {
  char ch;

  while ((ch = *str++)) {
    std::cout << static_cast<char>(ch + 1);
  }
  std::cout << std::endl;
}

static void UnitTests(void) {
  int nums[] = {1, 2, 3, 4, 5};
  ::Iter(nums, sizeof(nums) / sizeof(nums[0]), &Increment);
  ::Iter(nums, sizeof(nums) / sizeof(nums[0]), &Print);
  char *words[] = {"foo", "baz", "bar"};
  ::Iter(words, sizeof(words) / sizeof(words[0]), &Print);
  ::Iter(words, sizeof(words) / sizeof(words[0]), &Increment);
  double rationals[] = {1.11, 2.42, 42.42, 55.122, 42.02};
  ::Iter(rationals, sizeof(rationals) / sizeof(rationals[0]), &Print);
}

int main(void) {
  UnitTests();
  return 0;
}
