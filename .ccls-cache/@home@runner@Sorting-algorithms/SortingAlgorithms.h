#include <iostream>

void SortArray_BubbleSort(int *ArrayY);
void SortArray_HeapSort(int *ArrayY);
void SortArray_StoogeSort(int *ArrayY, int h, int l);

void Tool_Swap(int *LeftElement, int *RightElement);
void Tool_Heapify(int arr[], int n, int i);
void Tool_ClearTxt();
void Tool_ClearSortTxt();