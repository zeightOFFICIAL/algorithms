// PiChudnovsky.h

#include "math.h" // sqrt

namespace picalc {
  /*
    (double A) -> (double B)
    Finds 1/pi number B with precision of A.
    Returns 1/pi number B.
  */
  double chudnovskyPi(double precision);
  /*
    (double A) -> (double B)
    Finds factorial B of number A.
    Returns factorial number B.
  */
  double factorial(double number);
  
  double factorial(double number) {
    if ((number == 1.0) || (number == 0.0)) {
      return 1.0;
    }
    return number * factorial(number - 1.0);
  }
  
  double chudnovskyPi(double precisionRequired) {
    double result = 0.0;
    for (double precision = 0.0; precision < precisionRequired; precision++) {
      result += (pow(-1.0, precision) * factorial(6.0 * precision) *
                 (13591409.0 + (545140134.0 * precision))) /
                (factorial(3.0 * precision) * pow(factorial(precision), 3.0) *
                 pow(640320.0, 3.0 * precision + 3.0f / 2.0));
    }
    result *= 12.0;
  
    return result;
  }
} // namespace picalc