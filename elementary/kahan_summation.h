// kahan_summation.h

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

template <typename T> T KahanSummation(std::vector<T> elements);

/*
    (vector T A)->(T B)
    Finds the sum of elements in vector A.
    Returns B.
*/
template <typename T> T KahanSummation(std::vector<T> elements) {
  T result = 0.0f, c = 0.0f;
  for (T value : elements) {
    T y = value - c;
    T m = result + y;
    c = (m - result) - y;
    result = m;
  }
  return result;
}