#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: This class will implement the quick sort algorithm. This sort algorithm is more efficient than Bubble, Insertion, and Selection sort.
 *
 **************************************************************************************************************************************************************/

class QuickSort {
public:
  QuickSort();
  ~QuickSort();

  void quick_sort(int32_t array[], int32_t low, int32_t high);
private:
  int32_t partition(int32_t array[], int32_t low, int32_t high);
  void swap(int32_t* a, int32_t* b);
};

#endif //QUICKSORT_H
