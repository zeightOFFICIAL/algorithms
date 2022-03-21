/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 7
Hashing algorithms
- SHA-1 (secure hashing algorithm)
- Custom SAGH (saganenko hashing algorithm)
main.cpp
21.03.2022
ver 0.29
*/

#include <iostream>

#include "hashing/sha1.h"
#include "hashing/sagh.h"
 
using std::cout;
 
int main()
{
    cout << sha1("A Test") << "\n";
    cout<<sagh("A Test")<<"\n";
    //cout<<addBinary("01010101","1");

    return 0;
}