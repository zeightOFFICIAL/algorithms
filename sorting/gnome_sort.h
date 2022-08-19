#pragma once
/*
    (T* A, unsigned long B, bool C)->()
    Takes an array A (type T) with length of B and sorts it in
    the ascending order if C - true, descending if 
    C - false, using gnome sorting (a.k.a stupid sort)
    Changes the array given as argument.
    >>GnomeSort(unsorted array, amount of elements)
*/
template <typename T>
void GnomeSort(T* array, unsigned long amount_of_elements, bool order = true) {
    unsigned long this_element = 0;
    while (this_element < amount_of_elements)  {
        if (this_element == 0)
            this_element++;
        else if (order == true && array[this_element] >= array[this_element - 1])
            this_element++;
        else if (order == false && array[this_element] <= array[this_element - 1])
            this_element++;
        else  {
            _SwapByPointer<T>(&array[this_element], &array[this_element - 1]);
            this_element--;
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
void _SwapByPointer(T* left_element, T* right_element)
{
    T temp = *left_element;
    *left_element = *right_element;
    *right_element = temp;
}