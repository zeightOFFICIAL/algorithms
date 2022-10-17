// naive.h

/*
Slide the pattern over text one by one and check for a match.
If a match is found, then slide by 1 again to check for subsequent
matches.
https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
*/

#include <string>
#include <vector>

std::vector<unsigned long> NaiveSearch(std::string text, std::string pattern);

/*
        (string A, string B) -> (vector<unsigned long> C)
        Takes text string A, pattern string B as arguments.
        Finds pattern B in A, using Naive algorithm.
        Returns vector<unsigned long> C which stores
        every point of occurance of the pattern
        in text.
*/
std::vector<unsigned long> NaiveSearch(std::string text, std::string pattern) {
  unsigned long pattern_length = pattern.length(), text_length = text.length(),
                start, next;
  std::vector<unsigned long> occurance_points;
  if (pattern_length == 0 || text_length == 0 || pattern_length > text_length)
    return occurance_points;
  for (start = 0; start <= text_length - pattern_length; start++) {
    for (next = 0; next < pattern_length; next++)
      if (text[start + next] != pattern[next])
        break;
    if (next == pattern_length)
      occurance_points.push_back(start);
  }
  return occurance_points;
}