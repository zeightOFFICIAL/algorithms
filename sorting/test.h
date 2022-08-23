//use only for testing of the program's work
//for version 1.2
#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

#include "heap_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "stooge_sort.h"
#include "gnome_sort.h"

const unsigned long EXTREME_LENGTH = 429496;

/*
    (unsigned long A, long long B, long long C)->(long long* D)
    Generates the array, with the length of A, using true random
    numbers. Seeds of the random numbers are equal to current time.
    Each value is generated within range of B...C
    Returns the array.
    >>GenerateRandomArray(amount of elements, max value, min value)
*/
long long* GenerateRandomArray(unsigned long amount_of_elements, long long max_value, long long min_value)
{
    long long* array = new long long[EXTREME_LENGTH];
    srand((int)time(0));
    for (unsigned long index = 0; index < amount_of_elements; index++)
        array[index] = (rand() % (max_value - min_value) + min_value);
    return array;
}
/*
    (T* A, unsigned long B)->()
    Prints all values of the array A with length of B
    in console. Returns nothing.
    >>PrintArray(array, amount of elements)
    >>-150
    >>56
*/
template <typename T>
void PrintArray(T* array, unsigned long amount_of_elements)
{
    for (unsigned long index = 0; index < amount_of_elements; index++)
        std::cout << "i: " << index << " value: " << array[index] << "\n";
}
/*
    (unsigned long A)->(T A[])->(T*)
    Creates the array, with the length of A, using custom (user's)
    numbers.
    Returns the array.
    >>GenerateCustomArray(amount of elements)
    >>Input element with index 0: 6
    >>Input element with index 1: 10
*/
long long* GenerateCustomArray(unsigned long amount_of_elements)
{
    long long* array = new long long[EXTREME_LENGTH];
    long long this_element = 0;
    for (unsigned long index = 0; index < amount_of_elements; index++) {
        std::cout << "Input element with index " << index << ": ";
        std::cin >> this_element;
        array[index] = this_element;
    }
    return array;
}
/*
    (string A, unsigned long &B)->(long long* C)
    Creates the array, taking all the numbers from the file.
    File location is string A, Variable B responds for
    amount of elements in the array. Return the array C.
    >>GenerateArrayFile("test.txt", Amount of elements)
*/
long long* GenerateArrayFile(std::string filename, unsigned long& amount_of_elements)
{
    static long long array[EXTREME_LENGTH];
    long long this_number, amount_of_elements_local = 0;
    std::string this_string;
    std::ifstream file;
    file.open(filename);
    if (!file)
        std::cout << "wr: No such file.";
    else {
        while (getline(file, this_string)) {
            this_number = stoll(this_string);
            array[amount_of_elements_local] = this_number;
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
    >>WriteProof("test.txt", array1, array2, array3, amount of elements)
*/
template <typename T>
void WriteProof(std::string filename, T* array, T* array2, T* array3, unsigned long long amount_of_elements)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
    if (!file)
        std::cout << "wr: No such file.";
    else {
        file << "The only proof of the correctness of all\nthese sorting algorithms is actual exactness\nof how they've performed. The equality of\nsorted arrays proves so.\n1st method\t2nd method\t3rd method\n";
        for (unsigned long index = 0; index < amount_of_elements; index++)
            file << array[index] << "\t" << array2[index] << "\t" << array3[index] << "\n";
    }
    file.close();
}
/*
    (string A, T* B, ulong C)->()
    Prints all values of the array B with length of C
    in file with path A.
    Returns nothing.
    >>WriteArray("test.txt", array, Amount of elements)
*/
template <typename T>
void WriteArray(std::string filename, T* array, unsigned long amount_of_elements)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
    if (!file)
        std::cout << "wr: No such file.";
    else
        for (unsigned long index = 0; index < amount_of_elements; index++)
            file << array[index] << "\n";
    file.close();
}
// -------------------------------------------------------------------------------------------------------------------------
void fulltest(int tries)
{
    long long* array, * array2, * array3, * array4, * array5;
    long double alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0; //time summers    
    int min_value = -15000, max_value = 15000; //intervals of generating numbers
    std::chrono::steady_clock::time_point start, end, start2, end2, start3, end3, start4, end4, start5, end5; //time stamps
    int local_length;
    for (local_length = 5000; local_length <= 100000; local_length += 5000) {
        std::cout << local_length << "\n";
        alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0;
        for (int local_tries = 0; local_tries < tries; local_tries++)
        {
            array = GenerateRandomArray(local_length, max_value, min_value);
            start = std::chrono::steady_clock::now();
            BubbleSort(array, local_length, false);
            end = std::chrono::steady_clock::now();
            alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;

            array2 = GenerateRandomArray(local_length, max_value, min_value);
            start2 = std::chrono::steady_clock::now();
            HeapSort(array2, local_length, false);
            end2 = std::chrono::steady_clock::now();
            alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;

            array3 = GenerateRandomArray(local_length, max_value, min_value);
            start3 = std::chrono::steady_clock::now();
            InsertionSort(array3, local_length, false);
            end3 = std::chrono::steady_clock::now();
            alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;

            array4 = GenerateRandomArray(local_length, max_value, min_value);
            start4 = std::chrono::steady_clock::now();
            //StoogeSort(array4, local_length, false);
            end4 = std::chrono::steady_clock::now();
            alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;

            array5 = GenerateRandomArray(local_length, max_value, min_value);
            start5 = std::chrono::steady_clock::now();
            GnomeSort(array5, local_length, false);
            end5 = std::chrono::steady_clock::now();
            alltime5 = alltime5 + std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() / 1000000.0;
        }        
        delete array;
        delete array2;
        delete array3;
        delete array4;
        delete array5;
        std::cout << "Bubble sort: Average time: " << std::setprecision(9) << (alltime / tries) << " seconds" << "\n";
        std::cout << "Heap sort: Average time: " << std::setprecision(9) << (alltime2 / tries) << " seconds" << "\n";
        std::cout << "Insertion sort: Average time: " << std::setprecision(9) << (alltime3 / tries) << " seconds" << "\n";
        std::cout << "Stooge sort: Average time: " << std::setprecision(9) << (alltime4 / tries) << " seconds" << "\n";
        std::cout << "Gnome sort: Average time: " << std::setprecision(9) << (alltime5 / tries) << " seconds" << "\n";
        std::cout << "Total elements: " << local_length << "\n";
        std::cout << "Total tries: " << tries << "\n";
        std::cout << "\n";
    }
}
