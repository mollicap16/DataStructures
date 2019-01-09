#include <iostream>
#include <gtest/gtest.h>
#include <BubbleSort.h>
#include <SelectionSort.h>
#include <InsertionSort.h>
#include <QuickSort.h>
#include <MergeSort.h>

TEST(SortingTest, BubbleSortTest){
  BubbleSort sorting;

  int32_t array[] = {10, 100, 50, 151, 1, 99, 73, 3000, 3, 15};
  int32_t array_size = sizeof(array)/sizeof(array[0]);

  sorting.bubble_sort(array, array_size);

  ASSERT_EQ(array[0], 1);
  ASSERT_EQ(array[1], 3);
  ASSERT_EQ(array[2], 10);
  ASSERT_EQ(array[3], 15);
  ASSERT_EQ(array[4], 50);
  ASSERT_EQ(array[5], 73);
  ASSERT_EQ(array[6], 99);
  ASSERT_EQ(array[7], 100);
  ASSERT_EQ(array[8], 151);
  ASSERT_EQ(array[9], 3000);
}

TEST(SortingTest, SelectionSortTest){
  SelectionSort sorting;

  int32_t array[] = {10, 100, 50, 151, 1, 99, 73, 3000, 3, 15};
  int32_t array_size = sizeof(array)/sizeof(array[0]);

  sorting.selection_sort(array, array_size);

  ASSERT_EQ(array[0], 1);
  ASSERT_EQ(array[1], 3);
  ASSERT_EQ(array[2], 10);
  ASSERT_EQ(array[3], 15);
  ASSERT_EQ(array[4], 50);
  ASSERT_EQ(array[5], 73);
  ASSERT_EQ(array[6], 99);
  ASSERT_EQ(array[7], 100);
  ASSERT_EQ(array[8], 151);
  ASSERT_EQ(array[9], 3000);
}

TEST(SortingTest, InsertionSortTest){
  InsertionSort sorting;

  int32_t array[] = {10, 100, 50, 151, 1, 99, 73, 3000, 3, 15};
  int32_t array_size = sizeof(array)/sizeof(array[0]);

  sorting.insertion_sort(array, array_size);

  ASSERT_EQ(array[0], 1);
  ASSERT_EQ(array[1], 3);
  ASSERT_EQ(array[2], 10);
  ASSERT_EQ(array[3], 15);
  ASSERT_EQ(array[4], 50);
  ASSERT_EQ(array[5], 73);
  ASSERT_EQ(array[6], 99);
  ASSERT_EQ(array[7], 100);
  ASSERT_EQ(array[8], 151);
  ASSERT_EQ(array[9], 3000);
}

TEST(SortingTest, QuickSortTest){
  QuickSort sorting;

  int32_t array[] = {10, 100, 50, 151, 1, 99, 73, 3000, 3, 15};
  int32_t array_size = sizeof(array)/sizeof(array[0]);

  sorting.quick_sort(array, 0, array_size - 1);

  ASSERT_EQ(array[0], 1);
  ASSERT_EQ(array[1], 3);
  ASSERT_EQ(array[2], 10);
  ASSERT_EQ(array[3], 15);
  ASSERT_EQ(array[4], 50);
  ASSERT_EQ(array[5], 73);
  ASSERT_EQ(array[6], 99);
  ASSERT_EQ(array[7], 100);
  ASSERT_EQ(array[8], 151);
  ASSERT_EQ(array[9], 3000);
}

TEST(SortingTest, MergeSortTest){
  MergeSort sorting;

  int32_t array[] = {10, 100, 50, 151, 1, 99, 73, 3000, 3, 15};
  int32_t array_size = sizeof(array)/sizeof(array[0]);

  sorting.merge_sort(array, 0, array_size - 1);

  ASSERT_EQ(array[0], 1);
  ASSERT_EQ(array[1], 3);
  ASSERT_EQ(array[2], 10);
  ASSERT_EQ(array[3], 15);
  ASSERT_EQ(array[4], 50);
  ASSERT_EQ(array[5], 73);
  ASSERT_EQ(array[6], 99);
  ASSERT_EQ(array[7], 100);
  ASSERT_EQ(array[8], 151);
  ASSERT_EQ(array[9], 3000);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
