#include "theoryofnumbers/sieve_of_eratosthenes.h"
#include "elementary/kahan_summation.h"
#include "elementary/naive_summation.h"
#include "elementary/gauss_legendre_pi.h"
#include <vector>
#include <iostream>
#include <limits>
int main() {
	//sorting_demo(1);
	//sorting_demo_silly(1);

	//substrsearch_demo(1);

	//reciter1_demo(1);
	//reciter2_demo(30, 1, 1);
    std::cout.precision(9);
    std::vector<long> x = {5000, -300, 900, 40000, 90000, 45465132};
    //std::cout << KahanSummation(x);
    std::cout << NaiveSumIterative<long>(x) << "\n";
    std::cout << NaiveSumRecursive<long>(x) << "\n";
    std::cout << KahanSummation<long>(x) << "\n";
    std::cout << GaussLegendrePi(1);
}