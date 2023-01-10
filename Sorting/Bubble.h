/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Bubble.h
#include "_Utils.h"

namespace sorting {  
  /**
  (T *A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using bubble sorting. Changes A, returns nothing.
  */
  template <typename T>
  static void BubbleSort(T *array, ulong length, bool order = true);
  
  template <typename T>
  static void BubbleSort(T *array, ulong length, bool order) {
    if (length == 0) {
      return;
    }
    ulong each, compare;
  
    for (each = 0; each < length - 1; each++) {
      for (compare = 0; compare < length - each - 1; compare++) {
        if (array[compare] > array[compare + 1]) {
          swap(array[compare], array[compare + 1]);
        }
      }
    }
    if (!order) {
      reverse(array, length);
    }
  }
}