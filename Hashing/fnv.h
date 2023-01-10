/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// fnv.h

#include "_Utils.h"

namespace hashing {
  static const uint32 FNV32_PRIME = 0x01000193;
  static const uint32 FNV32_OFFSET = 0x811c9dc5;
  static const uint64 FNV64_PRIME = 0x00000100000001B3;
  static const uint64 FNV64_OFFSET = 0xcbf29ce484222325;
  /**
  (string A) -> (string B)
  Creates checksum B of string A, using
  fnv132 hashing function. 
  Return string B - checksum.
  */
  static string fnv132(const string data);
  /**
  (string A) -> (string B)
  Creates checksum B of string A, using
  fnv164 hashing function. 
  Return string B - checksum.
  */
  static string fnv164(const string data);

  static string fnv132(const string data) {
    ulong length = data.length();
    uint32 hash = FNV32_OFFSET;
    
    for (ulong index = 0; index < length; index++) {
      hash *= FNV32_PRIME;
      hash ^= (data[index]);
    }
    
    return intToHex(hash);
  }

  static string fnv164(const string data) {
    ulong length = data.length();
    uint64 hash = FNV64_OFFSET;
    
    for (ulong index = 0; index < length; index++) {
      hash *= FNV64_PRIME;
      hash ^= (data[index]);
    }
    
    return intToHex(hash);
  }
} // namespace hashing