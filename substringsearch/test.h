#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

#include "auxiliary.h"
#include "boyer_moore.h"
#include "naive.h"
#include "rabin_karp.h"
#include "bitap.h"

void fulltest(int tries)
{
    char* array;
    std::vector<unsigned long> occurrences;
    unsigned long length;
    std::cin>>length;
    long double alltime = 0, alltime2 = 0, alltime3 = 0, alltime4 = 0, alltime5 = 0; //time summers  
    std::chrono::steady_clock::time_point start, end, start2, end2, start3, end3, start4, end4, start5, end5; //time stamps
    int local_tries;
    for(local_tries = 0; local_tries <= tries; local_tries++)
        {
            array = GenerateRandomString(length,1);
            
            start = std::chrono::steady_clock::now();
            occurrences = BoyerMoore(array, "ab" , length);
            end = std::chrono::steady_clock::now();
            alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;
            if (local_tries==tries)
                std::cout << "BoyerMoore found: " << occurrences.size() << "\n";
            
            start2 = std::chrono::steady_clock::now();
            occurrences = RabinKarp(array, "ab" , length);
            end2 = std::chrono::steady_clock::now();
            alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
            if (local_tries==tries)
                std::cout << "RabinKarp found: " << occurrences.size() << "\n";
            
            start3 = std::chrono::steady_clock::now();
            occurrences = NaiveSearch(array, "ab" , length);
            end3 = std::chrono::steady_clock::now();
            alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
            if (local_tries==tries)
                std::cout << "Naive found: " << occurrences.size() << "\n";
            
            start4 = std::chrono::steady_clock::now();
            occurrences = Bitap(array, "ab" , length);
            end4 = std::chrono::steady_clock::now();
            alltime4 = alltime4 + std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() / 1000000.0;
            if (local_tries==tries)
                std::cout << "Bitap found: " << occurrences.size() << "\n";
        }
    std::cout << "Boyer-Moore: Average time: " << std::setprecision(9) <<  (alltime / tries) << " seconds" << "\n";
    std::cout << "Rabin-Karp: Average time: " << std::setprecision(9) << (alltime2 / tries) << " seconds" << "\n";
    std::cout << "Naive: Average time: " << std::setprecision(9) << (alltime3 / tries) << " seconds" << "\n";
    std::cout << "Bitap: Average time: " << std::setprecision(9) << (alltime4 / tries) << " seconds" << "\n";
    std::cout << "Total elements: " << length << "\n";
    std::cout << "Total tries: " << tries << "\n";
}