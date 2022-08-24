// insertion_sort.h

/*
Insertion sort is a simple sorting algorithm that works similar
to the way you sort playing cards in your hands. The array is
virtually split into a sorted and an unsorted part. Values from
the unsorted part are picked and placed at the correct position
in the sorted part.
https://www.geeksforgeeks.org/insertion-sort/
*/

typedef unsigned long u_long;

/*
	(T* A, unsigned long B, bool C) -> ()
	Takes an array A with length of B and sorts it in
	the ascending order if C - true, descending if C - false
	using insertion sorting.
	- Changes the array given as argument, length and order remains
	unchanged.
*/
template <typename T>
static void InsertionSort(T* array, u_long length, bool order = true)
{
	T selected_element;
	if (order == true) {
		for (u_long this_element = 1; this_element < length; this_element++) {
			selected_element = array[this_element];
			u_long next_element = this_element - 1;
			while ((next_element >= 0) && (array[next_element] > selected_element)) {
				array[next_element + 1] = array[next_element];
				next_element = next_element - 1;
			}
			array[next_element + 1] = selected_element;
		}
	}
	else {
		for (u_long this_element = 1; this_element < length; this_element++) {
			selected_element = array[this_element];
			u_long next_element = this_element - 1;
			while ((next_element >= 0) && (array[next_element] < selected_element)) {
				array[next_element + 1] = array[next_element];
				next_element = next_element - 1;
			}
			array[next_element + 1] = selected_element;
		}
	}
}