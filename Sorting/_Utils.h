/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Utils.h
// must be included and used in each sorting header file
// for ver 1.32-1.33

#pragma once

namespace sorting {  
  typedef unsigned long ulong;
  typedef unsigned long long ulong64;
  typedef unsigned short ushort;
  typedef long long long64;

  template <typename T> static void swap(T &first, T &second) {
    T temp = second;
    second = first;
    first = temp;
  }
  template <typename T> static void reverse(T *array, ulong length) {
    T temp;
    for (ulong i = 0; i < length / 2; i++) {
      temp = array[i];
      array[i] = array[length - i - 1];
      array[length - i - 1] = temp;
    }
  }
} // namespace sorting