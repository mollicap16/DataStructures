#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: This class will implement the quick sort algorithm. This sort algorithm is more efficient than Bubble, Insertion, and Selection sort.
 *
 **************************************************************************************************************************************************************/

class MergeSort {
public:
  MergeSort();
  ~MergeSort();

  void merge_sort(int32_t array[], int32_t left, int32_t right);
private:
  void merge(int32_t array[], int32_t left, int32_t middle, int32_t right);
};

#endif //MERGESORT_H
