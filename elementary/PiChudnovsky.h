// PiChudnovsky.h

/*
The Chudnovsky algorithm is a fast method for calculating
the digits of π, based on Ramanujan’s π formulae. It was
published by the Chudnovsky brothers in 1988.

It was used in the world record calculations of 2.7 trillion
digits of π in December 2009, 10 trillion digits in
October 2011, 22.4 trillion digits in November 2016,
31.4 trillion digits in September 2018–January 2019,
50 trillion digits on January 29, 2020, 62.8 trillion
digits on August 14, 2021, and 100 trillion digits on
March 21, 2022.

https://en.wikipedia.org/wiki/Chudnovsky_algorithm
*/

#include "math.h" // sqrt

/*
  (unsigned int A) -> (long double B)
  Finds 1/pi number B with precision of A.
  -Returns 1/pi number B.
*/
long double piChudnovsky(unsigned int precision);
/*
  (long double A) -> (long double B)
  Finds factorial B of number A.
  -Returns factorial number B.
*/
long double factorial(long double number);

long double factorial(long double number) {
  if ((number == 1.0f) || (number == 0.0f))
    return 1.0f;
  return number * factorial(number - 1.0f);
}

long double piChudnovsky(unsigned int precisionRequired) {
  long double result = 0.0f;
  for (unsigned int precision = 0; precision < precisionRequired; precision++) {
    result += (pow(-1.0f, precision) * factorial(6.0f * precision) *
               (13591409.0f + (545140134.0f * precision))) /
              (factorial(3.0f * precision) * pow(factorial(precision), 3.0f) *
               pow(640320.0f, 3.0f * precision + 3.0f / 2.0f));
  }
  result *= 12.0;
  return result;
}
