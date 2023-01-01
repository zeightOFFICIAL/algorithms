// BorweinPi.h

#include "math.h"

namespace picalc {
  typedef unsigned short ushort;

  /*
    (unsigned short A) -> (double B)
    Finds pi number B with precision of A.
    Uses Borwein Quadratic formula.
    Returns pi number B.
  */
  static double BorweinQuadraticPi(ushort precisionRequired);
  /*
    (unsigned short A) -> (double B)
    Finds 1/pi number B with precision of A.
    Uses Borwein Cubic formula.
    Returns 1/pi number B.
  */
  static double BorweinCubicPi(ushort precisionRequired);
  /*
    (unsigned short A) -> (double B)
    Finds 1/pi number B with precision of A.
    Uses Borwein Quartic formula.
    Returns 1/pi number B.
  */
  static double BorweinQuarticPi(ushort precisionRequired);

  static double BorweinQuadraticPi(ushort precisionRequired) {
    double an = sqrt(2.0), bn = 0.0, pn = 2.0 + an;
    double aNew, bNew, pNew;
    
    for (ushort precision = 0; precision < precisionRequired; precision++) {
      aNew = (sqrt(an) + (1.0 / sqrt(an))) / (2.0);
      bNew = ((1.0 + bn) * sqrt(an)) / (an + bn);
      pNew = ((1.0 + aNew) * pn * bNew) / (1.0 + bNew);
      an = aNew;
      bn = bNew;
      pn = pNew;
    }
    
    return pn;
  }

  static double BorweinCubicPi(ushort precisionRequired) {
    double an = (1.0) / (3.0), sn = (sqrt(3.0) - 1.0) / (2.0);
    double aNew, sNew, rNew;
    
    for (ushort precision = 0; precision < precisionRequired; precision++) {
      rNew = (3.0) / (1.0 + 2.0 * (pow(1.0 - pow(sn, 3.0), 1.0 / 3.0)));
      sNew = (rNew - 1.0) / (2.0);
      aNew = pow(rNew, 2.0) * an - pow(3.0, precision) * (pow(rNew, 2.0) - 1.0);
      an = aNew;
      sn = sNew;
    }
    
    return an;
  }

  static double BorweinQuarticPi(ushort precisionRequired) {
    double an = 2.0 * pow(sqrt(2.0) - 1.0, 2.0), yn = sqrt(2.0) - 1;
    double aNew, yNew;
    
    for (ushort precision = 0; precision < precisionRequired; precision++) {
      yNew = (1.0 - pow(1.0 - pow(yn, 4.0), 1.0 / 4.0)) /
            (1.0 + pow(1.0 - pow(yn, 4.0), 1.0 / 4.0));
      aNew = an * pow(1.0 + yNew, 4.0) -
            pow(2.0, 2.0 * precision + 3.0) * yNew * (1.0 + yNew + pow(yNew, 2.0));
      an = aNew;
      yn = yNew;
    }
    
    return an;
  }
} // namespace picalc
