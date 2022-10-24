// ExponentiationNaive.h

#include "math.h" // int64_t

/*
  (long double A, int64_t B) -> (long double C)
  Finds C of the A**B=C equation. Uses iteration.
  -Returns the C.
*/
long double exponentiationNaiveIterative(long double base, int64_t power);
/*
  (long double A, int64_t B) -> (long double C)
  Finds C of the A**B=C equation. Uses Recursion.
  -Returns the C.
*/
long double exponentiationNaiveRecursive(long double base, int64_t power);

long double exponentiationNaiveIterative(long double base, int64_t power) {
  long double startBase = base, resultBase;
  if (power == 0)
    return 1.0f;
  else if (power > 0) {
    resultBase = base;
    for (int64_t i = 1; i < power; i++) {
      resultBase = resultBase * startBase;
    }
  } else if (power < 0) {
    resultBase = 1.0f / base;
    for (int64_t i = 1; i < abs(power); i++) {
      resultBase = resultBase * 1 / startBase;
    }
  }
  return resultBase;
}

long double exponentiationNaiveRecursive(long double base, int64_t power) {
  long double startBase = base, resultBase;
  if (power == 0)
    return 1.0f;
  else if (power > 0) {
    return exponentiationNaiveRecursive(base, power - 1) * base;
  } else if (power < 0) {
    return exponentiationNaiveRecursive(base, power + 1) * 1.0f / base;
  }
  return -1.0f;
}