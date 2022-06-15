/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 2
String-searching algorithms
- Boyer–Moore
- Rabin-Karp
- Naive
- Bitap
originally build on
Clang++ 12 (12.0.1)
main.cpp
15.06.2022
ver 1.195
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
    std::cout<<"Start."<<"\n";
    
    fulltest(100);
    
    std::cout<<"End."<<"\n";       
    return 0;
}