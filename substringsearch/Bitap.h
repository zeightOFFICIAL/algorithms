// Bitap.h

/*
Bitap distinguishes itself from other well-known string searching
algorithms in its natural mapping onto simple bitwise operations,
as in the following modification of the above program. Notice
that in this implementation, counterintuitively, each bit with
value zero indicates a match, and each bit with value 1 indicates
a non-match.

https://en.wikipedia.org/wiki/Bitap_algorithm
*/

#include <climits> // CHAR_MAX
#include <string> // std::string
#include <vector> // vector

/*
  (string A, string B) -> (vector<unsigned long> C)
  Takes string A, string pattern B, as
  arguments. Finds pattern B in the
  string A, using Bitap, shift-or algorithm.
  -Returns vector<unsigned long> C which
  stores every point of occurance of the pattern
  in text.
*/
std::vector<unsigned long> substrBitap(std::string text, std::string pattern);

std::vector<unsigned long> substrBitap(std::string text, std::string pattern) {
  unsigned long patternLength = pattern.length(), textLength = text.length(),
                R = ~1;
  std::vector<unsigned long> occurancePoints, patternBitmask;
  if (patternLength == 0 || textLength == 0 || patternLength > textLength ||
      patternLength > 31)
    return occurancePoints;
  for (int throughBitmask = 0; throughBitmask <= CHAR_MAX; ++throughBitmask)
    patternBitmask.push_back(~0);
  for (unsigned long byteInPattern = 0; byteInPattern < patternLength;
       ++byteInPattern)
    patternBitmask[pattern[byteInPattern]] &= ~(1 << byteInPattern);
  for (unsigned long throughText = 0; throughText < textLength; ++throughText) {
    R |= patternBitmask[text[throughText]];
    R <<= 1;
    if (0 == (R & (1 << patternLength)))
      occurancePoints.push_back(throughText + 1);
  }
  return occurancePoints;
}