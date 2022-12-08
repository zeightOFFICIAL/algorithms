// StoogeSort.h

#include "Utils.h"
using namespace sorting;

/*
(T *A, unsigned long B, bool C) -> ()
Takes an array A (type T) with length of B and sorts it in
the ascending order if C - true and descending if C - false,
using stooge sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortStooge(T *array, u_long length, bool order = true);
/*
(T* A, unsigned long B, unsigned long C, bool D) -> ()
Takes an array A (type T) within range of B..C and sorts it in
the ascending order if D - true and descending if C - false,
using stooge sorting. Changes A, returns nothing.
*/
template <typename T>
static void sortRangedStooge(T *array, u_long startPoint, u_long endPoint, bool order);

template <typename T>
static void sortStooge(T *array, u_long length, bool order) {
  length--;
  sortRangedStooge(array, 0, length, order);
}

template <typename T>
static void sortRangedStooge(T *array, u_long startPoint, u_long endPoint, bool order) {
  if (startPoint >= endPoint)
    return;
  
  if (order == true)
    if (array[startPoint] > array[endPoint])
      swap(array[startPoint], array[endPoint]);
  if (order == false)
    if (array[startPoint] < array[endPoint])
      swap(array[startPoint], array[endPoint]);

  if (endPoint - startPoint + 1 > 2) {
    u_long cutIndex = (endPoint - startPoint + 1) / 3;
    sortRangedStooge(array, startPoint, endPoint - cutIndex, order);
    sortRangedStooge(array, startPoint + cutIndex, endPoint, order);
    sortRangedStooge(array, startPoint, endPoint - cutIndex, order);
  }
}