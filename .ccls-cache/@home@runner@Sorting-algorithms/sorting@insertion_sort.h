#pragma once

/*
    (T* A, unsigned int B)->()
    Takes an array A with length of B and sorts it in 
    the ascending order, using insertion sorting. 
    Changes the array given as argument.
    >>InsertionSort(unsorted array, amount of elements)
*/
template <typename T>
void InsertionSort(T* array, unsigned int amount_of_elements)
{
    T key;
    for (auto i = 1; i < amount_of_elements; i++)  {
            key = array[i];
            auto j = i - 1;
            while (j >= 0 && array[j] > key)  {
                    array[j + 1] = array[j];
                    j = j - 1;
                }
            array[j + 1] = key;
        }
}