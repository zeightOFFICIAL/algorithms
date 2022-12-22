// Factorial.h

/*
Factorial of a non-negative integer is the multiplication
of all positive integers smaller than or equal to n.
For example factorial of 6 is 6*5*4*3*2*1 which is 720.

https://www.geeksforgeeks.org/program-for-factorial-of-a-number/
*/

#include <cstdint> // uint64_t

/*
  (uint64 A) -> (uint64 B)
  Finds factorial of number A. Uses recursion.
  -Returns B.
*/
uint64_t recursiveFactorial(uint64_t x);
/*
  (uint64 A) -> (uint64 B)
  Finds factorial of number A. Uses iteration.
  -Returns B.
*/
uint64_t iterativeFactorial(uint64_t n);

uint64_t recursiveFactorial(uint64_t x) {
  if ((x == 1) || (x == 0))
    return 1;
  return x * recursiveFactorial(x - 1);
}
uint64_t iterativeFactorial(uint64_t n) {
  uint64_t result = 1, i;
  for (i = 2; i <= n; i++)
    result *= i;
  return result;
}