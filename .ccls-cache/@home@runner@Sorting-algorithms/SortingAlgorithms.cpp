#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cmath>
#include <array>

#include "SortingAlgorithms.h"

using std::cout, std::copy, std::begin, std::end;
const int EXTREME_LENGTH = 1000000; 

int* SortArray_BubbleSort(int* array, int amount_of_elements)
{
    static int* array_sorted = array;    
    clock_t t;

    t = clock();
    for (auto i = 0; i < amount_of_elements-1; i++)           
        for (auto j = 0; j < amount_of_elements-i-1; j++) 
            if (array_sorted[j] > array_sorted[j+1]) 
                Tool_Swap(&array_sorted[j], &array_sorted[j+1]); 
    t = clock()-t;
    cout<<"Bubble sort. Elements: "<<amount_of_elements<<"\n";
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    return array_sorted;
}

int* SortArray_HeapSort(int* array, int amount_of_elements)
{    
    static int* array_sorted = array;   
    clock_t t;

    t = clock();
    for (auto i = amount_of_elements / 2 - 1; i >= 0; i--)
        Tool_Heapify(array_sorted, amount_of_elements, i);
    for (auto i = amount_of_elements - 1; i > 0; i--) 
        {
            Tool_Swap(&array_sorted[0], &array_sorted[i]);
            Tool_Heapify(array_sorted, i, 0);
        }        
    t = clock()-t;
    
    cout<<"Heap sort. Elements: "<<amount_of_elements<<"\n";
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    return array_sorted;
}

int* SortArray_InsertionSort(int* array, int amount_of_elements)
{
    static int* array_sorted = array; 
    clock_t t;
    int key;

    t = clock();
    for (auto i = 1; i < amount_of_elements; i++)
        {
            key = array_sorted[i];
            auto j = i - 1;
            while (j >= 0 && array[j] > key)
                {
                    array_sorted[j + 1] = array_sorted[j];
                    j = j - 1;
                }
            array_sorted[j + 1] = key;
        }
    t = clock()-t;
    cout<<"Insertion sort. Elements: "<<amount_of_elements<<"\n";
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    return array_sorted;
}

//=============================================================================

void Tool_Swap(int *LeftElement, int *RightElement) 
{
/*
    (int* A, int* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>Tool_Swap(&ArrayX[K],&Array[K+1])
    <<
*/
    int temp = *LeftElement; 
    *LeftElement = *RightElement; 
    *RightElement = temp; 
} 


void Tool_Heapify(int* ArrayY4, int AmountOfElements, int i)
{
/*
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
    >>Tool_Heapify(Array,AmountOfElements,Head)
*/
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < AmountOfElements && ArrayY4[l] > ArrayY4[largest])
        largest = l;
    if (r < AmountOfElements && ArrayY4[r] > ArrayY4[largest])
        largest = r;
    if (largest != i) {
        Tool_Swap(&ArrayY4[i], &ArrayY4[largest]);
        Tool_Heapify(ArrayY4, AmountOfElements, largest);
    }
}