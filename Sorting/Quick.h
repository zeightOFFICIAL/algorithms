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

template <typename T>
static void QuickSortRanged(T *array, long64 low, long64 high);

template <typename T>
static long64 QuickSortPartition(T *array, long64 low, long64 high);

template <typename T>
static void QuickSort(T *array, ulong length, bool order) {
  if (length == 0) {
    return;
  }

  QuickSortRanged(array, 0, length);

  if (!order) {
    reverse(array, length);
  }
}

template <typename T>
static void QuickSortRanged(T *array, long64 low, long64 high) {
  if (low < high) {
    long64 pi = QuickSortPartition(array, low, high);
    QuickSortRanged(array, low, pi - 1);
    QuickSortRanged(array, pi + 1, high);
  }
}

template <typename T>
static long64 QuickSortPartition(T *array, long64 low, long64 high) {
  long64 pivot = array[high];
  long64 i = (low - 1);
  for (long64 j = low; j <= high - 1; j++) {
    if (array[j] < pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }
  swap(array[i+1], array[high]);
  return (i + 1);
}
} // namespace sorting
