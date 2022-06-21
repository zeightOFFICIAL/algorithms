#include <vector>
#include "bitap.h"
#include "limits.h"

std::vector<unsigned long> Bitap(char* text, std::string pattern_string, unsigned long length)
{
    int pattern_length = pattern_string.length();
    std::vector<unsigned long> occurance_points, pattern_mask;
    unsigned long R = ~1;

    if (pattern_length==0)
        return occurance_points;
    if (pattern_length > 31)
        return occurance_points;

    for (int i = 0; i <= CHAR_MAX; ++i)
         pattern_mask.push_back(~0);
    
    for (int i = 0; i < pattern_length; ++i)
        pattern_mask[pattern_string[i]] &= ~(1UL << i);

    for (unsigned long i = 0; i < length; ++i)
        {
            R |= pattern_mask[text[i]];
            R <<= 1;
            if (0 == (R & (1UL << pattern_length)))
                occurance_points.push_back(i+1);
        }
    return occurance_points;
}

