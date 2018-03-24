// stack.hpp

#ifndef STACK_HPP
#define STACK_HPP

#include "../linked-list/linked-list.hpp"

class Stack : protected LinkedList {
  public:
    void push(int);
    int pop(void);
    int peek(void);
};

#endif