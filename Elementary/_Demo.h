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

#include "BorweinPi.h"
#include "ChudnovskyPi.h"
#include "GaussLegendrePi.h"

#include "KahanSum.h"
#include "NaiveSum.h"

#include "NaiveExp.h"
#include "SquaringExp.h"

typedef std::numeric_limits< double > dbl;

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

void testExp(int startPow = 0, int endPow = 10, int startBase = 0, int endBase = 5) {
  double tempValue1, tempValue2, tempValue3,
         tempValue4, tempValue5;
  int power, base;

  for (int base = startBase; base < endBase; base++) {
      for (int power = startPow; power < endPow; power++) {
        std::cout << "BASE = " << base << " POWER = " << power << "\n";
        
        tempValue1 = exponentiation::NaiveExpIterative(base, power);
        tempValue2 = exponentiation::NaiveExpRecursive(base, power);
        tempValue3 = exponentiation::SquaringIterativeExp(base, power);
        tempValue4 = exponentiation::SquaringRecursiveExp(base, power);
        tempValue5 = pow(base, power);
        
        std::cout << "Math.h POW:         " << tempValue5 << "\n";
        std::cout << "Naive iterative:    " << tempValue1 << "\n";
        std::cout << "Naive recursive:    " << tempValue2 << "\n";
        std::cout << "Squaring iterative: " << tempValue3 << "\n";
        std::cout << "Squaring recursive: " << tempValue4 << "\n\n";
      }
    }
}

void testSum(int size = 1000) {
  std::vector<double> seq;
  double value = 0.0;
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<double> distr(-5000.0, 5000.0);

  seq.resize(size);
  for (int i = 0; i < size; i++) {
      double newValue = distr(eng);
      value = value + newValue;
      seq[i] = newValue;
  }
  
  std::cout << "Vector accumulate:            " << std::accumulate(seq.begin(), seq.end(), 0.0) << "\n";
  std::cout << "Inline summation:             " << value << "\n";
  std::cout << "Naive iterative summation:    " << summation::NaiveIterativeSummation(seq) << "\n";
  std::cout << "Naive recursive summation:    " << summation::NaiveRecursiveSummation(seq) << "\n";
  std::cout << "Kahan compensation summation: " << summation::KahanSummation(seq) << "\n";
}