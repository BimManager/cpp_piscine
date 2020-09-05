// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Intern.h"

Form *(*Intern::creators_[N_FORMS])(std::string const &target) = {
  &ShrubberyCreationForm::CreateForm,
  &RobotomyRequestForm::CreateForm,
  &PresidentialPardonForm::CreateForm
};

char const *Intern::formNames_[N_FORMS] = {
  "Shrubbery Creation Form",
  "Robotomy Request Form",
  "Presidential Pardon Form"
};

Intern::Intern(void) {}

Intern::Intern(Intern const &other) {}

Intern::~Intern(void) {}

Form *Intern::MakeForm(std::string const &name, std::string const &target) {
  int i = -1;
  while (++i < 3) {
    if (formNames_[i] && 0 == name.compare(formNames_[i]))
      return creators_[i](target);
  }
  std::cout << name << " has not been found.\nAvailable Forms:\n";
  i = -1;
  while (++i < N_FORMS)
    std::cout << formNames_[i] << std::endl;
  return (NULL);
}
