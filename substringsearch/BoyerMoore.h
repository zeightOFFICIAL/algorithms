// boyer_moore.h

/*
The algorithm preprocesses the string being searched for (the pattern),
but not the string being searched in (the text). It is thus well-suited
for applications in which the pattern is much shorter than the text or
where it persists across multiple searches. The Boyer-Moore algorithm
uses information gathered during the preprocess step to skip sections
of the text, resulting in a lower constant factor than many other
string search algorithms.

The idea of bad character heuristic is simple. The character
of the text which doesn't match with the current character
of the pattern is called the Bad Character. Upon mismatch,
we shift the pattern until:
- he mismatch becomes a match
- Pattern P moves past the mismatched character.

https://en.wikipedia.org/wiki/Boyer-Moore_string-search_algorithm
https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
*/

#include <string> // std::string
#include <vector> // vector

/*
  (string A, string B) -> (vector<unsigned long> C)
  Takes string A - text, string B - pattern, as
  arguments. Finds pattern B in the text A,
  using Boyer-Moore algorithm with heuristics
  of bad chars.
  Returns vector<unsigned long> C which stores every
  point of occurance of the pattern in text.
*/
std::vector<unsigned long> substrBoyerMoore(std::string text,
                                            std::string pattern);
/*
  (string A, unsigned long B, int* C, unsigned long D) -> ()
  So, for Boyer-Moore algorithm's correct work. Firstly, as
  one of two possible heuristics we need to create a badchar
  table. The table which indicates last occurrence of letter
  from alphabet in A within range of (0...length of B - 1)
  The remained alphabet symbols are set to -1
  Returns nothing. Changes C.
*/
void heuristicsBadChar(std::string pattern, unsigned long patternLength,
                       int *heuristicsUnsigned, unsigned long textLength);
/*
  (int64 A, int64 B) -> (int64 C)
  Returns C biggest of values A and B
*/
long long maxByValue(long long a, long long b);

std::vector<unsigned long> substrBoyerMoore(std::string text,
                                            std::string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length();
  int *heuristicsTable = new int[256];
  long long textIndex = 0, patternIndex;
  std::vector<unsigned long> occurancePoints;
  if (patternLength == 0 || textLength == 0 || patternLength > textLength)
    return occurancePoints;
  heuristicsBadChar(pattern, patternLength, heuristicsTable, textLength);
  while (textIndex <= (textLength - patternLength)) {
    patternIndex = patternLength - 1;
    while (patternIndex >= 0 &&
           pattern[patternIndex] == text[textIndex + patternIndex])
      --patternIndex;
    if (patternIndex < 0) {
      occurancePoints.push_back(textIndex);
      textIndex +=
          (textIndex + patternLength < textLength)
              ? patternLength - heuristicsTable[text[textIndex + patternLength]]
              : 1;
    } else
      textIndex += maxByValue(
          1, patternIndex - heuristicsTable[text[textIndex + patternIndex]]);
  }
  delete[] heuristicsTable;
  return occurancePoints;
}

void heuristicsBadChar(std::string pattern, unsigned long patternLength,
                       int *heuristicsTable, unsigned long textLength) {
  for (unsigned long letterAlphabet = 0; letterAlphabet < 256; letterAlphabet++)
    heuristicsTable[letterAlphabet] = -1;
  for (unsigned long letterPattern = 0; letterPattern < patternLength;
       letterPattern++)
    heuristicsTable[(int)pattern[letterPattern]] = letterPattern;
}

long long maxByValue(long long a, long long b) { return a >= b ? a : b; }