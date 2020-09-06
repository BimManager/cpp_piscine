// Copyright 2020 kkozlov

#ifndef DAY05_EX05_OFFICEBLOCK_H_
#define DAY05_EX05_OFFICEBLOCK_H_

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
  void SetBureaucrat(Bureaucrat *bureaucrat);
  void SetIntern(Intern *intern);

  Intern *GetIntern(void) const;
  int IsFull(void) const;

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

#endif  // DAY05_EX05_OFFICEBLOCK_H_
