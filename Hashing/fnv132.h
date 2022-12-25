// fnv132.h

#include "_Utils.h"

namespace hashing {
  static const uint32 FNV32_PRIME = 0x01000193;
  static const uint32 FNV32_OFFSET = 0x811c9dc5;

  /**
  (string A) -> (string B)
  Creates checksum B of string A, using
  fnv132 hashing function. 
  Return string B - checksum.
  */
  string fnv132(const string data) {
    ulong length = data.length();
    uint32 hash = FNV32_OFFSET;
    
    for (ulong index = 0; index < length; index++) {
      hash *= FNV32_PRIME;
      hash ^= (data[index]);
    }
    
    return intToHex(hash);
  }
} // namespace hashing