#include "fnv132.h"

namespace hashing {
  string fnv132(const string data) {
    u_long length = data.length();
    uint32 hash = FNV32_OFFSET;
    
    for (u_long index = 0; index < length; index++) {
      hash *= FNV32_PRIME;
      hash ^= (data[index]);
    }
    
    return intToHex(hash);
  }
} // namespace hashing