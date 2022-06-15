#pragma once
#include "auxiliary.h"

/*
    (T* A, long long B, long long C) -> ()
    In order for heapsort to work properly, firstly we need to
    build the max heap tree, with maximum value at the vertex.
    Generally, speaking tree must be in decreasing order.
    Process 'heapify' swaps the values so that the tree, beside
    the already sorted part is in decreasing order, technically
    parent value of the tree is bigger than children's.
    A is an array which is needed to be heapfied. B responds
    for amount of elements. C for current head of the tree
    >>ToolHeapifyArray(array,amount of elements, head)
*/
template <typename T>
void ToolHeapifyArray(T* array, long long amount_of_elements, long long i)
{
    auto largest = i, l = 2 * i + 1, r = 2 * i + 2; 
    if (l < amount_of_elements && array[l] > array[largest])
        largest = l;
    if (r < amount_of_elements && array[r] > array[largest])
        largest = r;
    if (largest != i) {
        ToolSwapByPointer<T>(&array[i], &array[largest]);
        ToolHeapifyArray<T>(array, amount_of_elements, largest);
    }
}

/*
    (T* A, long long B)->()
    Takes an array A with length of B and sorts it in 
    the ascending order, using heap sorting. 
    Changes the array given as argument.
    >>HeapSort(unsorted array, amount of elements)
*/
template <typename T>
void HeapSort(T* array, long long amount_of_elements)
{    
    for (auto i = amount_of_elements / 2 - 1; i >= 0; i--)
        ToolHeapifyArray<T>(array, amount_of_elements, i);
    for (auto i = amount_of_elements - 1; i > 0; i--) 
        {
            ToolSwapByPointer<T>(&array[0], &array[i]);
            ToolHeapifyArray<T>(array, i, 0);
        }        
}