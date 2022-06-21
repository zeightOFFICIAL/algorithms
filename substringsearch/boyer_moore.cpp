#include <vector>
#include "boyer_moore.h"


std::vector<unsigned long> BoyerMoore(std::string text, std::string pattern_string)
{
	unsigned long pattern_length = pattern_string.length(), text_length = text.length();
	int *heuristics_table = new int[256];
	long long text_current_index = 0, pattern_previous_index;
	std::vector<unsigned long> occurance_points;
	
	BadCharHeuristics(pattern_string, pattern_length, heuristics_table, text_length);

    while (text_current_index <= (text_length - pattern_length))  {
		pattern_previous_index = pattern_length - 1;
		while (pattern_previous_index >= 0 && pattern_string[pattern_previous_index] == text[text_current_index + pattern_previous_index])
		    --pattern_previous_index;
		if (pattern_previous_index < 0)  {
            occurance_points.push_back(text_current_index);
			text_current_index += (text_current_index + pattern_length < text_length) ? pattern_length - heuristics_table[text[text_current_index + pattern_length]] : 1;
		}
		else
			text_current_index += MaxByValue(1, pattern_previous_index - heuristics_table[text[text_current_index + pattern_previous_index]]);
	}
    delete[] heuristics_table;
    return occurance_points;
}

void BadCharHeuristics(std::string array, unsigned long pattern_length, int* bad_char, unsigned long length)
{
    for (unsigned long this_letter_from_alphabet = 0; this_letter_from_alphabet < 256; this_letter_from_alphabet++)
		bad_char[this_letter_from_alphabet] = -1;
	for (unsigned long this_letter_from_pattern = 0; this_letter_from_pattern < pattern_length; this_letter_from_pattern++)
		bad_char[(int)array[this_letter_from_pattern]] = this_letter_from_pattern;
}

long long MaxByValue(long long a, long long b)  {
    return a >= b ? a : b;
}