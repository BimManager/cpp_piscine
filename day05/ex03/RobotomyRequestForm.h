// Copyright 2020 kkozlov

#ifndef DAY05_EX03_ROBOTOMYREQUESTFORM_H_
#define  DAY05_EX03_ROBOTOMYREQUESTFORM_H_

#include <string>

#include "Form.h"

class RobotomyRequestForm : public Form {
 public:
  explicit RobotomyRequestForm(std::string const &target);
  ~RobotomyRequestForm(void);

  void Action(void);
  static Form *CreateForm(std::string const &target);
};

#endif  //  DAY05_EX03_ROBOTOMYREQUESTFORM_H_
