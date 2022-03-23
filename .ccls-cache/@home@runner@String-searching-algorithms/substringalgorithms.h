#include <string>

/**
    struct (int* A, int B)
    Structure which stores the return result
    of the substring-search algorithms. Meaning
    total amount of occurances plus the actual points.
*/
struct Occurances  {
    int* occurances_points;
    int count_occurances; 
};

/**
    (char* A, char* B, int C) -> (int* D, int E)
    Takes an A array of chars (string), the pattern B
    (string) and the length C of array A 
    as the arguments. Finds pattern string B in the 
    text char* A with length of B, using 
    Boyer-Moore algorithm. Returns the int* D, 
    meaning array of each occurance of B in A
    and amount of occurances. In struct.
    >>BoyerMoore(array, pattern ,length)
*/
Occurances BoyerMoore(char* text, std::string pattern_string, int length);

/**
    (char* A, char* B, int C) -> (int* D, int E)
    Takes an A array of chars (string), the pattern B
    (string) and the length C of array A 
    as the arguments. Finds pattern string B in the 
    text char* A with length of B, using 
    Rabin-Karp algorithm. Returns the int* D, 
    meaning array of each occurance of B in A
    and amount of occurances. In struct.
    >>RabinKarp(array, pattern ,length)
*/
Occurances RabinKarp(char* text, std::string pattern_string, int length);

/**
    (char* A, char* B, int C) -> (int* D, int E)
    Takes an A array of chars (string), the pattern B
    (string) and the length C of array A 
    as the arguments. Finds pattern string B in the 
    text char* A with length of B, using 
    Naive algorithm. Returns the int* D, 
    meaning array of each occurance of B in A
    and amount of occurances. In struct.
    >>NaiveSubstring(array, pattern ,length)
*/
Occurances NaiveSubstring(char* text, std::string pattern_string, int length);

//=================================================================

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
Occurances EveloperWithCustomText(char* text,int length,Occurances(*func)(char*,std::string,int));

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

/**
    (struct A, int B, string C) -> ()
    Prints all the occurances A.occurances_points
    with amount of A.count_occurances in the
    file (exodus/{C}.txt). Returns nothing.
    >>WriteOccurances(a,pattern length, name of file)
*/
void WriteOccurances(Occurances a, int pattern_length, std::string name);