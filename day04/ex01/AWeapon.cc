// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "AWeapon.h"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
    : name_(name), apcost_(apcost), damage_(damage) {
}

AWeapon::AWeapon(AWeapon const &other)
    : name_(other.Name()), apcost_(other.APCost()), damage_(other.Damage()) {
}

AWeapon::~AWeapon(void) {
}

AWeapon& AWeapon::operator=(AWeapon const &rhs) {
  if (&rhs == this)
    return *this;
  name_ = rhs.Name();
  apcost_ = rhs.APCost();
  damage_ = rhs.Damage();
  return *this;
}

std::string const& AWeapon::Name(void) const {
  return name_;
}

int AWeapon::APCost(void) const {
  return apcost_;
}

int AWeapon::Damage(void) const {
  return damage_;
}

void AWeapon::SetName(std::string const &name) {
  name_ = name;
}

void AWeapon::SetAPCost(int apcost) {
  apcost_ = apcost;
}

void AWeapon::SetDamage(int damage) {
  damage_ = damage;
}

std::ostream& operator<<(std::ostream &os, AWeapon const &in) {
  os << in.Name() << ' ' << in.APCost() << ' ' << in.Damage() << std::endl;
  return os;
}
