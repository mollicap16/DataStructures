#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>
#include <QueueInterface.h>
/***************************************************************************************************************************************************************
 * DESCRIPTION: A Queue is an abstract data type that allows adding and removing elements in a particular order. A Queue object is said to be a FIFO
 *              (First In First Out) storage object.
 *
 * IMPLEMENTATIONS: The underlying structure of a queue can be an array, a linked list or even stacks. This implementation will be a Linked List implementation.
 *                  Also the values being stored in the queue will be interger values.
 *
 *    (node)         (node)         (node)
 *    ======         ======         ======
 *   |      |       |      |       |      |
 *   | tail |<------|      |<------| head |
 *   |      |       |      |       |      |
 *    ======         ======         ======
 * ************************************************************************************************************************************************************/


class QueueLL : QueueInterface {
public:
  QueueLL();
  virtual ~QueueLL();

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
  struct Node{
    int32_t data;
    Node* prev;
  };

  Node* head_;
  Node* tail_;
};

#endif //QUEUELL_H
