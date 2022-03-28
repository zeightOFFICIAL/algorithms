#include <vector>
#include "rabin_karp.h"

using std::string, std::vector;

vector<unsigned long> RabinKarp(char* text, string pattern_string, unsigned long length)
{
    int d = 7, q = 7, pattern_length = pattern_string.length();
    int hashP, hashS, h = 1, j;
    vector<unsigned long> occurance_points;
  
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
            if (j == pattern_length)
                occurance_points.push_back(i);
        }
        if ( i < length-pattern_length )  {
            hashS = (d*(hashS - text[i]*h) + text[i+pattern_length])%q;
            if (hashS < 0)
            hashS = (hashS + q);
        }
    }
    return occurance_points;
}