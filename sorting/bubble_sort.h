// bubble_sort.h

/*
Bubble Sort is the simplest sorting algorithm that works by
repeatedly swapping the adjacent elements if they are in the
wrong order. This algorithm is not suitable for large data sets
as its average and worst-case time complexity is quite high.
https://www.geeksforgeeks.org/bubble-sort/
*/

typedef unsigned long u_long;

/*
	(T* A, unsigned long B, bool C) -> ()
	Takes an array A (type T) with length of B and sorts it in
	the ascending order if C - true and descending if C - false,
	using bubble sorting.
	- Changes the array given as argument, length and order remains
	unchanged.
*/
template <typename T>
static void BubbleSort(T* array, u_long length, bool order = true)
{
	if (order == true) {
		for (u_long i = 0; i < length - 1; i++)
			for (u_long k = 0; k < length - i - 1; k++)
				if (array[k] > array[k + 1])
					std::swap(array[k], array[k + 1]);
	}
	else {
		for (u_long i = 0; i < length - 1; i++)
			for (u_long k = 0; k < length - i - 1; k++)
				if (array[k] < array[k + 1])
					std::swap(array[k], array[k + 1]);
	}
}