#include <iostream>

#include "Elementary/_Demo.h"
#include "TheoryOfNumbers/_Demo.h"
#include "Sorting/_Demo.h"
#include "PatternSearch/_Demo.h"
#include "Hashing/_Demo.h"
#include "Graph/_Demo.h"
#include "Applied/ZellerCongruence.h"
#include "Applied/Meeus.h"
#include "Applied/GaussEaster.h"


int main() {
  // testExp();
  // testSum();

  // testPi();
  // testFactorial();
  // testFibonacci();
  // testGCD();
  // testSieves();
  
  // testSorting(&sorting::sortComb, 500, false);
  // testAllSortings(10, 100000, 10000);
  // testSillySortings(1);

  // testSearchFull(5, "aa");

  // testHashing();

  // testSPG();
  // testMST();
  
  // std::cout << applied::ZellerCongruence(1,1,2023) << "\n";
  // std::cout << easterday::MeeusJulianEaster(1961) << "\n";
  std::cout << easterday::GaussGregorianEaster(2022) << "\n";
    
  return 0;
}