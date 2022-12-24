// fnv132.h

#include "_Utils.h"

namespace hashing {
  const uint64 FNV64_PRIME = 0x00000100000001B3;
  const uint64 FNV64_OFFSET = 0xcbf29ce484222325;
  string fnv164(const string data);
} // namespace hashing