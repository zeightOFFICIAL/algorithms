#include <string>
#include <vector>

/*
    (ulong &A) -> (char* B)
    Allows user to input his custom string,
    adjusting the length B of the array,
    using external variable.
    Returns created array B.
    >>GenerateCustomString(length)
    <<String:
    >>012345678
*/
char* GenerateCustomString(unsigned long &length);

/*
    (ulong A, int B) -> (char* C)
    Generates string with length of A. The string
    is random generated from alphabet decided by mode B.
    Returns created array C.
    >>GenerateRandomString(10,2)
*/
char* GenerateRandomString(unsigned long length, char alphabet_type);

/*
    (string A, ulong &B) -> (char* C)
    Generates string with length of B. The string
    is take from the txt file. The path of the file
    is equal to A. Returns created array C.
    >>GenerateArrayFile("hello.txt",length)
*/
char* GenerateArrayFile(std::string filename, unsigned long &length);

/*
    (char* A, ulong B) -> ()
    (vector<unsigned long> A) -> ()
    Prints the entire array A with length of B
    in the console.
    >>PrintArray(array, length)
    <<Hello world!
*/
void PrintArray(char* array, unsigned long length);
void PrintArray(std::vector<unsigned long> array);

/**
    (string A, vector<unsigned long> B) -> ()
    (string A, char* B, ulong C) -> ()
    Writes all the text of array B with 
    length of C into the file (string A)
    Returns nothing.
    >>WriteArray(string, length)
*/
void WriteArray(std::string filename, std::vector<unsigned long> array);
void WriteArray(std::string filename, char* array, unsigned long length);

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
std::vector<unsigned long> EveloperWithCustomText(char* text,unsigned long length,std::vector<unsigned long>(*func)(char*,std::string,unsigned long));