//use only for testing of the program's work
//for version 1.19

#include <iostream>

#include "auxiliary.h"

#include "heap_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "stooge_sort.h"


void fulltest(unsigned long amount_of_elements, int tries)
{
    long long* array; //array to be sorted    
    long double alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0; //time summers    
    clock_t t; //getting current time    
    int min_value = -15000, max_value = 15000; //intervals of generating numbers
    
    for(int local_tries = 0; local_tries < tries; local_tries++)
        {
            array = GenerateRandomArray<long long>(amount_of_elements,max_value,min_value);
            t = clock();
            BubbleSort(array, amount_of_elements);
            t = clock()-t;
            alltime = alltime + ((float)t)/CLOCKS_PER_SEC;

            array = GenerateRandomArray<long long>(amount_of_elements, max_value, min_value);
            t = clock();
            HeapSort(array, amount_of_elements);
            t = clock() - t;
            alltime2 = alltime2 + ((float)t) / CLOCKS_PER_SEC;

            array = GenerateRandomArray<long long>(amount_of_elements, max_value, min_value);
            t = clock();
            InsertionSort(array, amount_of_elements);
            t = clock() - t;
            alltime3 = alltime3 + ((float)t) / CLOCKS_PER_SEC;

            array = GenerateRandomArray<long long>(amount_of_elements, max_value, min_value);
            t = clock();
            StoogeSort(array, amount_of_elements);
            t = clock() - t;
            alltime4 = alltime4 + ((float)t) / CLOCKS_PER_SEC;
        }
    std::cout << "Bubble sort: Average time: " <<  alltime / tries << " seconds" << "\n";
    std::cout << "Heap sort: Average time: " << alltime2 / tries << " seconds" << "\n";
    std::cout << "Insertion sort: Average time: " << alltime3 / tries << " seconds" << "\n";
    std::cout << "Stooge sort: Average time: " << alltime4 / tries << " seconds" << "\n";
    std::cout << "Total tries: " << tries << "\n";
}