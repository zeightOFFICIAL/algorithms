#pragma once
#include <string>
#include <vector>

/*
    (string A, string B, int C) -> (vector<unsigned long> D)
    Takes text string A, the pattern B, as
    arguments. C is an amount of unique symbols in A.
    Finds pattern B in the text A, using 
    Rabin-Karp algorithm. 
    Returns vector<unsigned long> D which 
    stores every point of occurance of the pattern 
    in text.
    >>NaiveSearch(text, pattern, alphabet)
*/
std::vector<unsigned long> RabinKarp(std::string text, std::string pattern_string, int alphabet = 64);