/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 7
Hashing algorithms
- sha-1
main.cpp
21.03.2022
ver 0.4
*/

#include <iostream>

#include "hashing/sha1.h"
 
using std::cout;
 
int main()
{
    cout<<"Start."<<"\n";
    
    cout << sha1("hello world!") << "\n";
    
    cout<<"End."<<"\n";
    return 0;
}