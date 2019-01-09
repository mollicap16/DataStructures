#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: This class will implement the selction sort algorithm. This gives us a slight improvement on bubble sort.
 *
 **************************************************************************************************************************************************************/

class SelectionSort {
public:
  SelectionSort();
  ~SelectionSort();

  void selection_sort(int32_t array[], int32_t n);
private:
  void swap(int32_t* a, int32_t* b);
};

#endif //SELECTIONSORT_H
