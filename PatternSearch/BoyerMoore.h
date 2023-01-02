// BoyerMoore.h

#include "_Utils.h"

namespace patternsearch {
  /**
  (string A, string B) -> (vector<unsigned long> C)
  Takes string A, string pattern B, as
  arguments. Finds pattern B in the
  string A, using Boyer-Moore algorithm.
  Returns vector<unsigned long> C which
  stores every point of occurrence of the pattern
  in text.
  */
  static vector BoyerMooreSearch(string text, string pattern);
  /**
  (string A, unsigned long B, int* C, unsigned long D) -> ()
  Takes pattern string A, its length B, int table C, text length D.
  Finds bad char heuristic. The table which indicates last occurrence
  of letter from alphabet in A within range of (0...length of B - 1)
  The remained alphabet symbols are set to -1. Returns nothing, changes C
  */
  static void Heuristics(string pattern, ulong patternLength, int *heuristicsUnsigned, ulong textLength);
  
  static vector BoyerMooreSearch(string text, string pattern) {
    if (pattern.length() == 0 || text.length() == 0 || pattern.length() > text.length()) {
      return vector{0};
    }
    ulong patternLength = pattern.length(), textLength = text.length();
    int *heuristics = new int[256];
    int64 textIndex = 0, patternIndex;
    vector occurancePoints;
  
    heuristics(pattern, patternLength, heuristics, textLength);
    while (textIndex <= (textLength - patternLength)) {
      patternIndex = patternLength - 1;
      while (patternIndex >= 0 && pattern[patternIndex] == text[textIndex + patternIndex]) {
        --patternIndex;
      }
      if (patternIndex < 0) {
        occurancePoints.push_back(textIndex);
        textIndex += (textIndex + patternLength < textLength) ? patternLength - heuristics[text[textIndex + patternLength]] : 1;
      } else
        textIndex += maxByValue(1, patternIndex - heuristics[text[textIndex + patternIndex]]);
    }
    delete[] heuristics;
  
    return occurancePoints;
  }
  
  static void Heuristics(string pattern, ulong patternLength, int *table, ulong textLength) {
    for (ulong alphabetIndex = 0; alphabetIndex < 256; alphabetIndex++) {
      table[alphabetIndex] = -1;
    }
    for (ulong patternIndex = 0; patternIndex < patternLength; patternIndex++) {
      table[(int)pattern[patternIndex]] = patternIndex;
    }
  }
}