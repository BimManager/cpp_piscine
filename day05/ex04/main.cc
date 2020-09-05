// Copyright 2020 kkozlov

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"
#include "OfficeBlock.h"

int main(void) {
  Intern intern;
  Bureaucrat signBureaucrat("Signer", 150);
  Bureaucrat execBureaucrat("Executer", 20);
  OfficeBlock office;

  office.SetIntern(&intern);
  office.SetSignBureaucrat(&signBureaucrat);
  office.SetExecBureaucrat(&execBureaucrat);
  try {
    office.DoBureaucracy("Shrubbery Creation Form", "Baz");
  }
  catch (std::exception &exp) {
    std::cerr << exp.what() << std::endl;
  }
  return (0);
}
