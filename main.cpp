#include "sorting/test.h"
#include <iostream>

int main() {
  long long* arr;
  arr = GenerateRandomArray(1000, 15000, -15000);
  //PrintArray(arr, 10000);
  
  arr = new long long[6];
  arr[0] = -1;
  arr[1] = 500;
  arr[2] = 0;
  arr[3] = 10;
  arr[4] = 500000;
  arr[5] = -500000;
  
  StoogeSort(arr, 6);
  PrintArray(arr, 6);
  std::cout << arr[0];
  std::cout << arr[1];
  std::cout << arr[2];
  std::cout << arr[3];
  std::cout << arr[4];
  std::cout << arr[5];
  return 0;
}