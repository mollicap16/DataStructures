#include <MergeSort.h>
#include <vector>

MergeSort::MergeSort(){}

MergeSort::~MergeSort(){}


void MergeSort::merge(int32_t array[], int32_t left, int32_t middle, int32_t right){
  int32_t index_left, index_right, index_temp;
  std::vector<int32_t> temp_array(right - left + 1);
  index_left = left;
  index_temp = 0;
  index_right = middle + 1;

  while (index_left <= middle && index_right <= right){
    if (array[index_left] < array[index_right]){
      temp_array[index_temp] = array[index_left];
      index_left++;
      index_temp++;
    } else {
      temp_array[index_temp] = array[index_right];
      index_right++;
      index_temp++;
    }
  }

  // Insert any remaining values in temp
  while (index_left <= middle) {
    temp_array[index_temp] = array[index_left];
    index_temp++;
    index_left++;
  }

  while (index_right <= right){
    temp_array[index_temp] = array[index_right];
    index_temp++;
    index_right++;
  }

  for(index_left = left; index_left <= right; ++index_left){
    array[index_left] = temp_array[index_left - left];
  }
}

void MergeSort::merge_sort(int32_t array[], int32_t left, int32_t right){
  if (left < right){
    int32_t middle = (left + right)/2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    merge(array, left, middle, right);
  }
}
