// Copyright 2020 kkozlov

#include <string>
#include <iostream>

#include "Enemy.h"

Enemy::Enemy(int hp, std::string const &type)
    : hp_(hp), type_(type) {
}

Enemy::Enemy(Enemy const &other)
    : hp_(other.HP()), type_(other.Type()) {
}

Enemy::~Enemy(void) {
}

Enemy& Enemy::operator=(Enemy const &rhs) {
  if (&rhs == this)
    return *this;
  hp_ = rhs.HP();
  type_ = rhs.Type();
  return *this;
}

std::string const& Enemy::Type(void) const {
  return type_;
}

int Enemy::HP(void) const {
  return hp_;
}

void Enemy::SetType(std::string const &type) {
  type_ = type;
}

void Enemy::SetHP(int hp) {
  hp_ = hp;
}

void Enemy::TakeDamage(int sub) {
  if (hp_ < 0)
    return;
  hp_ -= sub;
}

std::ostream& operator<<(std::ostream &os, Enemy const &in) {
  os << in.Type() << ' ' << in.HP() << std::endl;
  return os;
}
