// KnuthMorrisPratt.h

#include "Utils.h"
using namespace substrsearch;

/*
(string A, string B) -> (vector<unsigned long> C)
Takes string A, string pattern B, as
arguments. Finds pattern B in the
string A, using Knuth-Morris-Pratt algorithm.
Returns vector<unsigned long> C which
stores every point of occurrence of the pattern
in text.
*/
vector searchKMP(string text, string pattern);
/*
(string A, unsigned long B, unsigned long* C, unsigned long D) -> ()
Takes pattern A, its length B, unsigned long table C
and text length D. KMP algorithm requires preprocessing.
It processes pattern A and constructs an auxiliary table C
of size B (same as size of pattern) which is used to skip
characters while matching. Name of LPS (actual for table C)
indicates longest proper prefix which is also a suffix.
A proper prefix is a prefix with wholestring not allowed.
Returns nothing, changes C.
*/
void longestPrefixSufix(string pattern, unsigned long patternLength,
                        unsigned long *table, unsigned long textLength);

vector searchKMP(string text, string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length();
  unsigned long *prefixTable = new unsigned long[patternLength];
  vector occurancePoints;

  if (patternLength == 0 || textLength == 0 || patternLength > textLength) {
    return occurancePoints;
  }
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
  delete[] prefixTable;
  return occurancePoints;
}

void longestPrefixSufix(string pattern, unsigned long patternLength, unsigned long *table, unsigned long textLength) {
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