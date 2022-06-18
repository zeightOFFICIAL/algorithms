#pragma once
/*
    (T* A, unsigned long B, bool C, unsigned long D)->()
    Takes an array A within range of D..B and sorts it in 
    the ascending order if C - true and descending if C - false, 
    using stooge sorting. 
    Changes the array given as argument.
    >>StoogeSort(unsorted array, end point, order, HIDDEN start point HIDDEN)
*/
template <typename T>
void StoogeSort(T* array, unsigned long end_point, bool order = true, unsigned long start_point = 0)
{
        if (start_point >= end_point)
            return;
        if ((array[start_point] > array[end_point]) && (order == true)) {
            SwapByPointer_<T>(&array[start_point], &array[end_point]);
        }
        else if ((array[start_point] < array[end_point]) && (order == false)) {
            SwapByPointer_<T>(&array[start_point], &array[end_point]);
        }
        if (end_point - start_point + 1 > 2) {
            unsigned long cut_index = (end_point - start_point + 1) / 3;
            StoogeSort<T>(array, end_point - cut_index, order, start_point);
            StoogeSort<T>(array, end_point, order, start_point + cut_index);
            StoogeSort<T>(array, end_point - cut_index, order, start_point);
        }
}
/*
    (T* A, T* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>SwapByPointer_(&array[K], &array[K+1])
*/
template <typename T>
void SwapByPointer_(T* left_element, T* right_element)
{
    T temp = *left_element;
    *left_element = *right_element;
    *right_element = temp;
}