// Copyright 2020 kkozlov

#ifndef DAY05_EX03_FORM_H_
#define DAY05_EX03_FORM_H_

#include <string>
#include <stdexcept>
#include <iostream>

#include "Bureaucrat.h"

class Bureaucrat;

class Form {
 public:
  Form(std::string const &name, unsigned minGradeToSign,
       unsigned minGradeToExecute, std::string const &target) throw();
  Form(Form const &other);
  virtual ~Form(void);

  Form &operator=(Form const &rhs);

  std::string const &Name(void) const;
  unsigned MinGradeToSign(void) const;
  unsigned MinGradeToExecute(void) const;
  bool IsSigned(void) const;
  std::string const &Target(void) const;

  void BeSigned(Bureaucrat const &bureaucat) throw();

  void Execute(Bureaucrat const &executor) throw();

 protected:
  virtual void Action(void) = 0;

 private:
  std::string const name_;
  unsigned const minGradeToSign_;
  unsigned const minGradeToExecute_;
  bool isSigned_;
  std::string target_;

  class GradeTooLowException : public std::exception {
   public:
    char const *what(void) const throw();
  };

  class GradeTooHighException : public std::exception {
   public:
    char const *what(void) const throw();
  };
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif  // DAY05_EX03_FORM_H_
