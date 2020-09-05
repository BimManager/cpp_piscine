// Copyright 2020 kkozlov

#include "OfficeBlock.h"

OfficeBlock::OfficeBlock(void) {}

OfficeBlock::OfficeBlock(Bureaucrat *signBureaucrat,
                         Bureaucrat *execBureaucrat, Intern *intern) {
  signBureaucrat_ = signBureaucrat;
  execBureaucrat_ = execBureaucrat;
  intern_ = intern;
}

OfficeBlock::~OfficeBlock(void) {}

void OfficeBlock::SetSignBureaucrat(Bureaucrat *signBureaucrat) {
  signBureaucrat_ = signBureaucrat;
}

void OfficeBlock::SetExecBureaucrat(Bureaucrat *execBureaucrat) {
  execBureaucrat_ = execBureaucrat;
}

void OfficeBlock::SetIntern(Intern *intern) {
  intern_ = intern;
}

void OfficeBlock::DoBureaucracy(std::string const &formName,
                                std::string const &target) throw() {
  Form *form;
  if (!intern_) {
    throw InternNullException();
  } else if (!signBureaucrat_ || !execBureaucrat_) {
    throw BureaucratNullException();
  } else {
    form = intern_->MakeForm(formName, target);
    signBureaucrat_->SignForm(form);
    execBureaucrat_->ExecuteForm(form);
  }
}
