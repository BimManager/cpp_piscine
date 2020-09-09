// Copyright 2020 kkozlov

#ifndef SCALARCONVERTER_H_
#define SCALARCONVERTER_H_

#include <climits>
#include <cfloat>

#include <string>
#include <iostream>
#include <iomanip>

class ScalarConverter {
 public:
  explicit ScalarConverter(char const *value);
  ~ScalarConverter(void);

  char GetValueChar(void) const;
  int GetValueInt(void) const;
  float GetValueFloat(void) const;
  double GetValueDouble(void) const;

  void Print(void) const;
  void PrintChar(void) const;
  void PrintInt(void) const;
  void PrintFloat(void) const;
  void PrintDouble(void) const;

 private:
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(ScalarConverter const &rhs);

  int IsSpecialValue(char const *value);
  void ConvertChar(char const *value);
  void ConvertInt(char const *value);
  void ConvertFloat(char const *value);
  void ConvertDouble(char const *value);
  int Convert(char const *value);

  enum class ValueType {
    CHAR, INT, FLOAT, DOUBLE, SPECIAL
  };

  enum class ValueValidity {
    VALID, INVALID
  };

  ValueType type_;
  ValueValidity validity_[4];
  char valueChar_;
  int valueInt_;
  float valueFloat_;
  double valueDouble_;
  static char const *specialValues_[];
  static int const kNbSpecialValues_;
};

#endif  // SCALARCONVERTER_H_
