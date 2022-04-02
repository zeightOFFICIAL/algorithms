#pragma once

#include <random>
#include <iostream>
#include <fstream>
#include <string>

const unsigned long int EXTREME_LENGTH = 10000000;

/*
    (T* A, T* B)->()
    Swaps element A with element B of an array, or other structure.
    Returns nothing.
    >>ToolSwapByPointer(&array[K],&array[K+1])
*/
template <typename T>
void ToolSwapByPointer(T *left_element, T *right_element)  {
    T temp = *left_element; 
    *left_element = *right_element; 
    *right_element = temp; 
} 

/*
    (ulong A, long B, long C)->(T* D)
    Generates the array, with the length of A, using true random
    numbers. Seeds of the random numbers are equal to current time.
    Each value is generated within range of B...C
    Returns the array.
    >>GenerateRandomArray(amount of elements, max value, min value)
*/
template <typename T>
T *GenerateRandomArray(unsigned long amount_of_elements, long max_value, long min_value)
{    
    static T array[EXTREME_LENGTH];
    srand((int)time(0));   
    for (unsigned long i = 0; i < amount_of_elements; i++)
        array[i]=static_cast<T>(rand()%(max_value-min_value)+min_value);
    return array;
}

/*
    (T* A, ulong B)->()
    Prints all values of the array A with length of B
    in console. Returns nothing.
    >>PrintArray(array, amount of elements)
    >>-150
    >>56
*/
template <typename T>
void PrintArray(T* array, unsigned long amount_of_elements)
{
    for (unsigned long i = 0; i < amount_of_elements; i++)
        std::cout<<"i: "<<i<<" Value: "<<array[i]<<"\n";
}

/*
    (ulong A)->(T A[])->(T*)
    Creates the array, with the length of A, using custom (user's)
    numbers.
    Returns the array.
    >>GenerateCustomArray(amount of elements)
    >>Input element with index 0: 6
    >>Input element with index 1: 10
*/
template <typename T>
T *GenerateCustomArray(unsigned long amount_of_elements)
{     
    static T array[EXTREME_LENGTH];
    T this_element = 0;
    for (unsigned long i = 0; i < amount_of_elements; i++)  {   
            std::cout<<"Input element with index "<<i<<": ";
            std::cin>>this_element;
            array[i]=this_element;
        }
    return array;
}

/*
    (string A, ulong &B)->(long long* C)
    Creates the array, taking all the numbers from the file.
    File location is string A, Variable B responds for 
    amount of elements in the array. Return the array C.
    >>GenerateArrayFile("test.txt",Amount of elements)
*/
long long *GenerateArrayFile(std::string filename, unsigned long &amount_of_elements)
{
    static long long array[EXTREME_LENGTH];
    long long this_number, amount_of_elements_local = 0;
    std::string this_string;
    std::ifstream file;
    file.open(filename);
	if (!file)
		std::cout << "No such file.";
	else  {
            while (getline (file, this_string)) {
            this_number=stoll(this_string);
            array[amount_of_elements_local]=this_number;
            amount_of_elements_local++;
        }
	}
    file.close();
    amount_of_elements = amount_of_elements_local;
    return array;
}

/*
    (string A, T* B, T* C, T* D, ulong E)->()
    Writes all the sorted arrays (B,C,D) 
    with length of D in the file with path A. 
    Thus user can examine that all the
    algorithms are equally correct.
    Returns nothing.
    >>WriteProof("test.txt",array1,array2,array3,amount of elements)
*/
template <typename T> 
void WriteProof(std::string filename, T* array, T* array2, T* array3, unsigned long amount_of_elements)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
	if (!file)
		std::cout << "No such file.";
	else  {
        file<<"The only proof of the correctness of all\nthese sorting algorithms is actual exactness\nof how they've performed. The equality of\nsorted arrays proves so.\n1st method\t2nd method\t3rd method\n";
        for (unsigned long i = 0; i < amount_of_elements; i++)
        file<<array[i]<<"\t"<<array2[i]<<"\t"<<array3[i]<<"\n";
        }
    file.close();
}

/*
    (string A, T* B, ulong C)->()
    Prints all values of the array B with length of C
    in file with path A.
    Returns nothing.
    >>WriteArray("test.txt", array ,Amount of elements)
*/
template <typename T> 
void WriteArray(std::string filename, T* array, unsigned long amount_of_elements)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
	if (!file)
		std::cout << "No such file.";
	else
        for (unsigned long i = 0; i < amount_of_elements; i++)
            file<<array[i]<<"\n";
    file.close();
}