// Copyright 2020 kkozlov

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main(void) {
  Bureaucrat executorX("X", 5);
  ShrubberyCreationForm formA("office");
  RobotomyRequestForm robotForm("chair");
  PresidentialPardonForm pardonForm("Putin");
  try {
    executorX.SignForm(&formA);
    formA.Execute(executorX);
    executorX.SignForm(&robotForm);
    robotForm.Execute(executorX);
    executorX.SignForm(&pardonForm);
    pardonForm.Execute(executorX);
    executorX.ExecuteForm(&formA);
    executorX.ExecuteForm(&robotForm);
  }
  catch (std::exception &exp) {
    std::cerr << exp.what() << std::endl;
  }
  return (0);
}
