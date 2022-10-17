// gauss_legendre_pi.h

/*
    The Gauss–Legendre algorithm is an algorithm to compute the digits of
    π. It is notable for being rapidly convergent, with only 25
    iterations producing 45 million correct digits of π.

    https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_algorithm
*/

#include "math.h" // sqrt

long double GaussLegendrePi(unsigned int n);

/*
    (unsigned int A) -> (long double B)
    Finds pi number with precision of A.
    Returns pi number B.
*/
long double GaussLegendrePi(unsigned int n) {
  long double result = 0.0f;
  long double a0 = 1.0f, b0 = 1.0f / sqrt(2), t0 = 1.0f / 4.0f, p0 = 1.0f;
  long double an, bn, tn, pn;
  for (unsigned int i = 0; i < n; i++) {
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