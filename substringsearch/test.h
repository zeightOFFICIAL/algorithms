#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <cstring>
#include <random>
#include <fstream>

#include "boyer_moore.h"
#include "naive.h"
#include "rabin_karp.h"
#include "bitap.h"

const unsigned long int EXTREME_LENGTH = 10000000;
/*
    (char* A, ulong B) -> ()
    (vector<unsigned long> A) -> ()
    Prints the entire array A with length of B
    in the console.
    >>PrintArray(array, length)
    <<Hello world!
*/
void PrintArray(char* array, unsigned long length)
{
    for (unsigned long i = 0; i < length; i++)
        std::cout << array[i];
    std::cout << "\n";
}
void PrintArray(std::vector<unsigned long> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        std::cout << array[i] << "\n";
        if (i >= 0 && array[i + 1] == 0)
            break;
    }
}
/**
    (string A, vector<unsigned long> B) -> ()
    (string A, char* B, ulong C) -> ()
    Writes all the text of array B with
    length of C into the file (string A)
    Returns nothing.
    >>WriteArray(string, length)
*/
void WriteArray(std::string filename, std::vector<unsigned long> array)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
    if (!file)
        std::cout << "No such file.";
    else
        for (int i = 0; i < array.size(); i++)
            file << array[i] << "\n";
    file.close();
}
void WriteArray(std::string filename, char* array, unsigned long length)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
    if (!file)
        std::cout << "No such file.";
    else
        for (int i = 0; i < length; i++)
            file << array[i];
    file.close();
}
/*
    (string A, ulong &B) -> (char* C)
    Generates string with length of B. The string
    is take from the txt file. The path of the file
    is equal to A. Returns created array C.
    >>GenerateArrayFile("hello.txt",length)
*/
char* GenerateArrayFile(std::string filename, unsigned long& length)
{
    static char array[EXTREME_LENGTH];
    unsigned long i = 0;
    std::ifstream file;
    file.open(filename);
    if (!file)
        std::cout << "No such file.";
    else {
        char ch;
        while (file >> std::noskipws >> ch) {
            array[i] = ch;
            i++;
        }
    }
    file.close();
    length = i;
    return array;
}
/*
    (unsigned long A, int B) -> (char* C)
    Generates string with length of A. The string
    is random generated from alphabet decided by mode B.
    Returns created array C.
    >>GenerateRandomString(10,2)
*/
char* GenerateRandomString(unsigned long length, char alphabet_type)
{
    static char array[EXTREME_LENGTH];
    std::string alphabet_set;
    int this_symbol_index = -1;

    if (alphabet_type == 1)
        alphabet_set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
    else if (alphabet_type == 2)
        alphabet_set = "ABC123 ";
    else {
        std::cout << "Wrong alphabet type. Another will be selected." << "\n";
        alphabet_set = "ABC123 ";
    }
    int set_length = alphabet_set.length();

    srand((int)time(0));
    for (auto i = 0; i < length; i++) {
        this_symbol_index = rand() % set_length;
        array[i] = alphabet_set[this_symbol_index];
    }
    return array;
}
/*
    (unsigned long &A) -> (char[]) -> (char* B)
    Allows user to input his custom string,
    adjusting the length B of the array,
    using external variable.
    Returns created array B.
    >>GenerateCustomString(length)
    <<String:
    >>012345678
*/
char* GenerateCustomString(unsigned long& length)
{
    static char array[EXTREME_LENGTH];
    int local_length = 0;

    std::cout << "String: ";
    std::cin.getline(array, EXTREME_LENGTH);
    local_length = strlen(array);
    length = local_length;
    return array;
}
/**
    (char* A, int B, int*(*C)) -> (int* D, int E)
    Envelopes base function C, used with arguments of
    A, B and local string. So that the user can enter
    his own string.
    Returns D, the array returned by int*(*C) base function.
    >>EveloperWithCustomText(text, lenght, boyer-moore)
    >>Enter a pattern:
    >>hello
*/
std::vector<unsigned long> EveloperWithCustomText(char* text, unsigned long length, std::vector<unsigned long>(*func)(char*, std::string, unsigned long))
{
    std::string pattern_string;
    std::cout << "Enter a pattern: ";
    std::cin >> pattern_string;
    return func(text, pattern_string, length);
}

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
            std::string strarray = array;
            
            start = std::chrono::steady_clock::now();
            occurrences = BoyerMoore(strarray, "ab");
            end = std::chrono::steady_clock::now();
            alltime = alltime + std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;
            if (local_tries==tries)
                std::cout << "BoyerMoore found: " << occurrences.size() << "\n";
            
            start2 = std::chrono::steady_clock::now();
            occurrences = RabinKarp(strarray, "ab");
            end2 = std::chrono::steady_clock::now();
            alltime2 = alltime2 + std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() / 1000000.0;
            if (local_tries==tries)
                std::cout << "RabinKarp found: " << occurrences.size() << "\n";
            
            start3 = std::chrono::steady_clock::now();
            occurrences = NaiveSearch(strarray, "ab");
            end3 = std::chrono::steady_clock::now();
            alltime3 = alltime3 + std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() / 1000000.0;
            if (local_tries==tries)
                std::cout << "Naive found: " << occurrences.size() << "\n";
            
            start4 = std::chrono::steady_clock::now();
            occurrences = Bitap(array, "ab");
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