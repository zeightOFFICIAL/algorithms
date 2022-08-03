/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 7
Hashing algorithms
- sha1 (Secure Hash Algorithm)
- sha256 (Secure Hash Algorithm)
- adler32
- fnv1-32
originally build on
Clang++ 12 (12.0.1)
compatible with:
g++ 7.5.0
main.cpp
03.08.2022
ver 1005
*/

#include <iostream>

#include "hashing/sha1.h"
#include "hashing/sha256.h"
#include "hashing/adler32.h"
#include "hashing/fnv132.h"
  
int main()
{
    std::cout << std::hex << adler32("Wikipedia") << "\n";
    std::cout << std::hex << fnv132("Wikipedia") << "\n";
    std::cout << sha1("A Test") << "\n";
    return 0;
}