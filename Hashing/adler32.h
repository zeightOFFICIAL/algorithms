// adler32.h

#include "_Utils.h"

namespace hashing {
  const u_long ADLER32_MOD = 65521;
  string adler32(const string data);
} // namespace hashing