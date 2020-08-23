// Copyright 2020 kkozlov

#include <iostream>
#include <string>

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : Form("Presidential Pardon Form", 25, 5, target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::Action(void) {
  std::cout << this->Target() << " has been pardoned by Zafod Beeblebrox"
            << std::endl;
}
