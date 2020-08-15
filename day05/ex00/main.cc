// Copyright 2020 kkozlov

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.h"

int main(void) {
  Bureaucrat dogsbody("John", 10);
  std::cout << dogsbody;

  try {
    Bureaucrat *creep_p = new Bureaucrat("Michael", 1);
    creep_p->DecrementGrade();
    creep_p->IncrementGrade();
    std::cout << *creep_p;
  } catch (std::exception &e) {
    std::cerr << e.what()  << std::endl;
  }
  return (0);
}
