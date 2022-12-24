// fnv132.h

#include "_Utils.h"

namespace hashing {
  const uint32 FNV32_PRIME = 0x01000193;
  const uint32 FNV32_OFFSET = 0x811c9dc5;
  string fnv132(const string data);
} // namespace hashing