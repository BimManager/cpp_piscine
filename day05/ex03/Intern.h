// Copyright 2020 kkozlov

#ifndef DAY05_EX03_INTERN_H_
#define DAY05_EX03_INTERN_H_

#include <string>

#include "Form.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "PresidentialPardonForm.h"

#define N_FORMS 3

class Intern {
 public:
  Intern(void);
  Intern(Intern const &other);
  ~Intern(void);

  Form *MakeForm(std::string const &name, std::string const &target);

 private:
  Intern &operator=(Intern const &rhs);

  static Form *(*creators_[N_FORMS])(std::string const &targer);
  static char const *formNames_[N_FORMS];
};

#endif  // DAY05_EX03_INTERN_H_
