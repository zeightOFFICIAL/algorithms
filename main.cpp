/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V, Kuksin A.A
Lab 2
String-searching algorithms, comparison (time and difficulty)  
 - Boyer–Moore
 - 
main.cpp
06.03.2022
ver 0.2
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <ctime>
#include <string>
#include "SubstringAlgorithms.h"

using namespace std;
const int ExtremeLength = 1000000; 

void GenerateArray_RandomString(char *Array, int Length, int Mode)
{
/*
    (char* A, int B, int C, int D) -> ()
    Generates string A with length of B. The string
    is random generated from alphabet decided by mode C
    Stores the power of alphabet in D
    Returns nothing.
    >>GenerateArray_RandomString(Array,10,2)
    <<The string has been successfully generated.
      String:
      aaaaaaaaaaaaaaaaaaaaaaaaaa123
*/
    string Set;   
    if (Mode==1)
        Set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    else if (Mode==2)
        Set = "abcdefghijklmnopqrstuvwxyz0123456789";
    else if (Mode==3)
        Set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    else if (Mode==4)
        Set = "0123456789АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя"; 
    else if (Mode==5)
        Set = "ABC123 ";
    
    int SetLength = Set.length();
    int ThisSymbolIndex = -1;
    srand((int)time(0));
    for (int i = 0; i < Length; i++)    {
            ThisSymbolIndex = rand()%SetLength;
            Array[i]=Set[ThisSymbolIndex];
        }
    cout<<"The string has been successfully generated.\nString:\n"<<Array<<"\n";
}

//===================================================================

int main() {
    char ArrayX[ExtremeLength];
    cout<<"Start."<<"\n=========================================================\n";
    
    GenerateArray_RandomString(ArrayX,100000,1);
    Substring_Boyer_Moore(ArrayX,100000);
    
    cout<<"End."<<"\n=========================================================\n";    
}