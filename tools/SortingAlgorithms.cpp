#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cmath>

#include "SortingAlgorithms.h"

using namespace std;

void SortArray_HeapSort(int *ArrayY2, int Length)
{
    int AmountOfElements, i;
    string ThisLine;

    AmountOfElements = Length;
    
    for (int i = AmountOfElements / 2 - 1; i >= 0; i--)
        Tool_Heapify(ArrayY2, AmountOfElements, i);
    for (int i = AmountOfElements - 1; i > 0; i--) 
        {
            Tool_Swap(&ArrayY2[0], &ArrayY2[i]);
            Tool_Heapify(ArrayY2, i, 0);
        }        
}

//=============================================================================

void Tool_Swap(int *LeftElement, int *RightElement) 
{
    int temp = *LeftElement; 
    *LeftElement = *RightElement; 
    *RightElement = temp; 
} 

void Tool_Heapify(int* ArrayY4, int AmountOfElements, int i)
{
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