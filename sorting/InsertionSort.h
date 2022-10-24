// InsertionSort.h

/*
Insertion sort is a simple sorting algorithm that works similar
to the way you sort playing cards in your hands. The array is
virtually split into a sorted and an unsorted part. Values from
the unsorted part are picked and placed at the correct position
in the sorted part.

https://www.geeksforgeeks.org/insertion-sort/
*/

/*
  (T* A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using insertion sorting.
  -Changes the array given as argument.
*/
template <typename T>
static void sortInsertion(T *array, unsigned long length, bool order = true);

template <typename T>
static void sortInsertion(T *array, unsigned long length, bool order) {
  T selectedElement;
  if (order == true) {
    for (unsigned long element = 1; element < length; element++) {
      selectedElement = array[element];
      unsigned long nextElement = element - 1;
      while ((nextElement >= 0) && (array[nextElement] > selectedElement)) {
        array[nextElement + 1] = array[nextElement];
        nextElement = nextElement - 1;
      }
      array[nextElement + 1] = selectedElement;
    }
  } else if (order == false) {
    for (unsigned long element = 1; element < length; element++) {
      selectedElement = array[element];
      unsigned long nextElement = element - 1;
      while ((nextElement >= 0) && (array[nextElement] < selectedElement)) {
        array[nextElement + 1] = array[nextElement];
        nextElement = nextElement - 1;
      }
      array[nextElement + 1] = selectedElement;
    }
  }
}