#pragma once
#include <string>
#include <vector>

/*
    (string A, string B) -> (vector<unsigned long> C)
    Takes text string A, pattern string B as arguments.
    Finds pattern B in A, using Naive algorithm. 
    Returns vector<unsigned long> C which stores
    every point of occurance of the pattern 
    in text.
    >>NaiveSearch(text, pattern, length)
*/
std::vector<unsigned long> NaiveSearch(std::string text, std::string pattern_string);