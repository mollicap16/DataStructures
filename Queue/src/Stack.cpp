#include <Stack.h>
#include <iostream>

Stack::Stack() : head_(nullptr)
{
}

Stack::~Stack(){
  delete head_;
}

bool Stack::Push(int32_t value){
  // Creating a new node and pushing it to the top of the list.
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = head_;
  head_ = new_node;

  return true;
}

int32_t Stack::Pop(){
  int32_t ret_value;
  if(IsEmpty()){
    ret_value = INT_MIN;
  }
  else {
    // Pop the head node off of the list
    Node* temp_node = head_;
    head_ = temp_node->next;
    ret_value = temp_node->data;

    delete temp_node;
  }

  return ret_value;
}

int32_t Stack::Peek(){
  if (IsEmpty()){
    std::cout << "The Stack is Empty!!!!" << std::endl;
    return INT_MIN;
  }

  return head_->data;
}


bool Stack::IsEmpty() {
  if(head_ == nullptr) {
    return true;
  }
  else {
    return false;
  }
}

void Stack::PrintStack(){
  Node* temp_node = head_;
  while(temp_node != nullptr){
    std::cout << temp_node->data << " ";
    temp_node=temp_node->next;
  }
  std::cout << std::endl;
}
