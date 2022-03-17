/*
    (int* A, int B)->(int*)
    Takes an array A with length of B and sorts it in 
    the ascending order, using bubble sorting. 
    Puts all the sorted numbers in the new array 
    and returns it.
    >>bubble_sort(unsorted array, amount of elements)
*/
int* bubble_sort(int* array, int amount_of_elements);
/*
    (int* A, int B)->(int*)
    Takes an array A with length of B and sorts it in 
    the ascending order, using heap sorting. 
    Puts all the sorted numbers in the new array 
    and returns it.
    >>heap_sort(unsorted array, amount of elements)
*/
int* heap_sort(int* array, int amount_of_elements);
/*
    (int* A, int B)->(int*)
    Takes an array A with length of B and sorts it in 
    the ascending order, using insertion sorting. 
    Puts all the sorted numbers in the new array 
    and returns it.
    >>insertion_sort(unsorted array, amount of elements)
*/
int* insertion_sort(int* array, int amount_of_elements);

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
    build the max heap tree, with maximum value at the vertex.
    Generally, speaking tree must be in decreasing order.
    Process 'heapify' changes the values so that the tree, beside
    the already sorted part is in decreasing order, technically
    parent value of the tree is bigger than children's. 
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