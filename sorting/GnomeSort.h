// GnomeSort.h

#include "Utils.h"
using namespace sorting;

/*
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using gnome sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortGnome(T *array, unsigned long length, bool order = true);

template <typename T>
static void sortGnome(T *array, unsigned long length, bool order) {
  unsigned long index = 1, lastPosition = 2;

  while (index < length) {
    if (array[index - 1] < array[index]) {
      index = lastPosition;
      lastPosition++;
    } else {
      swap(array[index - 1], array[index]);
      index--;
      if (index == 0) {
        index = lastPosition;
        lastPosition++;
      }
    }
  }
  if (!order) {
    reverse(array, length);
  }
}