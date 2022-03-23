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
23.03.2022
ver 1.16
*/

#include <iostream>
#include <random>
#include <cstring>
#include <fstream>

#include "substringalgorithms.h"

using std::cin, std::cout, std::string, std::ofstream, std::ifstream, std::ios;
const unsigned long int EXTREME_LENGTH = 10000000; 

/**
    (int &A) -> (char* B)
    Allows user to input his custom string,
    adjusting the length B of the array,
    using external variable.
    Returns created array B.
    >>GenerateCustomString(length)
    <<String:
    >>012345678
*/
char* GenerateCustomString(int &length);

/**
    (int A, int B) -> (char* C)
    Generates string with length of A. The string
    is random generated from alphabet decided by mode B.
    Returns created array C.
    >>GenerateRandomString(10,2)
*/
char* GenerateRandomString(int length, int alphabet_type);

/**
    (string A, int &B) -> (char* C)
    Generates string with length of B. The string
    is take from the txt file. The path of the file
    is equal to A. Returns created array C.
    >>GenerateArrayFile("hello.txt",length)
*/
char* GenerateArrayFile(string path, int &length);

/**
    (char* || int* A, int B) -> ()
    Prints the entire array A with length of B
    in the console.
    >>PrintArray(array, length)
    <<Hello world!
*/
void PrintArray(char* array, int length);
void PrintArray(int* array, int length);

/**
    (char* A, int B) -> ()
    Writes all the text into the file (exodus/text.txt)
    Returns nothing.
    >>WriteArray(string, length)
*/
void WriteArray(char* array, int length);

//============================================================================

char* GenerateCustomString(int &length)
{    
    static char array[EXTREME_LENGTH];
    int local_length = 0;
    
    cout<<"String: ";
    cin.getline(array,EXTREME_LENGTH);
    local_length = strlen(array);
    length = local_length;
    return array;
}

char* GenerateRandomString(int length, int alphabet_type)
{
    static char array[EXTREME_LENGTH];
    string alphabet_set;
    int this_symbol_index = -1;
    
    if (alphabet_type==1)
        alphabet_set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
    else if (alphabet_type==2)
        alphabet_set = "ABC123 ";
    else {
        cout << "Wrong alphabet type. Another will be selected."<<"\n";
        alphabet_set = "ABC123 ";
        }
    int set_length = alphabet_set.length();
    
    srand((int)time(0));
    for (auto i = 0; i < length; i++)    {
            this_symbol_index = rand()%set_length;
            array[i]=alphabet_set[this_symbol_index];
        }
    return array;
}

char* GenerateArrayFile(string path, int &length)
{
    static char array[EXTREME_LENGTH];
    int i = 0;
    ifstream file;
    file.open(path);
	if (!file)
		cout << "No such file.";
	else  {
        char ch;
        while (file >> std::noskipws >> ch) {
            array[i]=ch;
            i++;
        }
	}
    file.close();
    length = i;
    return array;
}

void PrintArray(char* array, int length)
{
    for (int i = 0; i < length; i++)
        cout<<array[i];
    cout<<"\n";
}
void PrintArray(int* array, int length)
{
    for (auto i = 0; i < length; i++) {
        cout<<array[i]<<"\n";
        if (i >= 0 && array[i+1] == 0)
            break;
        }
}

void WriteArray(char* array, int length)
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

    array = GenerateRandomString(length,1);
    //array = GenerateCustomString(length);
    //array = GenerateArrayFile("test.txt",length);

    //WriteArray(array,length);
    //PrintArray(array,length);
    
    structure = BoyerMoore(array,"XY",length);
    structure = RabinKarp(array,"XY",length);
    structure = NaiveSubstring(array,"XY",length);
    //structure = EveloperWithCustomText(array,length,BoyerMoore);

    //PrintArray(structure.occurances_points,structure.count_occurances);
    
    cout<<"End."<<"\n";    
    return 0;
}