/* 
ИКПИ-04
Саганенко А.В, Куксин А.А
Лабораторная работа 1
Сравнение алгоритмов сортировки
- Сортировка пузырьком
- Пирамидальная сортировка
- Блуждающая сортировка
main.cpp
23.02.2022
ver 0.2
*/

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cmath>

#include "SortingAlgorithms.h"

using namespace std;

const int ExtremeLength = 100000; 

void GenerateArray_TrulyRandom(int AmountOfElements, int *ArrayX)
{
/*
    (int A, int* B)->()
    Generates array B, with length A, using true random numbers,
    with seed equal to current time and withing range of (MIN..MAX)
    After that writes the result into the txt file. (exodus/presort.txt)
    Returns nothing.
    >>GenerateArray_TrulyRandom(5, Array)
    <<
*/  
    
    int MaxElement = 10000;
    int MinElement = -10000;
    srand((int)time(0));
    
    cout<<"Input the maximum possible element in the array: ";
    cin>>MaxElement;
    cout<<"Input the minimum possible element in the array: ";
    cin>>MinElement;
    
    ofstream file;
    file.open("exodus/presort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   ArrayX[i]=rand()%(MaxElement-MinElement+1)+MinElement;
            file<<ArrayX[i]<<endl;
        }
    file.close();
}

void GenerateArray_CustomNumbers(int AmountOfElements, int *ArrayX)
{   
/*
    (int A, int* B)->()
    Generates array B, with length A, using custom numbers.
    After that writes the result into the txt file. (exodus/presort.txt)
    Returns nothing.
    >>GenerateArray_TrulyRandom(2, Array)
    >>Input element with index 0: 6
    >>Input element with index 1: 10
*/    
    int ThisNumber = 0;
    
    ofstream file;
    file.open("exodus/presort.txt",ios::app);
    for (int i = 0; i < AmountOfElements; i++)
        {   
            cout<<"Input element with index "<<i<<": ";
            cin>>ThisNumber;
            ArrayX[i]=ThisNumber;
            file<<ArrayX[i]<<endl;
        }
    file.close();
}

void ClearTxts()
{   
/*
    ()->()
    Clears all the used txts.
    Returns nothing.
    >>ClearTxts()
*/
    ofstream file;
    file.open("exodus/presort.txt");
    file<<"";
    Tool_ClearTxt();
}

int main() {
    int AmountOfElements = 5;
    int ArrayX[ExtremeLength]; 
    srand((int)time(0));
    
    cout<<"Input amount of elements in the array: ";
    cin>>AmountOfElements;

    ClearTxts();
    GenerateArray_TrulyRandom(AmountOfElements,ArrayX);
    SortArray_BubbleSort(AmountOfElements,ArrayX);
}