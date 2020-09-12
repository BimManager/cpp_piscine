// Copyright 2020 kkozlov

#include <climits>
#include <cstdlib>

#include <stdexcept>
#include <algorithm>

#include "Span.h"

Span::Span(unsigned n)
    : size_(0), capacity_(n) {
  integers_ = new int[n];
}

Span::Span(Span const &other)
    : size_(other.size_), capacity_(other.capacity_) {
  integers_ = new int[capacity_];
  CopyArray(other.integers_, other.size_);
}

Span &Span::operator=(Span const &rhs) {
  if (&rhs != this) {
    delete[] integers_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    integers_ = new int[capacity_];
    CopyArray(rhs.integers_, rhs.size_);
  }
  return *this;
}

int Span::operator[](std::size_t idx) throw(std::out_of_range) {
  if (idx >= size_)
    throw std::out_of_range("index is out of range");
  return integers_[idx];
}

void Span::CopyArray(int *arr, unsigned n) {
  while (n--)
    integers_[n] = arr[n];
}

Span::~Span(void) {
  delete[] integers_;
}

unsigned Span::Size(void) const {
  return size_;
}

void Span::AddNumber(int nb) throw(std::length_error) {
  if (size_ == capacity_)
    throw std::length_error("the array is jam-packed");
  integers_[size_++] = nb;
}

void Span::AddRange(int const *begin, int const *end) throw(std::length_error) {
  if (size_ + (end - begin) > capacity_)
    throw std::length_error("the array is not big enough");
  while (begin < end)
    integers_[size_++] = *begin++;
}

std::size_t Span::ShortestSpan(void) throw(NotEnoughElementsException) {
  if (size_ < 2)
    throw NotEnoughElementsException();
  std::size_t minSpan = LONG_MAX;
  std::size_t currMin;
  unsigned i = 0;
  while (++i < size_) {
    currMin = std::abs(integers_[i - 1] - integers_[i]);
    if (minSpan > currMin)
      minSpan = currMin;
  }
  return minSpan;
}

std::size_t Span::LongestSpan(void) throw(NotEnoughElementsException) {
  if (size_ < 2)
    throw NotEnoughElementsException();
  int *min_p = std::min_element(integers_, integers_ + size_);
  int *max_p = std::max_element(integers_, integers_ + size_);
  return static_cast<std::int64_t>(*max_p) - static_cast<std::int64_t>(*min_p);
}
