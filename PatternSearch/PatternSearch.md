# Naive
Naive pattern search is a simple algorithm used to find a pattern within a text. The algorithm works by scanning the text from left to right, comparing each substring of the text of length equal to the pattern with the pattern itself.

If a match is found, the algorithm reports the starting index of the match in the text. If a match is not found, the algorithm moves to the next substring and continues the comparison until the end of the text is reached.

The time complexity of the naive pattern search algorithm is O(mn), where m is the length of the pattern and n is the length of the text. This makes it inefficient for very large texts or patterns. However, the algorithm is very simple to implement and can be used as a basis for more advanced pattern search algorithms.

# Knuth-Morris-Pratt
The Knuth-Morris-Pratt (KMP) algorithm is a string searching algorithm that finds all occurrences of a given pattern string in a longer text string. It was developed by Donald Knuth, Vaughan Pratt, and James Morris in 1977.

The KMP algorithm uses a pre-processing step to construct a prefix function for the pattern string, which is used to determine where to resume searching in the text string after a mismatch occurs. The prefix function calculates the length of the longest proper prefix of the pattern that matches a proper suffix of the pattern. This information is stored in an array that is used during the matching process to avoid unnecessary backtracking.

The algorithm then iterates over the text string, comparing characters in the pattern to characters in the text. If a mismatch occurs, the prefix function is used to determine how far to shift the pattern to the right before resuming the comparison. This avoids redundant comparisons and allows the algorithm to run in linear time, O(n+m), where n is the length of the text and m is the length of the pattern.

The KMP algorithm is particularly useful when the pattern has repeated substrings, as it can take advantage of this repetition to avoid unnecessary comparisons. It is widely used in computer science and bioinformatics for tasks such as sequence alignment, DNA analysis, and text search.

# Boyer-Moore
Boyer-Moore algorithm is a string searching algorithm that finds all occurrences of a given pattern in a given text. It works by preprocessing the pattern and the text to construct two tables that are used to skip over as many characters as possible in the text. The first table is the bad character table, which is an array indexed by character, and contains the number of characters to skip over if a mismatch occurs at that position in the pattern. The second table is the good suffix table, which contains information about the occurrence of suffixes of the pattern within the pattern.

To perform the search, the algorithm starts at the end of the pattern and compares the last character of the pattern with the corresponding character in the text. If they match, it continues to compare the preceding characters until either the pattern is found or a mismatch is encountered. If a mismatch is encountered, the algorithm uses the bad character table to determine the number of characters to skip over in the text before starting the next comparison.

The bad character table is constructed by iterating over the pattern and storing the position of the last occurrence of each character in the pattern. If a character does not occur in the pattern, its position is set to -1. If a character occurs multiple times in the pattern, only the last occurrence is stored.

The good suffix table is constructed by iterating over the pattern and storing the length of the longest suffix of the pattern that matches a prefix of the pattern, starting from each position in the pattern. If no suffix matches a prefix, the length is set to 0.

The time complexity of the algorithm is O(n + m), where n is the length of the text and m is the length of the pattern. The space complexity is O(k), where k is the size of the character set. In practice, the algorithm is very efficient for searching in large texts, especially if the pattern is long and the character set is small.

# Rabin-Karp
Rabin-Karp is a string searching algorithm that uses hashing to find occurrences of a pattern within a larger text. It was developed by Richard M. Karp and Michael O. Rabin in 1987 and is based on the idea of comparing hash values instead of the pattern and the text themselves.

The Rabin-Karp algorithm works by computing a hash value for the pattern and for each window of the same size in the text. It then compares the hash values of the pattern and each window of the text, and if they match, it checks the pattern and the corresponding substring in the text character by character to confirm the match.

To speed up the hashing process, Rabin-Karp uses a rolling hash function that efficiently updates the hash value of a new window based on the hash value of the previous window. This allows the algorithm to perform the hash computation in constant time for each window.

Rabin-Karp has an average case time complexity of O(n+m), where n is the length of the text and m is the length of the pattern. In the worst case, the time complexity can be O(nm), which occurs when the hash function has a high collision rate.

Overall, Rabin-Karp is a simple and effective algorithm for string searching, especially for cases where the pattern and the text are large and the alphabet is small.

# Bitap (Shift-OR)
The Bitap (Shift-Or) algorithm is a string searching algorithm that uses bitwise operations to compare the pattern with the text. It works by pre-processing the pattern to create a bitmask that represents the positions of each character in the pattern. It then uses this bitmask to search for the pattern in the text.

The advantage of the Bitap algorithm is that it can match patterns with errors or variations, by allowing a certain number of mismatches or gaps in the pattern. This is done by keeping track of a set of bitmasks, each representing a different state of the pattern match, and updating them based on the current character in the text.

Overall, the Bitap algorithm has a time complexity of O(mn), where m is the length of the pattern and n is the length of the text. However, it can be optimized to O(n/m) in the average case, by using a technique called skip-ahead, which allows the algorithm to skip over parts of the text that cannot match the pattern.