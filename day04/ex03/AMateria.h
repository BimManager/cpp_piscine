// Copyright 2020 kkozlov

#ifndef DAY04_EX03_AMATERIA_H_
#define DAY04_EX03_AMATERIA_H_

#include <string>

#include "ICharacter.h"

class ICharacter;

class AMateria {
 public:
  explicit AMateria(std::string const &type);
  AMateria(AMateria const &other);
  virtual ~AMateria(void);

  AMateria &operator=(AMateria const &rhs);

  std::string const &Type(void) const;
  unsigned XP(void) const;

  virtual AMateria *Clone(void) const = 0;
  virtual void Use(ICharacter &target);

 protected:
  void SetType(std::string const &type);
  void SetXP(unsigned xp);

 private:
  std::string type_;
  unsigned xp_;
};

#endif  // DAY04_EX03_AMATERIA_H_
