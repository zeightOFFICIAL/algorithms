// Demo.h
// use !ONLY! for testing of the program's work
// for ver 1.32-1.33
#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Bubble.h"
#include "Cocktail.h"
#include "Comb.h"
#include "Gnome.h"
#include "Heap.h"
#include "Insertion.h"
#include "Shell.h"
#include "Stooge.h"
#include "Cycle.h"
#include "Quick.h"

const unsigned long EXTREME_SIZE = 429496;

long long *GenerateRandomArray(unsigned long length, long long maxValue, long long minValue) {
  long long *array = new long long[EXTREME_SIZE];
  
  srand((int)time(0));
  for (unsigned long index = 0; index < length; index++) {
    array[index] = (rand() % (maxValue - minValue) + minValue);
  }
  
  return array;
}

template <typename T> void PrintArray(T *array, unsigned long length) {
  for (unsigned long index = 0; index < length; index++) {
    std::cout << "i: " << index << " value: " << array[index] << "\n";
  }
}

bool checkCorrect(long long * array, unsigned int length, bool order = true) {
  for (unsigned long index = 0; index < length - 1; index++) {
    if (array[index] > array[index+1] && order == true) {
      return false;
    }
    if (order == false && array[index] < array[index+1]) {
      return false;
    }
  }
  
  return true;
}

// -------------------------------------------------------------------------------------------------------------------------
void testSorting(void (*sorting)(long long *, unsigned long, bool), unsigned int length, bool order = true, 
             int maxValue = 15000, int minValue = -15000) {
  long long *arr = GenerateRandomArray(length, maxValue, minValue);
  
  sorting(arr, length, order);
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << "\n";
  }
  std::cout << "Is correct: " << checkCorrect(arr, length, order);
  
  delete[] arr;
}

void testAllSortings(int tries, unsigned int maxSize, unsigned int step, int maxValue = 15000, int minValue = -15000) {
  long long *arr1, *arr2, *arr3, *arr4, *arr5, *arr6, *arr7, *arr8, *arr9;
  long double alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, 
              alltime5 = 0, alltime6 = 0, alltime7 = 0, alltime8 = 0,
              alltime9 = 0;
  int localLength;
  bool allequal = true;
  std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3, 
                                        start4, end4, start5, end5, start6, end6, 
                                        start7, end7, start8, end8, start9, end9;

  for (localLength = 0; localLength <= maxSize; localLength += step) {
    std::cout << localLength << "\n";
    alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0;
    for (int localTries = 0; localTries < tries; localTries++) {
      
      arr1 = GenerateRandomArray(localLength, maxValue, minValue);
      start1 = std::chrono::steady_clock::now();
      sorting::BubbleSort(arr1, localLength);
      end1 = std::chrono::steady_clock::now();
      alltime1 = alltime1 + std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() /1000000.0;

      arr2 = GenerateRandomArray(localLength, maxValue, minValue);
      start2 = std::chrono::steady_clock::now();
      sorting::HeapSort(arr2, localLength);
      end2 = std::chrono::steady_clock::now();
      alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() /1000000.0;

      arr3 = GenerateRandomArray(localLength, maxValue, minValue);
      start3 = std::chrono::steady_clock::now();
      sorting::InsertionSort(arr3, localLength);
      end3 = std::chrono::steady_clock::now();
      alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() /1000000.0;

      arr4 = GenerateRandomArray(localLength, maxValue, minValue);
      start4 = std::chrono::steady_clock::now();
      sorting::GnomeSort(arr4, localLength);
      end4 = std::chrono::steady_clock::now();
      alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() /1000000.0;

      arr5 = GenerateRandomArray(localLength, maxValue, minValue);
      start5 = std::chrono::steady_clock::now();
      sorting::CombSort(arr5, localLength);
      end5 = std::chrono::steady_clock::now();
      alltime5 = alltime5 + std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() /1000000.0;

      arr6 = GenerateRandomArray(localLength, maxValue, minValue);
      start6 = std::chrono::steady_clock::now();
      sorting::CocktailSort(arr6, localLength);
      end6 = std::chrono::steady_clock::now();
      alltime6 = alltime6 + std::chrono::duration_cast<std::chrono::microseconds>(end6 - start6).count() /1000000.0;

      arr7 = GenerateRandomArray(localLength, maxValue, minValue);
      start7 = std::chrono::steady_clock::now();
      sorting::ShellSort(arr7, localLength);
      end7 = std::chrono::steady_clock::now();
      alltime7 = alltime7 + std::chrono::duration_cast<std::chrono::microseconds>(end7 - start7).count() /1000000.0;

      arr8 = GenerateRandomArray(localLength, maxValue, minValue);
      start8 = std::chrono::steady_clock::now();
      sorting::CycleSort(arr8, localLength);
      end8 = std::chrono::steady_clock::now();
      alltime8 = alltime8 + std::chrono::duration_cast<std::chrono::microseconds>(end8 - start8).count() /1000000.0;

      arr9 = GenerateRandomArray(localLength, maxValue, minValue);
      start9 = std::chrono::steady_clock::now();
      sorting::CycleSort(arr9, localLength);
      end9 = std::chrono::steady_clock::now();
      alltime9 = alltime9 + std::chrono::duration_cast<std::chrono::microseconds>(end9 - start9).count() /1000000.0;
    }
    std::cout << "Bubble sort: Average time: " << std::setprecision(9)
              << (alltime1 / tries) << " seconds" << "\n";
    std::cout << "Heap sort: Average time: " << std::setprecision(9)
              << (alltime2 / tries) << " seconds" << "\n";
    std::cout << "Insertion sort: Average time: " << std::setprecision(9)
              << (alltime3 / tries) << " seconds" << "\n";
    std::cout << "Gnome sort: Average time: " << std::setprecision(9)
              << (alltime4 / tries) << " seconds" << "\n";
    std::cout << "Comb sort: Average time: " << std::setprecision(9)
              << (alltime5 / tries) << " seconds" << "\n";
    std::cout << "Cocktail sort: Average time: " << std::setprecision(9)
              << (alltime6 / tries) << " seconds" << "\n";
    std::cout << "Shell sort: Average time: " << std::setprecision(9)
              << (alltime7 / tries) << " seconds" << "\n";
    std::cout << "Cycle sort: Average time: " << std::setprecision(9)
              << (alltime8 / tries) << " seconds" << "\n";
    std::cout << "Quick sort: Average time: " << std::setprecision(9)
              << (alltime9 / tries) << " seconds" << "\n";
    std::cout << "Total elements: " << localLength << "\n";
    std::cout << "Total tries: " << tries << "\n";

    allequal = checkCorrect(arr1, localLength) && checkCorrect(arr2, localLength) &&
               checkCorrect(arr3, localLength) && checkCorrect(arr4, localLength) &&
               checkCorrect(arr5, localLength) && checkCorrect(arr6, localLength) &&
               checkCorrect(arr7, localLength) && checkCorrect(arr8, localLength);
    
    std::cout << "Is correct: " << allequal << "\n";
    std::cout << "\n";
  }
  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;
  delete[] arr5;
  delete[] arr6;
  delete[] arr7;
}

void testSillySortings(int tries) {
  long long *arr;
  long double alltime = 0;
  int localLength;
  int min_value = -15000, max_value = 15000;
  std::chrono::steady_clock::time_point start, end;
  
  for (localLength = 500; localLength <= 2500; localLength += 500) {
    std::cout << localLength << "\n";
    alltime = 0;
    for (int localTries = 0; localTries < tries; localTries++) {
      
      arr = GenerateRandomArray(localLength, max_value, min_value);
      start = std::chrono::steady_clock::now();
      sorting::StoogeSort(arr, localLength);
      end = std::chrono::steady_clock::now();
      alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() /1000000.0;
    }
    std::cout << "Stooge sort: Average time: " << std::setprecision(9)
              << (alltime / tries) << " seconds" << "\n";
    std::cout << "Total elements: " << localLength << "\n";
    std::cout << "Total tries: " << tries << "\n";
    std::cout << "Is correct: " << checkCorrect(arr, localLength) << "\n";
    std::cout << "\n";
  }
  delete[] arr;
}