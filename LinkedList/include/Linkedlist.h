#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>

/***************************************************************************************************************************************************************
 * DESCRIPTION: A Linked List is a data structure that can store an undefined amout of items (of course limited to the amount of memory). The items in the list
 *              are connected using pointers to the next node in the list.
 *
 * IMPLEMENTATION: This is an example of a singly linked list.
 * ************************************************************************************************************************************************************/

struct node {
  int32_t data;
  node* next;
};

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  void AddNode(int32_t value); // Might want this to be private.
  void PrintList(); // Print data in linked list
  void InsertAtStart(int32_t value);
  bool InsertAt(int32_t pos, int32_t value); // Position is a zero based index
  void DeleteHead();
  void DeleteTail();
  bool DeleteAt(int32_t pos); // Position is a zero based index
  bool DeleteValue(int32_t value);

  int32_t GetSize(){ return size_; }
private:
  void traverse();

  node* head_;
  node* tail_;
  int32_t size_;
};

#endif //LINKEDLIST_H
