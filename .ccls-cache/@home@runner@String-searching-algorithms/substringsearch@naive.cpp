#include <vector>
#include "naive.h"

using std::string, std::vector;

vector<unsigned long> NaiveSearch(char* text, string pattern_string, unsigned long length)
{
    int pattern_length = pattern_string.length();
    vector<unsigned long> occurance_points;
    
    for (int i = 0; i <= length - pattern_length; i++)  {
        int j;
        for (j = 0; j < pattern_length; j++)
            if (text[i + j] != pattern_string[j])
                break;
        if (j == pattern_length)
                occurance_points.push_back(i);
    }
    return occurance_points;
}