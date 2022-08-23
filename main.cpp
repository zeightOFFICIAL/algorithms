#include "sorting/test.h"
#include "sorting/bubble_sort.h"

int main() 
{
    long long* arr;
    arr = GenerateRandomArray(5000, 10000, -10000);
    BubbleSort(arr, 5000, false);
    PrintArray(arr, 5000);
    return 0;
}