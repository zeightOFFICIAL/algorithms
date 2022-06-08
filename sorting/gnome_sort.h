#pragma once
#include "auxiliary.h"

/*
    (T* A, unsigned long B)->()
    Takes an array A (type T) with length of B and sorts it in
    the ascending order, using gnome sorting.
    Changes the array given as argument.
    >>GnomeSort(unsorted array, amount of elements)
*/
template <typename T>
void GnomeSort(T* array, unsigned long amount_of_elements) {
    unsigned long i = 0;
    while (i < amount_of_elements)  {
        if (i == 0 || array[i] >= array[i - 1])
            i++;
        else  {
            ToolSwapByPointer<T>(&array[i], &array[i - 1]);
            i--;
        }
    }
}