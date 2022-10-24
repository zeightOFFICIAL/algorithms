#include "elementary/ExponentiationNaive.h"
#include "elementary/ExponentiationSquaring.h"
#include "elementary/PiGaussLegendre.h"
#include "elementary/SummationKahan.h"
#include "elementary/SummationNaive.h"
#include <iostream>
#include <limits>
#include <vector>
int main() {
  // sorting_demo(1);
  // sorting_demo_silly(1);

  // substrsearch_demo(1);

  // reciter1_demo(1);
  // reciter2_demo(30, 1, 1);
  // std::cout.precision(9);
  // std::cout << NaiveSumIterative<long>(x) << "\n";
  // std::cout << NaiveSumRecursive<long>(x) << "\n";
  // std::cout << KahanSummation<long>(x) << "\n";
  // std::cout << piGaussLegendre(5);
  std::cout << exponentiationNaiveIterative(-5, -5) << "\n";
  std::cout << exponentiationNaiveRecursive(-5, -5) << "\n";

  std::cout << exponentiationSquaringIterative(-5, -5) << "\n";
  std::cout << exponentiationSquaringRecursive(-5, -5) << "\n";
  //std::cout << exponentiationSquaringIterativeWithPrime(-5, -3) << "\n";

  // std::cout << exponentiationSquaringIterative(-5, 5) << "\n";
  // std::cout << exponentiationSquaringRecursive(-5, 5) << "\n";
  // std::cout << exponentiationSquaringIterativeWithPrime(-5, 5) << "\n";
  // std::cout << exponentiationSquaringRecursiveWithPrime(-5, 5) << "\n";
  // std::cout << exponentiationNaiveRecursiveIterative(15, 5);
}