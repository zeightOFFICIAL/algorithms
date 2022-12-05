// BoyerMoore.h

#include "Utils.h"
using namespace substrsearch;

/*
(string A, string B) -> (vector<unsigned long> C)
Takes string A, string pattern B, as
arguments. Finds pattern B in the
string A, using Boyer-Moore algorithm.
Returns vector<unsigned long> C which
stores every point of occurrence of the pattern
in text.
*/
vector searchBoyerMoore(string text, string pattern);
/*
(string A, unsigned long B, int* C, unsigned long D) -> ()
Takes pattern string A, its length B, int table C, text length D.
Finds bad char heuristic. The table which indicates last occurrence
of letter from alphabet in A within range of (0...length of B - 1)
The remained alphabet symbols are set to -1. Returns nothing, changes C
*/
void heuristicsBadChar(string pattern, unsigned long patternLength, int *heuristicsUnsigned, unsigned long textLength);

vector searchBoyerMoore(string text, string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length();
  int *heuristicsTable = new int[256];
  long long textIndex = 0, patternIndex;
  vector occurancePoints;

  if (patternLength == 0 || textLength == 0 || patternLength > textLength) {
    return occurancePoints;
  }
  heuristicsBadChar(pattern, patternLength, heuristicsTable, textLength);
  while (textIndex <= (textLength - patternLength)) {
    patternIndex = patternLength - 1;
    while (patternIndex >= 0 && pattern[patternIndex] == text[textIndex + patternIndex]) {
      --patternIndex;
    }
    if (patternIndex < 0) {
      occurancePoints.push_back(textIndex);
      textIndex += (textIndex + patternLength < textLength) ? patternLength - heuristicsTable[text[textIndex + patternLength]] : 1;
    } else
      textIndex += maxByValue(1, patternIndex - heuristicsTable[text[textIndex + patternIndex]]);
  }
  delete[] heuristicsTable;
  return occurancePoints;
}

void heuristicsBadChar(string pattern, unsigned long patternLength, int *heuristicsTable, unsigned long textLength) {
  for (unsigned long letterAlphabet = 0; letterAlphabet < 256; letterAlphabet++)
    heuristicsTable[letterAlphabet] = -1;
  for (unsigned long letterPattern = 0; letterPattern < patternLength; letterPattern++)
    heuristicsTable[(int)pattern[letterPattern]] = letterPattern;
}