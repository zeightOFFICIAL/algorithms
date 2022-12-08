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
static void sortCocktail(T *array, u_long length, bool order = true);

template <typename T>
static void sortCocktail(T *array, u_long length, bool order) {
  u_long left = 0, right = length, split = length;

  while (left < right) {
    for (u_long fromLeft = left; fromLeft < right; fromLeft++) {
      if (array[fromLeft] > array[fromLeft + 1]) {
        swap(array[fromLeft], array[fromLeft + 1]);
        split = fromLeft;
      }
    }
    right = split;
    for (u_long fromRight = right; fromRight > left; fromRight--) {
      if (array[fromRight] < array[fromRight - 1]) {
        swap(array[fromRight], array[fromRight - 1]);
        split = fromRight;
      }
    }
    left = split;
  }
  if (!order) {
    reverse(array, length);
  }
}