/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 2
String-searching algorithms
 - Boyer–Moore
 - Rabin-Karp
 - Naive
main.cpp
18.03.2022
ver 1.13
*/

#include <iostream>
#include <random>
#include <cstring>
#include <fstream>

#include "substringalgorithms.h"

using std::cin, std::cout, std::string, std::ofstream, std::ios;
const int EXTREME_LENGTH = 1000000; 

/**
    (&int A) -> (char* B)
    Allows user to input his custom string,
    adjusting the length B of the array,
    using external variable.
    Returns created array B.
    >>GenerateArray_CustomText(length)
    <<String:
    >>012345678
*/
char* generate_custom_string(int &length);

/*
    (int A, int B) -> (char* C)
    Generates string with length of A. The string
    is random generated from alphabet decided by mode B.
    Returns created array C.
    >>GenerateArray_RandomString(10,2)
*/
char* generate_random_string(int length, int alphabet_type);

/**
    (char* || int* A, int B) -> ()
    Prints the entire array A with length of B
    in the console.
    >>print_array(array, length)
    <<Hello world!
*/
void print_array(char* array, int length);
void print_array(int* array, int length);

/**
    (char* A, int B) -> ()
    Writes all the text into the file (exodus/text.txt)
    Returns nothing.
    >>write_array(string, length)
*/
void write_array(char* array, int length);

//============================================================================

char* generate_custom_string(int &length)
{    
    static char array[EXTREME_LENGTH];
    int local_length = 0;
    
    cout<<"String: ";
    cin.getline(array,EXTREME_LENGTH);
    local_length = strlen(array);
    length = local_length;
    return array;
}

char* generate_random_string(int length, int alphabet_type)
{
    static char array[EXTREME_LENGTH];
    string alphabet_set;   
    if (alphabet_type==1)
        alphabet_set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
    else if (alphabet_type==2)
        alphabet_set = "ABC123 ";
    int set_length = alphabet_set.length();
    int this_symbol_index = -1;
    srand((int)time(0));
    
    for (auto i = 0; i < length; i++)    {
            this_symbol_index = rand()%set_length;
            array[i]=alphabet_set[this_symbol_index];
        }
    return array;
}

void print_array(char* array, int length)
{
    for (int i = 0; i < length; i++)
        cout<<array[i];
    cout<<"\n";
}
void print_array(int* array, int length)
{
    for (auto i = 0; i < length; i++) {
        cout<<array[i]<<"\n";
        if (i >= 0 && array[i+1] == 0)
            break;
        }
}

void write_array(char* array, int length)
{
    ofstream file;
    file.open("exodus/text.txt",ios::trunc);
    for (int i = 0; i < length; i++)
        file<<array[i];
    file.close();
}
//===================================================================

int main() {
    char* array;
    Occurances structure;
    int length = 1500;
    
    cout<<"Start."<<"\n";

    array = generate_random_string(length,1);
    //array = generate_custom_string(length);

    write_array(array,length);
    //print_array(array,length);
    
    structure = boyer_moore(array,"AB",length);
    structure = rabin_karp(array,"AB",length);
    structure = naive_substring(array,"AB",length);
    //structure = enveloper_with_custom_text(array,length,boyer_moore);

    //print_array(structure.occurances_points,structure.count_occurances);
    
    cout<<"End."<<"\n";    
}