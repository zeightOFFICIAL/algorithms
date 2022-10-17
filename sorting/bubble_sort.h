// bubble_sort.h

/*
Bubble Sort is the simplest sorting algorithm that works by
repeatedly swapping the adjacent elements if they are in the
wrong order. This algorithm is not suitable for large data sets
as its average and worst-case time complexity is quite high.
https://www.geeksforgeeks.org/bubble-sort/
*/

template <typename T>
static void BubbleSort(T *array, unsigned long length, bool order = true);

/*
        (T* A, unsigned long B, bool C) -> ()
        Takes an array A (type T) with length of B and sorts it in
        the ascending order if C - true and descending if C - false,
        using bubble sorting.
        - Changes the array given as argument.
*/
template <typename T>
static void BubbleSort(T *array, unsigned long length, bool order) {
  if (order == true) {
    for (unsigned long element = 0; element < length - 1; element++) {
      bool swapped = 0;
      for (unsigned long i = 0; i < length - element - 1; i++) {
        if (array[i] > array[i + 1]) {
          std::swap(array[i], array[i + 1]);
          swapped = 1;
        }
      }
      if (swapped == 0)
        break;
    }
  } else if (order == false) {
    for (unsigned long element = 0; element < length - 1; element++) {
      bool swapped = 0;
      for (unsigned long i = 0; i < length - element - 1; i++) {
        if (array[i] < array[i + 1]) {
          std::swap(array[i], array[i + 1]);
          swapped = 1;
        }
      }
      if (swapped == 0)
        break;
    }
  }
}