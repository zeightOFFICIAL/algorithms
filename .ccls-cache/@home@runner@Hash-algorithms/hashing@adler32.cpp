#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
#include <sstream>

#include <iostream>

#include "adler32.h"
#include "../tools/bitwise_operations.h"

const uint32_t MOD_ADLER = 65521;

std::string adler32(std::string data) 
{
    uint32_t innumber;
    innumber = adler32_base(data);
    std::string strnumber = ConvertUintStr(innumber);
    strnumber = ConvertBinHex(strnumber);
    return strnumber;
}

std::uint32_t adler32_base(std::string data)
{
    int len = data.length();
    uint32_t a = 1, b = 0;
    std::string hash = "";
    for (size_t index = 0; index < len; ++index)  {
        a = (a + data[index]) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }
    a  = (b << 16) | a;
    hash = ConvertUintStr(a);
    return (b << 16) | a;
}