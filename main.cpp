#include "sorting/sorting_demo.h"
#include "substringsearch/substrsearch_demo.h"
#include "recursioniteration/reciter_demo.h"
#include "theoryofnumbers/euclidean_gcd.h"
#include "theoryofnumbers/stein_gcd.h"
#include <iostream>

int main() {
    long long res = 0;
    res = EuclideanGCDIterative(24826148, 45296490);
    std::cout << res << "\n";
    res = SteinGCDIterative(24826148, 45296490);
    std::cout << res;
	//sorting_demo(1);
	//sorting_demo_silly(1);

	//substrsearch_demo(1);

	//reciter1_demo(1);
	//reciter2_demo(30, 1, 1);
	return 0;
}