// insertion_sort.h

/*
Insertion sort is a simple sorting algorithm that works similar
to the way you sort playing cards in your hands. The array is
virtually split into a sorted and an unsorted part. Values from
the unsorted part are picked and placed at the correct position
in the sorted part.
https://www.geeksforgeeks.org/insertion-sort/
*/

template <typename T>
static void InsertionSort(T *array, unsigned long length, bool order = true);

/*
        (T* A, unsigned long B, bool C) -> ()
        Takes an array A (type T) with length of B and sorts it in
        the ascending order if C - true and descending if C - false,
        using insertion sorting.
        - Changes the array given as argument.
*/
template <typename T>
static void InsertionSort(T *array, unsigned long length, bool order) {
  T selected_element;
  if (order == true) {
    for (unsigned long element = 1; element < length; element++) {
      selected_element = array[element];
      unsigned long next_element = element - 1;
      while ((next_element >= 0) && (array[next_element] > selected_element)) {
        array[next_element + 1] = array[next_element];
        next_element = next_element - 1;
      }
      array[next_element + 1] = selected_element;
    }
  } else if (order == false) {
    for (unsigned long element = 1; element < length; element++) {
      selected_element = array[element];
      unsigned long next_element = element - 1;
      while ((next_element >= 0) && (array[next_element] < selected_element)) {
        array[next_element + 1] = array[next_element];
        next_element = next_element - 1;
      }
      array[next_element + 1] = selected_element;
    }
  }
}