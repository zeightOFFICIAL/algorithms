// comb_sort.h

/*
Comb Sort is mainly an improvement over Bubble Sort. Bubble
sort always compares adjacent values. So all inversions are
removed one by one. Comb Sort improves on Bubble Sort by
using a gap of the size of more than 1. The gap starts with
a large value and shrinks by a factor of 1.3 in every
iteration until it reaches the value 1. Thus Comb Sort
removes more than one inversion count with one swap and
performs better than Bubble Sort.
https://www.geeksforgeeks.org/comb-sort/
*/

typedef unsigned long u_long;
typedef long double d_double;

template <typename T>
static void CombSort(T *array, u_long length, bool order = true);

/*
    (T* A, unsigned long B, bool C) -> ()
    Takes an array A (type T) with length of B and sorts it in
    the ascending order if C - true and descending if C - false,
    using comb sorting.
    - Changes the array given as argument.
*/
template <typename T>
static void CombSort(T *array, u_long length, bool order) 
{
    d_double dec_factor = 1.247330950103979;
    u_long gap = length;

    if (order == true) {
        while (gap >= 1) {
            for (u_long element = 0; element + gap < length; element++)
                if (array[element] > array[element + gap])
                    std::swap(array[element], array[element + gap]);
            gap /= dec_factor;
        }
    }
    else if (order == false) {
        while (gap >= 1) {
            for (u_long element = 0; element + gap < length; element++)
                if (array[element] < array[element + gap])
                    std::swap(array[element], array[element + gap]);
            gap /= dec_factor;
        }
    }
}