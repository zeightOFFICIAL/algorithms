// KnuthMorrisPratt.h

#include "_Utils.h"

namespace patternsearch {
  /**
  (string A, string B) -> (vector<unsigned long> C)
  Takes string A, string pattern B, as
  arguments. Finds pattern B in the
  string A, using Knuth-Morris-Pratt algorithm.
  Returns vector<unsigned long> C which
  stores every point of occurrence of the pattern
  in text.
  */
  static vector KMPSearch(string text, string pattern);
  /**
  (string A, unsigned long B, unsigned long* C, unsigned long D) -> ()
  Takes pattern A, its length B, unsigned long table C
  and text length D. KMP algorithm requires preprocessing.
  It processes pattern A and constructs an auxiliary table C
  of size B (same as size of pattern) which is used to skip
  characters while matching. Name of LPS (actual for table C)
  indicates longest proper prefix which is also a suffix.
  A proper prefix is a prefix with wholestring not allowed.
  Returns nothing, changes C.
  */
  static void Heuristics(string pattern, ulong patternLength, ulong *table, ulong textLength);
  
  static vector KMPSearch(string text, string pattern) {
    if (pattern.length() == 0 || text.length() == 0 || pattern.length() > text.length()) {
      return vector{0};
    }  
    ulong patternLength = pattern.length(), textLength = text.length();
    ulong *prefixTable = new ulong[patternLength];
    ulong each = 0, inRow = 0;
    vector occurancePoints;
  
    Heuristics(pattern, patternLength, prefixTable, textLength);
    while (each < textLength) {
      if (pattern[inRow] == text[each]) {
        each++;
        inRow++;
      }
      if (inRow == patternLength) {
        occurancePoints.push_back(each - inRow);
        inRow = prefixTable[inRow - 1];
      } else if (each < textLength && pattern[inRow] != text[each]) {
        if (inRow != 0) {
          inRow = prefixTable[inRow - 1];
        }
        else {
          each++;
        }
      }
    }
    delete[] prefixTable;
    
    return occurancePoints;
  }
  
  static void Heuristics(string pattern, ulong patternLength, ulong *table, ulong textLength) {
    table[0] = 0;
    ulong each = 1, prefixLength = 0;
    
    while (each < patternLength) {
      if (pattern[each] == pattern[prefixLength]) {
        prefixLength++;
        table[each] = prefixLength;
        each++;
      } else if (pattern[each] != pattern[prefixLength]) {
        if (prefixLength != 0)
          prefixLength = table[prefixLength - 1];
        else {
          table[each] = 0;
          each++;
        }
      }
    }
  }
}