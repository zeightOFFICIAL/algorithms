// exponentiation_squaring.h

/*
    In mathematics and computer programming, exponentiating by
    squaring is a general method for fast computation of large
    positive integer powers of a number, or more generally of
    an element of a semigroup, like a polynomial or a square
    matrix. Some variants are commonly referred to as
    square-and-multiply algorithms or binary exponentiation.
    These can be of quite general use, for example in modular
    arithmetic or powering of matrices. For semigroups for
    which additive notation is commonly used, like elliptic
    curves used in cryptography, this method is also referred
    to as double-and-add.

    https://en.wikipedia.org/wiki/Exponentiation_by_squaring
*/

#include "math.h" // int64_t

#define PRIME_NUMBER 1000000007

int64_t ExponentiationSquaringRecursive(int64_t base, int64_t power);
int64_t ExponentiationSquaringRecursiveWithPrime(int64_t base, int64_t power);
int64_t ExponentiationSquaringIterative(int64_t base, int64_t power);
int64_t ExponentiationSquaringIterativeWithPrime(int64_t base, int64_t power);

/*
    (int64_t A, int64_t B)->(int64_t C)
    Finds C of the A^B=C equation.
    Returns the C.
*/
int64_t ExponentiationSquaringRecursive(int64_t base, int64_t power) {
  if (power < 0)
    return ExponentiationSquaringRecursive(1 / base, -power);
  else if (power == 0)
    return 1;
  else if (power % 2 == 0)
    return ExponentiationSquaringRecursive(base * base, power / 2);
  else if (power % 2 != 0)
    return base * ExponentiationSquaringRecursive(base * base, (power - 1) / 2);
  return -1;
}
int64_t ExponentiationSquaringRecursiveWithPrime(int64_t base, int64_t power) {
  if (power == 0)
    return 1;
  else if (power == 1)
    return base % PRIME_NUMBER;
  int64_t next = ExponentiationSquaringRecursive(base, power / 2);
  next = (next * next) % PRIME_NUMBER;
  if (power % 2 == 0)
    return next;
  else
    return ((base % PRIME_NUMBER) * next) % PRIME_NUMBER;
}
int64_t ExponentiationSquaringIterative(int64_t base, int64_t power) {
  int64_t y;
  if (power < 0) {
    base = 1 / base;
    power = -power;
  }
  if (power == 0)
    return 1;
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
int64_t ExponentiationSquaringIterativeWithPrime(int64_t base, int64_t power) {
  int64_t y = 1L;
  while (power > 0) {
    if (power % 2 != 0)
      y = (y * base) % PRIME_NUMBER;
    base = (base * base) % PRIME_NUMBER;
    power = power / 2;
  }
  return y % PRIME_NUMBER;
}