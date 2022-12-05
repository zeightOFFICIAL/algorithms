// InsertionSort.h

#include <iostream>

/*
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using insertion sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortInsertion(T *array, unsigned long length, bool order = true);

template <typename T>
static void sortInsertion(T *array, unsigned long length, bool order) {
  T selectedElement;

  for (unsigned int position = 1; position < length; position++) {
    selectedElement = array[position];
    long long nextPosition = position - 1;
    while (nextPosition >= 0 && array[nextPosition] > selectedElement) {
      array[nextPosition + 1] = array[nextPosition];
      nextPosition = nextPosition - 1;
    }
    array[nextPosition + 1] = selectedElement;
  }
  if (!order) {
    reverse(array, length);
  }
}