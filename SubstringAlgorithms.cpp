#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <ctime>
#include <string>

#include "SubstringAlgorithms.h"

using namespace std;
#define NO_OF_CHARS 7

void Substring_Boyer_Moore(char* Array, int Length)
{
    
    string PatternString;
    int* OccurancesIndex[PatternString.length()];
    int CountOccurances;
    while (1)    {
            cout<<"Enter a pattern to find: ";
            cin>>PatternString;
            if (PatternString.length()>Length || PatternString.length()<1)
                cout<<"Error: Substring search: Pattern is bigger than string or equal to 0!\n";
            else
                break;    
        }
    
    int PatternLength = PatternString.length();
    int Badchar[NO_OF_CHARS];
    int s = 0;
    Tool_BadCharHeuristic(Array,Length,Badchar);
    while(s<=(Length-PatternLength))
        {
            int j = PatternLength-1;
            while(j >= 0 && PatternString[j]==Array[s+j])
                j--;
            if (j<0)
            {
                cout<<"Pattern occurs at shift: "<<s<<endl;
                s += (s+PatternLength<Length) ? PatternLength-Badchar[Array[s+PatternLength]] : 1;
            }
            else
                s += max(1,j-Badchar[Array[s+j]]);
        }
}

void Tool_BadCharHeuristic(char* Array, int Length, int* Badchar)
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        Badchar[i] = -1;
    for (i = 0; i < Length; i++)
        Badchar[(int) Array[i]] = i;
}