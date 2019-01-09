#include <InsertionSort.h>
#include <limits>

InsertionSort::InsertionSort(){}

InsertionSort::~InsertionSort(){}

void InsertionSort::insertion_sort(int32_t array[], int32_t n){
  int32_t key;
  int32_t sorted_index;
  for (int32_t i = 1; i < n; ++i){
    key = array[i];
    sorted_index = i -1;

    while(sorted_index >= 0 && array[sorted_index] > key){
      array[sorted_index + 1] = array [sorted_index];
      sorted_index -= 1;
    }
    array[sorted_index + 1] = key;
  }
}
