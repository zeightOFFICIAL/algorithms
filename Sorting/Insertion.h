/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Insertion.h

#include "_Utils.h"

namespace sorting { 
  /**
  (T *A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using insertion sorting. Changes A, returns nothing.
  */
  template <typename T>
  static void InsertionSort(T *array, ulong length, bool order = true);
  
  template <typename T>
  static void InsertionSort(T *array, ulong length, bool order) {
    if (length == 0) {
      return;
    }  
    T selectedElement;
    long64 compare;
    ulong each;
  
    for (each = 1; each < length; each++) {
      selectedElement = array[each];
      compare = each - 1;
      while (compare >= 0 && array[compare] > selectedElement) {
        array[compare + 1] = array[compare];
        compare = compare - 1;
      }
      array[compare + 1] = selectedElement;
    }  
    if (!order) {
      reverse(array, length);
    }
  }
}