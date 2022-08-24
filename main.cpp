#include "sorting/test.h"

int main() {
  long long* arr;
  arr = GenerateRandomArray(10000, 15000, -15000);
  //PrintArray(arr, 10000);
  /*
  arr = new long long[6];
  arr[0] = -1;
  arr[1] = 500;
  arr[2] = 0;
  arr[3] = 10;
  arr[4] = 500000;
  arr[5] = -500000;
  */
  GnomeSort(arr, 10000, false);
  PrintArray(arr, 10000);
  return 0;
}