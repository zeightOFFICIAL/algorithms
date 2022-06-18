#pragma once
/*
    (T* A, long long B, long long C, bool D) -> ()
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
void HeapifyArray(T* array, long long amount_of_elements, long long i, bool order)
{
    long long peak = i, left_child = 2 * i + 1, right_child = 2 * i + 2;
    if (order == true) {
        if (left_child < amount_of_elements && array[left_child] > array[peak])
            peak = left_child;
        if (right_child < amount_of_elements && array[right_child] > array[peak])
            peak = right_child;
    }
    else if (order == false) {
        if (left_child < amount_of_elements && array[left_child] < array[peak])
            peak = left_child;
        if (right_child < amount_of_elements && array[right_child] < array[peak])
            peak = right_child;
    }
    if (peak != i) {
        SwapByPointer__<T>(&array[i], &array[peak]);
        HeapifyArray<T>(array, amount_of_elements, peak, order);
    }
}
/*
    (T* A, unsigned long B, bool C)->()
    Takes an array A with length of B and sorts it in 
    the ascending order if C - true, descending if 
    C - false, using heap sorting. 
    Changes the array given as argument.
    >>HeapSort(unsorted array, amount of elements, order)
*/
template <typename T>
void HeapSort(T* array, unsigned long amount_of_elements, bool order = true)
{    
    for (long long this_nexus = amount_of_elements / 2 - 1; this_nexus >= 0; this_nexus--)
        HeapifyArray<T>(array, amount_of_elements, this_nexus, order);
    for (long long this_nexus = amount_of_elements - 1; this_nexus > 0; this_nexus--)  {
            SwapByPointer__<T>(&array[0], &array[this_nexus]);
            HeapifyArray<T>(array, this_nexus, 0, order);
        }        
}
/*
    (T* A, T* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>SwapByPointer__(&array[K], &array[K+1])
*/
template <typename T>
void SwapByPointer__(T* left_element, T* right_element)
{
    T temp = *left_element;
    *left_element = *right_element;
    *right_element = temp;
}