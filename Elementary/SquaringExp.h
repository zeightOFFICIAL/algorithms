/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// ExponentiationSquaring.h

#include "math.h"

namespace elementary {
  typedef int64_t int64;
  /*
    (double A, int64 B) -> (double C)
    Finds C of the A**B=C equation. Uses squaring recursion.
    Returns C.
  */
  static double SquaringRecursiveExp(double base, int64 power);
  /*
    (double A, int64 B) -> (double C)
    Finds C of the A**B=C equation. Uses squaring iteration.
    Returns C.
  */
  static double SquaringIterativeExp(double base, int64 power);
  
  static double SquaringRecursiveExp(double base, int64 power) {
    if (power == 0) {
      return 1.0;
    }
    if (base == 0) {
      return 0.0;
    }
  
    if (power < 0) {
      return SquaringRecursiveExp(1.0 / base, -power);
    } else if (power == 0) {
      return 1.0;
    } else if (power % 2 == 0) {
      return SquaringRecursiveExp(base * base, power / 2);
    } else if (power % 2 != 0) {
      return base * SquaringRecursiveExp(base * base, (power - 1) / 2);
    }
  
    return -1.0;
  }
  static double SquaringIterativeExp(double base, int64 power) {
    if (power == 0) {
      return 1.0;
    }
    if (base == 0) {
      return 0.0;
    }
    double y;
    
    if (power < 0) {
      base = 1.0 / base;
      power = -power;
    }  
    y = 1;
    while (power > 1) {
      if (power % 2 == 0) {
        base = base * base;
        power = power / 2;
      } else {
        y = base * y;
        base = base * base;
        power = (power - 1) / 2;
      }
    }
    
    return base * y;
  }
} // namespace exponentiation
