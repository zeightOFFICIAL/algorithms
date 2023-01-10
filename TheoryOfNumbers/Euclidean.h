/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// GCDEuclidean.h

#include <cstdint>

namespace gcd {
  typedef uint64_t uint64;
  /**
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses euclidean method with recursion.
    Returns C.
  */
  static uint64 RecursiveEuclideanGCD(uint64 x, uint64 y);
  /**
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses euclidean method with iteration.
    Returns C.
  */
  static uint64 IterativeEuclideanGCD(uint64 x, uint64 y);
  
  static uint64 RecursiveEuclideanGCD(uint64 x, uint64 y) {
    if (x == 0) {
      return x;
    }
    
    if (y == 0) {
      return x;
    }
  
    return RecursiveEuclideanGCD(y, x % y);
  }

  static uint64 IterativeEuclideanGCD(uint64 x, uint64 y) {
    if (x == 0) {
      return y;
    }    
    if (y == 0) {
      return x;
    }    
    
    while (x != y) {
      if (x > y) {
        x -= y;
      } else {
        y -= x;
      }
    }
    
    return x;
  }
} // namespace gcd