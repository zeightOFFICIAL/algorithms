/*
    (int* A, int B)->(int*)
    Takes an array A with length of B and sorts it in 
    the ascending order, using bubble sorting. 
    Puts all the sorted numbers in the new array 
    and returns it.
    >>SortArray_BubbleSort(unsorted array, amount of elements)
*/
int* SortArray_BubbleSort(int* array, int amount_of_elements);
/*
    (int* A, int B)->(int*)
    Takes an array A with length of B and sorts it in 
    the ascending order, using heap sorting. 
    Puts all the sorted numbers in the new array 
    and returns it.
    >>SortArray_HeapSort(unsorted array, amount of elements)
*/
int* SortArray_HeapSort(int* array, int amount_of_elements);
/*
    (int* A, int B)->(int*)
    Takes an array A with length of B and sorts it in 
    the ascending order, using insertion sorting. 
    Puts all the sorted numbers in the new array 
    and returns it.
    >>SortArray_InsertionSort(unsorted array, amount of elements)
*/
int* SortArray_InsertionSort(int* array, int amount_of_elements);

//tools =======================================================

void Tool_Swap(int *LeftElement, int *RightElement);
void Tool_Heapify(int* ArrayY4, int AmountOfElements, int i);
void Tool_ClearTxt();
void Tool_ClearSortTxt();