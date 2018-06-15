#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack{
public:
  Stack();
  ~Stack();

  // This function Pushes value onto the stack.
  bool Push(int32_t value);

  // This function Pops the value off of the top of the stack.
  int32_t Pop();

  // This function will return the value on top of the stack without poping it off the stack.
  int32_t Peek();

  // This function checks to see if the stack is emepty.
  bool IsEmpty();

  // This function prints all of the elements in the list
  void PrintStack();

private:
  struct Node {
    int32_t data;
    Node* next;
  };

  Node* head_;
};

#endif //STACK_H
