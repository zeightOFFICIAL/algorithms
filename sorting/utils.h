#pragma once
/*
    (T* A, T* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>SwapByPointer(array[K], array[K+1])
*/
template <typename T>
void Swap(T left_element, T right_element)
{
    T temp = left_element;
    left_element = right_element;
    right_element = temp;
}