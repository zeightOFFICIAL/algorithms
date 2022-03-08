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
/*
    (char* A, int B) -> ()
    Finds all the occurances of pattern in the main
    string A, length of B. It uses Boyer-Moore 
    algorithm to quickly detect all of the
    coincedences.
    Returns nothing.
    >>Substring_Boyer_Moore(Array,100)
    >>Enter a pattern to find: 12
    <<Detected at: 34 [34..35]
    <<Detected at: 90 [90..91]
    <<Time: 0.0001 seconds
*/
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
    
    Tool_Badchar(PatternString,PatternLength,Badchar,Length);
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

    Tool_ClearTxt();
    ofstream file;
    file.open("allinfo.txt",ios::app);
    file<<"String: \n"<<Array<<endl;
    for (int i = 0; i < Points.size(); i++)
        {   
            file<<"Detected at: "<<Points[i]<<" ["<<Points[i]<<".."<<Points[i]+PatternLength-1<<"]"<<endl;
        }
    file<<"Total cases: "<<CountOccurances<<endl;
    file<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    file.close();
}

void Substring_Rabin_Karp(char* Array, int Length, int Mode)
{
/*
    (char* A, int B, int C) -> ()
    Finds all the occurances of pattern in the main
    string A, length of B. It uses Rabin Karp
    algorithm to quickly detect all of the
    coincedences. Var C stands for the mode of
    the alphabet, ultimately deciding its power.
    >>Substring_Rabin_Karp(Array,100,7)
    >>Enter a pattern to find: 12
    <<Detected at: 34 [34..35]
    <<Detected at: 90 [90..91]
    <<Time: 0.0001 seconds
*/
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

    int d = 7;
    int q = 7;
    if (Mode==1 || Mode==2)
        {d = 36;q = 5;}
    else if (Mode==3)
        {d = 62;q = 5;}
    else if (Mode==4)
        {d = 7;q = 7;}
    
    t = clock();
    vector<int> Points;
    int PatternLength = PatternString.length();

    int i,j;
    int hashP, hashS;
    int h = 1;
    
    for (i = 0; i < PatternLength - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < PatternLength; i++)
    {   hashP = (d * hashP + PatternString[i]) % q;
        hashS = (d * hashS + Array[i]) % q;    }
    for (i = 0; i <= Length - PatternLength; i++)
    {
        if ( hashP == hashS )
        {  
            bool flag = true;
            for (j = 0; j < PatternLength; j++)
            {
                if (Array[i+j] != PatternString[j])
                {
                  flag = false;
                  break;
                }
            }
            if (j == PatternLength)
            {
                cout<<"Detected at: "<<i<<" ["<<i<<".."<<i+PatternLength-1<<"]"<<endl;
                Points.push_back(i);
                CountOccurances++;
            }
        }
        if ( i < Length-PatternLength )
        {
            hashS = (d*(hashS - Array[i]*h) + Array[i+PatternLength])%q;
            if (hashS < 0)
            hashS = (hashS + q);
        }
    }
    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    Tool_ClearTxt();
    ofstream file;
    file.open("allinfo.txt",ios::app);
    file<<"String: \n"<<Array<<endl;
    
    for (int i = 0; i < Points.size(); i++)
        {   
            file<<"Detected at: "<<Points[i]<<" ["<<Points[i]<<".."<<Points[i]+PatternLength-1<<"]"<<endl;
        }
    file<<"Total cases: "<<CountOccurances<<endl;
    file<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    file.close();            
}

void Substring_Naive(char* Array, int Length)
{
/*
    (char* A, int B) -> ()
    Finds all the occurances of pattern in the main
    string A, length of B. It uses naive algorithm.
    Returns nothing.
    >>Substring_Naive(Array,1000)
    >>Enter a pattern to find: AB
    >>Detected at: 506 [506..507]
    >>Detected at: 997 [997..998]
    >>Time: 0.00015 seconds
*/
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
    vector<int> Points;

    for (int i = 0; i <= Length - PatternLength; i++) {
        int j;
        for (j = 0; j < PatternLength; j++)
            if (Array[i + j] != PatternString[j])
                break;
        if (j == PatternLength)
            {
                cout<<"Detected at: "<<i<<" ["<<i<<".."<<i+PatternLength-1<<"]"<<endl;
                Points.push_back(i);
                CountOccurances++;
            }
    }

    t = clock()-t;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    
    Tool_ClearTxt();
    ofstream file;
    file.open("allinfo.txt",ios::app);
    file<<"String: \n"<<Array<<endl;
    
    for (int i = 0; i < Points.size(); i++)
        {   
            file<<"Detected at: "<<Points[i]<<" ["<<Points[i]<<".."<<Points[i]+PatternLength-1<<"]"<<endl;
        }
    file<<"Total cases: "<<CountOccurances<<endl;
    file<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    file.close();            
}

void Tool_Badchar(string Array, int PatternLength, int* Badchar, int Length)
{
/*
    (string A, int B, int* C, int D) -> ()
    So, for Boyer-Moore algorithm's correct work. Firstly,
    we need to create a badchar table. Table which indicates
    how big is the shifts, what algorithm makes to find next
    possible, or actual occurance.
    Text:    THIS IS A TEST
    Pattern: TEST
    Each letter in pattern has its own index.
    Value=max(1,length of pattern - index of character - 1)
    So in this case it looks like it: 
    T E S * (not T cuz it's repeating)
    1 2 1 4 (* is equal to length of the pattern)
    Returns nothing.
    >>Tool_Badchar(String,PatternLength,Badchar,Length)
    <<
*/
    int i;
    for (i = 0; i < Length; i++)
		Badchar[i] = -1;
	for (i = 0; i < PatternLength; i++)
		Badchar[(int)Array[i]] = i;
}

int Tool_Max(int a, int b)
/*
    (int A, int B) -> (int C)
    Compares A and B, returns the biggest of two.
    >>Tool_Max(10,15)
    <<15
*/
{
    return a >= b ? a : b;
}

void Tool_ClearTxt()
/*
    ()->()
    Clears the used txt
    Returns nothing.
    >>Tool_ClearTxt()
*/
{
    ofstream file;
    file.open("allinfo.txt");
    file<<"";
    file.close();
}