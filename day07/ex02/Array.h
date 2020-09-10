// Copyright 2020 kkozlov

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdexcept>

#ifndef NULL
#define NULL ((void *)0)
#endif

template<typename T>
class Array {
 public:
  Array(void);
  explicit Array(unsigned n);
  Array(Array const &other);
  ~Array(void);

  Array &operator=(Array const &rhs);
  T &operator[](std::size_t idx);

  unsigned Size(void) const;
  void PrintElements(void) const;

 private:
  T *array_;
  unsigned size_;

  void CopyArray(Array const &other);
};

template<typename T>
Array<T>::Array(void)
    : array_(NULL), size_(0) {}

template<typename T>
Array<T>::Array(unsigned n)
    : size_(n) {
  array_ = new T[n];
}

template<typename T>
Array<T>::Array(Array const &other)
    : size_(other.size_) {
  this->CopyArray(other);
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &rhs) {
  if (&rhs != this) {
    if (array_)
      delete[] array_;
    this->CopyArray(rhs);
  }
  return *this;
}

template<typename T>
Array<T>::~Array(void) {
  if (array_)
    delete[] array_;
}

template<typename T>
T &Array<T>::operator[](std::size_t idx) {
  if (idx >= size_)
    throw std::out_of_range("idx is out of range");
  return array_[idx];
}

template<typename T>
unsigned Array<T>::Size(void) const {
  return size_;
}

template<typename T>
void Array<T>::PrintElements(void) const {
  unsigned i = -1;
  while (++i < size_)
    std::cout << array_[i] << '\n';
}

template<typename T>
void Array<T>::CopyArray(Array const &other) {
  array_ = new T[size_];
  unsigned i = -1;
  while (++i < size_)
    array_[i] = T(other.array_[i]);
}

#endif  // ARRAY_H_
