#include <string>
#include <vector>

/*
    (char* A, string B, ulong C) -> (vector<ulong> D)
    Takes an A arary of chars (string), the pattern B,
    std::string and the length C of the array A as
    the arguments. Finds pattern std::string B in the
    text char* A with length ob C, using Boyer-Moore
    algorithm with heuristic of bad char. Returns
    vector<ulong> D which stores every point of 
    occurance of the pattern in text.
    >>BoyerMoore(text, pattern , length)
*/
std::vector<unsigned long> BoyerMoore(char* text, std::string pattern_string, unsigned long length);

/*
    (string A, int B, int* C, ulong D) -> ()
    So, for Boyer-Moore algorithm's correct work. Firstly, as
    one of two possible heuristics we need to create a badchar 
    table. Table which indicates how big is the shifts, 
    what algorithm makes to find next possible, or actual occurance.
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
*/
void ToolBadcharHeuristics(std::string array, int pattern_length, int* bad_char, unsigned long  length);

/*
    (int A, int B) -> (int C)
    Returns C biggest of values A and B
    >>ToolMaxByValue(5,6);
    <<6
*/
int ToolMaxByValue(int a, int b);