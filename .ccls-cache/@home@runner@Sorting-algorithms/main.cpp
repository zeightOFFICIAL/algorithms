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
16.03.2022
ver 1.1
*/

#include <iostream>
#include <fstream>
#include <random>

#include "SortingAlgorithms.h"

using std::cout, std::cin, std::ios, std::ofstream, std::ifstream, std::string;
const int EXTREME_LENGTH = 1000000; 

/**
    (int A, int B, int C)->(int*)
    Generates the array, with the length of A, using true random
    numbers. Seeds of the random numbers are equal to current time.
    Each value is generated within range of B...C
    Returns the array.
    >>GenerateArray_TrulyRandom(Amount of elements, max value, min value)
*/  
int *GenerateArray_TrulyRandom(int amount_of_elements, int max_value, int min_value);
/**
    (int A)->(int A[])->(int*)
    Creates the array, with the length of A, using custom (user's)
    numbers.
    Returns the array.
    >>GenerateArray_TrulyRandom(Amount of elements)
    >>Input element with index 0: 6
    >>Input element with index 1: 10
*/  
int *GenerateArray_CustomNumbers(int amount_of_elements);
/**
    (int* A)->(int*)
    Creates the array, taking all the numbers from the file.
    File location is: (exodus/presort.txt) Variable A
    is respond for amount of elements in the array.
    Return the array.
    >>GenerateArray_FromFile(Amount of elements)
*/
int *GenerateArray_FromFile(int &amount_of_elements);
/**
    (int* A, int B)->()
    Prints all values of the array A with length of B
    in console. Returns nothing.
    >>print_array(array,Amount of elements)
    >>-150
    >>56
*/ 
void print_array(int* array, int amount_of_elements);
/**
    (int* A, int B)->()
    Prints all values of the array A with length of B
    in file (exodus/presort.txt). Returns nothing
    Returns nothing.
    >>write_array(array,Amount of elements)
*/ 
void write_array(int* array, int amount_of_elements);

//============================================================================

int *GenerateArray_TrulyRandom(int amount_of_elements, int max_value, int min_value)
{    
    static int array[EXTREME_LENGTH];
    srand((int)time(0));   
    for (int i = 0; i < amount_of_elements; i++)
        array[i]=rand()%(max_value-min_value+1)+min_value;
    return array;
}

int *GenerateArray_CustomNumbers(int amount_of_elements)
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

int *GenerateArray_FromFile(int &amount_of_elements)
{
    static int array[EXTREME_LENGTH];
    int this_number;
    string this_string;
    int amount_of_elements_local = 0;
    ifstream file("exodus/presort.txt"); 
    while (getline (file, this_string)) {
        this_number=stoi(this_string);
        array[amount_of_elements_local]=this_number;
        amount_of_elements_local++;
    }
    amount_of_elements = amount_of_elements_local;
    return array;
}

void print_array(int* array, int amount_of_elements)
{
    for (auto i = 0; i < amount_of_elements; i++)
        cout<<"i: "<<i<<" Value: "<<array[i]<<"\n";
}

void write_array(int* array, int amount_of_elements)
{
    ofstream file;
    file.open("exodus/presort.txt",ios::trunc);
    for (int i = 0; i < amount_of_elements; i++)
        file<<array[i]<<"\n";
    file.close();
}

//============================================================================

int main() {
    int amount_of_elements = 1000;
    int min_value = -15000;
    int max_value = 15000;
    int *array;
    int *array_sorted;
    cout<<"Start."<<"\n";
   
    //array=GenerateArray_TrulyRandom(amount_of_elements,max_value,min_value);
    //array=GenerateArray_CustomNumbers(amount_of_elements);
    array = GenerateArray_FromFile(amount_of_elements);

    //write_array(array,amount_of_elements);
    //print_array(array,amount_of_elements);
    
    SortArray_BubbleSort(array,amount_of_elements);
    //print_array(array_sorted,amount_of_elements);
    SortArray_HeapSort(array,amount_of_elements);
    SortArray_InsertionSort(array,amount_of_elements);
    
    cout<<"End."<<"\n";
}