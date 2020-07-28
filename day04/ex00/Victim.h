// Copyright 2020 kkozlov

#ifndef DAY04_EX00_VICTIM_H_
#define DAY04_EX00_VICTIM_H_

#include <string>
#include <iostream>

class Victim {
 public:
  explicit Victim(std::string const &name);
  Victim(Victim const &other);
  ~Victim(void);

  Victim& operator=(Victim const &rhs);

  std::string const& Name(void) const;

  virtual void GetPolymorphed(void) const;

 private:
  std::string name_;
};

std::ostream& operator<<(std::ostream &os, Victim const &in);

#endif  // DAY04_EX00_VICTIM_H_
