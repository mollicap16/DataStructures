#include <iostream>
#include <MinHeap.h>

int main(){

  std::cout << "Hello World" << std::endl;

  // Min heap of 10 elements
  MinHeap min_heap(10);

  // Testing Min heap Insert
  min_heap.InsertKey(12);
  min_heap.PrintArray();
  min_heap.InsertKey(11);
  min_heap.PrintArray();
  min_heap.InsertKey(10);
  min_heap.PrintArray();
  min_heap.InsertKey(50);
  min_heap.PrintArray();
  min_heap.InsertKey(5);
  min_heap.PrintArray();
  min_heap.InsertKey(1);
  min_heap.PrintArray();
  min_heap.InsertKey(100);
  min_heap.PrintArray();
  min_heap.InsertKey(-10);
  min_heap.PrintArray();
  min_heap.InsertKey(500);
  min_heap.PrintArray();
  min_heap.InsertKey(-10);
  min_heap.PrintArray();
  std::cout << std::endl;

  // Testing Extract Min
  min_heap.ExtractMin();
  min_heap.PrintArray();
  std::cout << std::endl;
  min_heap.ExtractMin();
  min_heap.PrintArray();
  std::cout << std::endl;
  min_heap.ExtractMin();
  min_heap.PrintArray();
  std::cout << std::endl;

  std::cout << "=====================================================================================" << std::endl;

  // Min Heap of 20 elements
  MinHeap min_heap2(20);

  min_heap2.InsertKey(12);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(11);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(10);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(50);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(5);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(1);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(100);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(-10);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(500);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(-10);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(-100);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.InsertKey(350);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();

  // Testing Delete Value
  min_heap2.DeleteValue(100);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.DeleteValue(111);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.DeleteValue(-10);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();
  min_heap2.DeleteValue(5);
  min_heap2.PrintArray();
  min_heap2.PrintHeap();

  return 0;
}
