#include "fnv164.h"

namespace hashing {
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