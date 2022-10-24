// Fibonacci.h

/*
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144...
F(n) = F(n-1) + F(n-2)

https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
*/

#include <cstdint> // uint64_t

/*
  (uint64 A) -> (uint64 B)
  Finds A-x element of fibonacci sequence.
  Uses recursion.
  -Returns B.
*/
uint64_t recursiveFibonacci(uint64_t x);
/*
  (uint64 A) -> (uint64 B)
  Finds A-x element of fibonacci sequence.
  Uses pure recursion.
  -Returns B.
*/
uint64_t pureRecursiveFibonacci(uint64_t x, uint64_t a = 0, uint64_t b = 1);
/*
  (uint64 A) -> (uint64 B)
  Finds A-x element of fibonacci sequence.
  Uses iteration.
  -Returns B.
*/
uint64_t iterativeFibonacci(int x);

uint64_t recursiveFibonacci(uint64_t x) {
  if ((x == 1) || (x == 0))
    return (x);
  return (recursiveFibonacci(x - 1) + recursiveFibonacci(x - 2));
}
uint64_t pureRecursiveFibonacci(uint64_t x, uint64_t a, uint64_t b) {
  if (x == 0)
    return a;
  if (x == 1)
    return b;
  return pureRecursiveFibonacci(x - 1, b, a + b);
}
uint64_t iterativeFibonacci(int n) {
  uint64_t result = 0, x = 1, y = 0, i;
  for (i = 0; i < n; i++) {
    y = result + x;
    result = x;
    x = y;
  }
  return result;
}