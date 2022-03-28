#include <string>
#include <vector>

/**
    (char* A, char* B, int C) -> (int* D, int E)
    Takes an A array of chars (string), the pattern B
    (string) and the length C of array A 
    as the arguments. Finds pattern string B in the 
    text char* A with length of B, using 
    Boyer-Moore algorithm. Returns the int* D, 
    meaning array of each occurance of B in A
    and amount of occurances E. In struct.
    >>BoyerMoore(array, pattern ,length)
*/
std::vector<unsigned long> BoyerMoore(char* text, std::string pattern_string, int length);

/**
    (string A, int B, int* C, int D) -> ()
    So, for Boyer-Moore algorithm's correct work. Firstly,
    we need to create a badchar table. Table which indicates
    how big is the shifts, what algorithm makes to find next
    possible, or actual occurance.
    Text:    THIS IS A TEST
    Pattern: TEST
    Each letter in pattern has its own index.
    Value=max(1,length of pattern - index of character - 1)
    So in this case it looks like it: 
    T E S * (not T cuz it's repeating)
    1 2 1 4 (* is equal to length of the pattern)
    That naturally makes A - a pattern to find. B its length.
    C the actual created array of badchars shifts. And D -
    length of text.
    Returns nothing.
    >>ToolBadcharHeuristics(pattern, pattern length, badchar table, length)
    <<
*/
void ToolBadcharHeuristics(std::string array, int pattern_length, int* bad_char, int length);

/**
    (int A, int B) -> (int C)
    Returns C biggest of values A and B
    >>ToolMaxByValue(5,6);
    <<6
*/
int ToolMaxByValue(int a, int b);