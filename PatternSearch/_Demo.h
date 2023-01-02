// Demo.h
// use !ONLY! for testing of the program's work
// for version 1.32
#pragma once

#include <chrono>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

#include "Bitap.h"
#include "BoyerMoore.h"
#include "KnuthMorrisPratt.h"
#include "Naive.h"
#include "RabinKarp.h"

const unsigned long EXTREME_LENGTH = 10000000;

void PrintArray(char *array, unsigned long length) {
  for (unsigned long index = 0; index < length; index++)
    std::cout << array[index];
  std::cout << "\n";
}
void PrintArray(std::vector<unsigned long> array) {
  for (unsigned long index = 0; index < array.size(); index++) {
    std::cout << array[index] << "\n";
    if (index >= 0 && array[index + 1] == 0)
      break;
  }
}

char *GenerateRandomString(unsigned long length, char alphabetType) {
  static char array[EXTREME_LENGTH];
  patternsearch::string alphabetSet;
  int symbolIndex = -1;

  if (alphabetType == 1)
    alphabetSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
  else if (alphabetType == 2)
    alphabetSet = "ABC123 ";
  else {
    std::cout << "Wrong alphabet type. Another will be selected." << "\n";
    alphabetSet = "ABC123 ";
  }
  int lengthSet = alphabetSet.length();
  srand((int)time(0));
  for (auto each = 0; each < length; each++) {
    symbolIndex = rand() % lengthSet;
    array[each] = alphabetSet[symbolIndex];
  }
  
  return array;
}

char *GenerateCustomString(unsigned long &length) {
  static char array[EXTREME_LENGTH];
  int localLength = 0;

  std::cout << "String: ";
  std::cin.getline(array, EXTREME_LENGTH);
  localLength = strlen(array);
  length = localLength;
  
  return array;
}

//--------------------------------------------------------------------------------------------------------------------------

void testSearchFull(int tries, patternsearch::string pattern = "ga") {
  char *array;
  patternsearch::vector occurrences;
  unsigned long length;
  long double alltime1 = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0,
              alltime5 = 0;
  std::chrono::steady_clock::time_point start1, end1, start2, end2, start3,
                                        end3, start4, end4, start5, end5;
  
  for (length = 10000; length <= 250000; length += 10000) {
    for (int localTries = 0; localTries <= tries; localTries++) {
      array = GenerateRandomString(length, 1);
      patternsearch::string strarray = array;

      start1 = std::chrono::steady_clock::now();
      occurrences = patternsearch::BoyerMooreSearch(strarray, pattern);
      end1 = std::chrono::steady_clock::now();
      alltime1 = alltime1 + std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() / 1000000.0;
      if (localTries == tries)
        std::cout << "BoyerMoore found: " << occurrences.size() << "\n";

      start5 = std::chrono::steady_clock::now();
      occurrences = patternsearch::KMPSearch(array, pattern);
      end5 = std::chrono::steady_clock::now();
      alltime5 =alltime5 + std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() / 1000000.0;
      if (localTries == tries)
        std::cout << "Knuth-Morris-Pratt found: " << occurrences.size() << "\n";

      start2 = std::chrono::steady_clock::now();
      occurrences = patternsearch::RabinKarpSearch(strarray, pattern, 64);
      end2 = std::chrono::steady_clock::now();
      alltime2 =alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
      if (localTries == tries)
        std::cout << "RabinKarp found: " << occurrences.size() << "\n";

      start3 = std::chrono::steady_clock::now();
      occurrences = patternsearch::NaiveSearch(strarray, pattern);
      end3 = std::chrono::steady_clock::now();
      alltime3 =alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
      if (localTries == tries)
        std::cout << "Naive found: " << occurrences.size() << "\n";

      start4 = std::chrono::steady_clock::now();
      occurrences = patternsearch::BitapSearch(array, pattern);
      end4 = std::chrono::steady_clock::now();
      alltime4 =alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;
      if (localTries == tries)
        std::cout << "Bitap found: " << occurrences.size() << "\n";
    }
    std::cout << "Boyer-Moore: Average time: " << std::setprecision(9)
              << (alltime1 / tries) << " seconds" << "\n";
    std::cout << "Knuth-Morris-Pratt: Average time: " << std::setprecision(9)
              << (alltime5 / tries) << " seconds" << "\n";
    std::cout << "Rabin-Karp: Average time: " << std::setprecision(9)
              << (alltime2 / tries) << " seconds" << "\n";
    std::cout << "Naive: Average time: " << std::setprecision(9)
              << (alltime3 / tries) << " seconds" << "\n";
    std::cout << "Bitap: Average time: " << std::setprecision(9)
              << (alltime4 / tries) << " seconds" << "\n";
    std::cout << "Total elements: " << length << "\n";
    std::cout << "Total tries: " << tries << "\n";
    std::cout << "\n";
  }
}
