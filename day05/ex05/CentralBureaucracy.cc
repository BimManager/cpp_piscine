// Copyright 2020 kkozlov

#include <iostream>
#include <string>

#include "CentralBureaucracy.h"

CentralBureaucracy::CentralBureaucracy(void) {
  int i = -1;
  while (++i < N_BLOCKS) {
    blocks_[i].SetIntern(new Intern());
  }
}

CentralBureaucracy::~CentralBureaucracy(void) {
  int i = -1;
  while (++i < N_BLOCKS) {
    delete blocks_[i].GetIntern();
  }
}

void CentralBureaucracy::FeedBureaucrat(Bureaucrat *bureaucrat) {
  if (iEmptyBlock_ == N_BLOCKS) {
    std::cout << "Central Bureaucracy is jam-packed. No more bureaucrats."
              << std::endl;
    return;
  }
  blocks_[iEmptyBlock_].SetBureaucrat(bureaucrat);
  if (blocks_[iEmptyBlock_].IsFull()) {
    ++iEmptyBlock_;
  }
}

void CentralBureaucracy::DoBureaucracy(void) {
  int i;
  std::string target;
  char const **formNames;

  srand(clock());
  formNames = Intern::GetFormNames();
  while (!queue_.IsEmpty()) {
    target = queue_.Dequeue();
    i = -1;
    while (++i < iEmptyBlock_) {
      blocks_[i].DoBureaucracy(formNames[rand() % N_FORMS], target);
    }
  }
}

void CentralBureaucracy::QueueUp(std::string const &target) {
  queue_.Enqueue(target);
}

void CentralBureaucracy::QueuePrint(void) const {
  queue_.Print();
}

CentralBureaucracy::Queue::Node::Node(std::string const &data)
    : data_(data), next_(0) {}

CentralBureaucracy::Queue::Node::~Node(void) {}

CentralBureaucracy::Queue::Node
*CentralBureaucracy::Queue::Node::GetNext(void) const {
  return next_;
}

std::string CentralBureaucracy::Queue::Node::GetData(void) const {
  return data_;
}

void CentralBureaucracy::Queue::Node::SetNext(
    CentralBureaucracy::Queue::Node *node) {
  next_ = node;
}

void CentralBureaucracy::Queue::Node::SetData(std::string const &data) {
  data_ = data;
}

CentralBureaucracy::Queue::Queue(void)
    : head_(0), tail_(0) {}

CentralBureaucracy::Queue::~Queue(void) {
  CentralBureaucracy::Queue::Node *it;
  CentralBureaucracy::Queue::Node *del;

  it = head_;
  while (it) {
    del = it;
    it = it->GetNext();
    delete del;
  }
}

int CentralBureaucracy::Queue::IsEmpty(void) const {
  return 0 == head_;
}

void CentralBureaucracy::Queue::Enqueue(std::string const &data) {
  CentralBureaucracy::Queue::Node *node;

  node = new Node(data);
  if (!head_)
    head_ = node;
  else
    tail_->SetNext(node);
  tail_ = node;
}

std::string CentralBureaucracy::Queue::Dequeue(void) {
  CentralBureaucracy::Queue::Node *node;

  if (this->IsEmpty())
    return (NULL);
  node = head_;
  if (head_ == tail_)
    tail_ = 0;
  head_ = node->GetNext();
  std::string data = node->GetData();
  delete node;
  return data;
}

void CentralBureaucracy::Queue::Print(void) const {
  CentralBureaucracy::Queue::Node *it;

  it = head_;
  while (it) {
    std::cout << it->GetData();
    it = it->GetNext();
  }
}
