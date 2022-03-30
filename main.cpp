/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 2
String-searching algorithms
 - Boyer–Moore
 - Rabin-Karp
 - Bitap
 - Naive
main.cpp
30.03.2022
ver 1.18
*/

#include <iostream>
#include <vector>

#include "substringsearch/auxiliary.h"

#include "substringsearch/boyer_moore.h"
#include "substringsearch/naive.h"
#include "substringsearch/rabin_karp.h"
#include "substringsearch/bitap.h"

using std::cout, std::vector;

int main() {
    char* array;
    vector<unsigned long> occurrences;
    clock_t t;
    
    cout<<"Start."<<"\n";
    //...............................................
    
    //array = GenerateRandomString(length,2);
    //array = GenerateCustomString(length);
    //array = GenerateArrayFile("test.txt",length);

    //PrintArray(array,length);
    //WriteArray("test.txt",array,length);
    //...............................................

    //occurances = BoyerMoore(array,"AB",length);
    //occurances = RabinKarp(array,"AB",length);
    //occurances = NaiveSearch(array,"AB",length);
    //occurances = Bitap(array,"AB",length);
    
    //occurances = EveloperWithCustomText(array,length,BoyerMoore);

    //PrintArray(occurances);
    //WriteArray("resulttest.txt",occurances);

    //.....................................................................................
    /*
    unsigned long length;
    std::cin>>length;
    long double alltime, alltime2, alltime3, alltime4 = 0;
    int tries;
    for(tries = 0; tries < 1000; tries++)
        {
            array = GenerateRandomString(length,1);
            
            t = clock();
            occurrences = BoyerMoore(array, "ab" , length);
            t = clock()-t;
            alltime = alltime + ((float)t)/CLOCKS_PER_SEC;
            
            t = clock();
            occurrences = RabinKarp(array, "ab" , length);
            t = clock()-t;
            alltime2 = alltime2 + ((float)t)/CLOCKS_PER_SEC;
            
            t = clock();
            occurrences = NaiveSearch(array, "ab" , length);
            t = clock()-t;
            alltime3 = alltime3 + ((float)t)/CLOCKS_PER_SEC;
            
            t = clock();
            occurrences = Bitap(array, "ab" , length);
            t = clock()-t;
            alltime4 = alltime4 + ((float)t)/CLOCKS_PER_SEC;
        }
    cout<<"Average time: "<<alltime/tries<<" seconds"<<"\n";
    cout<<"Average time: "<<alltime2/tries<<" seconds"<<"\n";
    cout<<"Average time: "<<alltime3/tries<<" seconds"<<"\n";
    cout<<"Average time: "<<alltime4/tries<<" seconds"<<"\n";
    */
    //.....................................................................................
    //.....................................................................................
    
    unsigned long length;
    int tries;
    long double alltime = 0;
    array = GenerateArrayFile("test.txt",length);
    for(tries = 0; tries < 1000; tries++)
        {
            t = clock();
            occurrences = NaiveSearch(array,"The dark man had set his guardposts all along the eastern border of Oregon. The largest was at Ontario, where I-80 crosses over from Idaho; there were six men there, quartered in the trailer of a large Peterbilt truck.",length);
            t = clock()-t;
            alltime = alltime + ((float)t)/CLOCKS_PER_SEC;
        }
    cout<<"Average time: "<<alltime/tries<<" seconds"<<"\n";
    cout<<occurrences.size()<<"\n";
    cout<<length<<"\n";
    //.....................................................................................
    
    
    //...............................................
    cout<<"End."<<"\n";   
    
    return 0;
}