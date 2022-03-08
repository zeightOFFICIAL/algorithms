/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V, Kuksin A.A
Lab 2
String-searching algorithms, comparison (time and difficulty)  
 - Boyer–Moore
 - Rabin-Karp
 - Naive
main.cpp
08.03.2022
ver 1.1
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <ctime>
#include <cstring>
#include "SubstringAlgorithms.h"

using namespace std;
const int ExtremeLength = 1000000; 

void GenerateArray_CustomText(char *Array, int &Length)
{
/*
    (char* A, int B) -> ()
    Allows user to input his custom string A with the
    length of B.
    Returns nothing.
    >>GenerateArray_CustomText(Array,10);
    >>String:
    <<0123456789
    <<The string has been successfully created.
*/
    cout<<"String: ";
    cin.getline(Array,ExtremeLength);
    Length = strlen(Array);
    cout<<"The string has been successfully created."<<endl;
}

void GenerateArray_RandomString(char *Array, int Length, int Mode)
{
/*
    (char* A, int B, int C) -> ()
    Generates string A with length of B. The string
    is random generated from alphabet decided by mode C.
    Returns nothing.
    >>GenerateArray_RandomString(Array,10,2)
    <<The string has been successfully generated.
*/
    string Set;   
    if (Mode==1)
        Set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    else if (Mode==2)
        Set = "abcdefghijklmnopqrstuvwxyz0123456789";
    else if (Mode==3)
        Set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    else if (Mode==4)
        Set = "ABC123 ";
    
    int SetLength = Set.length();
    int ThisSymbolIndex = -1;
    srand((int)time(0));
    for (int i = 0; i < Length; i++)    {
            ThisSymbolIndex = rand()%SetLength;
            Array[i]=Set[ThisSymbolIndex];
        }
    cout<<"The string has been successfully generated."<<endl;
}

//===================================================================

int main() {
    char ArrayX[ExtremeLength];
    int Length;
    cout<<"Start."<<"\n=========================================================\n";
    
    GenerateArray_RandomString(ArrayX,1000,4);
    //GenerateArray_CustomText(ArrayX,Length);
    
    //Substring_Boyer_Moore(ArrayX,50000);
    //Substring_Rabin_Karp(ArrayX,Length,4);
    Substring_Naive(ArrayX,1000);
    
    cout<<"End."<<"\n=========================================================\n";    
}