#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: This Class will implement the most basic least efficient sorting algorithm. Just for the purpose of demonstrating a sorting algorithm. The
 *              algorithm we will be implementing is a basic bubble sort. It can only sort arrays of type int32_t. This algorithm runs in O(N^2).
 *
 **************************************************************************************************************************************************************/

class BubbleSort {
public:
  BubbleSort();
  ~BubbleSort();

  void bubble_sort(int32_t array[], int32_t n);
private:
  void swap(int32_t* a, int32_t* b);
};

#endif //BUBBLESORT_H
