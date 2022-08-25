// boyer_moore.h

/*
The algorithm preprocesses the string being searched for (the pattern),
but not the string being searched in (the text). It is thus well-suited
for applications in which the pattern is much shorter than the text or
where it persists across multiple searches. The Boyer–Moore algorithm
uses information gathered during the preprocess step to skip sections
of the text, resulting in a lower constant factor than many other
string search algorithms.

The idea of bad character heuristic is simple. The character
of the text which doesn’t match with the current character
of the pattern is called the Bad Character. Upon mismatch,
we shift the pattern until:
- he mismatch becomes a match
- Pattern P moves past the mismatched character.
https://en.wikipedia.org/wiki/Boyer–Moore_string-search_algorithm
https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
*/

#include <string>
#include <vector>

typedef unsigned long u_long;
typedef long long d_long;

std::vector<u_long> BoyerMoore(std::string text, std::string pattern);
void BadCharHeuristics(std::string pattern, u_long pattern_length, int* heuristics_table, u_long text_length);
d_long MaxByValue(d_long a, d_long b);

/*
	(string A, string B) -> (vector<unsigned long> C)
	Takes string A - text, string B - pattern, as
	arguments. Finds pattern B in the text A,
	using Boyer-Moore algorithm with heuristics
	of bad chars.
	Returns vector<unsigned long> C which stores every
	point of occurance of the pattern in text.
*/
std::vector<u_long> BoyerMoore(std::string text, std::string pattern)
{
	u_long pattern_length = pattern.length(), text_length = text.length();
	int* heuristics_table = new int[256];
	d_long text_index = 0, pattern_index;
	std::vector<u_long> occurance_points;
	if (pattern_length == 0 || text_length == 0 || pattern_length > text_length)
		return occurance_points;
	BadCharHeuristics(pattern, pattern_length, heuristics_table, text_length);
	while (text_index <= (text_length - pattern_length)) {
		pattern_index = pattern_length - 1;
		while (pattern_index >= 0 && pattern[pattern_index] == text[text_index + pattern_index])
			--pattern_index;
		if (pattern_index < 0) {
			occurance_points.push_back(text_index);
			text_index += (text_index + pattern_length < text_length) ? pattern_length - heuristics_table[text[text_index + pattern_length]] : 1;
		}
		else
			text_index += MaxByValue(1, pattern_index - heuristics_table[text[text_index + pattern_index]]);
	}
	delete[] heuristics_table;
	return occurance_points;
}

/*
	(string A, unsigned long B, int* C, unsigned long D) -> ()
	So, for Boyer-Moore algorithm's correct work. Firstly, as
	one of two possible heuristics we need to create a badchar
	table. The table which indicates last occurrence of letter
	from alphabet in A within range of (0...length of B - 1)
	The remained alphabet symbols are set to -1
	Returns nothing. Changes C.
	>>BadCharHeuristics(pattern, pattern length, heuristics table, length)
*/
void BadCharHeuristics(std::string pattern, u_long pattern_length, int* heuristics_table, u_long text_length)
{
	for (u_long letter_from_alphabet = 0; letter_from_alphabet < 256; letter_from_alphabet++)
		heuristics_table[letter_from_alphabet] = -1;
	for (u_long letter_from_pattern = 0; letter_from_pattern < pattern_length; letter_from_pattern++)
		heuristics_table[(int)pattern[letter_from_pattern]] = letter_from_pattern;
}

/*
	(int64 A, int64 B) -> (int64 C)
	Returns C biggest of values A and B
	>>MaxByValue(5,6);
	<<6
*/
d_long MaxByValue(d_long a, d_long b)
{
	return a >= b ? a : b;
}