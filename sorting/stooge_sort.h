#include "auxiliary.h"

/*
    (T* A, ulong B. ulong C)->()
    Takes an array A with range of B..C and sorts it in 
    the ascending order, using stooge sorting. 
    Changes the array given as argument.
    >>StoogeSort(unsorted array, start point, HIDDEN end point HIDDEN)
*/
template <typename T>
void StoogeSort(T* array, unsigned long end_point, unsigned long start_point = 0)
{
    if (start_point >= end_point)
      return;
    if (array[start_point] > array[end_point])
       ToolSwapByPointer(&array[start_point], &array[end_point]);
    if(end_point-start_point+1>2)
    {
        unsigned long cut_index = (end_point-start_point+1)/3;
        StoogeSort(array, end_point-cut_index, start_point);
        StoogeSort(array, end_point, start_point+cut_index);
        StoogeSort(array, end_point-cut_index, start_point);
    }
}