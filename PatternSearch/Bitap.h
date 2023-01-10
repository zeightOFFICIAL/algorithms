/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Bitap.h

#include "_Utils.h"

namespace patternsearch {
  /**
  (string A, string B) -> (vector<unsigned long> C)
  Takes string A, string pattern B, as
  arguments. Finds pattern B in the
  string A, using Bitap, shift-or algorithm.
  Returns vector<unsigned long> C which
  stores every point of occurrence of the pattern
  in text.
  * Pattern B MUST be SHORTER than 32 bytes
  */
  static vector BitapSearch(string text, string pattern);
  
  static vector BitapSearch(string text, string pattern) {
    if (pattern.length() == 0 || text.length() == 0 || pattern.length() > text.length() || pattern.length() > 31) {
      return vector{0};
    }
    ulong patternLength = pattern.length(), textLength = text.length();
    ulong R = ~1, byteInPattern, textIndex;
    vector occurancePoints, bitmaskIndex;
  
    for (int throughBitmask = 0; throughBitmask <= CHAR_MAX; ++throughBitmask) {
      bitmaskIndex.push_back(~0);
    }
    for (byteInPattern = 0; byteInPattern < patternLength; ++byteInPattern) {
      bitmaskIndex[pattern[byteInPattern]] &= ~(1 << byteInPattern);
    }
    for (textIndex = 0; textIndex < textLength; ++textIndex) {
      R |= bitmaskIndex[text[textIndex]];
      R <<= 1;
      if (0 == (R & (1 << patternLength)))
        occurancePoints.push_back(textIndex + 1);
    }
  
    return occurancePoints;
  }
}