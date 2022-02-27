#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cmath>

#include "SortingAlgorithms.h"

using namespace std;

void SortArray_BubbleSort(int *ArrayY1)
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
        ArrayY1[AmountOfElements]=ThisNumber;
        AmountOfElements++;
    }
    
    for (i = 0; i < AmountOfElements-1; i++)           
        for (j = 0; j < AmountOfElements-i-1; j++) 
            if (ArrayY1[j] > ArrayY1[j+1]) 
                Tool_Swap(&ArrayY1[j], &ArrayY1[j+1]); 
    ofstream file;
    file.open("exodus/bubblesort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            file<<ArrayY1[i]<<endl;
        }
    file.close();
    cout<<"Array is sorted in ascending order. (Bubble sort)\nResult in bubblesort.txt\n";
}

void SortArray_HeapSort(int *ArrayY2)
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
    AmountOfElements = 0;
    
    Tool_ClearSortTxt();
    ifstream File("exodus/presort.txt"); 
    while (getline(File, ThisLine))
    {
        ThisNumber=stoi(ThisLine);
        ArrayY2[AmountOfElements]=ThisNumber;
        AmountOfElements++;
    }
    File.close();
    
    for (int i = AmountOfElements / 2 - 1; i >= 0; i--)
        Tool_Heapify(ArrayY2, AmountOfElements, i);
    for (int i = AmountOfElements - 1; i > 0; i--) 
    {
        Tool_Swap(&ArrayY2[0], &ArrayY2[i]);
        Tool_Heapify(ArrayY2, i, 0);
    }        
    
    ofstream file;
    file.open("exodus/heapsort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            file<<ArrayY2[i]<<endl;
        }
    file.close();
    cout<<"Array is sorted in ascending order. (Heap sort)\nResult in heapsort.txt\n";
}

void SortArray_InsertionSort(int *ArrayY3)
{
/*
    (int* A)->()
    Reads presort file, where the array is stored. After that
    sorts all the array in ascending order and writes it
    in array A.
    Returns nothing.
    >>SortArray_InsertionSort(ArrayHeapSorted)
    <<Array is sorted in ascending order. (insertion sort)
      Result in insertionsort.txt
*/ 
    int i, j, ThisNumber, AmountOfElements, key;
    string ThisLine;
    AmountOfElements = 0;

    Tool_ClearSortTxt();
    ifstream File("exodus/presort.txt"); 
    while (getline(File, ThisLine))
    {
        ThisNumber=stoi(ThisLine);
        ArrayY3[AmountOfElements]=ThisNumber;
        AmountOfElements++;
    }
    File.close();

    for (i = 1; i < AmountOfElements; i++)
    {
        key = ArrayY3[i];
        j = i - 1;
        while (j >= 0 && ArrayY3[j] > key)
        {
            ArrayY3[j + 1] = ArrayY3[j];
            j = j - 1;
        }
        ArrayY3[j + 1] = key;
    }
    
    ofstream file;
    file.open("exodus/insertionsort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            file<<ArrayY3[i]<<endl;
        }
    file.close();
    cout<<"Array is sorted in ascending order. (Insertion sort)\nResult in insertionsort.txt\n";
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
    file.open("exodus/insertionsort.txt");
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
    file.open("exodus/insertionsort.txt");
    file<<"";
    file.close();
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