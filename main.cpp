/*
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 1 
Sorting algorithms
- Bubble sort
- Heap sort
- Insertion sort
- Stooge sort
Clang++ 12
main.cpp
02.04.2022
ver 1.193
*/

#include <iostream>

#include "sorting/auxiliary.h"

#include "sorting/heap_sort.h"
#include "sorting/bubble_sort.h"
#include "sorting/insertion_sort.h"
#include "sorting/stooge_sort.h"

//============================================================================
int main() {
    int min_value = -15000, max_value = 15000;
    unsigned long amount_of_elements = 5000;
    long long* array;
    clock_t t; // t = clock(); t = clock()-t; cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    
    std::cout<<"Start."<<"\n"; //.................................................

    //array = GenerateRandomArray<long long>(amount_of_elements,max_value,min_value);
    //farray = GenerateCustomArray<float>(amount_of_elements);
    //array = GenerateArrayFile("test.txt", amount_of_elements);
    
    //WriteArray("test.txt",array,amount_of_elements);
    //PrintArray(array,amount_of_elements);

    //farray2 = farray;
    //farray3 = farray;
    
    //BubbleSort(farray, amount_of_elements);
    //HeapSort(farray, amount_of_elements);
    //InsertionSort(farray,amount_of_elements);
    //StoogeSort(array,amount_of_elements);

    //WriteProof("test.txt",farray,farray2,farray3,amount_of_elements);

    //.....................................................................................
    /*
    long double alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0;
    int tries;
    std::cin >> amount_of_elements;
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
    */
    //.....................................................................................
    
    std::cout<<"End."<<"\n";  //.................................................
    return 0;
}