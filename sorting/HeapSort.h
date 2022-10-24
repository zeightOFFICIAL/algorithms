// HeapSort.h

/*
Heap sort is a comparison-based sorting technique based on
Binary Heap data structure. It is similar to the selection
sort where we first find the minimum element and place the
minimum element at the beginning. Repeat the same process
for the remaining elements.

Heapify is the process of creating a heap data structure
from a binary tree represented using an array. It is used
to create Min-Heap or Max-heap. Start from the first index
of the non-leaf node whose index is given by n/2 � 1.
Heapify uses recursion

https://www.geeksforgeeks.org/stooge-sort/
*/

/*
  (T* A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using heap sorting.
  -Changes the array given as argument.
*/
template <typename T>
static void sortHeap(T *array, unsigned long length, bool order = true);
/*
  (T* A, long long B, long long C, bool D) -> ()
  In order for heapsort to work properly, firstly we need to
  build the max (min) - heap tree, with maximum (minumum) value
  at the vertex. Generally, speaking tree must be in decreasing
  or increasing order.
  Process 'heapify' swaps the values so that the tree, beside
  the already sorted part is in decreasing (increasing) order,
  technically parent value of the tree is bigger (smaller) than
  children's.
  A is an array which is needed to be heapfied. B responds
  for amount of elements. C for current head of the tree
*/
template <typename T>
void arrayHeapify(T *array, long long length, long long i, bool order);

template <typename T>
static void sortHeap(T *array, unsigned long length, bool order) {
  long long node;
  for (node = length / 2 - 1; node >= 0; node--)
    arrayHeapify<T>(array, length, node, order);
  for (node = length - 1; node > 0; node--) {
    std::swap(array[0], array[node]);
    arrayHeapify<T>(array, node, 0, order);
  }
}

template <typename T>
void arrayHeapify(T *array, long long length, long long i, bool order) {
  long long peak = i, left = 2 * i + 1, right = 2 * i + 2;
  if (order == true) {
    if (left < length && array[left] > array[peak])
      peak = left;
    if (right < length && array[right] > array[peak])
      peak = right;
  } else if (order == false) {
    if (left < length && array[left] < array[peak])
      peak = left;
    if (right < length && array[right] < array[peak])
      peak = right;
  }
  if (peak != i) {
    std::swap(array[i], array[peak]);
    arrayHeapify<T>(array, length, peak, order);
  }
}