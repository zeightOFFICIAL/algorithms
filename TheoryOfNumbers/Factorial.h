// Factorial.h

#include <cstdint>

namespace factorial {
  typedef uint64_t uint64;
  
  /**
    (uint64 A) -> (uint64 B)
    Finds factorial of number A. Uses recursion.
    Returns B.
  */
  uint64 recursiveFactorial(uint64 x);
  /**
    (uint64 A) -> (uint64 B)
    Finds factorial of number A. Uses iteration.
    Returns B.
  */
  uint64 iterativeFactorial(uint64 n);
  
  uint64 recursiveFactorial(uint64 x) {
    if ((x == 1) || (x == 0))
      return 1;
    return x * recursiveFactorial(x - 1);
  }
  uint64 iterativeFactorial(uint64 n) {
    uint64 result = 1, i;
    for (i = 2; i <= n; i++)
      result *= i;
    return result;
  }
} // namespace factorial