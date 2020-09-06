// Copyright 2020 kkozlov

#ifndef DAY05_EX05_CENTRALBUREAUCRACY_H_
#define DAY05_EX05_CENTRALBUREAUCRACY_H_

#include <ctime>
#include <string>

#include "Bureaucrat.h"
#include "Intern.h"
#include "OfficeBlock.h"

#define N_BLOCKS 20
#define N_FORMS 3

class CentralBureaucracy {
 public:
  CentralBureaucracy(void);
  ~CentralBureaucracy(void);

  void FeedBureaucrat(Bureaucrat *bureaucrat);
  void DoBureaucracy(void);

  void QueueUp(std::string const &target);
  void QueuePrint(void) const;

 private:
  CentralBureaucracy(CentralBureaucracy const &other);
  CentralBureaucracy &operator=(CentralBureaucracy const &rhs);

  class Queue {
   public:
    Queue(void);
    ~Queue(void);

    int IsEmpty(void) const;
    void Enqueue(std::string const &data);
    std::string Dequeue(void);

    void Print(void) const;

   private:
    class Node {
     public:
      explicit Node(std::string const &data);
      ~Node(void);

      Node *GetNext(void) const;
      std::string GetData(void) const;

      void SetNext(Node *next);
      void SetData(std::string const &data);

     private:
      std::string data_;
      Node *next_;

      Node(Node const &other);
      Node &operator=(Node const &rhs);
    };

    Node *head_;
    Node *tail_;

    Queue(Queue const &other);
    Queue& operator=(Queue const &rhs);
  };

  OfficeBlock blocks_[N_BLOCKS];
  int iEmptyBlock_;
  Queue queue_;
};

#endif  // DAY05_EX05_CENTRALBUREAUCRACY_H_
