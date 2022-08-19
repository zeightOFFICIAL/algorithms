/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 3
Recursive and iterable algorithms
- Fibonacci (recursion, iterative, tail-recursion)
- Greatest common divisor (recursion, iterative)
- Factorial (tail-recursion, iterative)
- Sum of numbers in interval (tail-recursion)
originally build on
Clang++ 12 (12.0.1)
compatible with
MSVC 142 (14.29)
main.cpp
23.06.2022
ver 1.071
*/

// input output library
#include <iostream>

// library for testing
#include "recursion_vs_iteration/test.h"

// recursive and iterative algorithms libraries
#include "recursion_vs_iteration/factorial.h"
#include "recursion_vs_iteration/fibonacci.h"
#include "recursion_vs_iteration/gcd.h"
#include "recursion_vs_iteration/totalsum.h"


int main() 
{
    fulltestunary(10);
    fulltestbinary(170000, 125000, 10);
    return 0;
}