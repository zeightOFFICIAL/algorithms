#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

#include "SortingAlgorithms.h"

using namespace std;

void SortArray_BubbleSort(int AmountOfElements, int *ArrayX)
{
    int i, j; 
    for (i = 0; i < AmountOfElements-1; i++)           
        for (j = 0; j < AmountOfElements-i-1; j++) 
            if (ArrayX[j] > ArrayX[j+1]) 
                Tool_Swap(&ArrayX[j], &ArrayX[j+1]); 
    ofstream file;
    file.open("exodus/bubblesort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            file<<ArrayX[i]<<endl;
        }
    file.close();
}

void Tool_Swap(int *LeftElement, int *RightElement) 
{ 
    int temp = *LeftElement; 
    *LeftElement = *RightElement; 
    *RightElement = temp; 
} 

void Tool_Cleartxt()
{
    ofstream file;
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