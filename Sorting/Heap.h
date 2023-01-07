// Heap.h

#include "_Utils.h"

namespace sorting {   
  /**
  (T *A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using heap sorting. Changes A, returns nothing.
  */
  template <typename T>
  static void HeapSort(T *array, ulong length, bool order = true);
  /**
  (T* A, long long B, long long C) -> ()
  Takes an array A (type T) with length of B which start with
  C and builds maxheap. Changes A, returns nothing.
  */
  template <typename T>
  static void Heapify(T *array, long64 length, long64 i);
  
  template <typename T>
  static void HeapSort(T *array, ulong length, bool order) {
    if (length == 0) {
      return;
    }  
    long64 each;
  
    for (each = length / 2 - 1; each >= 0; each--)
      Heapify(array, length, each);
    for (each = length - 1; each > 0; each--) {
      swap(array[0], array[each]);
      Heapify(array, each, 0);
    }  
    if (!order) {
      reverse(array, length);
    }
  }
  
  template <typename T>
  static void Heapify(T *array, long64 length, long64 summit) {
    long64 primeParent = summit, left = 2 * summit + 1, right = 2 * summit + 2;
  
    if (left < length && array[left] > array[primeParent]) {
      primeParent = left;
    }
    if (right < length && array[right] > array[primeParent]) {
      primeParent = right;
    }
    if (primeParent != summit) {
      swap(array[summit], array[primeParent]);
      Heapify<T>(array, length, primeParent);
    }
  }
}