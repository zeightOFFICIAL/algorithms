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

/*
    (long double A, int64_t B)->(long double C)
    Finds C of the A**B=C equation. Recursuve.
    Returns the C.
*/
long double exponentiationSquaringRecursive(long double base, int64_t power);
/*
    (long double A, int64_t B)->(long double C)
    Finds C of the A**B=C equation. Iterative.
    Returns the C.
*/
long double exponentiationSquaringIterative(long double base, int64_t power);
/*
    (long double A, int64_t B)->(long double C)
    Finds C of the A**B=C equation. Iterative with prime.
    Returns the C.
*/
long double exponentiationSquaringRecursiveWithPrime(long double base, int64_t power);
/*
    (long double A, int64_t B)->(long double C)
    Finds C of the A**B=C equation. Recursive with prime.
    Returns the C.
*/
long double exponentiationSquaringIterativeWithPrime(long double base, int64_t power);

long double exponentiationSquaringRecursive(long double base, int64_t power) {
  if (power < 0)
    return exponentiationSquaringRecursive(1.0f / base, -power);
  else if (power == 0)
    return 1.0f;
  else if (power % 2 == 0)
    return exponentiationSquaringRecursive(base * base, power / 2);
  else if (power % 2 != 0)
    return base * exponentiationSquaringRecursive(base * base, (power - 1) / 2);
  return -1.0f;
}
int64_t exponentiationSquaringRecursiveWithPrime(int64_t base, int64_t power) {
  if (power == 0)
    return 1;
  else if (power == 1)
    return base % PRIME_NUMBER;
  int64_t next = exponentiationSquaringRecursive(base, power / 2);
  next = (next * next) % PRIME_NUMBER;
  if (power % 2 == 0)
    return next;
  else
    return ((base % PRIME_NUMBER) * next) % PRIME_NUMBER;
}

long double exponentiationSquaringIterative(long double base, int64_t power) {
  long double y;
  if (power < 0) {
    base = 1.0f / base;
    power = -power;
  }
  if (power == 0)
    return 1.0f;
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
int64_t exponentiationSquaringIterativeWithPrime(int64_t base, int64_t power) {
  int64_t y = 1L;
  while (power > 0) {
    if (power % 2 != 0)
      y = (y * base) % PRIME_NUMBER;
    base = (base * base) % PRIME_NUMBER;
    power = power / 2;
  }
  return y % PRIME_NUMBER;
}