// Copyright 2020 kkozlov

#include "Squad.h"

Squad::Squad(void)
    : capacity_(INIT_CAPACITY), count_(0) {
  marines_ = static_cast<ISpaceMarine **>(
      operator new[](capacity_ * sizeof(void *)));
}

Squad::Squad(Squad const &other)
    : capacity_(other.capacity_), count_(other.Count()) {
  int i = other.Count();
  marines_ = static_cast<ISpaceMarine **>(
      operator new[](capacity_ * sizeof(void *)));
  while (i--) {
    Push((other.Unit(i))->Clone());
  }
}

Squad::~Squad(void) {
  while (count_--) {
    delete Unit(count_);
  }
  operator delete[](marines_);
}

Squad &Squad::operator=(Squad const &rhs) {
  if (&rhs == this) {
    return *this;
  }
  while (count_--) {
    delete Unit(count_);
  }
  operator delete[](marines_);
  count_ = rhs.Count();
  capacity_ = rhs.capacity_;
  marines_ = static_cast<ISpaceMarine **>(
      operator new[](capacity_ * sizeof(void *)));
  int i = count_;
  while (i--)
    Push((rhs.Unit(i))->Clone());
  return *this;
}

int Squad::Count(void) const {
  return count_;
}

ISpaceMarine *Squad::Unit(int i) const {
  if (i >= count_) {
    return 0;
  }
  return marines_[i];
}

int Squad::Push(ISpaceMarine *marine) {
  int i;
  if (count_ == capacity_) {
    capacity_ <<= 1;
    ISpaceMarine **rawMemory = static_cast<ISpaceMarine **>(
        operator new[](capacity_ * sizeof(void *)));
    i = count_;
    while (i--)
      rawMemory[i] = marines_[i];
    operator delete[](marines_);
    marines_ = rawMemory;
  }
  i = count_;
  while (i--)
    if (marines_[i] == marine)
      return count_;
  marines_[count_++] = marine;
  return count_;
}
