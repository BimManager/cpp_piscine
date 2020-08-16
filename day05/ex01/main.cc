// Copyright 2020 kkozlov

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.h"
#include "Form.h"

int main(void) {
  Form formA("Form A", 10, 3);
  std::cout << formA;
  Bureaucrat *creep_p;
  Form *formB_p;
  try {
    creep_p = new Bureaucrat("Michael", 5);
    formB_p = new Form("Form B", 5, 2);
    creep_p->DecrementGrade();
    creep_p->IncrementGrade();
    formB_p->BeSigned(*creep_p);
    std::cout << *formB_p;
    std::cout << *creep_p;
    creep_p->SignForm(&formA);
    creep_p->DecrementGrade();
    creep_p->SignForm(formB_p);
  } catch (std::exception &e) {
    std::cerr << e.what()  << std::endl;
    delete creep_p;
    delete formB_p;
  }
  return (0);
}
