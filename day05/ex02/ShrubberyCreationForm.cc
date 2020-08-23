// Copyright 2020 kkozlov

#include <string>
#include <fstream>

#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : Form("Shrubbery Creation Form", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::Action(void) {
  std::string filename(this->Target());
  filename.append("_shrubbery");
  std::ofstream ofs(filename, std::ios_base::binary);
  ofs << "ASCII trees" << std::endl;
  ofs.close();
}
