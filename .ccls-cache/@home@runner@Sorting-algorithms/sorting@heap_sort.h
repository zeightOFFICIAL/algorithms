/*
    (T* A, T* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>ToolSwapByPointer(&array[K],&array[K+1])
*/
void ToolSwapByPointerHeap(long long int *left_element, long long int *right_element);

/*
    (T* A, unsigned long B, unsigned long C) -> ()
    In order for heapsort to work properly, firstly we need to
    build the max heap tree, with maximum value at the vertex.
    Generally, speaking tree must be in decreasing order.
    Process 'heapify' swaps the values so that the tree, beside
    the already sorted part is in decreasing order, technically
    parent value of the tree is bigger than children's. 
    >>ToolHeapifyArray(array,amount of elements, head)
*/
void ToolHeapifyArray(long long int* array, unsigned int amount_of_elements, unsigned int i);

/*
    (T* A, unsigned long B)->()
    Takes an array A with length of B and sorts it in 
    the ascending order, using heap sorting. 
    Changes the array given as argument.
    >>HeapSort(unsorted array, amount of elements)
*/
void HeapSort(long long int* array, unsigned int amount_of_elements);

//======================================================================

void HeapSort(long long int* array, unsigned int amount_of_elements)
{    
    for (unsigned int i = amount_of_elements / 2 - 1; i >= 0; i--)
        ToolHeapifyArray(array, amount_of_elements, i);
    for (unsigned int i = amount_of_elements - 1; i > 0; i--) 
        {
            ToolSwapByPointerHeap(&array[0], &array[i]);
            ToolHeapifyArray(array, i, 0);
        }        
}

void ToolSwapByPointerHeap(long long int *left_element, long long int *right_element)  {
    long long int temp = *left_element; 
    *left_element = *right_element; 
    *right_element = temp; 
} 

void ToolHeapifyArray(long long int* array, unsigned int amount_of_elements, unsigned int i)
{
    unsigned int largest = i, l = 2 * i + 1, r = 2 * i + 2; 
    if (l < amount_of_elements && array[l] > array[largest])
        largest = l;
    if (r < amount_of_elements && array[r] > array[largest])
        largest = r;
    if (largest != i) {
        ToolSwapByPointerHeap(&array[i], &array[largest]);
        ToolHeapifyArray(array, amount_of_elements, largest);
    }
}