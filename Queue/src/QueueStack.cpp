#include <QueueStack.h>
#include <iostream>
#include <limits>

QueueStack::QueueStack() : stack_1_(), stack_2_(), front_(std::numeric_limits<int32_t>::min()),
                           rear_(std::numeric_limits<int32_t>::min())
{
}

QueueStack::~QueueStack(){
}

bool QueueStack::Enqueue(int32_t value){
  if(stack_1_.IsEmpty()){
    stack_1_.Push(value);
    front_ = value;
    rear_ = value;
  }
  else{
    // Move all elements from stack 1 to stack 2
    while(!stack_1_.IsEmpty()){
      stack_2_.Push(stack_1_.Pop());
    }
    // Push value onto stack 1
    stack_1_.Push(value);

    // Move all elements from stack 2 back to stack 1
    while(!stack_2_.IsEmpty()){
      stack_1_.Push(stack_2_.Pop());
    }

    rear_ = value;
  }

  return true;
}

int32_t QueueStack::Dequeue(){
  if(stack_1_.IsEmpty()){
    return std::numeric_limits<int32_t>::min();
  }

  int32_t return_value = stack_1_.Pop();
  front_ = stack_1_.Peek();

  return return_value;
}

int32_t QueueStack::PeekFront(){
  if (stack_1_.IsEmpty()){
    front_ = std::numeric_limits<int32_t>::min();
    rear_ = std::numeric_limits<int32_t>::min();
  }

  return front_;
}

int32_t QueueStack::PeekRear(){
  if (IsEmpty()){
    front_ = std::numeric_limits<int32_t>::min();
    rear_ = std::numeric_limits<int32_t>::min();
  }

  return rear_;
}

bool QueueStack::IsEmpty(){
  if(stack_1_.IsEmpty()){
    return true;
  }

  return false;
}

void QueueStack::PrintQueue(){
  Stack temp_stack;
  while(!stack_1_.IsEmpty()){
    std::cout << stack_1_.Peek() << " ";
    temp_stack.Push(stack_1_.Pop());
  }
  std::cout << std::endl;

  while(!temp_stack.IsEmpty()){
    stack_1_.Push(temp_stack.Pop());
  }
}

