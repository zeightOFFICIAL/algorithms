#include <sstream>
#include "fnv132.h"

const uint32_t FNV_PRIME = 0x01000193;
const uint32_t FNV_OFFSET = 0x811c9dc5;

std::uint32_t fnv132(const std::string data)
{
    int length = data.length();
    uint32_t hash = FNV_OFFSET;
    for (size_t index = 0; index < length; index++)
    {
        hash *= FNV_PRIME;
        hash ^= (data[index]);
    }
    return hash;
}