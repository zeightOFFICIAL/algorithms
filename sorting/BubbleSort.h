// BubbleSort.h

#include "Utils.h"
using namespace sorting;

/*
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using bubble sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortBubble(T *array, unsigned long length, bool order = true);

template <typename T>
static void sortBubble(T *array, unsigned long length, bool order) {
  if (length == 0) {
    return;
  }
  for (unsigned long element = 0; element < length - 1; element++) {
    bool swapped = 0;
    for (unsigned long i = 0; i < length - element - 1; i++) {
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
        swapped = 1;
      }
    }
    if (swapped == 0) {
      break;
    }
  }
  if (!order) {
    reverse(array, length);
  }
}