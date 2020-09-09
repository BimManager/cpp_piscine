// Copyright 2020 kkozlov

#include <cstdlib>
#include <cstring>
#include <cctype>

#include <string>
#include <iostream>

#include "ScalarConverter.h"

char const *ScalarConverter::specialValues_[] = {
  "inf", "-inf", "+inf", "nan"
};

int const ScalarConverter::kNbSpecialValues_ = 4;

ScalarConverter::ScalarConverter(char const *value) {
  int i = 4;
  while (i--)
    validity_[i] = ValueValidity::VALID;
  char const *it = value;
  if (IsSpecialValue(it)) {
    type_ = ValueType::SPECIAL;
  } else if ((it = strchr(it, '.'))) {
    if ((it = strchr(it, 'f')))
      type_ = ValueType::FLOAT;
    else
      type_ = ValueType::DOUBLE;
  } else {
    it = value;
    if ('+' == *it || '-' == *it)
      ++it;
    if (isdigit(*it))
      type_ = ValueType::INT;
    else
      type_ = ValueType::CHAR;
  }
  Convert(value);
}

ScalarConverter::~ScalarConverter(void) {}

char ScalarConverter::GetValueChar(void) const {
  return valueChar_;
}

int ScalarConverter::GetValueInt(void) const {
  return valueInt_;
}

float ScalarConverter::GetValueFloat(void) const {
  return valueFloat_;
}

double ScalarConverter::GetValueDouble(void) const {
  return valueDouble_;
}

int ScalarConverter::IsSpecialValue(char const *value) {
  size_t len = strlen(value);
  size_t i;

  if (len < 3)
    return 0;
  i = -1;
  while (++i < kNbSpecialValues_) {
    if (0 == strncmp(specialValues_[i], value, 'n' == *value ? 3 : 4))
      return 1;
  }
  return 0;
}

void ScalarConverter::ConvertChar(char const *value) {
    valueChar_ = *value;
    valueInt_ = static_cast<int>(valueChar_);
    valueFloat_ = static_cast<float>(valueChar_);
    valueDouble_ = static_cast<double>(valueChar_);
}

void ScalarConverter::ConvertInt(char const *value) {
  long tmp = strtol(value, NULL, 10);
  if (errno || tmp > INT_MAX || tmp < INT_MIN)
    validity_[static_cast<int>(ValueType::INT)] = ValueValidity::INVALID;
  else
    valueInt_ = static_cast<int>(tmp);
  if (ValueValidity::VALID == validity_[static_cast<int>(ValueType::INT)]
      && (valueInt_ >= 0 && valueInt_ <= CHAR_MAX))
    valueChar_ = static_cast<char>(valueInt_);
  else
    validity_[static_cast<int>(ValueType::CHAR)] = ValueValidity::INVALID;
  if (ValueValidity::INVALID == validity_[static_cast<int>(ValueType::INT)]) {
    valueFloat_ = strtof(value, NULL);
    if (errno)
      validity_[static_cast<int>(ValueType::FLOAT)] = ValueValidity::INVALID;
  }  else {
    valueFloat_ = static_cast<float>(valueInt_);
  }
  if (ValueValidity::INVALID == validity_[static_cast<int>(ValueType::INT)]) {
    valueDouble_ = strtod(value, NULL);
    if (errno)
      validity_[static_cast<int>(ValueType::DOUBLE)] = ValueValidity::INVALID;
  } else {
    valueDouble_ = static_cast<double>(valueInt_);
  }
}

void ScalarConverter::ConvertFloat(char const *value) {
  valueFloat_ = strtof(value, NULL);
  if (errno) {
    validity_[static_cast<int>(ValueType::CHAR)] = ValueValidity::INVALID;
    validity_[static_cast<int>(ValueType::INT)] = ValueValidity::INVALID;
    validity_[static_cast<int>(ValueType::FLOAT)] = ValueValidity::INVALID;
    valueDouble_ = strtod(value, NULL);
    if (errno)
      validity_[static_cast<int>(ValueType::FLOAT)] = ValueValidity::INVALID;
  } else {
    if (valueFloat_ >= 0 && valueFloat_ <= CHAR_MAX)
      valueChar_ = static_cast<char>(valueFloat_);
    else
      validity_[static_cast<int>(ValueType::CHAR)] = ValueValidity::INVALID;
    if (valueFloat_ >= INT_MIN && valueFloat_ <= INT_MAX)
      valueInt_ = static_cast<int>(valueFloat_);
    else
      validity_[static_cast<int>(ValueType::INT)] = ValueValidity::INVALID;
    valueDouble_ = static_cast<double>(valueFloat_);
  }
}

void ScalarConverter::ConvertDouble(char const *value) {
  valueDouble_ = strtod(value, NULL);
  if (errno) {
    validity_[static_cast<int>(ValueType::CHAR)] = ValueValidity::INVALID;
    validity_[static_cast<int>(ValueType::INT)] = ValueValidity::INVALID;
    validity_[static_cast<int>(ValueType::FLOAT)] = ValueValidity::INVALID;
    validity_[static_cast<int>(ValueType::DOUBLE)] = ValueValidity::INVALID;
  } else {
    if (valueDouble_ >= 0 && valueDouble_ <= CHAR_MAX)
      valueChar_ = static_cast<char>(valueDouble_);
    else
      validity_[static_cast<int>(ValueType::CHAR)] = ValueValidity::INVALID;
    if (valueDouble_ >= INT_MIN && valueDouble_ <= INT_MAX)
      valueInt_ = static_cast<int>(valueDouble_);
    else
      validity_[static_cast<int>(ValueType::INT)] = ValueValidity::INVALID;
    if (valueDouble_ >= FLT_MIN && valueDouble_ <= FLT_MAX)
      valueFloat_ = static_cast<double>(valueDouble_);
    else
      validity_[static_cast<int>(ValueType::FLOAT)] = ValueValidity::INVALID;
  }
}

int ScalarConverter::Convert(char const *value) {
  if (ValueType::CHAR == type_)
    ConvertChar(value);
  else if (ValueType::INT == type_)
    ConvertInt(value);
  else if (ValueType::FLOAT == type_ | ValueType::SPECIAL == type_)
    ConvertFloat(value);
  else
    ConvertDouble(value);
}

void ScalarConverter::PrintChar(void) const {
  std::cout << "char: ";
  if (ValueValidity::VALID == validity_[static_cast<int>(ValueType::CHAR)]) {
    if (isprint(valueChar_))
      std::cout << valueChar_;
    else
      std::cout << "non-printable";
  } else {
    std::cout << "impossible";
  }
  std::cout << std::endl;
}

void ScalarConverter::PrintInt(void) const {
    std::cout << "int: ";
  if (ValueValidity::VALID == validity_[static_cast<int>(ValueType::INT)])
    std::cout << valueInt_;
  else
    std::cout << "impossible";
  std::cout << std::endl;
}

void ScalarConverter::PrintFloat(void) const {
  std::cout << "float: ";
  if (ValueValidity::VALID == validity_[static_cast<int>(ValueType::FLOAT)])
    std::cout << std::fixed << std::setprecision(1) << valueFloat_ << 'f';
  else
    std::cout << "impossible";
  std::cout << std::endl;
}

void ScalarConverter::PrintDouble(void) const {
  std::cout << "double: ";
  if (ValueValidity::VALID == validity_[static_cast<int>(ValueType::DOUBLE)])
    std::cout << std::setprecision(1) << valueDouble_;
  else
    std::cout << "impossible";
  std::cout << std::endl;
}

void ScalarConverter::Print(void) const {
  PrintChar();
  PrintInt();
  PrintFloat();
  PrintDouble();
}
