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
    Changes the array given as argument.
    >>StoogeSort(unsorted array, end point, order, HIDDEN start point HIDDEN)
*/
template <typename T>
void StoogeSort(T* array, u_long end_point, bool order = true, u_long start_point = 0)
{
        if (start_point >= end_point)
            return;
        if ((array[start_point] > array[end_point]) && (order == true)) {
            std::swap(array[start_point], array[end_point]);
        }
        else if ((array[start_point] <= array[end_point]) && (order == false)) {
            std::swap(array[start_point], array[end_point]);
        }
        if (end_point - start_point + 1 > 2) {
            u_long cut_index = (end_point - start_point + 1) / 3;
            StoogeSort<T>(array, end_point - cut_index, order, start_point);
            StoogeSort<T>(array, end_point, order, start_point + cut_index);
            StoogeSort<T>(array, end_point - cut_index, order, start_point);
        }
}