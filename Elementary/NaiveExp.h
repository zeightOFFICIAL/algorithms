/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// ExponentiationNaive.h

#include "math.h"

namespace elementary {
  typedef int64_t int64;
  /**
    (double A, int64 B) -> (double C)
    Finds C of the A**B=C equation. Uses naive iteration.
    Returns C.
  */
  static double NaiveExpIterative(double base, int64 power);
  /**
    (double A, int64 B) -> (double C)
    Finds C of the A**B=C equation. Uses naive recursion.
    Returns C.
  */
  static double NaiveExpRecursive(double base, int64 power);
  
  static double NaiveExpIterative(double base, int64 power) {
    if (power == 0) {
      return 1.0;
    }
    if (base == 0) {
      return 0.0;
    }
    double startBase = base, resultBase;
  
    if (power > 0) {
      resultBase = base;
      for (int64 i = 1; i < power; i++) {
        resultBase = resultBase * startBase;
      }
    } else if (power < 0) {
      resultBase = 1.0 / base;
      for (int64 i = 1; i < abs(power); i++) {
        resultBase = resultBase * 1 / startBase;
      }
    }
  
    return resultBase;
  }

  static double NaiveExpRecursive(double base, int64 power) {
    if (power == 0) {
      return 1.0;
    }
    if (base == 0) {
      return 0.0;
    }  
    double startBase = base, resultBase;
    
    if (power > 0) {
      return NaiveExpRecursive(base, power - 1) * base;
    } else if (power < 0) {
      return NaiveExpRecursive(base, power + 1) * 1.0 / base;
    }
  
    return -1.0f;
  }
} // namespace exponentiation