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
  long double an = 1.0f, bn = 1.0f / sqrt(2), tn = 1.0f / 4.0f, pn = 1.0f;
  long double an_, bn_, tn_, pn_;
  for (unsigned int precision = 0; precision < precisionRequired; precision++) {
    an_ = (an + bn) / 2.0f;
    bn_ = sqrt(an * bn);
    tn_ = tn - (pn * (an - an_) * (an - an_));
    pn_ = 2 * pn;
    an = an_;
    bn = bn_;
    tn = tn_;
    pn = pn_;
    result = (an_ + bn_) * (an_ + bn_) / (4 * tn_);
  }
  return result;
}