// Copyright 2020 kkozlov

#ifndef SPAN_H_
#define SPAN_H_

#include <cstdint>

#include <stdexcept>

class Span {
 public:
  explicit Span(unsigned n);
  Span(Span const &other);
  ~Span(void);

  Span &operator=(Span const &rhs);
  int operator[](std::size_t idx) throw(std::out_of_range);

  unsigned Size(void) const;

  void AddNumber(int nb) throw(std::length_error);
  void AddRange(int const *begin, int const *end) throw(std::length_error);

  std::size_t ShortestSpan(void) throw(NotEnoughElementsException);
  std::size_t LongestSpan(void) throw(NotEnoughElementsException);

 private:
  int *integers_;
  unsigned size_;
  unsigned capacity_;

  void CopyArray(int *arr, unsigned n);

  class NotEnoughElementsException : std::exception {
  };
};

#endif  // SPAN_H_
