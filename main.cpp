#include <iostream>

#include "Sorting/_Demo.h"
#include "PatternSearch/_Demo.h"
#include "Elementary/_Demo.h"

#include "Hashing/adler32.h"
#include "Hashing/fnv132.h"
#include "Hashing/fnv164.h"
#include "Hashing/sha1.h"
#include "Hashing/sha256.h"

#include "TheoryOfNumbers/Factorial.h"
#include "TheoryOfNumbers/Fibonacci.h"
#include "TheoryOfNumbers/GCDEuclidean.h"
#include "TheoryOfNumbers/GCDStein.h"
#include "TheoryOfNumbers/SieveEratosthenes.h"
#include "TheoryOfNumbers/SieveSundaram.h"


int main() {
  testPi();
  
  // testSorting(&sorting::sortComb, 500, false);
  // testAllSortings(1, 10000, 5000);
  // testSillySortings(1);

  // testSearchFull(5, "aa");

  // std::cout << hashing::adler32("hello") << "\n";
  // std::cout << hashing::fnv132("hello") << "\n";
  // std::cout << hashing::fnv164("hello") << "\n";
  // std::cout << hashing::sha1("hello") << "\n";
  // std::cout << hashing::sha256("hello") << "\n";

  // std::cout << factorial::iterativeFactorial(20) << "\n";
  // std::cout << factorial::recursiveFactorial(20) << "\n";
  // std::cout << factorial::generatedFactorial20[20] << "\n";
  // std::cout << factorial::generatedFactorial50[20] << "\n";

  // std::cout << fibonacci::iterativeFibonacci(50) << "\n";
  // std::cout << fibonacci::recursiveFibonacci(50) << "\n";
  // std::cout << fibonacci::pureRecursiveFibonacci(50) << "\n";
  // std::cout << fibonacci::generatedFibonacci90[50] << "\n";

  // std::cout << gcd::iterativeSteinGCD(1, 1) << "\n";
  // std::cout << gcd::recursiveSteinRecursiveGCD(0, 1) << "\n";
  // std::cout << gcd::iterativeEuclideanGCD(1, 1) << "\n";
  // std::cout << gcd::recursiveEuclideanGCD(1, 1) << "\n";

  // std::vector<uint64_t> an, an2;
  // an = sieve::sundaramSieve(50);
  // an2 = sieve::eratosthenesSieve(50);
  // for (int i = 0; i < an2.size(); i++) {
  //   std::cout << an[i] << "\n";
  //   std::cout << an2[i] << "\n";
  // }

  
    
  return 0;
}