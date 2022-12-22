// RabinKarp.h

#include "Utils.h"
using namespace substrsearch;

/*
(string A, string B, int C=256) -> (vector<unsigned long> C)
Takes string A, string pattern B,
alphabet power C as arguments. Finds
pattern B in the string A, using
Rabin-Karp algorithm. Returns vector<unsigned long>
C which stores every point of occurrence of the
pattern in text.
*/
vector searchRabinKarp(string text, string pattern, int alphabet_power = 256);

vector searchRabinKarp(string text, string pattern, int alphabetPower) {
  unsigned long textLength = text.length(), patternLength = pattern.length();
  unsigned long throughPattern;
  int dCapacity = alphabetPower, qPrime = 7;
  long long patternHash = 1, textHash = 1, hValue = 1;
  vector occurancePoints;

  if (patternLength == 0 || textLength == 0 || patternLength > textLength) {
    return occurancePoints;
  }
  for (unsigned long letterPattern = 0; letterPattern < patternLength - 1; letterPattern++) {
    hValue = (hValue * dCapacity) % qPrime;
  }
  for (unsigned long letter = 0; letter < patternLength; letter++) {
    patternHash = (dCapacity * patternHash + pattern[letter]) % qPrime;
    textHash = (dCapacity * textHash + text[letter]) % qPrime;
  }
  for (unsigned long through_text = 0; through_text <= textLength - patternLength; through_text++) {
    if (patternHash == textHash) {
      for (throughPattern = 0; throughPattern < patternLength; throughPattern++) {
        if (text[through_text + throughPattern] != pattern[throughPattern]) {
          break;
        }
      }
      if (throughPattern == patternLength)
        occurancePoints.push_back(through_text);
    }
    if (through_text < textLength - patternLength) {
      textHash = (dCapacity * (textHash - text[through_text] * hValue) + text[through_text + patternLength]) % qPrime;
      if (textHash < 0)
        textHash = (textHash + qPrime);
    }
  }
  return occurancePoints;
}