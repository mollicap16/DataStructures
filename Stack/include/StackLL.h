#ifndef STACKLL_H
#define STACKLL_H

#include <iostream>
#include <StackInterface.h>

/***************************************************************************************************************************************************************
 * DESCRIPTION: A Stack is an abstract data type that allows adding and removing elements in a particular order. Every time an element is added, that element
 *              goes to the top of the stack.  The only element that can be removed is the element that is at the top of the stack. A Stack object is said to
 *              be a FILO (First In Last Out) or LIFO (Last In First Out) storage object.
 *
 * IMPLEMENTATIONS: A stack can be implemented as either an array or a linked list. This implementation will be a Linked List implementation. Also the values
 *                  being stored on the stack will be interger values.
 *
 * ************************************************************************************************************************************************************/


class StackLL : StackInterface {
public:
  StackLL();
  virtual ~StackLL();

  // This function Pushes a value onto the stack.
  virtual bool Push(int32_t value);

  // This function Pops the value off of the top of the stack.
  virtual int32_t Pop();

  // This function will return the value on top of the stack without poping it off the stack.
  virtual int32_t Peek();

  // This function checks to see if the stack is emepty.
  virtual bool IsEmpty();

  // This function prints all of the elements in the list
  void PrintStack();

private:
  struct Node {
    int32_t data;
    Node* next;
  };

  Node* head_;
};

#endif //STACKLL_H
