// Copyright 2020 kkozlov

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(void);
  ~MutantStack(void);
  MutantStack(MutantStack const &other);
  MutantStack &operator=(MutantStack const &rhs);

 private:
  struct Node {
    Node(void);
    explicit Node(T const &data);

    Node *next;
    Node *prev;
    T data;
  };

 public:
  class iterator : public std::iterator<std::bidirectional_iterator_tag,
                                        T, void, T*, T&> {
   public:
    explicit iterator(Node *head);
    ~iterator(void);
    iterator &operator++(void);
    iterator &operator--(void);
    T &operator*(void);
    bool operator==(iterator const &rhs) const;
    bool operator!=(iterator const &rhs) const;

   private:
    Node *it_;
  };

  void push(const T &value);
  void pop(void);

  iterator begin(void) const;
  iterator end(void) const;

 private:
  Node *head_;

  void CopyNodes(Node *head);
  void DeleteNodes(Node *head);
};

template<typename T>
MutantStack<T>::MutantStack(void)
    : head_(NULL) {}

template<typename T>
MutantStack<T>::~MutantStack(void) {
  DeleteNodes(head_);
  head_ = NULL;
}

template<typename T>
MutantStack<T>::Node::Node(void)
    : next(NULL), prev(NULL) {}

template<typename T>
MutantStack<T>::Node::Node(T const &data)
    : next(NULL), prev(NULL), data(data) {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &rhs) {
  CopyNodes(rhs.head_);
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs) {
  if (&rhs != this) {
    DeleteNodes(head_);
    CopyNodes(rhs.head_);
  }
  return *this;
}

template<typename T>
void MutantStack<T>::push(T const &value) {
  Node *node = new Node(value);
  node->next = head_;
  if (head_)
    head_->prev = node;
  head_ = node;
  std::stack<T>::push(value);
}

template<typename T>
void MutantStack<T>::pop(void) {
  if (head_ != NULL) {
    std::stack<T>::pop();
    Node *tmp = head_;
    head_ = head_->next;
    delete tmp;
  }
}

template<typename T>
void MutantStack<T>::CopyNodes(Node *head) {
  Node *prev = NULL;
  Node **it = &head_;
  while (head) {
    *it = new Node(head->data);
    if (prev)
      (*it)->prev = prev;
    prev = *it;
    it = &((*it)->next);
    head = head->next;
  }
}

template<typename T>
void MutantStack<T>::DeleteNodes(Node *head) {
  Node *tmp;

  while (head) {
    tmp = head;
    head = head->next;
    delete tmp;
  }
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) const {
  return iterator(head_);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) const {
  return iterator(NULL);
}

template<typename T>
MutantStack<T>::iterator::iterator(Node *head)
    : it_(head) {}

template<typename T>
MutantStack<T>::iterator::~iterator(void) {}

template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++(void) {
  assert(it_ != NULL);
  it_ = it_->next;
  return *this;
}

template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--(void) {
  assert(it_ != NULL);
  if (it_->prev)
    it_ = it_->prev;
  return *this;
}

template<typename T>
T &MutantStack<T>::iterator::operator*(void) {
  assert(it_ != NULL);
  return it_->data;
}

template<typename T>
bool MutantStack<T>::iterator::operator==(iterator const &rhs) const {
  return it_ == rhs.it_;
}

template<typename T>
bool MutantStack<T>::iterator::operator!=(iterator const &rhs) const {
  return !(it_ == rhs.it_);
}

#endif  // MUTANTSTACK_H
