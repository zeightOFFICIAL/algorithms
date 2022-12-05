// Bitap.h

#include "Utils.h"
using namespace substrsearch;

/*
(string A, string B) -> (vector<unsigned long> C)
Takes string A, string pattern B, as
arguments. Finds pattern B in the
string A, using Bitap, shift-or algorithm.
Returns vector<unsigned long> C which
stores every point of occurrence of the pattern
in text.
* Pattern B MUST be SHORTER than 32 bytes
*/
vector searchBitap(string text, string pattern);

vector searchBitap(string text, string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length();
  unsigned long R = ~1;
  vector occurancePoints, patternBitmask;

  if (patternLength == 0 || textLength == 0 || patternLength > textLength || patternLength > 31) {
    return occurancePoints;
  }
  for (int throughBitmask = 0; throughBitmask <= CHAR_MAX; ++throughBitmask) {
    patternBitmask.push_back(~0);
  }
  for (unsigned long byteInPattern = 0; byteInPattern < patternLength; ++byteInPattern) {
    patternBitmask[pattern[byteInPattern]] &= ~(1 << byteInPattern);
  }
  for (unsigned long throughText = 0; throughText < textLength; ++throughText) {
    R |= patternBitmask[text[throughText]];
    R <<= 1;
    if (0 == (R & (1 << patternLength)))
      occurancePoints.push_back(throughText + 1);
  }
  return occurancePoints;
}