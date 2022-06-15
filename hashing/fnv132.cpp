#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <sstream>

#include <iostream>

#include "fnv132.h"
#include "../tools/bitwise_operations.h"

const uint32_t FNV_PRIME = 16777619;
const uint32_t FNV_OFFSET = 2166136261;

std::string fnv132(std::string data)
{
    int len = data.length();
    uint32_t hash = FNV_OFFSET;
    for (auto i = 0; i < len; i++)
	{
		hash *= FNV_PRIME;
		hash ^= (data[i]);
	}
    std::string result = ConvertUintStr(hash);
    return ConvertBinHex(result);
}