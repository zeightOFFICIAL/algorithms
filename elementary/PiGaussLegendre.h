// PiGaussLegendre.h

/*
The Gauss–Legendre algorithm is an algorithm to compute the digits of
π. It is notable for being rapidly convergent, with only 25
iterations producing 45 million correct digits of π.

https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_algorithm
*/

#include "math.h" // sqrt

/*
  (unsigned int A) -> (long double B)
  Finds pi number B with precision of A.
  -Returns pi number B.
*/
long double piGaussLegendre(unsigned int precisionRequired);

long double piGaussLegendre(unsigned int precisionRequired) {
  long double result = 0.0f;
  long double a0 = 1.0f, b0 = 1.0f / sqrt(2), t0 = 1.0f / 4.0f, p0 = 1.0f;
  long double an, bn, tn, pn;
  for (unsigned int precision = 0; precision < precisionRequired; precision++) {
    an = (a0 + b0) / 2.0f;
    bn = sqrt(a0 * b0);
    tn = t0 - (p0 * (a0 - an) * (a0 - an));
    pn = 2 * p0;
    a0 = an;
    b0 = bn;
    t0 = tn;
    p0 = pn;
    result = (an + bn) * (an + bn) / (4 * tn);
  }
  return result;
}