#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <ctime>
#include <string>

#include "SubstringAlgorithms.h"

using namespace std;

void Substring_Boyer_Moore(char* Array, int Length)
{
    
    string PatternString;
    int CountOccurances = 0;
    clock_t t;
    while (1)    {
            cout<<"Enter a pattern to find: ";
            cin>>PatternString;
            if (PatternString.length()>Length || PatternString.length()<1)
                cout<<"Error: Substring search: Pattern is bigger than string or equal to 0!\n";
            else
                break;    
        }
    t = clock();
    int PatternLength = PatternString.length();
    int* Badchar = new int[Length];
    
    Tool_Badchar(PatternString,PatternLength,Badchar);
    int s = 0;
    vector<int> Points;

    while (s <= (Length - PatternLength))
	{
		int j = PatternLength - 1;
		while (j >= 0 && PatternString[j] == Array[s + j])
			--j;
		if (j < 0)
		{
			Points.push_back(s);
            cout<<"Detected at: "<<s<<" ["<<s<<".."<<s+PatternLength-1<<"]"<<endl;
            CountOccurances++;
			s += (s + PatternLength < Length) ? PatternLength - Badchar[Array[s + PatternLength]] : 1;
		}
		else
		{
			s += Tool_Max(1, j - Badchar[Array[s + j]]);
		}
	}
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    delete[] Badchar;
    
    ofstream file;
    file.open("boyermooreinfo.txt",ios::app);
    file<<Array<<endl;
    for (int i = 0; i < Points.size(); i++)
        {   
            file<<Points[i]<<endl;
        }
    file<<"Total cases: "<<CountOccurances<<endl;
    file<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    file.close();
}

void Tool_Badchar(string Array, int PatternLength, int* Badchar)
{
    int i;
    for (i = 0; i < 100000; i++)
		Badchar[i] = -1;
	for (i = 0; i < PatternLength; i++)
		Badchar[(int)Array[i]] = i;
}

int Tool_Max(int a, int b)
{
    return a >= b ? a : b;
}