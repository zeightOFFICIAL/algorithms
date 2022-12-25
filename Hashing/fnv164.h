// fnv132.h

#include "_Utils.h"

namespace hashing {
  const uint64 FNV64_PRIME = 0x00000100000001B3;
  const uint64 FNV64_OFFSET = 0xcbf29ce484222325;

  /**
  (string A) -> (string B)
  Creates checksum B of string A, using
  fnv164 hashing function. 
  Return string B - checksum.
  */
  string fnv164(const string data) {
    u_long length = data.length();
    uint64 hash = FNV64_OFFSET;
    
    for (u_long index = 0; index < length; index++) {
      hash *= FNV64_PRIME;
      hash ^= (data[index]);
    }
    
    return intToHex(hash);
  }
} // namespace hashing