#include <sstream>
#include "adler32.h"

const uint32_t MOD_ADLER = 65521;

std::uint32_t adler32(const std::string data)
{
    int length = data.length();
    uint32_t a = 1, b = 0;

    for (size_t index = 0; index < length; ++index) {
        a = (a + data[index]) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }
    return (b << 16) | a;
}