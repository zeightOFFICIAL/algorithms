#include <iostream>
#include <fstream>
#include <ctime>

#include "substringalgorithms.h"

using std::string, std::ios, std::ofstream, std::cin, std::cout;
const int EXTREME_LENGTH = 1000000; 

Occurances boyer_moore(char* text, string pattern_string, int length)
{
    int count_occurances = 0, pattern_length = pattern_string.length(), s = 0;
    clock_t t;
    int* bad_char = new int[length];
    static int occurance_points[EXTREME_LENGTH];
    
    t = clock();
    tool_badchar_heuristics(pattern_string,pattern_length,bad_char,length);
    while (s <= (length - pattern_length))  {
		auto j = pattern_length - 1;
		while (j >= 0 && pattern_string[j] == text[s + j])
		    --j;
		if (j < 0) {
            occurance_points[count_occurances] = s;
            count_occurances++;
			s += (s + pattern_length < length) ? pattern_length - bad_char[text[s + pattern_length]] : 1;
		}
		else
			s += tool_max_byvalue(1, j - bad_char[text[s + j]]);
	}
    t = clock()-t;
    cout<<"Boyer-Moore. Length: "<<length<<"\n";
    cout<<"Total cases: "<<count_occurances<<"\n";
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    delete[] bad_char;
    write_occurances(Occurances{occurance_points,count_occurances}, pattern_length, "boyer-moore");
    return Occurances{occurance_points,count_occurances};
}

Occurances rabin_karp(char* text, string pattern_string, int length)
{
    int count_occurances = 0, d = 7, q = 7, pattern_length = pattern_string.length();
    int hashP, hashS, h = 1, j;
    clock_t t;
    static int occurance_points[EXTREME_LENGTH];

    t = clock();    
    for (auto i = 0; i < pattern_length - 1; i++)
        h = (h * d) % q;
    for (auto i = 0; i < pattern_length; i++)  {
        hashP = (d * hashP + pattern_string[i]) % q;
        hashS = (d * hashS + text[i]) % q;    
    }
    for (auto i = 0; i <= length - pattern_length; i++)  {
        if ( hashP == hashS )  {  
            bool flag = true;
            for (j = 0; j < pattern_length; j++)  {
                if (text[i+j] != pattern_string[j])  {
                    flag = false;
                    break;
                }
            }
            if (j == pattern_length)  {
                occurance_points[count_occurances] = i;
                count_occurances++;
            }
        }
        if ( i < length-pattern_length )  {
            hashS = (d*(hashS - text[i]*h) + text[i+pattern_length])%q;
            if (hashS < 0)
            hashS = (hashS + q);
        }
    }
    t = clock()-t;
    cout<<"Rabin-Karp. Length: "<<length<<"\n";
    cout<<"Total cases: "<<count_occurances<<"\n";
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    write_occurances(Occurances{occurance_points,count_occurances}, pattern_length, "rabin-karp");
    return Occurances{occurance_points,count_occurances};
}

Occurances naive_substring(char* text, string pattern_string, int length)
{
    int count_occurances = 0, pattern_length = pattern_string.length();
    clock_t t;
    static int occurance_points[EXTREME_LENGTH];

    t = clock();
    for (int i = 0; i <= length - pattern_length; i++) {
        int j;
        for (j = 0; j < pattern_length; j++)
            if (text[i + j] != pattern_string[j])
                break;
        if (j == pattern_length)  {
                occurance_points[count_occurances] = i;
                count_occurances++;
            }
    }
    t = clock()-t;
    cout<<"Naive. Length: "<<length<<"\n";
    cout<<"Total cases: "<<count_occurances<<"\n";
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    write_occurances(Occurances{occurance_points,count_occurances}, pattern_length, "naive");
    return Occurances{occurance_points,count_occurances};
}

//=====================================================================

void tool_badchar_heuristics(string array, int pattern_length, int* bad_char, int length)
{
    for (auto i = 0; i < length; i++)
		bad_char[i] = -1;
	for (auto i = 0; i < pattern_length; i++)
		bad_char[(int)array[i]] = i;
}

int tool_max_byvalue(int a, int b)
{
    return a >= b ? a : b;
}

Occurances enveloper_with_custom_text(char* text,int length,Occurances(*func)(char*,string,int))
{
    string pattern_string;
    cout<<"Enter a pattern: ";
    cin>>pattern_string;  
    return func(text,pattern_string,length);
}    

void write_occurances(Occurances a, int pattern_length, string name)
{
    string path = "exodus/"+name+".txt";
    ofstream file;
    file.open(path,ios::trunc);
    for (int i = 0; i < a.count_occurances; i++)
        file<<a.occurances_points[i]<<"  ["<<a.occurances_points[i]<<"..."<<a.occurances_points[i]+pattern_length-1<<"]"<<"\n";
    file.close();
}