#include <iostream>
#include <chrono>
#include <iomanip>

#include "factorial.h"
#include "fibonacci.h"
#include "gcd.h"
#include "totalsum.h"

void fulltest(int tries = 10) {
	unsigned int x, local_tries;
	unsigned long long res = 0;
	std::chrono::steady_clock::time_point start, end, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7; //time stamps
	double alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0, alltime6 = 0, alltime7 = 0; //time summers

	for (x = 5; x <= 65; x++) {
		for (local_tries = 0; local_tries < tries; local_tries++)
		{
			start = std::chrono::steady_clock::now();
			res=FactorialIterative(x);
			end = std::chrono::steady_clock::now();
			alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";

			start2 = std::chrono::steady_clock::now();
			res=FactorialRecursive(x);
			end2 = std::chrono::steady_clock::now();
			alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";
			//--------------------------------------------------------------------------------------------------------------
			start3 = std::chrono::steady_clock::now();
			res = FibonacciIterative(x);
			end3 = std::chrono::steady_clock::now();
			alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";

			start4 = std::chrono::steady_clock::now();
			res = FibonacciRecursive(x);
			end4 = std::chrono::steady_clock::now();
			alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";

			start5 = std::chrono::steady_clock::now();
			res = FibonacciTailRecursive(x);
			end5 = std::chrono::steady_clock::now();
			alltime5 = alltime5 + std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";
		}
		std::cout << "Factorial iterative: Average time: " << std::setprecision(8) << (alltime / local_tries) << " seconds" << "\n";
		std::cout << "Factorial recursive: Average time: " << std::setprecision(8) << (alltime2 / local_tries) << " seconds" << "\n";
		std::cout << "Fibonacci iterative: Average time: " << std::setprecision(8) << (alltime3 / local_tries) << " seconds" << "\n";
		std::cout << "Fibonacci recursive: Average time: " << std::setprecision(8) << (alltime4 / local_tries) << " seconds" << "\n";
		std::cout << "Fibonacci tail recursive: Average time: " << std::setprecision(8) << (alltime5 / local_tries) << " seconds" << "\n";
		std::cout << "Total terms: " << x << "\n";
		std::cout << "Total tries: " << local_tries << "\n";

	}
}
