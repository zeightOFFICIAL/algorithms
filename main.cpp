#include "recursion_iteration/fibonacci.h"
#include <iostream>

int main() {
	std::cout << FibonacciIterative(17) << "\n";
	std::cout << FibonacciRecursive(17) << "\n";
	std::cout << FibonacciTailRecursive(17) << "\n";
	return 0;
}