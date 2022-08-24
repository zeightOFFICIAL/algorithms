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
    (T* A, unsigned long B, bool C, unsigned long D) -> ()
    Takes an array A within range of D..B and sorts it in 
    the ascending order if C - true and descending if C - false, 
    using stooge sorting. 
    - Changes the array given as argument, length and order remains
	unchanged.
*/
template <typename T>
void StoogeSort(T* array, u_long h, bool order = true, u_long l = 0)
{
        if (l >= h)
            return;

        if (order == true) {
            if (array[l] > array[h])
                std::swap(array[l], array[h]);
        }
        if (order == false) {
            if (array[l] < array[h])
                std::swap(array[l], array[h]);
        }

        if (h - l + 1 > 2) {
            u_long t = (h - l + 1) / 3;
            StoogeSort(array, h - t, order, l);
            StoogeSort(array, h, order, l + t);
            StoogeSort(array, h - t, order, l);
        }
}