// PiBorwein.h

#include "math.h"

namespace picalc {
/*
  (double A) -> (double B)
  Finds pi number B with precision of A.
  Returns pi number B.
*/
double BorweinQuadratic(double precisionRequired);
/*
  (double A) -> (double B)
  Finds 1/pi number B with precision of A.
  Returns 1/pi number B.
*/
double BorweinCubic(double precisionRequired);
/*
  (double A) -> (double B)
  Finds 1/pi number B with precision of A.
  Returns 1/pi number B.
*/
double BorweinQuartic(double precisionRequired);

double BorweinQuadratic(double precisionRequired) {
  double an = sqrt(2.0), bn = 0.0, pn = 2.0 + an;
  double an_, bn_, pn_;
  for (double precision = 0.0; precision < precisionRequired; precision++) {
    an_ = (sqrt(an) + (1.0 / sqrt(an))) / (2.0);
    bn_ = ((1.0 + bn) * sqrt(an)) / (an + bn);
    pn_ = ((1.0 + an_) * pn * bn_) / (1.0 + bn_);
    an = an_;
    bn = bn_;
    pn = pn_;
  }
  return pn;
}
double BorweinCubic(double precisionRequired) {
  double an = (1.0) / (3.0), sn = (sqrt(3.0) - 1.0) / (2.0);
  double an_, sn_, rn_;
  for (double precision = 0.0; precision < precisionRequired; precision++) {
    rn_ = (3.0) / (1.0 + 2.0 * (pow(1.0 - pow(sn, 3.0), 1.0 / 3.0)));
    sn_ = (rn_ - 1.0) / (2.0);
    an_ = pow(rn_, 2.0) * an - pow(3.0, precision) * (pow(rn_, 2.0) - 1.0);
    an = an_;
    sn = sn_;
  }
  return an;
}
double BorweinQuartic(double precisionRequired) {

  double an = 2.0 * pow(sqrt(2.0) - 1.0, 2.0), yn = sqrt(2.0) - 1;
  double an_, yn_;
  for (double precision = 0.0; precision < precisionRequired; precision++) {
    yn_ = (1.0 - pow(1.0 - pow(yn, 4.0), 1.0 / 4.0)) /
          (1.0 + pow(1.0 - pow(yn, 4.0), 1.0 / 4.0));
    an_ = an * pow(1.0 + yn_, 4.0) -
          pow(2.0, 2.0 * precision + 3.0) * yn_ * (1.0 + yn_ + pow(yn_, 2.0));
    an = an_;
    yn = yn_;
  }
  return an;
}
} // namespace picalc
