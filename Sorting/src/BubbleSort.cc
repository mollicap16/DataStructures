#include <BubbleSort.h>

BubbleSort::BubbleSort(){}

BubbleSort::~BubbleSort(){}

void BubbleSort::bubble_sort(int32_t array[], int32_t n){
  for(int32_t i = 0; i < n-1; ++i){
    for (int32_t j = 0; j < n-i-1; ++j){
      if (array[j] >= array[j+1]){
        swap(&array[j], &array[j+1]);
      }
    }
  }
}

void BubbleSort::swap(int32_t* a, int32_t* b){
 int32_t temp = *a;
 *a = *b;
 *b = temp;
}
