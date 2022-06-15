#pragma once
#include "auxiliary.h"

/*
    (T* A, unsigned long B)->()
    Takes an array A (type T) with length of B and sorts it in 
    the ascending order, using bubble sorting. 
    Changes the array given as argument.
    >>BubbleSort(unsorted array, amount of elements)
*/
template <typename T>
void BubbleSort(T* array, unsigned long amount_of_elements)  {
    for (unsigned long i = 0; i < amount_of_elements-1; i++)           
        for (unsigned long j = 0; j < amount_of_elements-i-1; j++) 
            if (array[j] > array[j+1]) 
                ToolSwapByPointer<T>(&array[j], &array[j+1]); 
}