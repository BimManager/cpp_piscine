// Copyright 2020 kkozlov

#include <ctime>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "easyfind.hpp"

int main(void) {
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(42);
  int target = 42;
  int idx = easyfind(nums, target);
  std::cout << "idx: " << idx << std::endl;
  std::array<int, 3> nums2 = {1, 2, 3};
  idx = easyfind(nums2, target);
  std::cout << "idx: " << idx << std::endl;
  return 0;
}
