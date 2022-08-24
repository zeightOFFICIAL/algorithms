// gnome_sort.h

/*
Gnome Sort also called Stupid sort is based on the concept of a
Garden Gnome sorting his flower pots. A garden gnome sorts the
flower pots by the following method:
 - He looks at the flower pot next to him and the previous one;
if they are in the right order he steps one pot forward, otherwise
he swaps them and steps one pot backwards.
 - If there is no previous pot (he is at the starting of the pot line),
he steps forwards; if there is no pot next to him (he is at the end of the pot line),
he is done.
https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
*/

typedef unsigned long u_long;

/*
	(T* A, unsigned long B, bool C) -> ()
	Takes an array A (type T) with length of B and sorts it in
	the ascending order if C - true, descending if
	C - false, using gnome sorting (a.k.a stupid sort)
	- Changes the array given as argument, length and order remains
	unchanged.
*/
template <typename T>
static void GnomeSort(T* array, u_long length, bool order = true) {
	unsigned long index = 0;
	if (order == true) {
		while (index < length) {
			if (index == 0)
				index++;
			else if (array[index] >= array[index - 1])
				index++;
			else {
				std::swap(array[index], array[index - 1]);
				index--;
			}
		}
	}
	else {
		while (index < length) {
			if (index == 0)
				index++;
			else if (array[index] <= array[index - 1])
				index++;
			else {
				std::swap(array[index], array[index - 1]);
				index--;
			}
		}
	}
}