// Copyright 2020 kkozlov

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"
#include "OfficeBlock.h"
#include "CentralBureaucracy.h"

#define N_BUREAUCRATS 20
#define N_NAMES 5

static char const *names_[] = {
  "John", "Alex", "Matthew",
  "Jane", "Jack"
};

int main(int argc, char **argv) {
  CentralBureaucracy central;
  int i;
  Bureaucrat *bureaucrats[N_BUREAUCRATS];

  while (argc-- > 1)
    central.QueueUp(std::string(argv[argc]));
  //  central.QueuePrint();
  i = -1;
  while (++i < N_BUREAUCRATS) {
    bureaucrats[i] = new Bureaucrat(names_[rand() % N_NAMES],
                                    1 + rand() % Bureaucrat::MinGrade());
    central.FeedBureaucrat(bureaucrats[i]);
  }
  central.DoBureaucracy();
  i = -1;
  while (++i < N_BUREAUCRATS)
    delete bureaucrats[i];
  return 0;
}

