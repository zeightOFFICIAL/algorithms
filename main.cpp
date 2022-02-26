/* 
IKPI-04
Saganenko A.V, Kuksin A.A
Lab 1
Sorting algorithms, comparison (time and difficulty)  
- Bubble sort
- Heap sort
- Stooge sort
main.cpp
26.02.2022
ver 0.3
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include "SortingAlgorithms.h"

using namespace std;
const int ExtremeLength = 1000000; 

void GenerateArray_TrulyRandom(int *ArrayX)
{
/*
    (int* A, int B)->()
    Generates array A, with length B, using true random numbers,
    with seed equal to the current time and values within range of (MIN..MAX)
    After that write the result into the text file. (exodus/presort.txt)
    Returns nothing.
    >>GenerateArray_TrulyRandom(Array)
    >>Input amount of elements in the array: 10
    <<Array with random numbers generated, results in presort.txt
*/      
    int MaxValue = 10000;
    int MinValue = -10000;
    int AmountOfElements = 5;
    srand((int)time(0));

    cout<<"Input amount of elements in the array: ";
    cin>>AmountOfElements;
    cout<<"Input the maximum possible value of the element: ";
    cin>>MaxValue;
    cout<<"Input the minimum possible value of the element: ";
    cin>>MinValue;

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

void GenerateArray_CustomNumbers(int *ArrayX)
{   
/*
    (int* A, int B)->(int[])->()
    Generates array A, with length B, using custom numbers.
    After that writes the result into the txt file. (exodus/presort.txt)
    Returns nothing.
    >>GenerateArray_TrulyRandom(Array)
    >>Input amount of elements in the array: 10
    >>Input element with index 0: 6
    >>Input element with index 1: 10
    <<All the numbers has been successfully append in the array, results in presort.txt
*/    
    int ThisNumber = 0;
    int AmountOfElements = 5;

    cout<<"Input amount of elements in the array: ";
    cin>>AmountOfElements;

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

void GenerateArray_FromFile(int *ArrayX)
{
/*
    (int* A)->(int[])->()
    Generates array A, taking all the values out of the txt file, located
    (exodus/presort.txt). Array will be exactly the same as values in txt
    Returns nothing.
    >>GenerateArray_FromFile(Array)
    <<Previously generated array stored in presort.txt has been transfered to program array.
*/  
    int CountAmount = 0;
    
    string ThisLine;
    int ThisNumber;

    ifstream File("exodus/presort.txt"); 
    while (getline(File, ThisLine))
    {
        ThisNumber=stoi(ThisLine);
        ArrayX[CountAmount]=ThisNumber;
        CountAmount++;
    }
    cout<<"Previously generated array stored in presort.txt has been\n transferred to program array.\n";
}

//=======================================================================

int main() {
    int ArrayX[ExtremeLength];
    int ArraySort1[ExtremeLength];
    int ArraySort2[ExtremeLength];
    int ArraySort3[ExtremeLength];
    cout<<"Start."<<"\n=========================================================\n";

    GenerateArray_TrulyRandom(ArrayX);
    //GenerateArray_FromFile(ArrayX);
    //GenerateArray_CustomNumbers(ArrayX);
    
    //SortArray_BubbleSort(ArraySort1);
    //SortArray_HeapSort(ArraySort2);
    SortArray_StoogeSort(ArraySort3,0,ExtremeLength);
    cout<<"End."<<"\n=========================================================";
}