// queue.hpp

#pragma once

#include "../linked-list/linked-list.hpp"

class Queue : protected LinkedList {
  public:
    void enqueue(int);
    int dequeue(void);
    int peek(void);
};
