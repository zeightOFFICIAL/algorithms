// substrsearch_demo.h
// use only for testing of the program's work
// for version 1.2
#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <cstring>
#include <random>
#include <fstream>

#include "boyer_moore.h"
#include "naive.h"
#include "rabin_karp.h"
#include "bitap.h"

typedef unsigned long u_long;
typedef long double d_double;

const u_long EXTREME_LENGTH = 10000000;

void PrintArray(char* array, u_long length)
{
	for (u_long i = 0; i < length; i++)
		std::cout << array[i];
	std::cout << "\n";
}
void PrintArray(std::vector<u_long> array)
{
	for (u_long i = 0; i < array.size(); i++) {
		std::cout << array[i] << "\n";
		if (i >= 0 && array[i + 1] == 0)
			break;
	}
}
char* GenerateRandomString(u_long length, char alphabet_type)
{
	static char array[EXTREME_LENGTH];
	std::string alphabet_set;
	int this_symbol_index = -1;

	if (alphabet_type == 1)
		alphabet_set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
	else if (alphabet_type == 2)
		alphabet_set = "ABC123 ";
	else {
		std::cout << "Wrong alphabet type. Another will be selected." << "\n";
		alphabet_set = "ABC123 ";
	}
	int set_length = alphabet_set.length();

	srand((int)time(0));
	for (auto i = 0; i < length; i++) {
		this_symbol_index = rand() % set_length;
		array[i] = alphabet_set[this_symbol_index];
	}
	return array;
}
char* GenerateCustomString(u_long& length)
{
	static char array[EXTREME_LENGTH];
	int local_length = 0;

	std::cout << "String: ";
	std::cin.getline(array, EXTREME_LENGTH);
	local_length = strlen(array);
	length = local_length;
	return array;
}

//--------------------------------------------------------------------------------------------------------------------------

void substrsearch_demo(int tries)
{
	char* array;
	std::vector<u_long> occurrences;
	u_long length;
	d_double alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0;
	std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3, start4, end4;
	for (length = 10000; length <= 250000; length += 10000) {
		for (int local_tries = 0; local_tries <= tries; local_tries++) {
			array = GenerateRandomString(length, 1);
			std::string strarray = array;

			start1 = std::chrono::steady_clock::now();
			occurrences = BoyerMoore(strarray, "ga");
			end1 = std::chrono::steady_clock::now();
			alltime1 = alltime1 + std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() / 1000000.0;
			if (local_tries == tries)
				std::cout << "BoyerMoore found: " << occurrences.size() << "\n";

			start2 = std::chrono::steady_clock::now();
			occurrences = RabinKarp(strarray, "ga", 64);
			end2 = std::chrono::steady_clock::now();
			alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
			if (local_tries == tries)
				std::cout << "RabinKarp found: " << occurrences.size() << "\n";

			start3 = std::chrono::steady_clock::now();
			occurrences = NaiveSearch(strarray, "ga");
			end3 = std::chrono::steady_clock::now();
			alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
			if (local_tries == tries)
				std::cout << "Naive found: " << occurrences.size() << "\n";

			start4 = std::chrono::steady_clock::now();
			occurrences = Bitap(array, "ga");
			end4 = std::chrono::steady_clock::now();
			alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;
			if (local_tries == tries)
				std::cout << "Bitap found: " << occurrences.size() << "\n";
		}
		std::cout << "Boyer-Moore: Average time: " << std::setprecision(9) << (alltime1 / tries) << " seconds" << "\n";
		std::cout << "Rabin-Karp: Average time: " << std::setprecision(9) << (alltime2 / tries) << " seconds" << "\n";
		std::cout << "Naive: Average time: " << std::setprecision(9) << (alltime3 / tries) << " seconds" << "\n";
		std::cout << "Bitap: Average time: " << std::setprecision(9) << (alltime4 / tries) << " seconds" << "\n";
		std::cout << "Total elements: " << length << "\n";
		std::cout << "Total tries: " << tries << "\n";
		std::cout << "\n";
	}
}