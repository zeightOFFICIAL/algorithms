/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 1 
Sorting algorithms
- Bubble sort
- Heap sort
- Insertion sort
main.cpp
23.03.2022
ver 1.16
*/

#include <iostream>
#include <fstream>
#include <random>

#include "sortingalgorithms.h"

using std::cout, std::cin, std::ios, std::ofstream, std::ifstream, std::string;
const unsigned long int EXTREME_LENGTH = 10000000; 

/**
    (int A, int B, int C)->(int*)
    Generates the array, with the length of A, using true random
    numbers. Seeds of the random numbers are equal to current time.
    Each value is generated within range of B...C
    Returns the array.
    >>GenerateRandomArray(Amount of elements, max value, min value)
*/  
int *GenerateRandomArray(int amount_of_elements, int max_value, int min_value);
/**
    (int A)->(int A[])->(int*)
    Creates the array, with the length of A, using custom (user's)
    numbers.
    Returns the array.
    >>GenerateCustomArray(Amount of elements)
    >>Input element with index 0: 6
    >>Input element with index 1: 10
*/  
int *GenerateCustomArray(int amount_of_elements);
/**
    (string A, int* B)->(int*)
    Creates the array, taking all the numbers from the file.
    File location is string A, Variable B responds for 
    amount of elements in the array.Return the array.
    >>GenerateArrayFile("test.txt",Amount of elements)
*/
int *GenerateArrayFile(string path, int &amount_of_elements);
/**
    (int* A, int B)->()
    Prints all values of the array A with length of B
    in console. Returns nothing.
    >>PrintArray(array,Amount of elements)
    >>-150
    >>56
*/ 
void PrintArray(int* array, int amount_of_elements);

//============================================================================

int *GenerateRandomArray(int amount_of_elements, int max_value, int min_value)
{    
    static int array[EXTREME_LENGTH];
    srand((int)time(0));   
    for (int i = 0; i < amount_of_elements; i++)
        array[i]=rand()%(max_value-min_value+1)+min_value;
    return array;
}

int *GenerateCustomArray(int amount_of_elements)
{     
    static int array[EXTREME_LENGTH];
    int this_number = 0;
    for (auto i = 0; i < amount_of_elements; i++)  {   
            cout<<"Input element with index "<<i<<": ";
            cin>>this_number;
            array[i]=this_number;
        }
    return array;
}

int *GenerateArrayFile(string path, int &amount_of_elements)
{
    static int array[EXTREME_LENGTH];
    int this_number;
    string this_string;
    int amount_of_elements_local = 0;
    ifstream file(path); 
    while (getline (file, this_string)) {
        this_number=stoi(this_string);
        array[amount_of_elements_local]=this_number;
        amount_of_elements_local++;
    }
    amount_of_elements = amount_of_elements_local;
    return array;
}

void PrintArray(int* array, int amount_of_elements)
{
    for (auto i = 0; i < amount_of_elements; i++)
        cout<<"i: "<<i<<" Value: "<<array[i]<<"\n";
}

//============================================================================

int main() {
    int amount_of_elements = 15000, min_value = -15000, max_value = 15000;
    int *array, *array_sorted1, *array_sorted2, *array_sorted3;
    
    cout<<"Start."<<"\n"; //.................................................

    array = GenerateRandomArray(amount_of_elements,max_value,min_value);
    //array = GenerateCustomArray(amount_of_elements);
    //array = GenerateArrayFile(amount_of_elements);

    //WriteArray(array,amount_of_elements,"presort");
    //PrintArray(array,amount_of_elements);
    
    array_sorted1 = BubbleSort(array,amount_of_elements);
    array_sorted2 = HeapSort(array,amount_of_elements);
    array_sorted3 = InsertionSort(array,amount_of_elements);
    
    //WriteArray(array_sorted1,amount_of_elements,"bubble");
    //WriteArray(array_sorted2,amount_of_elements,"heap");
    //WriteArray(array_sorted3,amount_of_elements,"insertion");
    
    //WriteProof(array_sorted1,array_sorted2,array_sorted3,amount_of_elements);
    
    cout<<"End."<<"\n";  //.................................................
    return 0;
}