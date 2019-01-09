#include <SelectionSort.h>
#include <limits>

SelectionSort::SelectionSort(){}

SelectionSort::~SelectionSort(){}

void SelectionSort::selection_sort(int32_t array[], int32_t n){
  int32_t smallest_value = std::numeric_limits<int32_t>::max();
  int32_t smallest_value_index = 0;

  for(int32_t i = 0; i < n-1; ++i){
    for (int32_t j = i; j < n; ++j){
      if (array[j] <= smallest_value){
        smallest_value = array[j];
        smallest_value_index = j;
      }
    }
    swap(&array[i], &array[smallest_value_index]);
    smallest_value = std::numeric_limits<int32_t>::max();
  }
}

void SelectionSort::swap(int32_t* a, int32_t* b){
 int32_t temp = *a;
 *a = *b;
 *b = temp;
}
