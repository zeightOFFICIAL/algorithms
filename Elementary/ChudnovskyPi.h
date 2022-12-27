// ChudnovskyPi.h

#include "math.h"

namespace picalc {
  typedef unsigned short ushort;

  /*
    (unsigned short A) -> (double B)
    Finds 1/pi number B with precision of A.
    Uses Chudnovsky formula.
    Returns 1/pi number B.
  */
  static double ChudnovskyPi(ushort precision);
  /*
    (double A) -> (double B)
    Finds factorial B of number A. Uses iteration.
    Returns factorial number B.
  */
  static double IterativeFactorial(double x);
  
  static double IterativeFactorial(double x) {
    if (x > 20) {
      return 0;
    } else if (x == 0) {
      return 1;
    }
    double result = 1;
    ulong index;
  
    for (index = 2; index <= x; index++) {
      result *= index;
    }
  
    return result;
  }

  static double ChudnovskyPi(ushort precisionRequired) {
    double result = 0.0;

    if (precisionRequired == 0) {
      result += ((13591409.0)) /
                (pow(640320.0, 3.0 * 0 + 3.0f / 2.0));
      result *= 12.0;
      return result;
    }    
    for (ushort precision = 0; precision < precisionRequired; precision++) {
      result += (pow(-1.0, precision) * IterativeFactorial(6.0 * precision) *
                 (13591409.0 + (545140134.0 * precision))) /
                (IterativeFactorial(3.0 * precision) * pow(IterativeFactorial(precision), 3.0) *
                 pow(640320.0, 3.0 * precision + 3.0f / 2.0));
    }
    result *= 12.0;
  
    return result;
  }
} // namespace picalc