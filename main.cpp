/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 7
Hashing algorithms
- SHA-1 (secure hashing algorithm)
- Custom SAGH (saganenko hashing algorithm)
main.cpp
20.03.2022
ver 0.09
*/

#include <iostream>

#include "hashing/sha1.h"
#include "hashing/sagh.h"
 
using std::cout;
 
int main()
{
    //cout << sha1("A Test") << "\n";
    cout<<sagh("A Test")<<"\n";
    //cout<<left_rotate("10101110",5);

    return 0;
}