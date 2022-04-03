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
main.cpp
03.04.2022
ver 1.1850
*/

#include <iostream>
#include <vector>

#include "substringsearch/auxiliary.h"

#include "substringsearch/boyer_moore.h"
#include "substringsearch/naive.h"
#include "substringsearch/rabin_karp.h"
#include "substringsearch/bitap.h"

int main() {
    char* array;
    std::vector<unsigned long> occurrences;
    clock_t t;
    
    std::cout<<"Start."<<"\n";
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
    std::cout<<"Average time: "<<alltime/tries<<" seconds"<<"\n";
    std::cout<<"Average time: "<<alltime2/tries<<" seconds"<<"\n";
    std::cout<<"Average time: "<<alltime3/tries<<" seconds"<<"\n";
    std::cout<<"Average time: "<<alltime4/tries<<" seconds"<<"\n";
    */
    //.....................................................................................
    //.....................................................................................
    /*
    unsigned long length;
    int tries;
    long double alltime = 0;
    array = GenerateArrayFile("test.txt",length);
    for(tries = 0; tries < 100; tries++)
        {
            t = clock();
            occurrences = Bitap(array,"His rifle was leaning against the rock beside him. He picked it up, flicked off the safety catch, and then put it down again, a little closer to hand. ", length);
            t = clock()-t;
            alltime = alltime + ((float)t)/CLOCKS_PER_SEC;
        }
    std::cout<<"Average time: "<<alltime/tries<<" seconds"<<"\n";
    std::cout<<occurrences.size()<<"\n";
    std::cout<<length<<"\n";
    */
    //.....................................................................................
    
    
    //...............................................
    std::cout<<"End."<<"\n";   
    
    return 0;
}