// Utils.h
// must be included and used in each sorting header file
// for ver 1.31

#pragma once

namespace sorting {
template <typename T> void static swap(T &first, T &second) {
  T temp = second;
  second = first;
  first = temp;
}
template <typename T> void static reverse(T *array, unsigned int length) {
  T temp;
  for (unsigned int i = 0; i < length / 2; i++) {
    temp = array[i];
    array[i] = array[length - i - 1];
    array[length - i - 1] = temp;
  }
}
}