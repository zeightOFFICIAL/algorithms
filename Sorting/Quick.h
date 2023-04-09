/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Quick.h

#include "_Utils.h"

namespace sorting {
/**
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using quick sorting. Changes A, returns nothing.
*/
template <typename T>
static void QuickSort(T *array, ulong length, bool order = true);
/**
(T* A, long long B, long long C) -> ()
Takes an array A (type T) within range of B..C and sorts it in
the ascending order if D - true and descending if C - false,
using quick sorting. Changes A, returns nothing.
*/
template <typename T>
static void QuickSortRanged(T *array, ulong low, ulong high);

template <typename T>
static long64 QuickSortPartition(T *array, ulong low, ulong high);

template <typename T>
static void QuickSort(T *array, ulong length, bool order) {
  if (length == 0) {
    return;
  }

  QuickSortRanged(array, 0, length-1);

  if (!order) {
    reverse(array, length);
  }
}

template <typename T>
static void QuickSortRanged(T *array, ulong leftmost, ulong rightmost) {
  if (leftmost < rightmost) {
    long64 partitionIndex = QuickSortPartition(array, leftmost, rightmost);
    QuickSortRanged(array, leftmost, partitionIndex - 1);
    QuickSortRanged(array, partitionIndex + 1, rightmost);
  }
}

template <typename T>
static long64 QuickSortPartition(T *array, ulong leftmost, ulong rightmost) {
  long64 anchor = array[rightmost];
  long64 index = (leftmost - 1);
  
  for (long64 next = leftmost; next <= rightmost - 1; next++) {
    if (array[next] < anchor) {
      index++;
      swap(array[index], array[next]);
    }
  }
  swap(array[index + 1], array[rightmost]);
  
  return (index + 1);
}
} // namespace sorting
