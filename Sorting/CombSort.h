// CombSort.h

#include "_Utils.h"

namespace sorting {
  const long double FACTOR = 1.247330950103979;
  /**
  (T *A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using comb sorting. Changes A, returns nothing.
  */
  template <typename T>
  static void sortComb(T *array, ulong length, bool order = true);
  
  template <typename T>
  static void sortComb(T *array, ulong length, bool order) {
    if (length == 0) {
      return;
    }
    double gap = length;
    ulong nextIndex, index;
    bool isSwapped = true;
  
    while (gap > 1 || isSwapped) {
      gap /= FACTOR;
      if (gap < 1) {
        gap = 1;
      }
      index = 0;
      isSwapped = false;
      while (index + gap < length) {
        nextIndex = index + (int)gap;
        if (array[index] > array[nextIndex]) {
          swap(array[index], array[nextIndex]);
          isSwapped = true;
        }
        ++index;
      }
    }
    if (!order) {
      reverse(array, length);
    }
  }
}