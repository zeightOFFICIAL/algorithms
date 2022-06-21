#pragma once
#include <string>
#include <vector>

/*
    (string A, string B) -> (vector<ulong> C)
    Takes an A arary of chars (string), the pattern B,
    std::string and the length C of the array A as
    the arguments. Finds pattern std::string B in the
    text char* A with length of C, using Bitap
    algorithm. Returns vector<ulong> D which 
    stores every point of occurance of the pattern 
    in text.
    >>NaiveSearch(text, pattern, length)
*/
std::vector<unsigned long> Bitap(std::string text, std::string pattern_string);