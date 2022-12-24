// Utils.h
// must be included and used in each sorting header file
// for ver 1.32

#pragma once

namespace sorting {  
  typedef unsigned long u_long;
  typedef unsigned short u_short;
  typedef long long long64;
  template <typename T> static void swap(T &first, T &second) {
    T temp = second;
    second = first;
    first = temp;
  }
  template <typename T> static void reverse(T *array, u_long length) {
    T temp;
    for (u_long i = 0; i < length / 2; i++) {
      temp = array[i];
      array[i] = array[length - i - 1];
      array[length - i - 1] = temp;
    }
  }
} // namespace sorting