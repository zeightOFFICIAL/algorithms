//use only for testing of the program's work
//for version 1.19

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
    
    for(tries = 0; tries < 1; tries++)
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
    std::cout << "Average time: " <<  alltime / tries << " seconds" << "\n";
    std::cout << "Average time: " << alltime2 / tries << " seconds" << "\n";
    std::cout << "Average time: " << alltime3 / tries << " seconds" << "\n";
    std::cout << "Average time: " << alltime4 / tries << " seconds" << "\n";
}