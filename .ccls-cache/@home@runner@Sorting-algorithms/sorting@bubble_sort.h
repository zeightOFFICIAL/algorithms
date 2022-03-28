/*
    (T* A, T* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>ToolSwapByPointer(&array[K],&array[K+1])
*/
template <typename T>
void ToolSwapByPointer(T *left_element, T *right_element)  {
    T temp = *left_element; 
    *left_element = *right_element; 
    *right_element = temp; 
} 
/*
    (T* A, unsigned long B)->()
    Takes an array A with length of B and sorts it in 
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