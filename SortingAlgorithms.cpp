#include <iostream>
//#include <algorithm>
#include <fstream>
#include <ctime>
#include <cmath>
#include <array>

#include "SortingAlgorithms.h"

using std::cout, std::ios, std::ofstream, std::string;
const int EXTREME_LENGTH = 1000000; 

int* SortArray_BubbleSort(int* array, int amount_of_elements)
{
    static int* array_sorted = array;    
    clock_t t;

    t = clock();
    for (auto i = 0; i < amount_of_elements-1; i++)           
        for (auto j = 0; j < amount_of_elements-i-1; j++) 
            if (array_sorted[j] > array_sorted[j+1]) 
                tool_swap_byptr(&array_sorted[j], &array_sorted[j+1]); 
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
        tool_heapify_array(array_sorted, amount_of_elements, i);
    for (auto i = amount_of_elements - 1; i > 0; i--) 
        {
            tool_swap_byptr(&array_sorted[0], &array_sorted[i]);
            tool_heapify_array(array_sorted, i, 0);
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

void tool_swap_byptr(int *left_element, int *right_element)
{
    auto temp = *left_element; 
    *left_element = *right_element; 
    *right_element = temp; 
} 

void tool_heapify_array(int* array, int amount_of_elements, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < amount_of_elements && array[l] > array[largest])
        largest = l;
    if (r < amount_of_elements && array[r] > array[largest])
        largest = r;
    if (largest != i) {
        tool_swap_byptr(&array[i], &array[largest]);
        tool_heapify_array(array, amount_of_elements, largest);
    }
}

void write_proof(int* array, int* array2, int* array3, int amount_of_elements)
{
    ofstream file;
    file.open("exodus/sorted.txt",ios::trunc);
    file<<"The only proof of the correctness of all\nthese sorting algorithms is actual exactness\nof how they've performed. The equality of\nsorted arrays proves so.\n1st method\t2nd method\t3rd method\n";
    for (int i = 0; i < amount_of_elements; i++)
        file<<array[i]<<"\t"<<array2[i]<<"\t"<<array3[i]<<"\n";
    file.close();
}

void write_array(int* array, int amount_of_elements, string name)
{
    string path = "exodus/"+name+".txt";
    ofstream file;
    file.open(path,ios::trunc);
    for (int i = 0; i < amount_of_elements; i++)
        file<<array[i]<<"\n";
    file.close();
}