#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <StackInterface.h>
/***************************************************************************************************************************************************************
 * DESCRIPTION: A Stack is an abstract data type that allows adding and removing elements in a particular order. Every time an element is added, that element
 *              goes to the top of the stack.  The only element that can be removed is the element that is at the top of the stack. A Stack object is said to
 *              be a FILO (First In Last Out) or LIFO (Last In First Out) storage object.
 *
 * IMPLEMENTATIONS: A stack can be implemented as either an array or a linked list. This implementation will be an array implementation. Also the values being
 *                  stored on the stack will be interger values.
 *
 * ************************************************************************************************************************************************************/


class Stack : StackInterface {
public:
  Stack(int32_t capacity);
  virtual ~Stack();

  // This function Pushes value onto the stack. If the stack is at max capacity it will return false. Else it will return true.
  virtual bool Push(int32_t value);

  // This function Pops the value off of the top of the stack.
  virtual int32_t Pop();

  // This function will return the value on top of the stack without poping it off the stack.
  virtual int32_t Peek();

  // This function checks to see if the stack is emepty.
  virtual bool IsEmpty();

  // This function will print all of the values in the stack
  void PrintStack();

private:
  int32_t* stack_;
  int32_t stack_index_;
  int32_t capacity_;
};

#endif //STACK_H
