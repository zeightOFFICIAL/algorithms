/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V, Kuksin A.A
Lab 1
Sorting algorithms, comparison (time and difficulty)  
- Bubble sort
- Heap sort
- Insertion sort
main.cpp
28.02.2022
ver 1.0
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <ctime>
#include "SortingAlgorithms.h"

using namespace std;
const int ExtremeLength = 1000000; 

void GenerateArray_TrulyRandom(int *ArrayX, int AmountOfElements, int MaxValue, int MinValue)
{
/*
    (int* A, int B, int C, int D)->()
    Generates array A, with length B, using true random numbers,
    with seed equal to the current time and values within range of (C..D)
    After that write the result into the text file. (exodus/presort.txt)
    Returns nothing.
    >>GenerateArray_TrulyRandom(Array, AmountOfElements, MaxValue, MinValue)
    <<Array with random numbers generated, result in presort.txt
*/      
    srand((int)time(0));
    Tool_ClearTxt();    
    ofstream File;
    File.open("exodus/presort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
    {   
        ArrayX[i]=rand()%(MaxValue-MinValue+1)+MinValue;
        File<<ArrayX[i]<<endl;
    }
    File.close();
    cout<<"Array with random numbers generated, results in presort.txt\n";
}

void GenerateArray_CustomNumbers(int *ArrayX, int AmountOfElements)
{   
/*
    (int* A, int B)->(int[])->()
    Generates array A, with length B, using custom numbers.
    After that writes the result into the txt file. (exodus/presort.txt)
    Returns nothing.
    >>GenerateArray_TrulyRandom(Array, AmountOfElements)
    >>Input element with index 0: 6
    >>Input element with index 1: 10
    <<All the numbers has been successfully append in the array, result in presort.txt
*/    
    int ThisNumber = 0;
    
    Tool_ClearTxt(); 
    ofstream File;
    File.open("exodus/presort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            cout<<"Input element with index "<<i<<": ";
            cin>>ThisNumber;
            ArrayX[i]=ThisNumber;
            File<<ArrayX[i]<<endl;
        }
    File.close();
    cout<<"All the numbers has been successfully append in the array, \nresults in presort.txt\n";
}

//=======================================================================

int main() {
    int ArrayX[ExtremeLength], AmountOfElements;
    int ArrayY[ExtremeLength];
    cout<<"Start."<<"\n=========================================================\n";
   
    GenerateArray_TrulyRandom(ArrayX,100000,10000,-10000);
    //GenerateArray_CustomNumbers(ArrayX,10);
    
    //SortArray_BubbleSort(ArrayY);
    //SortArray_HeapSort(ArrayY);
    //SortArray_InsertionSort(ArrayY);
    
    cout<<"End."<<"\n=========================================================";
}