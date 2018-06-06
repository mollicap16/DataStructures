#include <Stack.h>
#include <iostream>

Stack::Stack(int32_t capacity) : stack_(new int32_t[capacity]), stack_index_(-1), capacity_(capacity)
{
}

Stack::~Stack(){
  delete stack_;
}

bool Stack::Push(int32_t value){
  if (stack_index_ + 1 >= capacity_){
    std::cout << "Stack is is at Max capacity!!!!" << std::endl;
    return false;
  }

  // Push onto the array and increase the stack height
  stack_[++stack_index_] = value;

  return true;
}

int32_t Stack::Pop(){
  if(IsEmpty()){
    std::cout << "The stack is empty!!!!" << std::endl;
    return INT_MIN;
  }

  return stack_[stack_index_--];
}

int32_t Stack::Peek(){
  if (IsEmpty()){
    std::cout << "The Stack is Empty!!!!" << std::endl;
    return INT_MIN;
  }

  return stack_[stack_index_];
}


bool Stack::IsEmpty() {
  if(stack_index_ < 0) {
    return true;
  }
  else {
    return false;
  }
}

void Stack::PrintStack(){
  for (int32_t i = 0; i <= stack_index_; ++i){
    std::cout << stack_[i] << " ";
  }
  std::cout << std::endl;
}
