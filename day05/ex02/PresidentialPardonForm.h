// Copyright 2020 kkozlov

#ifndef DAY05_EX02_PRESIDENTIALPARDONFORM_H_
#define DAY05_EX02_PRESIDENTIALPARDONFORM_H_

#include <string>
#include <iostream>

#include "Form.h"

class PresidentialPardonForm : public Form {
 public:
  explicit PresidentialPardonForm(std::string const &target);
  ~PresidentialPardonForm(void);

  void Action(void);
};

#endif  // DAY05_EX02_PRESIDENTIALPARDONFORM_H_


