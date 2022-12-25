// GCDStein.h

#include <cstdint> // uint64_t

/*
  (uint64 A, uint64 B) -> (uint64 C)
  Finds GCD of numbers A and B and returns
  its value - C. Uses recursion.
  -Returns C.
*/
uint64_t gcdSteinRecursive(uint64_t x, uint64_t y);
/*
  (uint64 A, uint64 B) -> (uint64 C)
  Finds GCD of numbers A and B and returns
  its value - C. Uses iteration.
  -Returns C.
*/
uint64_t gcdSteinIterative(uint64_t x, uint64_t y);

uint64_t gcdSteinRecursive(uint64_t x, uint64_t y) {
  if (x == y)
    return x;
  if (x == 0)
    return y;
  if (y == 0)
    return x;
  if (~x & 1) {
    if (y & 1)
      return gcdSteinRecursive(x >> 1, y);
    else
      return gcdSteinRecursive(x >> 1, y >> 1) << 1;
  }
  if (~y & 1)
    return gcdSteinRecursive(x, y >> 1);
  if (x > y)
    return gcdSteinRecursive((x - y) >> 1, y);
  return gcdSteinRecursive((y - x) >> 1, x);
}

uint64_t gcdSteinIterative(uint64_t x, uint64_t y) {
  if (x == 0)
    return y;
  if (y == 0)
    return x;
  unsigned long long k;
  for (k = 0; ((x | y) & 1) == 0; k++) {
    x >>= 1;
    y >>= 1;
  }
  while ((x & 1) == 0)
    x >>= 1;
  do {
    while ((y & 1) == 0)
      y >>= 1;
    if (x > y)
      std::swap(x, y);
    y = (y - x);
  } while (y != 0);
  return x << k;
}