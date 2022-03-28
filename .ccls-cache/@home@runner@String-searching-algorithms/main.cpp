/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 2
String-searching algorithms
 - Boyer–Moore
 - Rabin-Karp
 - Naive
main.cpp
28.03.2022
ver 1.171
*/

#include <iostream>
#include <vector>

#include "substringsearch/auxiliary.h"
#include "substringsearch/boyer_moore.h"
#include "substringsearch/naive.h"
#include "substringsearch/rabin_karp.h"

using std::cout, std::vector;

int main() {
    char* array;
    unsigned long length = 2000;
    vector<unsigned long> occurances;
    
    cout<<"Start."<<"\n";
    //...............................................
    
    array = GenerateRandomString(length,2);
    //array = GenerateCustomString(length);
    //array = GenerateArrayFile("test.txt",length);

    //PrintArray(array,length);
    //WriteArray("test.txt",array,length);
    //...............................................

    //occurances = BoyerMoore(array,"AB",length);
    //occurances = RabinKarp(array,"AB",length);
    //occurances = NaiveSearch(array,"AB",length);
    
    //occurances = EveloperWithCustomText(array,length,BoyerMoore);

    //PrintArray(occurances);
    //WriteArray("resulttest.txt",occurances);
    
    //...............................................
    cout<<"End."<<"\n";   
    
    return 0;
}