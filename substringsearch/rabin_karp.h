// rabin_karp.h

/*
Like the Naive Algorithm, Rabin-Karp algorithm also slides the
pattern one by one. But unlike the Naive algorithm, Rabin Karp
algorithm matches the hash value of the pattern with the hash
value of current substring of text, and if the hash values
match then only it starts matching individual characters.
So Rabin Karp algorithm needs to calculate hash values for
following strings.
https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
*/

#include <string>
#include <vector>

typedef unsigned long u_long;
typedef long long d_long;

std::vector<u_long> RabinKarp(std::string text, std::string pattern, int alphabet_power = 256);

/*
	(string A, string B) -> (vector<unsigned long> D)
	Takes text string A, the pattern B, as
	arguments.Finds pattern B in the text A, using
	Rabin-Karp algorithm.
	Returns vector<unsigned long> D which
	stores every point of occurance of the pattern
	in text.
*/
std::vector<u_long> RabinKarp(std::string text, std::string pattern, int alphabet_power)
{
	u_long text_length = text.length(), pattern_length = pattern.length(), through_pattern;
	int d_capacity = alphabet_power, q_prime = 7;
	d_long pattern_hash = 1, text_hash = 1, h_value = 1;
	std::vector<u_long> occurance_points;
	if (pattern_length == 0 || text_length == 0 || pattern_length > text_length)
		return occurance_points;
	for (u_long letter_in_pattern = 0; letter_in_pattern < pattern_length - 1; letter_in_pattern++)
		h_value = (h_value * d_capacity) % q_prime;
	for (u_long letter = 0; letter < pattern_length; letter++) {
		pattern_hash = (d_capacity * pattern_hash + pattern[letter]) % q_prime;
		text_hash = (d_capacity * text_hash + text[letter]) % q_prime;
	}
	for (u_long through_text = 0; through_text <= text_length - pattern_length; through_text++) {
		if (pattern_hash == text_hash) {
			for (through_pattern = 0; through_pattern < pattern_length; through_pattern++) {
				if (text[through_text + through_pattern] != pattern[through_pattern]) {
					break;
				}
			}
			if (through_pattern == pattern_length)
				occurance_points.push_back(through_text);
		}
		if (through_text < text_length - pattern_length) {
			text_hash = (d_capacity * (text_hash - text[through_text] * h_value) + text[through_text + pattern_length]) % q_prime;
			if (text_hash < 0)
				text_hash = (text_hash + q_prime);
		}
	}
	return occurance_points;
}