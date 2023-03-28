/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Insertion.h

#include "_Utils.h"

namespace sorting {
/**
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using slow sorting. Changes A, returns nothing.
*/
template <typename T>
static void SlowSort(T *array, ulong length, bool order = true);
/**
(T* A, unsigned long B, unsigned long C) -> ()
Takes an array A (type T) within range of B..C and sorts it in
the ascending order if D - true and descending if C - false,
using slow sorting. Changes A, returns nothing.
*/
template <typename T>
static void SlowSortRanged(T *array, ulong leftmost, ulong rightmost);

template <typename T>
static void SlowSort(T *array, ulong length, bool order) {
  if (length == 0) {
    return;
  }

  SlowSortRanged(array, 0, length-1);
  
  if (!order) {
    reverse(array, length);
  }
}

template <typename T>
static void SlowSortRanged(T *array, ulong leftmost, ulong rightmost) {
  if (leftmost < rightmost) {
    ulong middle = (leftmost + rightmost) / 2;
    SlowSortRanged(array, leftmost, middle);
    SlowSortRanged(array, middle+1, rightmost);
    if (array[rightmost] < array[middle]) {
      swap(array[middle], array[rightmost]);
    }
    SlowSortRanged(array, leftmost, rightmost-1);
  }
}

} // namespace sorting