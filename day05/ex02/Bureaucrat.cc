// Copyright 2020 kkozlov

#include <string>
#include <stdexcept>

#include "Bureaucrat.h"

unsigned const Bureaucrat::kMinGrade_ = 150;
unsigned const Bureaucrat::kMaxGrade_ = 1;

Bureaucrat::Bureaucrat(std::string const &name, unsigned grade) throw()
    : name_(name) {
  if (grade > kMinGrade_)
    throw GradeTooLowException();
  else if (grade < kMaxGrade_)
    throw GradeTooHighException();
  else
    grade_ = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : name_(other.Name()), grade_(other.Grade()) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (&rhs != this) {
    grade_ = rhs.Grade();
  }
  return *this;
}

std::string const &Bureaucrat::Name(void) const {
  return name_;
}

unsigned Bureaucrat::Grade(void) const {
  return grade_;
}

void Bureaucrat::IncrementGrade(void) throw() {
  if (grade_ - 1 < kMaxGrade_)
    throw GradeTooHighException();
  --grade_;
}

void Bureaucrat::DecrementGrade(void) throw() {
  if (grade_ + 1 > kMinGrade_)
    throw GradeTooLowException();
  ++grade_;
}

void Bureaucrat::SignForm(Form *form) {
  if (Grade() < form->MinGradeToSign()) {
    form->BeSigned(*this);
    std::cout << Name() << " bureaucrat has just signed "
              << form->Name() << std::endl;
  } else {
    std::cout << Name() << " bureaucrat cannot sign the form "
              << form->Name() << std::endl;
  }
}

void Bureaucrat::ExecuteForm(Form *form) {
  std::cout << name_ << " executes " << form->Name() << std::endl;
  form->Execute(*this);
}

unsigned Bureaucrat::MinGrade(void) {
  return kMinGrade_;
}

unsigned Bureaucrat::MaxGrade(void) {
  return kMaxGrade_;
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return ("Grade cannot be lower than 150\n");
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return ("Grade cannot be higher than 1\n");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &in) {
  os << in.Name() << ", bureaucrat grade "
     << in.Grade() << std::endl;
  return os;
}
