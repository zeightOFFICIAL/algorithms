// Naive.h

#include "Utils.h"
using namespace substrsearch;

/*
(string A, string B) -> (vector<unsigned long> C)
Takes string A, string pattern B, as
arguments. Finds pattern B in the
string A, using Naive search algorithm.
Returns vector<unsigned long> C which
stores every point of occurrence of the pattern
in text.
*/
vector searchNaive(string text, string pattern);

vector searchNaive(string text, string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length();
  unsigned long start, next;
  vector occurancePoints;

  if (patternLength == 0 || textLength == 0 || patternLength > textLength) {
    return occurancePoints;
  }
  for (start = 0; start <= textLength - patternLength; start++) {
    for (next = 0; next < patternLength; next++)
      if (text[start + next] != pattern[next])
        break;
    if (next == patternLength)
      occurancePoints.push_back(start);
  }
  return occurancePoints;
}