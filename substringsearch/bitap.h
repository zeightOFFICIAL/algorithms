#pragma once
#include <string>
#include <vector>

/*
    (string A, string B) -> (vector<unsigned long> C)
    Takes string A, string pattern B, as
    arguments. Finds pattern B in the
    string A, using Bitap, shift-or algorithm. 
    Returns vector<unsigned long> C which 
    stores every point of occurance of the pattern 
    in text.
    >>NaiveSearch(text, pattern)
*/
std::vector<unsigned long> Bitap(std::string text, std::string pattern_string);