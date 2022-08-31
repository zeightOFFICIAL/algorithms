// knuth_morris_pratt.h

/*
The KMP matching algorithm uses degenerating property 
(pattern having same sub-patterns appearing more than 
once in the pattern) of the pattern and improves the 
worst case complexity to O(n). The basic idea behind 
KMP’s algorithm is: whenever we detect a mismatch 
(after some matches), we already know some of the 
characters in the text of the next window. We take 
advantage of this information to avoid matching 
the characters that we know will anyway match.
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*/

typedef unsigned long u_long;

std::vector<u_long> KnuthMorrisPratt(std::string text, std::string pattern);
void LongestPrefixSufix(std::string pattern, u_long pattern_length, u_long* table, u_long text_length);

/*
	(string A, string B) -> (vector<unsigned long> C)
	Takes string A - text, string B - pattern, as
	arguments. Finds pattern B in the text A,
	using KMP algorithm.
	Returns vector<unsigned long> C which stores every
	point of occurance of the pattern in text.
*/
std::vector<u_long> KnuthMorrisPratt(std::string text, std::string pattern)
{
    u_long pattern_length = pattern.length(), text_length = text.length();
	u_long* prefix_table = new u_long[pattern_length];
	std::vector<u_long> occurance_points;
	if (pattern_length == 0 || text_length == 0 || pattern_length > text_length)
		return occurance_points;
    LongestPrefixSufix(pattern, pattern_length, prefix_table, text_length);
    u_long index = 0, through = 0;
    while (index < text_length) {
        if (pattern[through] == text[index]) {
            index++;
            through++;
        }
        if (through == pattern_length) {
            occurance_points.push_back(index - through);
            through = prefix_table[through-1];
        }
        else if (index < text_length && pattern[through] != text[index]) {
            if (through != 0)
                through = prefix_table[through-1];
            else    
                index++;
        }
    }
    return occurance_points;
}

/*
    (string A, unsigned long B, unsigned long* C, unsigned long D) -> ()
    KMP algorithm preprocesses pat[] and constructs an 
    auxiliary lps[] of size m (same as size of pattern) which 
    is used to skip characters while matching. Name lps 
    indicates longest proper prefix which is also suffix. 
    A proper prefix is prefix with wholestring not allowed.
    Returns nothing, changes C.
*/
void LongestPrefixSufix(std::string pattern, u_long pattern_length, u_long* table, u_long text_length)
{
    table[0] = 0;
    u_long index = 1, prefix_length = 0;
    while (index < pattern_length) {
        if (pattern[index] == pattern[prefix_length]) {
            prefix_length++;
            table[index] = prefix_length;
            index++;
        }
        else if (pattern[index] != pattern[prefix_length]) {
            if (prefix_length != 0)
                prefix_length = table[prefix_length-1];
            else {
                table[index] = 0;
                index++;
            }
        }
    }
}