/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Cycle.h

#include "_Utils.h"

namespace sorting {
  /**
  (T *A, unsigned long B, bool C) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using cycle sorting. Changes A, returns nothing.
  */
  template <typename T>
  static void CycleSort(T *array, ulong length, bool order = true);
  
  template <typename T>
  static void CycleSort(T *array, ulong length, bool order) {
    if (length == 0) {
      return;
    }
    ulong cycleStart, cyclePos, cycleNext;
    
    for (cycleStart = 0; cycleStart < length - 1; cycleStart++) {
      T selectedElement = array[cycleStart];
      cyclePos = cycleStart;
      for (cycleNext = cycleStart + 1; cycleNext < length; cycleNext++) {
        if (array[cycleNext] < selectedElement) {
          cyclePos++;
        }
      }
      if (cyclePos == cycleStart) {
        continue;
      }
      while (selectedElement == array[cyclePos]) {
        cyclePos++;
      }
      swap(array[cyclePos], selectedElement);
      while (cyclePos != cycleStart) {
        cyclePos = cycleStart;
        for (cycleNext = cycleStart + 1; cycleNext < length; cycleNext++) {
          if (array[cycleNext] < selectedElement) {
            cyclePos++;
          }
        }
        while (selectedElement == array[cyclePos]) {
          cyclePos++;
        }
        swap(array[cyclePos], selectedElement);
      }
    }
  
    if (!order) {
      reverse(array, length);
    }
  }
} // namespace sorting