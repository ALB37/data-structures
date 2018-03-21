// stack.hpp

#include "../linked-list/linked-list.hpp"

#ifndef STACK_HPP
#define STACK_HPP

class Stack : protected LinkedList {
  public:
    void push(int);
    int pop(void);
    int peek(void);
};

#endif