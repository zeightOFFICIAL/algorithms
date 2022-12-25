// GCDEuclidean.h

#include <cstdint> // uint64_t

/*
  (uint64 A, uint64 B) -> (uint64 C)
  Finds GCD of numbers A and B and returns
  its value - C. Uses recursion.
  -Returns C.
*/
uint64_t gcdEuclideanRecursive(uint64_t x, uint64_t y);
/*
  (uint64 A, uint64 B) -> (uint64 C)
  Finds GCD of numbers A and B and returns
  its value - C. Uses iteration.
  -Returns C.
*/
uint64_t gcdEuclideanIterative(uint64_t x, uint64_t y);

uint64_t gcdEuclideanRecursive(uint64_t x, uint64_t y) {
  if (y == 0)
    return x;
  return gcdEuclideanRecursive(y, x % y);
}
uint64_t gcdEuclideanIterative(uint64_t x, uint64_t y) {
  while (x != y) {
    if (x > y)
      x -= y;
    else
      y -= x;
  }
  return x;
}