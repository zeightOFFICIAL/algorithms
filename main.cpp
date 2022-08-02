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
02.08.2022
ver 1001
*/

#include <iostream>

#include "hashing/sha1.h"
#include "hashing/sha256.h"
#include "hashing/adler32.h"
#include "hashing/fnv132.h"
  
int main()
{
    std::cout << adler32("Wikipedia");
    return 0;
}