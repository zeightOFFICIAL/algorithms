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

/*
  (string A, string B) -> (vector<unsigned long> C)
  Takes string A - text, string B - pattern, as
  arguments. Finds pattern B in the text A,
  using KMP algorithm.
  -Returns vector<unsigned long> C which stores every
  point of occurance of the pattern in text.
*/
std::vector<unsigned long> substrKnuthMorrisPratt(std::string text,
                                                  std::string pattern);
/*
  (string A, unsigned long B, unsigned long* C, unsigned long D) -> ()
  KMP algorithm preprocesses pat[] and constructs an
  auxiliary lps[] of size m (same as size of pattern) which
  is used to skip characters while matching. Name lps
  indicates longest proper prefix which is also suffix.
  A proper prefix is prefix with wholestring not allowed.
  -Returns nothing, changes C.
*/
void longestPrefixSufix(std::string pattern, unsigned long patternLength,
                        unsigned long *table, unsigned long textLength);

std::vector<u_long> substrKnuthMorrisPratt(std::string text,
                                           std::string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length();
  unsigned long *prefixTable = new unsigned long[patternLength];
  std::vector<unsigned long> occurancePoints;
  if (patternLength == 0 || textLength == 0 || patternLength > textLength)
    return occurancePoints;
  longestPrefixSufix(pattern, patternLength, prefixTable, textLength);
  unsigned long index = 0, through = 0;
  while (index < textLength) {
    if (pattern[through] == text[index]) {
      index++;
      through++;
    }
    if (through == patternLength) {
      occurancePoints.push_back(index - through);
      through = prefixTable[through - 1];
    } else if (index < textLength && pattern[through] != text[index]) {
      if (through != 0)
        through = prefixTable[through - 1];
      else
        index++;
    }
  }
  return occurancePoints;
}

void longestPrefixSufix(std::string pattern, unsigned long patternLength,
                        unsigned long *table, unsigned long textLength) {
  table[0] = 0;
  unsigned long index = 1, prefixLength = 0;
  while (index < patternLength) {
    if (pattern[index] == pattern[prefixLength]) {
      prefixLength++;
      table[index] = prefixLength;
      index++;
    } else if (pattern[index] != pattern[prefixLength]) {
      if (prefixLength != 0)
        prefixLength = table[prefixLength - 1];
      else {
        table[index] = 0;
        index++;
      }
    }
  }
}