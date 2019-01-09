#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: This class will implement the Insertion sort algorithm.
 *
 **************************************************************************************************************************************************************/

class InsertionSort {
public:
  InsertionSort();
  ~InsertionSort();

  void insertion_sort(int32_t array[], int32_t n);
};

#endif //INSERTIONSORT_H
