// queue.hpp

#include "../linked-list/linked-list.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue : protected LinkedList {
  public:
    void enqueue(int);
    int dequeue(void);
  
};

#endif