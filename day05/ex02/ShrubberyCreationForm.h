// Copyright 2020 kkozlov

#ifndef DAY05_EX02_SHRUBBERYCREATIONFORM_H_
#define DAY05_EX02_SHRUBBERYCREATIONFORM_H_

#include <string>

#include "Form.h"

class ShrubberyCreationForm : public Form {
 public:
  explicit ShrubberyCreationForm(std::string const &targer);
  ~ShrubberyCreationForm(void);

  void Action(void);
};

#endif  // DAY05_EX02_SHRUBBERYCREATIONFORM_H_
