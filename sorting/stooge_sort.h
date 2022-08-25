// stooge_sort.h

/*
Stooge Sort is a recursive sorting algorithm. It is not much
efficient but interesting sorting algorithm. It generally
divides the array into two overlapping parts (2/3 each). After
that it performs sorting in first 2/3 part and then it performs
sorting in last 2/3 part. And then, sorting is done on first 2/3
part to ensure that the array is sorted.
https://www.geeksforgeeks.org/stooge-sort/
*/

typedef unsigned long u_long;

/*
	(T* A, unsigned long B, bool C) -> ()
	Takes an array A (type T) with length of B and sorts it in
	the ascending order if C - true and descending if C - false,
	using stooge sorting.
	- Changes the array given as argument.
*/
template <typename T>
static void StoogeSort(T* array, u_long length, bool order = true)
{
	length--;
	StoogeSortRanged(array, 0, length, order);
}

/*
	(T* A, unsigned long B, unsigned long C, bool D) -> ()
	Takes an array A within range of B..C and sorts it in
	the ascending order if D - true and descending if C - false,
	using stooge sorting.
	- Changes the array given as argument.
*/
template <typename T>
static void StoogeSortRanged(T* array, u_long start_point, u_long end_point, bool order)
{
	if (start_point >= end_point)
		return;

	if (order == true)
		if (array[start_point] > array[end_point])
			std::swap(array[start_point], array[end_point]);
	if (order == false)
		if (array[start_point] < array[end_point])
			std::swap(array[start_point], array[end_point]);

	if (end_point - start_point + 1 > 2) {
		u_long cut_index = (end_point - start_point + 1) / 3;
		StoogeSortRanged(array, start_point, end_point - cut_index, order);
		StoogeSortRanged(array, start_point + cut_index, end_point, order);
		StoogeSortRanged(array, start_point, end_point - cut_index, order);
	}
}