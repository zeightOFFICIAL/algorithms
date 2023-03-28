/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Gnome.h

#include "_Utils.h"

namespace sorting {
/**
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using gnome sorting. Changes A, returns nothing.
*/
template <typename T>
static void GnomeSort(T *array, ulong length, bool order = true);

template <typename T>
static void GnomeSort(T *array, ulong length, bool order) {
  if (length == 0) {
    return;
  }
  ulong each = 1, lastPosition = 2;

  while (each < length) {
    if (array[each - 1] < array[each]) {
      each = lastPosition;
      lastPosition++;
    } else {
      swap(array[each - 1], array[each]);
      each--;
      if (each == 0) {
        each = lastPosition;
        lastPosition++;
      }
    }
  }

  if (!order) {
    reverse(array, length);
  }
}
} // namespace sorting