// Copyright 2020 kkozlov

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

#define N_FIELDS 11

class Contact {
 public:
  Contact(void);
  ~Contact(void);
  void SetByIndex(int idx, const std::string& data);
  const std::string &GetByIndex(int idx) const;
 private:
  enum FieldNames {
    FirstName, LastName, Nickname,
    Login, PostalAddress, EmailAddress,
    PhoneNumber, BirthdayDate, FavoriteMeal,
    UnderwearColor, DarkestSecret
  };
  std::string fields_[N_FIELDS];
  Contact(const Contact& other);
  Contact& operator=(const Contact& other);
};

#endif  // CONTACT_HPP_
