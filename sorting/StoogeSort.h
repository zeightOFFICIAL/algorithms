// StoogeSort.h

/*
Stooge Sort is a recursive sorting algorithm. It is not much
efficient but interesting sorting algorithm. It generally
divides the array into two overlapping parts (2/3 each). After
that it performs sorting in first 2/3 part and then it performs
sorting in last 2/3 part. And then, sorting is done on first 2/3
part to ensure that the array is sorted.

https://www.geeksforgeeks.org/stooge-sort/
*/

/*
  (T* A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using stooge sorting.
  -Changes the array given as argument.
*/
template <typename T>
static void sortStooge(T *array, unsigned long length, bool order = true);
/*
  (T* A, unsigned long B, unsigned long C, bool D) -> ()
  Takes an array A within range of B..C and sorts it in
  the ascending order if D - true and descending if C - false,
  using stooge sorting.
  -Changes the array given as argument.
*/
template <typename T>
static void sortRangedStooge(T *array, unsigned long startPoint,
                             unsigned long endPoint, bool order);

template <typename T>
static void sortStooge(T *array, unsigned long length, bool order) {
  length--;
  sortRangedStooge(array, 0, length, order);
}

template <typename T>
static void sortRangedStooge(T *array, unsigned long startPoint,
                             unsigned long endPoint, bool order) {
  if (startPoint >= endPoint)
    return;

  if (order == true)
    if (array[startPoint] > array[endPoint])
      std::swap(array[startPoint], array[endPoint]);
  if (order == false)
    if (array[startPoint] < array[endPoint])
      std::swap(array[startPoint], array[endPoint]);

  if (endPoint - startPoint + 1 > 2) {
    unsigned long cutIndex = (endPoint - startPoint + 1) / 3;
    sortRangedStooge(array, startPoint, endPoint - cutIndex, order);
    sortRangedStooge(array, startPoint + cutIndex, endPoint, order);
    sortRangedStooge(array, startPoint, endPoint - cutIndex, order);
  }
}