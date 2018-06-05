#include <Linkedlist.h>
#include <iostream>

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

LinkedList::~LinkedList() {
  delete head_;
  delete tail_;
}

// Adding a node to the end of the list
void LinkedList::AddNode(int32_t value){
  node* temp = new node();
  temp->data = value;
  temp->next = nullptr;

  // Check if the list is empty
  if(head_ == nullptr){
    // If the list is empty the head and tail will be the same node since it is only a single node list
    head_ = temp;
    tail_ = temp;
  } else{
    // Set the current tail's next to the new node's address
    tail_->next = temp;
    // Then replace the tail with the new node, since the new node is appended to the end of the list
    tail_ = temp;
  }

  size_++;
}

// Loop through the list and print out the data value.
void LinkedList::PrintList(){
  node* temp =head_;

  while(temp != nullptr){
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}


// Inserting a new node at the head of the linked list
void LinkedList::InsertAtStart(int32_t value){
  node* new_node = new node();
  new_node->data = value;
  // Set the address of the next node equal to the head_ then replace the head with the new node
  new_node->next = head_;
  head_ = new_node;

  size_++;
}

// Inserting a new node at a specified position. This function returns false if the position is past the tail
bool LinkedList::InsertAt(int32_t pos, int32_t value){
  if (pos > size_ || pos < 0)
    return false;

  node* current_node = new node();
  node* new_node = new node();
  new_node->data = value;

  // If the postion is at 0 (head) we insert it at the start of the list
  if (pos == 0){
    new_node->next = head_;
    head_ = new_node;
  }
  else {
    current_node = head_;

    // Iterating through the list to one node before the specified position
    for (int32_t index = 1; index < pos; index++){
      current_node = current_node->next;
    }

    // The next address that the new node should point to is the next address of the current node position
    new_node->next = current_node->next;
    // we then add our new node to the current location
    current_node->next = new_node;
    current_node = new_node;
  }

  size_++;
  return true;
}

// Deleting the head node
void LinkedList::DeleteHead(){
  node* temp = head_;
  head_ = temp->next;
  delete temp;

  size_--;
}

// Deleting the tail node
void LinkedList::DeleteTail(){
  // If the list is empty return
  if (tail_ == nullptr)
    return;

  if (size_ == 1) {
    node* temp = head_;
    node* temp2 = tail_;
    head_ = nullptr;
    tail_ = nullptr;
    // Memory clean up
    delete temp;
    delete temp2;
  }
  else{
    node* current_node = head_;
    for (int32_t i = 1; i < size_ - 1; ++i){
      current_node = current_node->next;
    }
    node* temp = current_node->next;
    current_node->next = nullptr;
    tail_ = current_node;
    delete temp;
  }
  size_--;
}

// Delete a specified postion in the linked list. This function returns false if the postion is negative or past the tail.
bool LinkedList::DeleteAt(int32_t pos){
  if (pos > size_ || pos < 0)
    return false;

  if(pos == 0){
    DeleteHead();
  }
  else{
    node* current = new node();
    node* previous = new node();
    current = head_;

    for (int32_t i = 0; i < pos; ++i){
      previous = current;
      current = current->next;
    }
    previous->next = current->next;
    size_--;
  }

  return true;
}


// Delete a specific data value in the linked list. This function returns false if the value is not in the list.
bool LinkedList::DeleteValue(int32_t value){
  node* current = new node();
  node* previous = new node();
  current = head_;

  // Case where the value is at the first position in the list
  if (current->data == value){
    DeleteHead();
    return true;
  }
  else{
    for (int32_t i = 1; i < size_; ++i){
      previous = current;
      current = current->next;

      if (current->data == value){
        previous->next = current->next;
        delete current;
        size_--;
        return true;
      }
    }
  }

  return false;
}
