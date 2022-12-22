// PiBorwein.h

/*
Borwein’s algorithm is a calculation contrived by
Jonathan and Peter Borwein to compute the estimation
of 1/π. They conceived a few different algorithms.
The following implementation of Borwein’s algorithm
with quartic assembly in Java in fact ascertains
Pi, however, converges excessively fast.
In principle, a merges quartic ally to 1/π.
On every emphasis, the number of correct digits
is in this way quadrupled.

https://www.geeksforgeeks.org/implementing-borwein-algorithm-in-java/
*/

#include "math.h" // sqrt

/*
  (long double A) -> (long double B)
  Finds pi number B with precision of A.
  -Returns pi number B.
*/
long double piBorweinQuadratic(long double precisionRequired);
/*
  (long double A) -> (long double B)
  Finds 1/pi number B with precision of A.
  -Returns 1/pi number B.
*/
long double piBorweinCubic(long double precisionRequired);
/*
  (long double A) -> (long double B)
  Finds 1/pi number B with precision of A.
  -Returns 1/pi number B.
*/
long double piBorweinQuartic(long double precisionRequired);

long double piBorweinQuadratic(long double precisionRequired) {
  long double an = sqrt(2.0f), bn = 0.0f, pn = 2.0f + an;
  long double an_, bn_, pn_;
  for (long double precision = 0.0f; precision < precisionRequired;
       precision++) {
    an_ = (sqrt(an) + (1.0f / sqrt(an))) / (2.0f);
    bn_ = ((1.0f + bn) * sqrt(an)) / (an + bn);
    pn_ = ((1.0f + an_) * pn * bn_) / (1.0f + bn_);
    an = an_;
    bn = bn_;
    pn = pn_;
  }
  return pn;
}

long double piBorweinCubic(long double precisionRequired) {
  long double an = (1.0f) / (3.0f), sn = (sqrt(3.0f) - 1.0f) / (2.0f);
  long double an_, sn_, rn_;
  for (long double precision = 0.0f; precision < precisionRequired;
       precision++) {
    rn_ = (3.0f) / (1.0f + 2.0f * (pow(1.0f - pow(sn, 3.0f), 1.0f / 3.0f)));
    sn_ = (rn_ - 1.0f) / (2.0f);
    an_ = pow(rn_, 2.0f) * an - pow(3.0f, precision) * (pow(rn_, 2.0f) - 1.0f);
    an = an_;
    sn = sn_;
  }
  return an;
}

long double piBorweinQuartic(long double precisionRequired) {

  long double an = 2.0f * pow(sqrt(2.0f) - 1.0f, 2.0f), yn = sqrt(2.0f) - 1;
  long double an_, yn_;
  for (long double precision = 0.0f; precision < precisionRequired;
       precision++) {
    yn_ = (1.0f - pow(1.0f - pow(yn, 4.0f), 1.0f / 4.0f)) /
          (1.0f + pow(1.0f - pow(yn, 4.0f), 1.0f / 4.0f));
    an_ = an * pow(1.0f + yn_, 4.0f) - pow(2.0f, 2.0f * precision + 3.0f) *
                                           yn_ * (1.0f + yn_ + pow(yn_, 2.0f));
    an = an_;
    yn = yn_;
  }
  return an;
}
