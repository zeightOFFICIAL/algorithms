// RabinKarp.h

#include "_Utils.h"
using namespace patternsearch;

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
  if (pattern.length() == 0 || text.length() == 0 || pattern.length() > text.length()) {
    return vector{0};
  }  
  u_long textLength = text.length(), patternLength = pattern.length();
  u_long patternIndex, textIndex;
  int capacity = alphabetPower, prime = 7;
  long64 patternHash = 1, textHash = 1, hashValue = 1;
  vector occurancePoints;

  for (u_long eachInPattern = 0; eachInPattern < patternLength - 1; eachInPattern++) {
    hashValue = (hashValue * capacity) % prime;
  }
  for (u_long eachInPattern = 0; eachInPattern < patternLength; eachInPattern++) {
    patternHash = (capacity * patternHash + pattern[eachInPattern]) % prime;
    textHash = (capacity * textHash + text[eachInPattern]) % prime;
  }
  for (textIndex = 0; textIndex <= textLength - patternLength; textIndex++) {
    if (patternHash == textHash) {
      for (patternIndex = 0; patternIndex < patternLength; patternIndex++) {
        if (text[textIndex + patternIndex] != pattern[patternIndex]) {
          break;
        }
      }
      if (patternIndex == patternLength)
        occurancePoints.push_back(textIndex);
    }
    if (textIndex < textLength - patternLength) {
      textHash = (capacity * (textHash - text[textIndex] * hashValue) + text[textIndex + patternLength]) % prime;
      if (textHash < 0)
        textHash = (textHash + prime);
    }
  }
  
  return occurancePoints;
}