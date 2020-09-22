// Copyright 2020 kkozlov

#include <iostream>

#include "BrainFuck.h"

int main(int argc, char **argv) {
  BrainFuck *brainFuck = BrainFuck::GetInstance();
  if (argc != 2) {
    std::cout << "Usage: " << *argv << " file" << std::endl;
  } else {
    if (!brainFuck->ReadFromFile(argv[1]))
      brainFuck->Run();
  }
  return 0;
}
