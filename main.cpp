/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 2
String-searching algorithms
- Boyer–Moore
- Rabin-Karp
- Naive
- Bitap (Shift-OR)
originally build on
Clang++ 12 (12.0.1)
compatible with
MSVC 142 (14.29)
main.cpp
21.06.2022
ver 1.202
*/

// input output library
#include <iostream>

// library for testing
#include "substringsearch/test.h"

// substring search algorithms libraries
#include "substringsearch/boyer_moore.h"
#include "substringsearch/naive.h"
#include "substringsearch/rabin_karp.h"
#include "substringsearch/bitap.h"

int main() {
    fulltest(1);
    return 0;
}