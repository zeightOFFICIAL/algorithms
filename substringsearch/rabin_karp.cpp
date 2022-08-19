#include <vector>
#include "rabin_karp.h"


std::vector<unsigned long> RabinKarp(std::string text, std::string pattern_string, int alphabet)
{
    unsigned long text_length = text.length(), pattern_length = pattern_string.length(), through_pattern;
    int d_capacity = alphabet, q_prime = 7;
    long long pattern_hash = 1, text_hash = 1, h_value = 1;
    std::vector<unsigned long> occurance_points;

    if (pattern_length == 0 || text_length == 0 || pattern_length > text_length)
        return occurance_points;
  
    for (unsigned long each_letter_in_pattern = 0; each_letter_in_pattern < pattern_length - 1; each_letter_in_pattern++)
        h_value = (h_value * d_capacity) % q_prime;
    for (unsigned long each_letter = 0; each_letter < pattern_length; each_letter++)  {
        pattern_hash = (d_capacity * pattern_hash + pattern_string[each_letter]) % q_prime;
        text_hash = (d_capacity * text_hash + text[each_letter]) % q_prime;    
    }
    for (unsigned long through_text = 0; through_text <= text_length - pattern_length; through_text++)  {
        if (pattern_hash == text_hash)  {  
            for (through_pattern = 0; through_pattern < pattern_length; through_pattern++)  {
                if (text[through_text+through_pattern] != pattern_string[through_pattern])  {
                    break;
                }
            }
            if (through_pattern == pattern_length)
                occurance_points.push_back(through_text);
        }
        if (through_text < text_length - pattern_length)  {
            text_hash = (d_capacity*(text_hash - text[through_text]*h_value) + text[through_text+pattern_length])%q_prime;
            if (text_hash < 0)
            text_hash = (text_hash + q_prime);
        }
    }
    return occurance_points;
}