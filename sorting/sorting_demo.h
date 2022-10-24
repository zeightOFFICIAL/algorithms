// sorting_demo.h
// use only for testing of the program's work
// for version 1.3
#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

#include "BubbleSort.h"
#include "CombSort.h"
#include "GnomeSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "StoogeSort.h"

const unsigned long EXTREME_SIZE = 429496;

long long *GenerateRandomArray(unsigned long length, long long max_value,
                               long long min_value) {
  long long *array = new long long[EXTREME_SIZE];
  srand((int)time(0));
  for (unsigned long index = 0; index < length; index++)
    array[index] = (rand() % (max_value - min_value) + min_value);
  return array;
}
long long *GenerateCustomArray(unsigned long length) {
  long long *array = new long long[EXTREME_SIZE];
  long long this_element = 0;
  for (unsigned long index = 0; index < length; index++) {
    std::cout << "Input element with index " << index << ": ";
    std::cin >> this_element;
    array[index] = this_element;
  }
  return array;
}
template <typename T> void PrintArray(T *array, unsigned long length) {
  for (unsigned long index = 0; index < length; index++)
    std::cout << "i: " << index << " value: " << array[index] << "\n";
}

// -------------------------------------------------------------------------------------------------------------------------
void sorting_demo(int tries) {
  long long *arr1, *arr2, *arr3, *arr4, *arr5;
  long double alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0,
              alltime5 = 0;
  int min_value = -15000, max_value = 15000;
  int local_length;
  std::chrono::steady_clock::time_point start1, end1, start2, end2, start3,
      end3, start4, end4, start5, end5;
  for (local_length = 5000; local_length <= 100000; local_length += 5000) {
    std::cout << local_length << "\n";
    alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0;
    for (int local_tries = 0; local_tries < tries; local_tries++) {
      arr1 = GenerateRandomArray(local_length, max_value, min_value);
      start1 = std::chrono::steady_clock::now();
      sortBubble(arr1, local_length, false);
      end1 = std::chrono::steady_clock::now();
      alltime1 =
          alltime1 +
          std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1)
                  .count() /
              1000000.0;

      arr2 = GenerateRandomArray(local_length, max_value, min_value);
      start2 = std::chrono::steady_clock::now();
      sortHeap(arr2, local_length, false);
      end2 = std::chrono::steady_clock::now();
      alltime2 =
          alltime2 +
          std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2)
                  .count() /
              1000000.0;

      arr3 = GenerateRandomArray(local_length, max_value, min_value);
      start3 = std::chrono::steady_clock::now();
      sortInsertion(arr3, local_length, false);
      end3 = std::chrono::steady_clock::now();
      alltime3 =
          alltime3 +
          std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3)
                  .count() /
              1000000.0;

      arr4 = GenerateRandomArray(local_length, max_value, min_value);
      start4 = std::chrono::steady_clock::now();
      sortGnome(arr4, local_length, false);
      end4 = std::chrono::steady_clock::now();
      alltime4 =
          alltime4 +
          std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4)
                  .count() /
              1000000.0;

      arr5 = GenerateRandomArray(local_length, max_value, min_value);
      start5 = std::chrono::steady_clock::now();
      sortComb(arr5, local_length, false);
      end5 = std::chrono::steady_clock::now();
      alltime5 =
          alltime5 +
          std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5)
                  .count() /
              1000000.0;
    }
    std::cout << "Bubble sort: Average time: " << std::setprecision(9)
              << (alltime1 / tries) << " seconds"
              << "\n";
    std::cout << "Heap sort: Average time: " << std::setprecision(9)
              << (alltime2 / tries) << " seconds"
              << "\n";
    std::cout << "Insertion sort: Average time: " << std::setprecision(9)
              << (alltime3 / tries) << " seconds"
              << "\n";
    std::cout << "Gnome sort: Average time: " << std::setprecision(9)
              << (alltime4 / tries) << " seconds"
              << "\n";
    std::cout << "Comb sort: Average time: " << std::setprecision(9)
              << (alltime5 / tries) << " seconds"
              << "\n";
    std::cout << "Total elements: " << local_length << "\n";
    std::cout << "Total tries: " << tries << "\n";
    std::cout << "\n";
  }
}
void sorting_demo_silly(int tries) {
  long long *arr;
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
      sortStooge(arr, local_length, false);
      end = std::chrono::steady_clock::now();
      alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(
                              end - start)
                                  .count() /
                              1000000.0;
    }
    std::cout << "Stooge sort: Average time: " << std::setprecision(9)
              << (alltime / tries) << " seconds"
              << "\n";
    std::cout << "Total elements: " << local_length << "\n";
    std::cout << "Total tries: " << tries << "\n";
    std::cout << "\n";
  }
}