// rabin_karp.h

/*
Like the Naive Algorithm, Rabin-Karp algorithm also slides the
pattern one by one. But unlike the Naive algorithm, Rabin Karp
algorithm matches the hash value of the pattern with the hash
value of current substring of text, and if the hash values
match then only it starts matching individual characters.
So Rabin Karp algorithm needs to calculate hash values for
following strings.
https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
*/

#include <string> // std::string
#include <vector> // vector

/*
  (string A, string B) -> (vector<unsigned long> D)
  Takes text string A, the pattern B, as
  arguments.Finds pattern B in the text A, using
  Rabin-Karp algorithm.
  -Returns vector<unsigned long> D which
  stores every point of occurance of the pattern
  in text.
*/
std::vector<unsigned long> substrRabinKarp(std::string text,
                                           std::string pattern,
                                           int alphabet_power = 256);

std::vector<unsigned long>
substrRabinKarp(std::string text, std::string pattern, int alphabetPower) {
  unsigned long textLength = text.length(), patternLength = pattern.length(),
                throughPattern;
  int dCapacity = alphabetPower, qPrime = 7;
  long long patternHash = 1, textHash = 1, hValue = 1;
  std::vector<unsigned long> occurancePoints;
  if (patternLength == 0 || textLength == 0 || patternLength > textLength)
    return occurancePoints;
  for (unsigned long letterPattern = 0; letterPattern < patternLength - 1;
       letterPattern++)
    hValue = (hValue * dCapacity) % qPrime;
  for (unsigned long letter = 0; letter < patternLength; letter++) {
    patternHash = (dCapacity * patternHash + pattern[letter]) % qPrime;
    textHash = (dCapacity * textHash + text[letter]) % qPrime;
  }
  for (unsigned long through_text = 0;
       through_text <= textLength - patternLength; through_text++) {
    if (patternHash == textHash) {
      for (throughPattern = 0; throughPattern < patternLength;
           throughPattern++) {
        if (text[through_text + throughPattern] != pattern[throughPattern]) {
          break;
        }
      }
      if (throughPattern == patternLength)
        occurancePoints.push_back(through_text);
    }
    if (through_text < textLength - patternLength) {
      textHash = (dCapacity * (textHash - text[through_text] * hValue) +
                  text[through_text + patternLength]) %
                 qPrime;
      if (textHash < 0)
        textHash = (textHash + qPrime);
    }
  }
  return occurancePoints;
}