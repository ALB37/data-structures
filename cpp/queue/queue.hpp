// queue.hpp
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../linked-list/linked-list.hpp"

class Queue : protected LinkedList {
  public:
    void enqueue(int);
    int dequeue(void);
    int peek(void);
};

#endif