// Copyright 2020 kkozlov

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon {
 public:
  explicit Weapon(const std::string& type);
  const std::string& GetType(void) const;
  void SetType(const std::string& newType);
 private:
  std::string type_;

  // Weapon(const Weapon& other);
  Weapon& operator=(const Weapon& other);
};

#endif
