#include "sorting/sorting_demo.h"
#include "substringsearch/substrsearch_demo.h"
#include "recursion_iteration/reciter_demo.h"

int main() {
    d_long* arr1;
    arr1 = GenerateRandomArray(1000, 10000, -10000);
    CombSort(arr1, 1000, false);
    PrintArray(arr1, 1000);
	//sorting_demo(1);
	//sorting_demo_silly(1);

	//substrsearch_demo(1);

	//reciter1_demo(1);
	//reciter2_demo(30, 1, 1);
	return 0;
}