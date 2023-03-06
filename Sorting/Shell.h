/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Shell.h

#include "_Utils.h"

namespace sorting {  
  static ushort A102549[] = {1, 4, 10, 23, 57, 132, 301, 701};
  static ushort A108870[] = {1, 4, 9, 20, 46, 103};
  static ushort A033622[] = {1, 5, 19, 41, 109};
  static ushort A036562[] = {1, 8, 23, 77, 281};
  static ushort A036569[] = {1, 3, 7, 21, 48, 112};
  static ushort A003462[] = {1, 4, 13, 40, 121};
  static ushort A003586[] = {1, 2, 3, 4, 6, 8, 9, 12};
  static ushort A083318[] = {1, 3, 5, 9, 17, 33, 65};
  static ushort A000225[] = {1, 3, 7, 15, 31, 63};
  
  /**
  (T *A, unsigned long B, bool C, Y D) -> ()
  Takes an array A (type T) with length of B and sorts it in
  the ascending order if C - true and descending if C - false,
  using shell sorting with sequence D. Changes A, returns nothing.
  */
  template <typename T, typename Y = ushort[8]>
  static void Shell(T *array, ulong length, bool order = true, Y &seq = A102549);
  
  template <typename T, typename Y>
  static void Shell(T *array, ulong length, bool order, Y &seq) {
    if (length == 0) {
      return;
    }
    ulong index, nextIndex;
    ushort gap;
  
    for (ushort gap : seq) {
      for (index = gap; index < length; index++) {
        T selectedElement = array[index];
        for (nextIndex = index; (nextIndex >= gap) && (array[nextIndex - gap] > selectedElement); nextIndex -= gap) {
          array[nextIndex] = array[nextIndex - gap];
        }
        array[nextIndex] = selectedElement;
      }
    }
    if (!order) {
      reverse(array, length);
    }
  }
}