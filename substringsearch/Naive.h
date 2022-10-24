// naive.h

/*
Slide the pattern over text one by one and check for a match.
If a match is found, then slide by 1 again to check for subsequent
matches.

https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
*/

#include <string> // std::string
#include <vector> // vector

/*
  (string A, string B) -> (vector<unsigned long> C)
  Takes text string A, pattern string B as arguments.
  Finds pattern B in A, using Naive algorithm.
  -Returns vector<unsigned long> C which stores
  every point of occurance of the pattern
  in text.
*/
std::vector<unsigned long> substrNaive(std::string text, std::string pattern);

std::vector<unsigned long> substrNaive(std::string text, std::string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length(),
                start, next;
  std::vector<unsigned long> occurancePoints;
  if (patternLength == 0 || textLength == 0 || patternLength > textLength)
    return occurancePoints;
  for (start = 0; start <= textLength - patternLength; start++) {
    for (next = 0; next < patternLength; next++)
      if (text[start + next] != pattern[next])
        break;
    if (next == patternLength)
      occurancePoints.push_back(start);
  }
  return occurancePoints;
}