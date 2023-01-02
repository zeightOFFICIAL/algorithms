// Demo.h
// use !ONLY! for testing of the program's work
// for version 1.32
#pragma once

#include "math.h"
#include <iostream>
#include <random>
#include <vector>

//-------------------------------------

#include "KahanSum.h"
#include "NaiveSum.h"

#include "NaiveExp.h"
#include "SquaringExp.h"

//-------------------------------------

void testExp(int startBase, int endBase, int startPow, int endPow) {
  int power, base;

  for (int base = startBase; base < endBase; base++) {
    for (int power = startPow; power < endPow; power++) {
      std::cout << "BASE = " << base << " POWER = " << power << "\n";

      double tempValue1 = exponentiation::NaiveExpIterative(base, power);
      double tempValue2 = exponentiation::NaiveExpRecursive(base, power);
      double tempValue3 = exponentiation::SquaringIterativeExp(base, power);
      double tempValue4 = exponentiation::SquaringRecursiveExp(base, power);

      std::cout << "Math.h POW:         " << pow(base, power) << "\n";
      std::cout << "Naive iterative:    " << tempValue1 << "\n";
      std::cout << "Naive recursive:    " << tempValue2 << "\n";
      std::cout << "Squaring iterative: " << tempValue3 << "\n";
      std::cout << "Squaring recursive: " << tempValue4 << "\n\n";
    }
  }
}

void testExp(int base = 2, int power = 5) {
  std::cout << "BASE = " << base << " POWER = " << power << "\n";

  double tempValue1 = exponentiation::NaiveExpIterative(base, power);
  double tempValue2 = exponentiation::NaiveExpRecursive(base, power);
  double tempValue3 = exponentiation::SquaringIterativeExp(base, power);
  double tempValue4 = exponentiation::SquaringRecursiveExp(base, power);

  std::cout << "Math.h POW:         " << pow(base, power) << "\n";
  std::cout << "Naive iterative:    " << tempValue1 << "\n";
  std::cout << "Naive recursive:    " << tempValue2 << "\n";
  std::cout << "Squaring iterative: " << tempValue3 << "\n";
  std::cout << "Squaring recursive: " << tempValue4 << "\n\n";
}

void testSum(std::vector<double> seq) {
  double value = 0.0;

  for (int i = 0; i < seq.size(); i++) {
    value = value + seq[i];
  }

  double tempValue1 = summation::NaiveIterativeSummation(seq);
  double tempValue2 = summation::NaiveRecursiveSummation(seq);
  double tempValue3 = summation::KahanSummation(seq);

  std::cout << "Vector accumulate:            "
            << std::accumulate(seq.begin(), seq.end(), 0.0) << "\n";
  std::cout << "Inline summation:             " << value << "\n";
  std::cout << "Naive iterative summation:    " << tempValue1 << "\n";
  std::cout << "Naive recursive summation:    " << tempValue2 << "\n";
  std::cout << "Kahan compensation summation: " << tempValue3 << "\n";
}

void testSum(int size = 1000) {
  std::vector<double> seq;
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<double> distr(-5000.0, 5000.0);
  double value = 0.0;

  seq.resize(size);
  for (int i = 0; i < size; i++) {
    double newValue = distr(eng);
    value = value + newValue;
    seq[i] = newValue;
  }

  double tempValue1 = summation::NaiveIterativeSummation(seq);
  double tempValue2 = summation::NaiveRecursiveSummation(seq);
  double tempValue3 = summation::KahanSummation(seq);

  std::cout << "Vector accumulate:            " << std::accumulate(seq.begin(), seq.end(), 0.0) << "\n";
  std::cout << "Inline summation:             " << value << "\n";
  std::cout << "Naive iterative summation:    " << tempValue1 << "\n";
  std::cout << "Naive recursive summation:    " << tempValue2 << "\n";
  std::cout << "Kahan compensation summation: " << tempValue3 << "\n";
}