// ExponentiationSquaring.h

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

/*
  (long double A, int64_t B)->(long double C)
  Finds C of the A**B=C equation. Recursuve.
  -Returns the C.
*/
long double exponentiationSquaringRecursive(long double base, int64_t power);
/*
  (long double A, int64_t B)->(long double C)
  Finds C of the A**B=C equation. Iterative.
  -Returns the C.
*/
long double exponentiationSquaringIterative(long double base, int64_t power);

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
