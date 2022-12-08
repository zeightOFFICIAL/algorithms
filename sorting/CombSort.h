// CombSort.h

#include "Utils.h"
using namespace sorting;

/*
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using comb sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortComb(T *array, u_long length, bool order = true);

template <typename T>
static void sortComb(T *array, u_long length, bool order) {
  long double decreaseFactor = 1.247330950103979f;
  u_long gap = length;

  while (gap >= 1) {
    for (u_long element = 0; element + gap < length; element++) {
      if (array[element] > array[element + gap]) {
        swap(array[element], array[element + gap]);
      }
    }
    gap /= decreaseFactor;
  }
  if (!order) {
    reverse(array, length);
  }
}