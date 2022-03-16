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

//=================================================================

/**
    (int* A, int* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>Tool_Swap(&array[K],&array[K+1])
*/
void tool_swap_byptr(int *left_element, int *right_element);

/**
    (int* A, int B, int I) -> ()
    In order for heapsort to work properly, firstly we need to
    'heapify' array meaning, to create an indexed tree of all the
    numbers.

       30(0)                 
       /   \         
    70(1)   50(2)

    And after that to compare the parent with both children. Swap if 
    needed and to proceed deeper into the tree, further into the
    array.

       70(0)                 
       /   \         
    30(1)   50(2)

    Returns nothing.
    >>tool_heapify_array(array,amount of elements, head)
*/
void tool_heapify_array(int* array, int amount_of_elements, int i);

/**
    (int* A, int* B, int* C, int D)->()
    Writes all the sorted arrays (A,B,C) 
    with length of D in the file. Thus 
    user can examine that all the
    algorithms are equally correct.
    Returns nothing.
    >>write_proof(array1,array2,array3,amount of elements)
*/
void write_proof(int* array, int* array2, int* array3, int amount_of_elements);

/**
    (int* A, int B, std::string C)->()
    Prints all values of the array A with length of B
    in file (exodus/{C}.txt)
    Returns nothing.
    >>write_array(array,Amount of elements, "presort")
*/
void write_array(int* array, int amount_of_elements, std::string name);