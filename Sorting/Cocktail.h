/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Cocktail.h

#include "_Utils.h"

namespace sorting {
/**
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using cocktail sorting. Changes A, returns nothing.
*/
template <typename T>
static void CocktailSort(T *array, ulong length, bool order = true);

template <typename T>
static void CocktailSort(T *array, ulong length, bool order) {
  if (length == 0) {
    return;
  }
  long64 begin = 0, end = length - 1, rightCompare, leftCompare;
  bool isSwapped = true;

  while (isSwapped) {
    isSwapped = false;
    for (rightCompare = begin; rightCompare < end; rightCompare++) {
      if (array[rightCompare] > array[rightCompare + 1]) {
        swap(array[rightCompare], array[rightCompare + 1]);
        isSwapped = true;
      }
    }
    if (!isSwapped) {
      break;
    }
    isSwapped = false;
    --end;
    for (leftCompare = end - 1; leftCompare >= begin; --leftCompare) {
      if (array[leftCompare] > array[leftCompare + 1]) {
        swap(array[leftCompare], array[leftCompare + 1]);
        isSwapped = true;
      }
    }
    ++begin;
  }

  if (!order) {
    reverse(array, length);
  }
}
} // namespace sorting