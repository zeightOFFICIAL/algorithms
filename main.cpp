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
ver 0.1
*/

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cmath>

#include "methods/bubblesort.h"
#include "methods/heapsort.h"
#include "methods/stoogesort.h"

using namespace std;

const int ExtremeLength = 75000; 

int main() {
    int AmountOfElements = 5;
    int MaxElement = 10000;
    int MinElement = -10000;
    int ArrayX[ExtremeLength]; 
    srand((int)time(0));
    
    cout<<"Input amount of elements in the array: ";
    cin>>AmountOfElements;
    cout<<"\nInput the maximum possible element in the array: ";
    cin>>MaxElement;
    cout<<"Input the minimum possible element in the array: ";
    cin>>MinElement;

    ifstream file;
    for (int i = 0; i < AmountOfElements; i++)
        {   ArrayX[i]=rand()%(MaxElement-MinElement+1)+MinElement;
            ofstream file;
            file.open("exodus/presort.txt",ios::app);
            file<<ArrayX[i]<<endl;
        }
    file.close();
}