#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <QueueInterface.h>
/***************************************************************************************************************************************************************
 * DESCRIPTION: A Queue is an abstract data type that allows adding and removing elements in a particular order. A Queue object is said to be a FIFO
 *              (First In First Out) storage object.
 *
 * IMPLEMENTATIONS: The underlying structure of a queue can be an array, a linked list or even stacks. This implementation will be a circular queue array
 *                  implementation.
 *
 * ************************************************************************************************************************************************************/


class Queue : QueueInterface {
public:
  Queue(int32_t capacity);
  virtual ~Queue();

  // This function inserts value into the queue. If the queue is at max capacity it will return false.
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
  bool IsFull();

  int32_t* queue_;      // Queue Array
  int32_t front_index_;
  int32_t rear_index_;
  int32_t capacity_;
  int32_t size_;
  int32_t front_;
  int32_t rear_;
};

#endif //QUEUE_H
