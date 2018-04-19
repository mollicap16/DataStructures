#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>

/***************************************************************************************************************************************************************
 *
 * DESCRIPTION: A Binary Heap is implementated as a binary tree with the following properties:
 *                  1) It's a complete tree (All leafs in  each level are full with the possible exception of the last level.
 *                  2) A Binary Heap can be either a Min Heap or Max Heap. Where the root is either the min or max respectively.
 *              A Binary Heap is typically reprsented as an array. And the traversal method used to achieve array representation is level order.
 *
 *              This Class is an implementation of the Integer Min Heap. Note we are implementing the array representation by starting the index at 1.
 *
 * REFERENCES:
 *    1) https://www.geeksforgeeks.org/binary-heap/
 *    2) https://www.geeksforgeeks.org/array-representation-of-binary-heap/
 *
 * APPLICATIONS:
 *    1) Heap Sort.
 *    2) Priority Queue.
 *    3) Graph Algorithms.
 *    4) Kth Largest element in an array.
 *    5) Sort an almost sorted array
 *    6) Merge K sorted arrays.
 * ************************************************************************************************************************************************************/


class MinHeap {
public:
  MinHeap(int capacity);
  ~MinHeap();

  // Returns the Minimum value
  int32_t GetMin() {return heap_array_[1]; }

  // Inserts a new key
  void InsertKey(int32_t key);

  // Removes the minimum element from Min Heap. Time Complexity is O(logN) since we need to restore the heap after removing the root (min-heapify).
  // Implemented without recursion but can be implemented with recursion
  int32_t ExtractMin();

  // Delete Specific value. Returns false if the value is not found in the heap
  bool DeleteValue(int32_t value);

  // Print out the full array up to it's capacity
  void PrintArray();

  // Print out the Heap in array representation
  void PrintHeap();

  // Return size of heap
  int32_t GetSize() {return heap_size_;}

private:
  // Returning the parent nodes array index.
  int32_t partent(int32_t index) { return index / 2; }

  // Returning the left node array index
  int32_t left(int32_t index) {return 2 * index; }

  // Returning the right node array index
  int32_t right(int32_t index) {return 2 * index + 1; }

  // to heapify a subtree with root at a given index
  void MinHeapify(int32_t parent_index);

  // Swap function
  void Swap(int32_t* x, int32_t* y);

  int32_t* heap_array_;
  int32_t capacity_;     // Maximum possible size of min heap
  int32_t heap_size_;    // Current number of elements in the heap
};

#endif //MIN_HEAP_H
