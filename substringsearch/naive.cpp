#include <vector>
#include "naive.h"

std::vector<unsigned long> NaiveSearch(std::string text, std::string pattern_string)
{
    unsigned long pattern_length = pattern_string.length(), text_length = text.length();
    std::vector<unsigned long> occurance_points;

    if (pattern_length == 0 || text_length == 0 || pattern_length > text_length)
        return occurance_points;
    
    for (unsigned long starting_index = 0; starting_index <= text_length - pattern_length; starting_index++)  {
        unsigned long next_element;
        for (next_element = 0; next_element < pattern_length; next_element++)
            if (text[starting_index + next_element] != pattern_string[next_element])
                break;
        if (next_element == pattern_length)
                occurance_points.push_back(starting_index);
    }
    return occurance_points;
}