// rec_iter_demo.h
// use only for testing of the program's work
// for version 1.2
#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>

#include "factorial.h"
#include "fibonacci.h"
#include "gcd.h"
#include "totalsum.h"

typedef unsigned long long u_d_long;
typedef unsigned int u_int;

void reciter1_demo(int tries = 10) {
	u_int term;
	u_d_long res = 0;
	double alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0;
	std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3, start4, end4, start5, end5;
	for (term = 5; term <= 65; term++) {
		for (int local_tries = 0; local_tries < tries; local_tries++)
		{
			start1 = std::chrono::steady_clock::now();
			res = FactorialIterative(term);
			end1 = std::chrono::steady_clock::now();
			alltime1 = alltime1 + std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";

			start2 = std::chrono::steady_clock::now();
			res = FactorialRecursive(term);
			end2 = std::chrono::steady_clock::now();
			alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";
			//--------------------------------------------------------------------------------------------------------------
			start3 = std::chrono::steady_clock::now();
			res = FibonacciIterative(term);
			end3 = std::chrono::steady_clock::now();
			alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";

			start4 = std::chrono::steady_clock::now();
			res = FibonacciRecursive(term);
			end4 = std::chrono::steady_clock::now();
			alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";

			start5 = std::chrono::steady_clock::now();
			res = FibonacciTailRecursive(term);
			end5 = std::chrono::steady_clock::now();
			alltime5 = alltime5 + std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() / 1000000.0;
			if (local_tries == tries - 1)
				std::cout << res << "\n";
		}
		std::cout << "Factorial iterative: Average time: " << std::setprecision(8) << (alltime1 / tries) << " seconds" << "\n";
		std::cout << "Factorial recursive: Average time: " << std::setprecision(8) << (alltime2 / tries) << " seconds" << "\n";
		std::cout << "Fibonacci iterative: Average time: " << std::setprecision(8) << (alltime3 / tries) << " seconds" << "\n";
		std::cout << "Fibonacci recursive: Average time: " << std::setprecision(8) << (alltime4 / tries) << " seconds" << "\n";
		std::cout << "Fibonacci tail recursive: Average time: " << std::setprecision(8) << (alltime5 / tries) << " seconds" << "\n";
		std::cout << "Total terms: " << term << "\n";
		std::cout << "Total tries: " << tries << "\n";
	}
}
void reciter2_demo(unsigned long long x, unsigned long long y, int tries = 10)
{
	u_d_long res = 0;
	double alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0;
	std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3, start4, end4;
	for (int local_tries = 0; local_tries < tries; local_tries++)
	{
		start1 = std::chrono::steady_clock::now();
		res = GCDIterative(x, y);
		end1 = std::chrono::steady_clock::now();
		alltime1 = alltime1 + std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() / 1000000.0;
		if (local_tries == tries - 1)
			std::cout << res << "\n";

		start2 = std::chrono::steady_clock::now();
		res = GCDRecursive(x, y);
		end2 = std::chrono::steady_clock::now();
		alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
		if (local_tries == tries - 1)
			std::cout << res << "\n";
		//-------------------------------------------------------------------------------------------------------------
		start3 = std::chrono::steady_clock::now();
		res = SumIterative(y, x);
		end3 = std::chrono::steady_clock::now();
		alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
		if (local_tries == tries - 1)
			std::cout << res << "\n";

		start4 = std::chrono::steady_clock::now();
		res = SumRecursive(y, x);
		end4 = std::chrono::steady_clock::now();
		alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;
		if (local_tries == tries - 1)
			std::cout << res << "\n";

	}
	std::cout << "GCD iterative: Average time: " << std::setprecision(8) << (alltime1 / tries) << " seconds" << "\n";
	std::cout << "GCD recursive: Average time: " << std::setprecision(8) << (alltime2 / tries) << " seconds" << "\n";
	std::cout << "SUM iterative: Average time: " << std::setprecision(8) << (alltime3 / tries) << " seconds" << "\n";
	std::cout << "SUM recursive: Average time: " << std::setprecision(8) << (alltime4 / tries) << " seconds" << "\n";
	std::cout << "Terms: " << x << " " << y << "\n";
	std::cout << "Total tries: " << tries << "\n";
}