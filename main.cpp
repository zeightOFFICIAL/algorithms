#include "sorting/test.h"
#include <iostream>

int main() {
	long long* arr;
	arr = GenerateRandomArray(1000, 15000, -15000);
	//PrintArray(arr, 10000);


	StoogeSort(arr, 1000, false);
	PrintArray(arr, 1000);
	return 0;
}