#include <Queue.h>
#include <iostream>
#include <limits>

Queue::Queue(int32_t capacity) : queue_(new int32_t[capacity]), front_index_(0), rear_index_(0),
                                 capacity_(capacity), size_(0), front_(std::numeric_limits<int32_t>::min()),
                                 rear_(std::numeric_limits<int32_t>::min())
{
}

Queue::~Queue(){
  delete queue_;
}

bool Queue::Enqueue(int32_t value){
  if(IsFull()){
    return false;
  }

  // Add element to the end of the queue
  queue_[rear_index_] = value;
  rear_ = value;
  front_ = queue_[front_index_];
  rear_index_ = (rear_index_ + 1) % capacity_;
  size_++;
  return true;
}

int32_t Queue::Dequeue(){
  if(IsEmpty()){
    return std::numeric_limits<int32_t>::min();
  }

  int32_t return_value = queue_[front_index_];
  front_index_ = (front_index_ + 1) % capacity_;
  front_ = queue_[front_index_];
  size_--;
  return return_value;
}

int32_t Queue::PeekFront(){
  if (IsEmpty()){
    front_ = std::numeric_limits<int32_t>::min();
    rear_ = std::numeric_limits<int32_t>::min();
  }

  return front_;
}

int32_t Queue::PeekRear(){
  if (IsEmpty()){
    front_ = std::numeric_limits<int32_t>::min();
    rear_ = std::numeric_limits<int32_t>::min();
  }

  return rear_;
}

bool Queue::IsEmpty(){
  if(size_ == 0){
    return true;
  }

  return false;
}

void Queue::PrintQueue(){
  for (int32_t i = 0; i < capacity_; ++i){
    std::cout << queue_[i] << " ";
  }
  std::cout << std::endl;
}

bool Queue::IsFull(){
  if(size_ == capacity_){
    return true;
  }

  return false;
}
