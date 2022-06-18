#pragma once
/*
    (T* A, unsigned long B, bool C)->()
    Takes an array A (type T) with length of B and sorts it in 
    the ascending order if C - true and descending if C - false, 
    using bubble sorting (a.k.a. sinking sort).
    Changes the array given as argument, length and order remains
    unchanged.
    >>BubbleSort(unsorted array, amount of elements, order)
*/
template <typename T>
void BubbleSort(T* array, unsigned long amount_of_elements, bool order = true) 
{
    for (unsigned long selected_element = 0; selected_element < amount_of_elements - 1; selected_element++) {
        for (unsigned long adjacent_element = 0; adjacent_element < amount_of_elements - selected_element - 1; adjacent_element++) {
            if (order == true) {
                if (array[adjacent_element] > array[adjacent_element + 1])
                    SwapByPointer<T>(&array[adjacent_element], &array[adjacent_element + 1]);
            }
            else if (order == false) {
                if (array[adjacent_element] < array[adjacent_element + 1])
                    SwapByPointer<T>(&array[adjacent_element], &array[adjacent_element + 1]);
            }
        }
    }
}
/*
    (T* A, T* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>SwapByPointer(&array[K], &array[K+1])
*/
template <typename T>
void SwapByPointer(T* left_element, T* right_element) 
{
    T temp = *left_element;
    *left_element = *right_element;
    *right_element = temp;
}