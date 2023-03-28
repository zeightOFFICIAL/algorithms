/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Stooge.h

#include "_Utils.h"

namespace sorting {  
  /**
  (T *A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using stooge sorting. Changes A, returns nothing.
  */
  template <typename T>
  static void StoogeSort(T *array, ulong length, bool order = true);
  /**
  (T* A, unsigned long B, unsigned long C, bool D) -> ()
  Takes an array A (type T) within range of B..C and sorts it in
  the ascending order if D - true and descending if C - false,
  using stooge sorting. Changes A, returns nothing.
  */
  template <typename T>
  static void StoogeRangedSort(T *array, ulong startPoint, ulong endPoint, bool order);
  
  template <typename T>
  static void StoogeSort(T *array, ulong length, bool order) {
    if (length == 0) {
      return;
    }
  
    length--;
    StoogeRangedSort(array, 0, length, order);
  }
  
  template <typename T>
  static void StoogeRangedSort(T *array, ulong startPoint, ulong endPoint, bool order) {
    if (startPoint >= endPoint) {
      return;
    }
    if (order == true) {
      if (array[startPoint] > array[endPoint]) {
        swap(array[startPoint], array[endPoint]);
      }
    }
    if (order == false) {
      if (array[startPoint] < array[endPoint]) {
        swap(array[startPoint], array[endPoint]);
      }
    }
    if (endPoint - startPoint + 1 > 2) {
      ulong cutIndex = (endPoint - startPoint + 1) / 3;
      StoogeRangedSort(array, startPoint, endPoint - cutIndex, order);
      StoogeRangedSort(array, startPoint + cutIndex, endPoint, order);
      StoogeRangedSort(array, startPoint, endPoint - cutIndex, order);
    }
  }
}