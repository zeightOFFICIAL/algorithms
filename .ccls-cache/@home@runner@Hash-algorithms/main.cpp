/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 7
Hashing algorithms
- sha1
- sha256
- ?
main.cpp
22.03.2022
ver 0.7
*/

#include <iostream>

#include "hashing/sha1.h"
#include "hashing/sha256.h"

#include "tools/bitwise_operations.h"
 
using std::cout;
 
int main()
{
    cout<<"Start."<<"\n";
    
    cout << sha1("hello world!") << "\n";
    cout << sha256("hello world!") << "\n";
    
    cout<<"End."<<"\n";
    return 0;
}