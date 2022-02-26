#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cmath>

#include "SortingAlgorithms.h"

using namespace std;

void SortArray_BubbleSort(int *ArrayY)
{
/*
    (int* A)->()
    Reads presort file, where the array is stored. After that
    sorts all the array in ascending order and writes it
    in array A.
    Returns nothing.
    >>SortArray_BubbleSort(ArrayBubbleSorted)
    <<Array is sorted in ascending order. (Bubble sort)
      Result in bubblesort.txt
*/
    int i, j, ThisNumber;
    int StartPoint = 0;
    int AmountOfElements = 0;
    string ThisLine;

    Tool_ClearSortTxt();
    ifstream File("exodus/presort.txt"); 
    while (getline(File, ThisLine))
    {
        ThisNumber=stoi(ThisLine);
        ArrayY[AmountOfElements]=ThisNumber;
        AmountOfElements++;
    }
    
    for (i = 0; i < AmountOfElements-1; i++)           
        for (j = 0; j < AmountOfElements-i-1; j++) 
            if (ArrayY[j] > ArrayY[j+1]) 
                Tool_Swap(&ArrayY[j], &ArrayY[j+1]); 
    ofstream file;
    file.open("exodus/bubblesort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            file<<ArrayY[i]<<endl;
        }
    file.close();
    cout<<"Array is sorted in ascending order. (Bubble sort)\nResult in bubblesort.txt\n";
}

void SortArray_HeapSort(int *ArrayY)
{
/*
    (int* A)->()
    Reads presort file, where the array is stored. After that
    sorts all the array in ascending order and writes it
    in array A.
    Returns nothing.
    >>SortArray_HeapSort(ArrayHeapSorted)
    <<Array is sorted in ascending order. (Heap sort)
      Result in heapsort.txt
*/    
    int AmountOfElements, i, ThisNumber;
    string ThisLine;
    
    Tool_ClearSortTxt();
    ifstream File("exodus/presort.txt"); 
    while (getline(File, ThisLine))
    {
        ThisNumber=stoi(ThisLine);
        ArrayY[AmountOfElements]=ThisNumber;
        AmountOfElements++;
    }
    AmountOfElements=AmountOfElements-1;
    File.close();
    
    for (int i = AmountOfElements / 2 - 1; i >= 0; i--)
        Tool_Heapify(ArrayY, AmountOfElements, i);
    for (int i = AmountOfElements - 1; i > 0; i--) 
    {
        Tool_Swap(&ArrayY[0], &ArrayY[i]);
        Tool_Heapify(ArrayY, i, 0);
    }        
    
    ofstream file;
    file.open("exodus/heapsort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            file<<ArrayY[i]<<endl;
        }
    file.close();
    cout<<"Array is sorted in ascending order. (Heap sort)\nResult in heapsort.txt\n";
}

void SortArray_StoogeSort(int *ArrayY)
{
/*
    (int* A)->()
    Reads presort file, where the array is stored. After that
    sorts all the array in ascending order and writes it
    in array A.
    Returns nothing.
    >>SortArray_HeapSort(ArrayHeapSorted)
    <<Array is sorted in ascending order. (Heap sort)
      Result in heapsort.txt
*/ 
    int i, ThisNumber, AmountOfNumbers;
    string ThisLine;
    
    Tool_ClearSortTxt();
    ifstream File("exodus/presort.txt"); 
    while (getline(File, ThisLine))
    {
        ThisNumber=stoi(ThisLine);
        ArrayY[AmountOfNumbers]=ThisNumber;
        AmountOfNumbers++;
    }
    File.close();

    
    
    ofstream file;
    file.open("exodus/stoogesort.txt",ios::app);
    for (int i = 0; i < AmountOfNumbers; i++)
        {   
            file<<ArrayY[i]<<endl;
        }
    file.close();
    cout<<"Array is sorted in ascending order. (Stooge sort)\nResult in stoogesort.txt\n";
}

//=============================================================================

void Tool_Swap(int *LeftElement, int *RightElement) 
{
/*
    (int* A, int* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>Tool_Swap(&ArrayX[K],&Array[K+1])
*/
    int temp = *LeftElement; 
    *LeftElement = *RightElement; 
    *RightElement = temp; 
} 

void Tool_ClearTxt()
{
/*
    ()->()
    Clears all the used txts.
    Returns nothing.
    >>ClearTxts()
*/
    ofstream file;
    file.open("exodus/presort.txt");
    file<<"";
    file.close();
    file.open("exodus/bubblesort.txt");
    file<<"";
    file.close();
    file.open("exodus/heapsort.txt");
    file<<"";
    file.close();
    file.open("exodus/stoogesort.txt");
    file<<"";
    file.close();
}

void Tool_ClearSortTxt()
{
/*
    ()->()
    Clears all the txts which stores sorted arrays.
    Returns nothing.
    >>ClearTxts()
*/
    ofstream file;
    file.close();
    file.open("exodus/bubblesort.txt");
    file<<"";
    file.close();
    file.open("exodus/heapsort.txt");
    file<<"";
    file.close();
    file.open("exodus/stoogesort.txt");
    file<<"";
    file.close();
}

void Tool_Heapify(int Array[], int AmountOfElements, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < AmountOfElements && Array[l] > Array[largest])
        largest = l;
    if (r < AmountOfElements && Array[r] > Array[largest])
        largest = r;
    if (largest != i) {
        Tool_Swap(&Array[i], &Array[largest]);
        Tool_Heapify(Array, AmountOfElements, largest);
    }
}