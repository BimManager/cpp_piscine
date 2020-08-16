// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Form.h"

Form::Form(std::string const &name,
           unsigned minGradeToSign,
           unsigned minGradeToExecute) throw()
    : name_(name) , minGradeToSign_(minGradeToSign),
      minGradeToExecute_(minGradeToExecute) {
  if (minGradeToSign > Bureaucrat::MinGrade() ||
      minGradeToExecute > Bureaucrat::MinGrade() )
    throw GradeTooLowException();
  if (minGradeToSign < Bureaucrat::MaxGrade() ||
      minGradeToExecute < Bureaucrat::MaxGrade())
    throw GradeTooHighException();
}

Form::Form(Form const &other)
    : name_(other.Name()), minGradeToSign_(other.MinGradeToSign()),
      minGradeToExecute_(other.MinGradeToExecute()) {}

Form::~Form(void) {}

Form &Form::operator=(Form const &rhs) {
  if (&rhs != this) {
    isSigned_ = rhs.IsSigned();
  }
  return *this;
}

std::string const &Form::Name(void) const {
  return name_;
}

unsigned Form::MinGradeToSign(void) const {
  return minGradeToSign_;
}

unsigned Form::MinGradeToExecute(void) const {
  return minGradeToExecute_;
}

bool Form::IsSigned(void) const {
  return isSigned_;
}

void Form::BeSigned(Bureaucrat const &bureaucrat) throw() {
  if (bureaucrat.Grade() > minGradeToSign_)
    throw GradeTooLowException();
  isSigned_ = true;
}

char const *Form::GradeTooLowException::what(void) const throw() {
  return "The grade too low exception\n";
}

char const *Form::GradeTooHighException::what(void) const throw() {
  return "The maximum grade is 150\n";
}

std::ostream &operator<<(std::ostream &os, Form const &in) {
  os << in.Name() << "\nMinimum grade to sign it: " << in.MinGradeToSign()
     << "\nMinimum grade to execute it: " << in.MinGradeToExecute()
     << "\nIs signed: " << (in.IsSigned() ? "yes" : "no") << std::endl;
  return os;
}
