#include <QuickSort.h>

QuickSort::QuickSort(){}

QuickSort::~QuickSort(){}

void QuickSort::quick_sort(int32_t array[], int32_t low, int32_t high){
  if (low < high){
    int32_t partition_index = partition(array, low, high);

    quick_sort(array, low, partition_index - 1);
    quick_sort(array, partition_index + 1, high);
  }

}

int32_t QuickSort::partition(int32_t array[], int32_t low, int32_t high){
  int32_t pivot = array[high];
  int32_t lowest_index = (low - 1);

  for (int32_t j = low; j <= high - 1; ++j){
    if (array[j] <= pivot){
      lowest_index++;
      swap(&array[lowest_index], &array[j]);
    }
  }
  swap(&array[lowest_index + 1], &array[high]);
  return (lowest_index + 1);
}

void QuickSort::swap(int32_t* a, int32_t* b){
 int32_t temp = *a;
 *a = *b;
 *b = temp;
}
