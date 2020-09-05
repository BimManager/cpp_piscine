// Copyright 2020 kkozlov

#ifndef DAY05_EX04_OFFICEBLOCK_H_
#define DAY05_EX04_OFFICEBLOCK_H_

#include <string>
#include <stdexcept>

#include "Bureaucrat.h"
#include "Intern.h"

class OfficeBlock {
 public:
  OfficeBlock(void);
  OfficeBlock(Bureaucrat *signBureaucrat,
              Bureaucrat *execBureaucrat, Intern *intern);
  ~OfficeBlock(void);

  void SetSignBureaucrat(Bureaucrat *signBureaucrat);
  void SetExecBureaucrat(Bureaucrat *execBureaucrat);
  void SetIntern(Intern *intern);

  void DoBureaucracy(std::string const &formName,
                     std::string const &target) throw();

 private:
  Bureaucrat *signBureaucrat_;
  Bureaucrat *execBureaucrat_;
  Intern *intern_;

  OfficeBlock(OfficeBlock const &other);

  OfficeBlock &operator=(OfficeBlock const &rhs);

  class BureaucratNullException : public std::exception {
  };
  class InternNullException : public std::exception {
  };
};

#endif  // DAY05_EX04_OFFICEBLOCK_H_
