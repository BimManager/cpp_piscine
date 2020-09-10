// Copyright 2020 kkozlov

template<typename T>
Array<T>::Array(void)
    : array_(NULL), size_(0) {}

template<typename T>
Array<T>::Array(unsigned n)
    : size_(0) {
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
void Array<T>::CopyArray(Array const &other) {
  array_ = new T[size_];
  unsigned i = -1;
  while (++i < size_)
    array_[i] = T(other[i]);
}

void TemporaryFunction(void) {
  Array<int> array;
}

