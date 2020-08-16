// Copyright 2020 kkozlov

#ifndef DAY05_EX00_BUREAUCRAT_H_
#define DAY05_EX00_BUREAUCRAT_H_

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat {
 public:
  Bureaucrat(std::string const &name, unsigned grade) throw();
  Bureaucrat(Bureaucrat const &other);
  ~Bureaucrat(void);

  Bureaucrat &operator=(Bureaucrat const &rhs);

  std::string const &Name(void) const;
  unsigned Grade(void) const;

  void IncrementGrade(void) throw();
  void DecrementGrade(void) throw();

 private:
  std::string const name_;
  unsigned grade_;
  static unsigned const kMinGrade_;
  static unsigned const kMaxGrade_;

  class GradeTooLowException : public std::exception {
   public:
    char const *what(void) const throw();
  };

  class GradeTooHighException : public std::exception {
   public:
    char const *what(void) const throw();
  };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &in);

#endif  // DAY05_EX00_BUREAUCRAT_H_
