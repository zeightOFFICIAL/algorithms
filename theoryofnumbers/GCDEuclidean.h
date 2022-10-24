// GCDEuclidean.h

/*
  In mathematics, the Euclidean algorithm, or Euclid's algorithm, is
  an efficient method for computing the greatest common divisor (GCD) of two
  integers (numbers), the largest number that divides them both without a
  remainder.

  https://en.wikipedia.org/wiki/Euclidean_algorithm
*/

#include <cstdint> // uint64_t

/*
(uint64 A, uint64 B) -> (uint64 C)
Finds GCD of numbers A and B and returns
its value - C. Uses recursion.
*/
uint64_t GCDEuclideanRecursive(uint64_t x, uint64_t y);
/*
(uint64 A, uint64 B) -> (uint64 C)
Finds GCD of numbers A and B and returns
its value - C. Uses iteration.
*/
uint64_t GCDEuclideanIterative(uint64_t x, uint64_t y);

uint64_t GCDEuclideanRecursive(uint64_t x, uint64_t y) {
  if (y == 0)
    return x;
  return GCDEuclideanRecursive(y, x % y);
}
uint64_t GCDEuclideanIterative(uint64_t x, uint64_t y) {
  while (x != y) {
    if (x > y)
      x -= y;
    else
      y -= x;
  }
  return x;
}