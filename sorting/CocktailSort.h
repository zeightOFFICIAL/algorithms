// CocktailSort.h

#include "Utils.h"
using namespace sorting;

/*
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using cocktail sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortCocktail(T *array, unsigned int length, bool order = true);

template <typename T>
static void sortCocktail(T *array, unsigned int length, bool order) {
  unsigned int left = 0, right = length, split = length;

  while (left < right) {
    for (unsigned int i = left; i < right; i++) {
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
        split = i;
      }
    }
    right = split;
    for (unsigned int i = right; i > left; i--) {
      if (array[i] < array[i - 1]) {
        swap(array[i], array[i - 1]);
        split = i;
      }
    }
    left = split;
  }
  if (!order) {
    reverse(array, length);
  }
}