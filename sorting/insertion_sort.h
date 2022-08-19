#pragma once
/*
    (T* A, unsigned long B, bool C)->()
    Takes an array A with length of B and sorts it in 
    the ascending order if C - true, descending if C - false
    using insertion sorting. 
    Changes the array given as argument.
    >>InsertionSort(unsorted array, amount of elements, order)
*/
template <typename T>
void InsertionSort(T* array, unsigned long amount_of_elements, bool order = true)
{
    T selected_element;
    for (unsigned long this_element = 1; this_element < amount_of_elements; this_element++) {
        selected_element = array[this_element];
        long long next_element = this_element - 1;
        if (order == true) {
            while ((next_element >= 0) && (array[next_element] > selected_element)) {
                array[next_element + 1] = array[next_element];
                next_element = next_element - 1;
            }
        }
        else if (order == false) {
            while ((next_element >= 0) && (array[next_element] < selected_element)) {
                array[next_element + 1] = array[next_element];
                next_element = next_element - 1;
            }
        array[next_element + 1] = selected_element;
        }
    }
}