#include <QueueLL.h>
#include <iostream>
#include <limits>

QueueLL::QueueLL() : head_(nullptr), tail_(nullptr)
{
}

QueueLL::~QueueLL(){
  delete head_;
  delete tail_;
}

bool QueueLL::Enqueue(int32_t value){

  // If the queue is empty head and tail will share the same value
  if(head_ == nullptr){
    Node* new_node = new Node();
    new_node->data = value;
    new_node->prev =nullptr;
    head_= new_node;
    tail_ = head_;
  }
  else{
    Node* new_tail = new Node();
    new_tail->data = value;
    new_tail->prev = nullptr;

    tail_->prev = new_tail;
    tail_= new_tail;
  }

  return true;
}

int32_t QueueLL::Dequeue(){
  if(head_ == nullptr){
    return std::numeric_limits<int32_t>::min();
  }

  int32_t return_value = head_->data;
  if (head_ == tail_){
    Node* delete_node = head_;
    head_ = nullptr;
    tail_ = nullptr;
    delete delete_node;
  }
  else{
    Node* delete_node = head_;
    head_ = head_->prev;
    delete delete_node;
  }

  return return_value;
}

int32_t QueueLL::PeekFront(){
  if(head_ == nullptr) {
    return std::numeric_limits<int32_t>::min();
  }

  return head_->data;
}

int32_t QueueLL::PeekRear(){
  if (tail_ == nullptr){
    return std::numeric_limits<int32_t>::min();
  }

  return tail_->data;
}

bool QueueLL::IsEmpty(){
  if (head_ == nullptr){
    return true;
  }

  return false;
}

void QueueLL::PrintQueue(){
  Node* temp = head_;
  while (temp != nullptr){
    std::cout << temp->data << " ";
    temp=temp->prev;
  }
  std::cout << std::endl;
}
