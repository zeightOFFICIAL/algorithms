//use only for testing of the program's work
//for version 1.2
#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>

#include "auxiliary.h"

#include "heap_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "stooge_sort.h"
#include "gnome_sort.h"


void fulltest(unsigned long amount_of_elements, int tries)
{
    long long* array; //array to be sorted    
    long double alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0; //time summers    
    int min_value = -15000, max_value = 15000; //intervals of generating numbers
    std::chrono::steady_clock::time_point start, end, start2, end2, start3, end3, start4, end4, start5, end5; //time stamps

    for(int local_tries = 0; local_tries < tries; local_tries++)
        {
            array = GenerateRandomArray<long long>(amount_of_elements,max_value,min_value);
            start = std::chrono::steady_clock::now();
            BubbleSort(array, amount_of_elements);
            end = std::chrono::steady_clock::now();
            alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;

            array = GenerateRandomArray<long long>(amount_of_elements, max_value, min_value);
            start2 = std::chrono::steady_clock::now();
            HeapSort(array, amount_of_elements);
            end2 = std::chrono::steady_clock::now();
            alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;

            array = GenerateRandomArray<long long>(amount_of_elements, max_value, min_value);
            start3 = std::chrono::steady_clock::now();
            InsertionSort(array, amount_of_elements);
            end3 = std::chrono::steady_clock::now();
            alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;

            array = GenerateRandomArray<long long>(amount_of_elements, max_value, min_value);
            start4 = std::chrono::steady_clock::now();
            StoogeSort(array, amount_of_elements);
            end4 = std::chrono::steady_clock::now();
            alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;

            array = GenerateRandomArray<long long>(amount_of_elements, max_value, min_value);
            start5 = std::chrono::steady_clock::now();
            GnomeSort(array, amount_of_elements);
            end5 = std::chrono::steady_clock::now();
            alltime5 = alltime5 + std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() / 1000000.0;
        }
    std::cout << "Bubble sort: Average time: " << std::setprecision(9) <<  (alltime / tries) << " seconds" << "\n";
    std::cout << alltime << "  " << tries << "\n";
    std::cout << "Heap sort: Average time: " << std::setprecision(9) << (alltime2 / tries) << " seconds" << "\n";
    std::cout << alltime2 << "  " << tries << "\n";
    std::cout << "Insertion sort: Average time: " << std::setprecision(9) << (alltime3 / tries) << " seconds" << "\n";
    std::cout << alltime3 << "  " << tries << "\n";
    std::cout << "Stooge sort: Average time: " << std::setprecision(9) << (alltime4 / tries) << " seconds" << "\n";
    std::cout << alltime4 << "  " << tries << "\n";
    std::cout << "Gnome sort: Average time: " << std::setprecision(9) << (alltime5 / tries) << " seconds" << "\n";
    std::cout << alltime5 << "  " << tries << "\n";
    std::cout << "Total elements: " << amount_of_elements << "\n";
    std::cout << "Total tries: " << tries << "\n";
}