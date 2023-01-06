// Demo.h
// use !ONLY! for testing of the program's work
// for version 1.32
#pragma once

#include "math.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

//-------------------------------------

#include "Factorial.h"

#include "Fibonacci.h"

#include "Euclidean.h"
#include "Stein.h"

#include "Eratosthenes.h"
#include "Sundaram.h"

#include "Borwein.h"
#include "Chudnovsky.h"
#include "GaussLegendre.h"

typedef std::numeric_limits< double > dbl;
typedef uint64_t uint64;

void testFactorial() {
  std::string tempValue1, tempValue2, tempValue3, tempValue4;  
  
  for (int i = 0; i < 51; i++) {
    std::cout << "TERM: " << i << "\n";

    tempValue1 = factorial::PreGenFactorial50[i];
    if (i < 21)
      tempValue2 = std::to_string(factorial::PreGenFactorial20[i]);
    else
      tempValue2 = std::to_string(0);
    tempValue3 = std::to_string(factorial::IterativeFactorial(i));
    tempValue4 = std::to_string(factorial::RecursiveFactorial(i));
    
    std::cout << "Pre-generated Factorial 50: " << tempValue1 << "\n";
    std::cout << "Pre-generated Factorial 20: " << tempValue2 << "\n";
    std::cout << "Factorial iterative:        " << tempValue3 << "\n";
    std::cout << "Factorial recursive:        " << tempValue4 << "\n";

    std::cout << "Are equal:                  " << (tempValue1 == tempValue2 & tempValue3 == tempValue4 & tempValue1 == tempValue4) << "\n\n";
  }
}

void testGCD(uint64 x = 360, uint64 y = 210)
{
  uint64 tempValue1, tempValue2, tempValue3, tempValue4,
  tempValue5;

  tempValue1 = gcd::IterativeEuclideanGCD(x, y);
  tempValue2 = gcd::RecursiveEuclideanGCD(x, y);
  tempValue3 = gcd::IterativeSteinGCD(x, y);
  tempValue4 = gcd::RecursiveSteinGCD(x, y);
  tempValue5 = std::__gcd(x, y);

  std::cout << "Euclidean iterative GCD: " << tempValue1 << "\n";
  std::cout << "Euclidean recursive GCD: " << tempValue2 << "\n";
  std::cout << "Stein iterative GCD:     " << tempValue3 << "\n";
  std::cout << "Stein recursive GCD:     " << tempValue4 << "\n";
  std::cout << "Inline C++:              " << tempValue5 << "\n";
  std::cout << "Are equal:               " << (tempValue1 == tempValue2 & tempValue3 == tempValue4 & tempValue1 == tempValue4 & tempValue5 == tempValue2) << "\n\n";
}

void testFibonacci()
{
  uint64_t tempValue1, tempValue2, tempValue3, tempValue4;
  
  for (int i = 0; i < 91; i++) {
    std::cout << "TERM: " << i << "\n";

    tempValue1 = fibonacci::PreGenFibonacci90[i];
    tempValue2 = fibonacci::PureRecursiveFibonacci(i);
    tempValue3 = fibonacci::RecursiveFibonacci(i);
    tempValue4 = fibonacci::IterativeFibonacci(i);
    
    std::cout << "Pre-generated Fibonacci 90: " << tempValue1 << "\n";
    std::cout << "Fibonacci pure recursive:   " << tempValue2 << "\n";
    std::cout << "Fibonacci recursive:        " << tempValue3 << " (worst time)"<< "\n";
    std::cout << "Fibonacci iterative:        " << tempValue3 << "\n";

    std::cout << "Are equal:                  " << (tempValue1 == tempValue2 & tempValue3 == tempValue4 & tempValue1 == tempValue4) << "\n\n";
  }
}

void testSieves(int size = 50) 
{
  std::vector<uint64_t> sieve1, sieve2;
  sieve1 = sieve::EratosthenesSieve(size);
  sieve2 = sieve::SundaramSieve(size);
  bool areEqual = true;

  std::cout << "ERATOSTHENES SUNDARAM" << "\n";
  for (int i = 0; i < sieve1.size(); i++)
  {
    std::cout << sieve1[i] << "\t" << sieve2[i] << "\n";
    if (sieve1[i] != sieve2[i]) {
      areEqual = false;
    }
  }
  std::cout << "Are equal: " << areEqual << "\n\n";
}

void testPi() {
  double tempValue1, tempValue2, tempValue3,
         tempValue4, tempValue5, tempValue6;
  int localPrec;

  for (int localPrec = 0; localPrec < 4; localPrec++) {
    std::cout << localPrec << "\n";

    tempValue1 = picalc::ChudnovskyPi(localPrec);
    tempValue2 = picalc::BorweinQuadraticPi(localPrec);
    tempValue3 = picalc::GaussLegendrePi(localPrec);
    tempValue4 = picalc::BorweinCubicPi(localPrec);
    tempValue5 = picalc::BorweinQuarticPi(localPrec);

    std::cout << std::setprecision(dbl::max_digits10+2) << "Math.h PI:        " << M_PI << "\n";
    std::cout << std::setprecision(dbl::max_digits10+2) << "BorweinQuadratic: " << tempValue2 << "\n";
    std::cout << std::setprecision(dbl::max_digits10+2) << "GaussLegendre:    " << tempValue3 << "\n";
    std::cout << std::setprecision(dbl::max_digits10+2) << "Math.h 1/PI:      " << 1.0/M_PI << "\n";
    std::cout << std::setprecision(dbl::max_digits10+2) << "Chudnovsky:       " << tempValue1 << "\n";
    std::cout << std::setprecision(dbl::max_digits10+2) << "BorweinCubic:     " << tempValue4 << "\n";
    std::cout << std::setprecision(dbl::max_digits10+2) << "BorweinQuartic:   " << tempValue5 << "\n";
  }
}