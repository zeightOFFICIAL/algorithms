// bitap.h

/*
Bitap distinguishes itself from other well-known string searching
algorithms in its natural mapping onto simple bitwise operations,
as in the following modification of the above program. Notice
that in this implementation, counterintuitively, each bit with
value zero indicates a match, and each bit with value 1 indicates
a non-match.
https://en.wikipedia.org/wiki/Bitap_algorithm
*/

#include <string>
#include <vector>
#include <climits>

typedef unsigned long u_long;

std::vector<u_long> Bitap(std::string text, std::string pattern);

/*
	(string A, string B) -> (vector<unsigned long> C)
	Takes string A, string pattern B, as
	arguments. Finds pattern B in the
	string A, using Bitap, shift-or algorithm.
	Returns vector<unsigned long> C which
	stores every point of occurance of the pattern
	in text.
*/
std::vector<u_long> Bitap(std::string text, std::string pattern)
{
	u_long pattern_length = pattern.length(), text_length = text.length(), R = ~1;
	std::vector<u_long> occurance_points, pattern_bitmask;
	if (pattern_length == 0 || text_length == 0 || pattern_length > text_length || pattern_length > 31)
		return occurance_points;
	for (int through_bitmask = 0; through_bitmask <= CHAR_MAX; ++through_bitmask)
		pattern_bitmask.push_back(~0);
	for (u_long byte_in_pattern = 0; byte_in_pattern < pattern_length; ++byte_in_pattern)
		pattern_bitmask[pattern[byte_in_pattern]] &= ~(1 << byte_in_pattern);
	for (u_long through_text = 0; through_text < text_length; ++through_text) {
		R |= pattern_bitmask[text[through_text]];
		R <<= 1;
		if (0 == (R & (1 << pattern_length)))
			occurance_points.push_back(through_text + 1);
	}
	return occurance_points;
}