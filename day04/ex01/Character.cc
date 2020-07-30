// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Character.h"

Character::Character(std::string const &name)
    : name_(name) , ap_(40), weapon_(nullptr) {
}

Character::Character(Character const &other)
    : name_(other.Name()), ap_(other.AP()), weapon_(other.Weapon()) {
}

Character::~Character(void) {
}

Character& Character::operator=(Character const &rhs) {
  if (&rhs == this)
    return *this;
  name_ = rhs.Name();
  ap_ = rhs.AP();
  weapon_ = rhs.Weapon();
  return *this;
}

std::string const& Character::Name(void) const {
  return name_;
}

int Character::AP(void) const {
  return ap_;
}

AWeapon *Character::Weapon(void) const {
  return weapon_;
}

void Character::RecoverAP(void) {
  int ap;
  if ((ap = ap_ + 10) > 40)
    ap_ = 40;
  else
    ap_ = ap;
}

void Character::Equip(AWeapon *weapon) {
  weapon_ = weapon;
}

void Character::Attack(Enemy *enemy) {
  if (!weapon_ || ap_ < weapon_->APCost())
    return;
  ap_ -= weapon_->APCost();
  std::cout << name_ << " attacks " << enemy->Type()
            << " with a " << weapon_->Name() << std::endl;
  weapon_->Attack();
  enemy->TakeDamage(weapon_->Damage());
  if (enemy->HP() <= 0)
    delete enemy;
}

std::ostream& operator<<(std::ostream &os, Character const &in) {
  os << in.Name() << " has " << in.AP() << " and ";
  if (in.Weapon())
    os << "wields a " << (in.Weapon())->Name();
  else
    os << "is unarmed";
  os << std::endl;
  return os;
}
