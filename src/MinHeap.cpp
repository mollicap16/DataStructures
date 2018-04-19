#include <MinHeap.h>

MinHeap::MinHeap(int capacity) : heap_array_(new int32_t[capacity + 1]), capacity_(capacity), heap_size_(0){
  heap_array_[0] = 0;
}

MinHeap::~MinHeap(){
  delete heap_array_;
}

void MinHeap::InsertKey(int32_t key){
  if(heap_size_ >= capacity_){
    std::cout << "AT FULL CAPACITY \n";
    return;
  }

  // Check to make sure we have room in the array
  heap_array_[heap_size_+1] = key;
  int32_t position = heap_size_ + 1;

  // Perculate up the heap
  while (position > 0 && partent(position) > 0){
    int32_t parent_index = partent(position);

    // If the current key is less than the parents key swap positions if not break from loop
    if (heap_array_[position] < heap_array_[parent_index])
      Swap(&heap_array_[position], &heap_array_[parent_index]);
    else
      break;

    position = parent_index;
  }

  heap_size_++;
}

int32_t MinHeap::ExtractMin() {
  int root = heap_array_[1];

  if(heap_size_ > 1){
    // swap root with last leaf
    Swap(&heap_array_[1], &heap_array_[heap_size_]);
    heap_size_--;

    // Heapify
    MinHeapify(1);

    PrintArray();
  }

  return root;
}

bool MinHeap::DeleteValue(int32_t value){
  bool found_value = false;
  int32_t value_index;

  // loop through heap and search for value
  for (int32_t array_index = 0; array_index < heap_size_; ++array_index){
    if (heap_array_[array_index]  == value){
      found_value = true;
      value_index = array_index;
      break;
    }
  }
  // if we dont find the value in the heap array return false
  if(found_value == false){
    std::cout << "Value not found!" << std::endl;
    return false;
  }

  // Swap last element of heap with value specified
  Swap(&heap_array_[value_index], &heap_array_[heap_size_]);
  heap_size_--;

  // Heapify
  MinHeapify(value_index);

  return true;
}

void MinHeap::PrintArray(){
  for (int32_t index = 0; index < capacity_ + 1; ++index){
    std::cout << " " << heap_array_[index];
  }
  std::cout << std::endl;
}

void MinHeap::PrintHeap(){
  for (int32_t index = 1; index < heap_size_ + 1; ++index){
    std::cout << " " << heap_array_[index];
  }
  std::cout << std::endl;
}

// WE CAN IMPLEMENT THIS RECURSIVELY (Take a look at reference 1 in the header to see the recursive implementation)
void MinHeap::MinHeapify(int32_t index) {
  int32_t parent_index = index;
  int32_t left_index = left(parent_index);
  int32_t right_index = right(parent_index);

  // Restore Heap Properties
  while (left_index <= heap_size_ && right_index <= heap_size_) {
    // If the parrent value is greater than the left or right child swap with the smaller of the two childern.
    if(heap_array_[parent_index] > heap_array_[left_index] || heap_array_[parent_index] > heap_array_[right_index]){
      // Compare left child to the right child
      if (heap_array_[left_index] <= heap_array_[right_index]) {
        Swap(&heap_array_[parent_index], &heap_array_[left_index]);
        parent_index = left(parent_index);
      }
      else{
        Swap(&heap_array_[parent_index], &heap_array_[right_index]);
        parent_index = right(parent_index);
      }

      // Update index
      left_index = left(parent_index);
      right_index = right(parent_index);
    }
    // If the parrent value is smaller than both the left and right child, it is in the right place.
    else {
      break;
    }
  }

}


void MinHeap::Swap(int32_t* x, int32_t* y){
  int32_t temp = *x;
  *x = *y;
  *y = temp;
}
