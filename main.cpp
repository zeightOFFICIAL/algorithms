<<<<<<< HEAD
<<<<<<< HEAD
#include "elementary/ExponentiationNaive.h"
#include "elementary/ExponentiationSquaring.h"
#include "elementary/PiBorwein.h"
#include "elementary/PiChudnovsky.h"
#include "elementary/PiGaussLegendre.h"
#include "elementary/SummationKahan.h"
#include "elementary/SummationNaive.h"

#include "sorting/sorting_demo.h"

#include "substringsearch/substrsearch_demo.h"

#include "theoryofnumbers/Factorial.h"
#include "theoryofnumbers/Fibonacci.h"
#include "theoryofnumbers/GCDEuclidean.h"
#include "theoryofnumbers/GCDStein.h"
#include "theoryofnumbers/SieveEratosthenes.h"
#include "theoryofnumbers/SieveSundaram.h"

#include <iostream>
#include <vector>

int main() {
  // std::cout << std::setprecision(15);
  // std::cout << 1.0f / piBorweinCubic(35.0f) << "\n";
  // std::cout << piBorweinQuadratic(35.0f) << "\n";
  // std::cout << 1.0f / piBorweinQuartic(35.0f) << "\n";
  // std::cout << piGaussLegendre(15) << "\n";
  // std::cout << 1.0f / piChudnovsky(15.0f);
  // std::cout << exponentiationNaiveIterative(15, -5) << "\n";
  // std::cout << exponentiationNaiveRecursive(15, -5) << "\n";
  // std::cout << exponentiationSquaringIterative(15, -5) << "\n";
  // std::cout << exponentiationSquaringRecursive(15, -5) << "\n";
  // std::cout << NaiveSumIterative<long>(x) << "\n";
  // std::cout << NaiveSumRecursive<long>(x) << "\n";
  // std::cout << KahanSummation<long>(x) << "\n";

  // sorting_test();
  sorting_demo(5, 10000, 2500);
  // sorting_demo_silly(1);

  // substrsearch_demo(1);

  // std::cout << gcdEuclideanIterative(1002, 3) << "\n";
  // std::cout << gcdEuclideanRecursive(1002, 3) << "\n";
  // std::cout << gcdSteinIterative(1002, 3) << "\n";
  // std::cout << gcdSteinRecursive(1002, 3) << "\n";
  // std::vector<u_long> res;
  // res = primesEratosthenes(100);
  // for (u_long value : res)
  //   std::cout << value << "\n";
  // res = primesSundaram(100);
  // for (u_long value : res)
  //   std::cout << value << "\n";
  // std::cout << iterativeFibonacci(21) << "\n";
  // std::cout << recursiveFibonacci(21) << "\n";
  // std::cout << pureRecursiveFibonacci(21) << "\n";
  // std::cout << recursiveFactorial(7) << "\n";
  // std::cout << iterativeFactorial(7) << "\n";
=======
/*
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 7
Hashing algorithms
- sha1 (secure hash algorithm)
- sha256 (secure hash algorithm)
- adler32 (checksum)
- fnv1-32 (checksum)
originally build on
Clang++ 12 (12.0.1)
compatible with:
g++ 7.5.0
main.cpp
04.08.2022
ver 1009
*/

#include <iostream>

#include "hashing/sha1.h"
#include "hashing/sha256.h"
#include "hashing/adler32.h"
#include "hashing/fnv132.h"

int main()
{
    return 0;
>>>>>>> repob/main
=======
/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 4, 5
Graph algorithms. 
Algorithms of finding minimum spanning tree (MST):
- Prim's algorithm (minimal spanning tree, MST)
- Kruskal's algorithm (MST)
- Reverse delete algorithm (MST)
Algorithms of finding shortest path on graph (SPG):
- Dijkstra algorithm (shortest path on graph, SPG)
- Floyd-Warshall's algorithm (SPG)
- Johnson's algorithm (SPG)
originally built on
Clang++ 12 (12.0.1)
compatible with:
MSVC 142 (14.29)
compatible with:
g++ 7.5.0
main.cpp
01.08.2022
ver 1.128
*/

#include "graph/graph.h"
#include "shortest_path_on_graph/spg.h"
#include "minimum_spanning_tree/mst.h"

int main() 
{   
    return 0;
>>>>>>> repoc/main
}