#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include <iostream>
#include <QueueInterface.h>
#include <Stack.h>
/***************************************************************************************************************************************************************
 * DESCRIPTION: A Queue is an abstract data type that allows adding and removing elements in a particular order. A Queue object is said to be a FIFO
 *              (First In First Out) storage object.
 *
 * IMPLEMENTATIONS: The underlying structure of a queue can be an array, a linked list or even stacks. This implementation of this queue class will be done
 *                  with multiple stacks.
 *
 * ************************************************************************************************************************************************************/

class QueueStack : QueueInterface {
public:
  QueueStack();
  virtual ~QueueStack();

  // This function inserts value into the queue.
  virtual bool Enqueue(int32_t value);

  // This function returns and removes the first element in the queue. If there isn't any elements in the queue it returns the smallest possible int32_t value.
  virtual int32_t Dequeue();

  // This function will return the value at the front of the queue. If there isn't any elements in the queue it returns the smallest possible int32_t value.
  virtual int32_t PeekFront();

  // This function will return the value at the back of the queue. If there isn't any elements in the queue it returns the smallest possible int32_t value.
  virtual int32_t PeekRear();

  // This function checks to see if the queue is emepty. If it is empty it returns true.
  virtual bool IsEmpty();

  // This function will print all of the values in the queue
  void PrintQueue();

private:
  Stack stack_1_;
  Stack stack_2_;
  int32_t front_;
  int32_t rear_;

};

#endif //QUEUESTACK_H
