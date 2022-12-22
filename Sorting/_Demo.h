// Demo.h
// use only for testing of the program's work
// for version 1.32
#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "BubbleSort.h"
#include "CocktailSort.h"
#include "CombSort.h"
#include "GnomeSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "StoogeSort.h"

const u_long EXTREME_SIZE = 429496;

long64 *GenerateRandomArray(u_long length, long64 maxValue, long64 minValue) {
  long64 *array = new long64[EXTREME_SIZE];
  
  srand((int)time(0));
  for (u_long index = 0; index < length; index++) {
    array[index] = (rand() % (maxValue - minValue) + minValue);
  }
  
  return array;
}

long64 *GenerateCustomArray(u_long length) {
  long64 *array = new long64[EXTREME_SIZE];
  long64 thisElement = 0;
  
  for (u_long index = 0; index < length; index++) {
    std::cout << "Input element with index " << index << ": ";
    std::cin >> thisElement;
    array[index] = thisElement;
  }
  
  return array;
}

template <typename T> void PrintArray(T *array, u_long length) {
  for (u_long index = 0; index < length; index++) {
    std::cout << "i: " << index << " value: " << array[index] << "\n";
  }
}

bool checkCorrect(long64 * array, unsigned int length, bool order = true) {
  for (u_long index = 0; index < length - 1; index++) {
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
void testOne(void (*sorting)(long64 *, u_long, bool), unsigned int length, bool order = true, 
             int maxValue = 15000, int minValue = -15000) {
  long64 *arr = GenerateRandomArray(length, maxValue, minValue);
  
  sorting(arr, length, order);
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << "\n";
  }
  std::cout << "Is correct: " << checkCorrect(arr, length, order);
  
  delete[] arr;
}

void testFull(int tries, unsigned int maxSize, unsigned int step, 
              int maxValue = 15000, int minValue = -15000) {
  long64 *arr1, *arr2, *arr3, *arr4, *arr5, *arr6, *arr7;
  long double alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, 
              alltime5 = 0, alltime6 = 0, alltime7 = 0;
  int local_length;
  bool allequal = true;
  std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3, 
                                        start4, end4, start5, end5, start6, end6, 
                                        start7, end7;

  for (local_length = 0; local_length <= maxSize; local_length += step) {
    std::cout << local_length << "\n";
    alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0;
    for (int local_tries = 0; local_tries < tries; local_tries++) {
      
      arr1 = GenerateRandomArray(local_length, maxValue, minValue);
      start1 = std::chrono::steady_clock::now();
      sortBubble(arr1, local_length);
      end1 = std::chrono::steady_clock::now();
      alltime1 = alltime1 + std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() /1000000.0;

      arr2 = GenerateRandomArray(local_length, maxValue, minValue);
      start2 = std::chrono::steady_clock::now();
      sortHeap(arr2, local_length);
      end2 = std::chrono::steady_clock::now();
      alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() /1000000.0;

      arr3 = GenerateRandomArray(local_length, maxValue, minValue);
      start3 = std::chrono::steady_clock::now();
      sortInsertion(arr3, local_length);
      end3 = std::chrono::steady_clock::now();
      alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() /1000000.0;

      arr4 = GenerateRandomArray(local_length, maxValue, minValue);
      start4 = std::chrono::steady_clock::now();
      sortGnome(arr4, local_length);
      end4 = std::chrono::steady_clock::now();
      alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() /1000000.0;

      arr5 = GenerateRandomArray(local_length, maxValue, minValue);
      start5 = std::chrono::steady_clock::now();
      sortComb(arr5, local_length);
      end5 = std::chrono::steady_clock::now();
      alltime5 = alltime5 + std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() /1000000.0;

      arr6 = GenerateRandomArray(local_length, maxValue, minValue);
      start6 = std::chrono::steady_clock::now();
      sortCocktail(arr6, local_length);
      end6 = std::chrono::steady_clock::now();
      alltime6 = alltime6 + std::chrono::duration_cast<std::chrono::microseconds>(end6 - start6).count() /1000000.0;

      arr7 = GenerateRandomArray(local_length, maxValue, minValue);
      start7 = std::chrono::steady_clock::now();
      sortShell(arr7, local_length);
      end7 = std::chrono::steady_clock::now();
      alltime7 = alltime7 + std::chrono::duration_cast<std::chrono::microseconds>(end7 - start7).count() /1000000.0;
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
    std::cout << "Total elements: " << local_length << "\n";
    std::cout << "Total tries: " << tries << "\n";

    allequal = checkCorrect(arr1, local_length) && checkCorrect(arr2, local_length) &&
               checkCorrect(arr3, local_length) && checkCorrect(arr4, local_length) &&
               checkCorrect(arr5, local_length) && checkCorrect(arr6, local_length) &&
               checkCorrect(arr7, local_length);
    
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

void testSilly(int tries) {
  long64 *arr;
  long double alltime = 0;
  int local_length;
  int min_value = -15000, max_value = 15000;
  std::chrono::steady_clock::time_point start, end;
  
  for (local_length = 500; local_length <= 2500; local_length += 500) {
    std::cout << local_length << "\n";
    alltime = 0;
    for (int local_tries = 0; local_tries < tries; local_tries++) {
      
      arr = GenerateRandomArray(local_length, max_value, min_value);
      start = std::chrono::steady_clock::now();
      sortStooge(arr, local_length);
      end = std::chrono::steady_clock::now();
      alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() /1000000.0;
    }
    std::cout << "Stooge sort: Average time: " << std::setprecision(9)
              << (alltime / tries) << " seconds" << "\n";
    std::cout << "Total elements: " << local_length << "\n";
    std::cout << "Total tries: " << tries << "\n";
    std::cout << "Is correct: " << checkCorrect(arr, local_length) << "\n";
    std::cout << "\n";
  }
  delete[] arr;
}