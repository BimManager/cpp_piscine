// Copyright 2020 kkozlov

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main(void) {
  Intern intern;
  Form *form;
  try {
    form = intern.MakeForm("Robotomy Request Form", "Putin");
    if (form) {
      std::cout << *form;
    }
    delete form;
    form = intern.MakeForm("Presidential Pardon Form", "Putin");
    if (form) {
      std::cout << *form;
    }
    delete form;
    form = intern.MakeForm("Shrubbery Creation Form", "Putin");
    if (form) {
      std::cout << *form;
    }
    delete form;
    form = intern.MakeForm("Bogus Form", "Putin");
    if (form) {
      std::cout << *form;
    }
  }
  catch (std::exception &exp) {
    std::cerr << exp.what() << std::endl;
  }
  return (0);
}
