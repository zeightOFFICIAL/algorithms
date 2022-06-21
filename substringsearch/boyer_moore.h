#pragma once
#include <string>
#include <vector>

/*
    (string A, string B) -> (vector<unsigned long> D)
    Takes string A - text, string B - pattern, as
    the arguments. Finds pattern B in the
    text A, using Boyer-Moore algorithm with 
    heuristics of bad chars
    Returns vector<unsigned long> D which stores every 
    point of occurance of the pattern in text.
    >>BoyerMoore(text, pattern)
*/
std::vector<unsigned long> BoyerMoore(std::string text, std::string pattern_string);

/*
    (string A, unsigned long B, int* C, unsigned long D) -> ()
    So, for Boyer-Moore algorithm's correct work. Firstly, as
    one of two possible heuristics we need to create a badchar 
    table. The table which indicates last occurrence of letter
    from alphabet in A within range of (0...length of B - 1) 
    The remained alphabet symbols are set to -1
    Returns nothing. Changes C.
    >>BadCharHeuristics(pattern, pattern length, heuristics table, length)
*/
void BadCharHeuristics(std::string array, unsigned long pattern_length, int* heuristics_table, unsigned long length);

/*
    (int64 A, int64 B) -> (int64 C)
    Returns C biggest of values A and B
    >>MaxByValue(5,6);
    <<6
*/
long long MaxByValue(long long a, long long b);