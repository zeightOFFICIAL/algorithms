#include <sstream>
#include "fnv132.h"

const uint32_t FNV_PRIME = 16777619;
const uint32_t FNV_OFFSET = 2166136261;

std::uint32_t fnv132(std::string data)
{
    int len = data.length();
    uint32_t hash = FNV_OFFSET;

    for (size_t index = 0; index < len; index++) {
		hash *= FNV_PRIME;
		hash ^= (data[index]);
	}

    return hash;
}