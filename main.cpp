/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 7
Hashing algorithms
- sha1
- sha256
- adler32
- fnv1-32
Clang++ 12 (12.0.1)
main.cpp
15.06.2022
ver 0.85
*/

//for input and output
#include <iostream>
//for time stamps
#include <chrono>
//for setprecision
#include <iomanip>

//hashing algorithms
#include "hashing/sha1.h"
#include "hashing/sha256.h"
#include "hashing/adler32.h"
#include "hashing/fnv132.h"
 
using std::cout;
 
int main()
{
    //testing --------------------------------------------------------------------------------------------------------------
    std::chrono::steady_clock::time_point start, end, start2, end2, start3, end3, start4, end4; //time stamps
    long double alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0; //time summers
    std::string teststring = "hellohellohellohellohellohelload"; //string for test
    //                       "hellohellohellohellohellohhdddd"
    int tries, total_tries; //number of try, total tries 
    std::string result; //result string
    total_tries = 10;

    cout<<"Start."<<"\n";
    for (tries = 0; tries <= total_tries; tries++)  {
        if (tries == total_tries)
            cout << "string: " + teststring << "\n";
        
        start = std::chrono::steady_clock::now();
        result = sha1(teststring);
        end = std::chrono::steady_clock::now();
        alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;
        if (tries == total_tries)
            cout << "sha1: " + result << "\n";
        
        start2 = std::chrono::steady_clock::now();
        result = sha256(teststring);
        end2 = std::chrono::steady_clock::now();
        alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
        if (tries == total_tries)
            cout << "sha256: " + result << "\n";
        
        start3 = std::chrono::steady_clock::now();
        result = adler32(teststring);
        end3 = std::chrono::steady_clock::now();
        alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
        if (tries == total_tries)
            cout << "adler32: " + result << "\n";

        start4 = std::chrono::steady_clock::now();
        result = fnv132(teststring);
        end4 = std::chrono::steady_clock::now();
        alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;
        if (tries == total_tries)
            cout << "fnv132: " + result << "\n";
    }   
    
    std::cout << "sha1: Average time: " << std::setprecision(9) <<  (alltime / tries) << " seconds" << "\n";
    std::cout << "sha256: Average time: " << std::setprecision(9) <<  (alltime2 / tries) << " seconds" << "\n";
    std::cout << "adler32: Average time: " << std::setprecision(9) <<  (alltime3 / tries) << " seconds" << "\n";
    std::cout << "fnv132: Average time: " << std::setprecision(9) <<  (alltime4 / tries) << " seconds" << "\n";
    
    cout<<"End."<<"\n";   
    //testing --------------------------------------------------------------------------------------------------------------
    return 0;
}