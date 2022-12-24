#include "adler32.h"

namespace hashing {
  string adler32(const string data) {
    u_long length = data.length();
    uint32 a = 1, b = 0;
  
    for (u_long index = 0; index < length; ++index) {
      a = (a + data[index]) % ADLER32_MOD;
      b = (b + a) % ADLER32_MOD;
    }
  
    return intToHex((b << 16) | a);
  }
} // namespace hashing