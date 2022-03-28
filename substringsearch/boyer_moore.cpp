#include <vector>
#include "boyer_moore.h"

using std::string, std::vector;

vector<unsigned long> BoyerMoore(char* text, string pattern_string, unsigned long length)
{
    int pattern_length = pattern_string.length(), s = 0;
    int* bad_char = new int[length];
    vector<unsigned long> occurance_points;
    
    ToolBadcharHeuristics(pattern_string,pattern_length,bad_char,length);
    while (s <= (length - pattern_length))  {
		auto j = pattern_length - 1;
		while (j >= 0 && pattern_string[j] == text[s + j])
		    --j;
		if (j < 0)  {
            occurance_points.push_back(s);
			s += (s + pattern_length < length) ? pattern_length - bad_char[text[s + pattern_length]] : 1;
		}
		else
			s += ToolMaxByValue(1, j - bad_char[text[s + j]]);
	}
    delete[] bad_char;
    return occurance_points;
}

void ToolBadcharHeuristics(string array, int pattern_length, int* bad_char, unsigned long  length)
{
    for (unsigned long i = 0; i < length; i++)
		bad_char[i] = -1;
	for (unsigned long i = 0; i < pattern_length; i++)
		bad_char[(int)array[i]] = i;
}

int ToolMaxByValue(int a, int b)  {
    return a >= b ? a : b;
}