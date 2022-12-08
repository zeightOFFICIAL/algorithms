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
static void sortBubble(T *array, u_long length, bool order = true);

template <typename T>
static void sortBubble(T *array, u_long length, bool order) {
  if (length == 0) {
    return;
  }
  bool isSwapped;

  for (u_long elemIndex = 0; elemIndex < length - 1; elemIndex++) {
    isSwapped = false;
    for (u_long nextElemIndex = 0; nextElemIndex < length - elemIndex - 1; nextElemIndex++) {
      if (array[nextElemIndex] > array[nextElemIndex + 1]) {
        swap(array[nextElemIndex], array[nextElemIndex + 1]);
        isSwapped = true;
      }
    }
    if (isSwapped == false) {
      break;
    }
  }
  if (!order) {
    reverse(array, length);
  }
}