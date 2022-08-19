#include <vector>
#include "bitap.h"

std::vector<unsigned long> Bitap(std::string text, std::string pattern_string)
{
    unsigned long pattern_length = pattern_string.length(), text_length = text.length(), R = ~1;
    std::vector<unsigned long> occurance_points, pattern_bitmask;

    if (pattern_length == 0 || text_length == 0 || pattern_length > text_length)
        return occurance_points;
    if (pattern_length > 31)
        return occurance_points;

    for (int through_bitmask = 0; through_bitmask <= CHAR_MAX; ++through_bitmask)
         pattern_bitmask.push_back(~0);
    for (unsigned long byte_in_pattern = 0; byte_in_pattern < pattern_length; ++byte_in_pattern)
        pattern_bitmask[pattern_string[byte_in_pattern]] &= ~(1 << byte_in_pattern);

    for (unsigned long through_text = 0; through_text < text_length; ++through_text) {
            R |= pattern_bitmask[text[through_text]];
            R <<= 1;
            if (0 == (R & (1 << pattern_length)))
                occurance_points.push_back(through_text+1);
        }
    return occurance_points;
}

