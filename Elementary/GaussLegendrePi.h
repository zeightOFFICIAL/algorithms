// PiGaussLegendre.h

#include "math.h"

namespace picalc {
  /*
    (double A) -> (double B)
    Finds pi number B with precision of A.
    Returns pi number B.
  */
  double GaussLegendrePi(double precisionRequired);
  
  double GaussLegendrePi(double precisionRequired) {
    double result = 0.0;
    double an = 1.0, bn = 1.0 / sqrt(2), tn = 1.0 / 4.0, pn = 1.0;
    double an_, bn_, tn_, pn_;
  
    for (double precision = 0.0; precision < precisionRequired; precision++) {
      an_ = (an + bn) / 2.0;
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
} // namespace picalc