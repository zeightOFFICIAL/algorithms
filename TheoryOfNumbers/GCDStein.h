// GCDStein.h

#include <cstdint>

namespace gcd {
  typedef uint64_t uint64;
  /**
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses stein method with recursion.
    Returns C.
  */
  static uint64 recursiveSteinRecursiveGCD(uint64 x, uint64 y);
  /**
    (uint64_t A, uint64_t B) -> (uint64_t C)
    Finds GCD of numbers A and B and returns
    its value - C. Uses stein method with iteration.
    Returns C.
  */
  static uint64 iterativeSteinGCD(uint64 x, uint64 y);
  
  static uint64 recursiveSteinRecursiveGCD(uint64 x, uint64 y) {
    if (x == y) {
      return x;
    }
    if (x == 0) {
      return y;
    }
    if (y == 0) {
      return x;
    }
  
    if (~x & 1) {
      if (y & 1) {
        return recursiveSteinRecursiveGCD(x >> 1, y);
      } else {
        return recursiveSteinRecursiveGCD(x >> 1, y >> 1) << 1;
      }
    }
    if (~y & 1) {
      return recursiveSteinRecursiveGCD(x, y >> 1);
    }
    if (x > y) {
      return recursiveSteinRecursiveGCD((x - y) >> 1, y);
    }
  
    return recursiveSteinRecursiveGCD((y - x) >> 1, x);
  }
  uint64 iterativeSteinGCD(uint64 x, uint64 y) {
    if (x == y) {
      return x;
    }
    if (x == 0) {
      return x;
    }
    if (y == 0) {
      return y;
    }
    uint64 k;
  
    for (k = 0; ((x | y) & 1) == 0; k++) {
      x >>= 1;
      y >>= 1;
    }
    while ((x & 1) == 0) {
      x >>= 1;
    }
    do {
      while ((y & 1) == 0) {
        y >>= 1;
      }
      if (x > y) {
        std::swap(x, y);
      }
      y = (y - x);
    } while (y != 0);
  
    return x << k;
  }
} // namespace gcd