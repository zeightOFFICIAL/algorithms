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
main.cpp
30.03.2022
ver 1.1905
*/

#include <iostream>

#include "sorting/auxiliary.h"

#include "sorting/heap_sort.h"
#include "sorting/bubble_sort.h"
#include "sorting/insertion_sort.h"
#include "sorting/stooge_sort.h"

using std::cout, std::cin, std::ios, std::ofstream, std::ifstream, std::string;

//============================================================================
int main() {
    int min_value = -15000, max_value = 15000;
    unsigned long amount_of_elements = 25000;
    long long* array;
    clock_t t; // t = clock(); t = clock()-t; cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    
    cout<<"Start."<<"\n"; //.................................................

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
    long double alltime = 0;
    int tries;
    for(tries = 0; tries < 100; tries++)
        {
            array = GenerateRandomArray<long long>(amount_of_elements,max_value,min_value);
            t = clock();
            BubbleSort(array, amount_of_elements);
            t = clock()-t;
            alltime = alltime + ((float)t)/CLOCKS_PER_SEC;
        }
    cout<<"Average time: "<<alltime/tries<<" seconds"<<"\n";
    */
    //.....................................................................................
    
    cout<<"End."<<"\n";  //.................................................
    return 0;
}