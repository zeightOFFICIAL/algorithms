// SummationKahan.h

/*
Kahan summation algorithm, also known as compensated summation
and summation with the carry algorithm, is used to minimize the
loss of significance in the total result obtained by adding a
sequence of finite-precision floating-point numbers. This is
done by keeping a separate running compensation (a variable
to accumulate small errors).

https://www.geeksforgeeks.org/kahan-summation-algorithm/
*/

#include <vector> // vector

/*
  (vector T A) -> (T B)
  Finds the sum of elements B in vector A.
  -Returns B.
*/
template <typename T> T summationKahan(std::vector<T> elements);

template <typename T> T summationKahan(std::vector<T> elements) {
  T result = 0.0f, compensation = 0.0f;
  for (T value : elements) {
    T valueCompensated = value - compensation;
    T resultCompensated = result + valueCompensated;
    compensation = (resultCompensated - result) - valueCompensated;
    result = resultCompensated;
  }
  return result;
}