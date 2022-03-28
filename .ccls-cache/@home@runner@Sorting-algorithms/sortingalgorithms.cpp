/*#include <iostream>
#include <fstream>
#include <ctime>

#include "sortingalgorithms.h"

using std::cout, std::ios, std::ofstream, std::string;
const int EXTREME_LENGTH = 1000000; 

void BubbleSort(int* array, int amount_of_elements)
{
    for (auto i = 0; i < amount_of_elements-1; i++)           
        for (auto j = 0; j < amount_of_elements-i-1; j++) 
            if (array[j] > array[j+1]) 
                ToolSwapByPointer(&array[j], &array[j+1]); 
}

void HeapSort(int* array, int amount_of_elements)
{    
    for (auto i = amount_of_elements / 2 - 1; i >= 0; i--)
        ToolHeapifyArray(array, amount_of_elements, i);
    for (auto i = amount_of_elements - 1; i > 0; i--) 
        {
            ToolSwapByPointer(&array[0], &array[i]);
            ToolHeapifyArray(array, i, 0);
        }        
}

void InsertionSort(int* array, int amount_of_elements)
{
    int key;
    for (auto i = 1; i < amount_of_elements; i++)  {
            key = array[i];
            auto j = i - 1;
            while (j >= 0 && array[j] > key)  {
                    array[j + 1] = array[j];
                    j = j - 1;
                }
            array[j + 1] = key;
        }
}

//=============================================================================
void ToolSwapByPointer(int *left_element, int *right_element)
{
    int temp = *left_element; 
    *left_element = *right_element; 
    *right_element = temp; 
} 

void ToolHeapifyArray(int* array, int amount_of_elements, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2; 
    if (l < amount_of_elements && array[l] > array[largest])
        largest = l;
    if (r < amount_of_elements && array[r] > array[largest])
        largest = r;
    if (largest != i) {
        ToolSwapByPointer(&array[i], &array[largest]);
        ToolHeapifyArray(array, amount_of_elements, largest);
    }
}

void WriteProof(int* array, int* array2, int* array3, int amount_of_elements)
{
    ofstream file;
    file.open("exodus/sorted.txt",ios::trunc);
    file<<"The only proof of the correctness of all\nthese sorting algorithms is actual exactness\nof how they've performed. The equality of\nsorted arrays proves so.\n1st method\t2nd method\t3rd method\n";
    for (int i = 0; i < amount_of_elements; i++)
        file<<array[i]<<"\t"<<array2[i]<<"\t"<<array3[i]<<"\n";
    file.close();
}

void WriteArray(int* array, int amount_of_elements, string name)
{
    string path = "exodus/"+name+".txt";
    ofstream file;
    file.open(path,ios::trunc);
    for (int i = 0; i < amount_of_elements; i++)
        file<<array[i]<<"\n";
    file.close();
}