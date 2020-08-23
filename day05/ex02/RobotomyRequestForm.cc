// Copyright 2020 kkozlov

#include <stdlib.h>
#include <time.h>

#include <string>
#include <iostream>

#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : Form("Robotomy Request Form", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::Action(void) {
  srand(clock());

  int rnd = rand() % 2;
  std::cout << "\a\a\a";
  std::cout << this->Target();
  if (rnd) {
    std::cout << " has been successfully"
        " robotomised";
  } else {
    std::cout << " has not been robotomised";
  }
  std::cout << std::endl;
}
