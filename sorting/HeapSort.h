// HeapSort.h

#include "Utils.h"
using namespace sorting;

/*
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using heap sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortHeap(T *array, u_long length, bool order = true);
/*
(T* A, long long B, long long C) -> ()
Takes an array A (type T) with length of B which start with
C and builds maxheap. Changes A, returns nothing.
*/
template <typename T>
void arrayHeapify(T *array, long long length, long long i);

template <typename T>
static void sortHeap(T *array, u_long length, bool order) {
  long long node;

  for (node = length / 2 - 1; node >= 0; node--)
    arrayHeapify(array, length, node);
  for (node = length - 1; node > 0; node--) {
    swap(array[0], array[node]);
    arrayHeapify(array, node, 0);
  }
  if (!order) {
    reverse(array, length);
  }
}

template <typename T>
void arrayHeapify(T *array, long long length, long long summit) {
  long long primeParent = summit, left = 2 * summit + 1, right = 2 * summit + 2;

  if (left < length && array[left] > array[primeParent]) {
    primeParent = left;
  }
  if (right < length && array[right] > array[primeParent]) {
    primeParent = right;
  }
  if (primeParent != summit) {
    swap(array[summit], array[primeParent]);
    arrayHeapify<T>(array, length, primeParent);
  }
}