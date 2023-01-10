/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Naive.h

#include "_Utils.h"

namespace patternsearch {
  /**
  (string A, string B) -> (vector<unsigned long> C)
  Takes string A, string pattern B, as
  arguments. Finds pattern B in the
  string A, using Naive search algorithm.
  Returns vector<unsigned long> C which
  stores every point of occurrence of the pattern
  in text.
  */
  static vector NaiveSearch(string text, string pattern);
  
  static vector NaiveSearch(string text, string pattern) {
    if (pattern.length() == 0 || text.length() == 0 ||
        pattern.length() > text.length()) {
      return vector{0};
    }
    ulong patternLength = pattern.length(), textLength = text.length();
    ulong start, next;
    vector occurancePoints;
  
    for (start = 0; start <= textLength - patternLength; start++) {
      for (next = 0; next < patternLength; next++) {
        if (text[start + next] != pattern[next]) {
          break;
        }
      }
      if (next == patternLength) {
        occurancePoints.push_back(start);
      }
    }
    
    return occurancePoints;
  }
}