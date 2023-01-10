/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// GaussLegendrePi.h

#include "math.h"

namespace picalc {
  typedef unsigned short ushort;
  /*
    (unsigned short A) -> (double B)
    Finds pi number B with precision of A.
    Uses Gauss-Legendre formula.
    Returns pi number B.
  */
  static double GaussLegendrePi(ushort precisionRequired);
  
  static double GaussLegendrePi(ushort precisionRequired) {
    double result = 0.0;
    double an = 1.0, bn = 1.0 / sqrt(2), tn = 1.0 / 4.0, pn = 1.0;
    double aNew, bNew, tNew, pNew;

    if (precisionRequired == 0) {
      return (an + bn) * (an + bn) / (4 * tn);
    }  
    for (ushort precision = 0; precision < precisionRequired; precision++) {
      aNew = (an + bn) / 2.0;
      bNew = sqrt(an * bn);
      tNew = tn - (pn * (an - aNew) * (an - aNew));
      pNew = 2 * pn;
      an = aNew;
      bn = bNew;
      tn = tNew;
      pn = pNew;
      result = (aNew + bNew) * (aNew + bNew) / (4 * tNew);
    }
  
    return result;
  }
} // namespace picalc